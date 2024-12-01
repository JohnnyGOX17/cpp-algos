#include <iostream>
// Declarations for multithreading in std C++ lib
#include <thread>

void hello() { std::cout << "Hello concurrent world\n"; }

// initial program thread
int main() {
    // initial function for new thread in ctor
    std::thread t(hello);
    // join() waits for thread object t
    t.join();
}
