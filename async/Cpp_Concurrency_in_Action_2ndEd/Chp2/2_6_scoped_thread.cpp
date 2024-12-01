// Use the std::move() support in std::thread to build on previous
// ./2_3_thread_guard.cpp glass and have it take ownership of a thread.
#include <thread>

class scoped_thread {
    std::thread t;

   public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
        if (!t.joinable()) {
            throw std::logic_error("No thread!");
        }
    }

    // NOTE: in C++20 there's a proposal to have a std::jthread
    // class/implementation which auto joins on destructor, much like this class
    // does
    ~scoped_thread() { t.join(); }
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};

struct func;

void f() {
    int some_local_state;
    scoped_thread t(std::thread(func(some_local_state)));
    // do something in current thread...
}
