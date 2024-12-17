#include <algorithm>
#include <list>
#include <mutex>

// single global variable we could potentially share between threads
std::list<int> some_list;
// ^ above protected with corresponding mutex
std::mutex some_mutex;

void add_to_list(int new_value) {
    // instead of calling lock and having to explicitly remember to unlock, C++
    // std lib provides std::lock_guard class template which provides RAII
    // (locks mutex on construction and unlocks on destruction)
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    // mutex here could potentially block if add_to_list() is in middle of
    // modification
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) !=
           some_list.end();
}
