#include <algorithm>
#include <iostream>
#include <numeric>
#include <thread>

template <typename Iterator, typename T>
struct accumulate_block {
    void operator()(Iterator first, Iterator last, T& result) {
        result = std::accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);
    if (!length) return init;

    // Divide the number of elements to process by the minimum block size in
    // order to give the max number of threads to spawn- this avoids creating
    // more threads than needed (for instance using all cores when < elements
    // than cores) or from running more threads than HW can support, as the
    // context switching will actually decrease overall performance
    // (oversubscription).
    auto const min_per_thread = 25;
    auto const max_threads = (length + min_per_thread - 1) / min_per_thread;
    auto const num_hw_threads = std::thread::hardware_concurrency();
    auto const num_threads =
        std::min(num_hw_threads != 0 ? num_hw_threads : 2, max_threads);

    auto const block_size = length / num_threads;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (auto i = 0; i < (num_threads - 1); i++) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start,
                                 block_end, std::ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator, T>()(block_start, last,
                                    results[num_threads - 1]);

    for (auto& i_thread : threads) i_thread.join();

    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    auto num_threads = std::thread::hardware_concurrency();
    std::cout << "Number of HW threads: " << num_threads << std::endl;
}
