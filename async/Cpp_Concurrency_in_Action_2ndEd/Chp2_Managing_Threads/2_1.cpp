#include <iostream>
#include <thread>

struct func {
    int& i;
    int k = 0;
    func(int& i_) : i(i_) {}
    void operator()() {
        // Do (relatively) lots of work in this thread...
        for (unsigned j = 0; j < 1000000; ++j) {
            k += i;
            if (j == 1000000 - 1) {
                // This should never execute as we exit the main thread (and
                // application) before this thread completes!
                std::cout << "Terminal count hit!" << std::endl;
            }
        }
    }
};

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);

    std::thread my_thread(my_func);

    // Don't wait for thread to finish, which means we exit right here at end of
    // while my_thread() is likely still running...
    my_thread.detach();
}

int main() {
    oops();
    // another call to oops() could access some already destroyed variable
    //
    // One common way to handle this scenario is to make the thread function
    // self-contained and copy the data into the thread rather than sharing the
    // data. Or to wait until a thread has completed executing by 'joining'
}
