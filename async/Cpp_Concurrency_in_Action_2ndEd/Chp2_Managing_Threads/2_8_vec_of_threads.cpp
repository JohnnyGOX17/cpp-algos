// Move-aware containers, like std::vector, allow you to write code like belwo
// which- spawns a number of threads and waits for them to finish
#include <thread>

void do_work(unsigned id);

void f() {
    std::vector<std::thread> threads;

    auto num_threads = 20;
    for (auto i = 0; i < num_threads; i++) {
        threads.emplace_back(do_work, i);
    }

    for (auto& i_thread : threads) i_thread.join();
}
