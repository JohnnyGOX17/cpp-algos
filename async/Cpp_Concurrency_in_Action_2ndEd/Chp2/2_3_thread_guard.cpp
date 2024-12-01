// To ensure a thread w/access to local state is finished before exiting-
// whether by exception or normal circumstances- we can use the Resource
// Acquisition Is Initialization (RAII) idiom to provide a class that handles
// this.
#include <thread>

class thread_guard {
    std::thread& t;

   public:
    explicit thread_guard(std::thread& t_) : t(t_) {}

    ~thread_guard() {
        // test if joinable as join() can only be called once
        if (t.joinable()) {
            t.join();
        }
    }
    // Copy constructor and copy assignment operators are marked as `=delete` to
    // ensure that they're not automatically provided by the compiler- we don't
    // want to copy or assign this object as it may outlive the scope of the
    // threat its joining (dangerous!)
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

struct func;

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    // do something in current thread...
}
