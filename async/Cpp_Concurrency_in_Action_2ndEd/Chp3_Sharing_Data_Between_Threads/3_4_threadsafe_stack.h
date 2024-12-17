#include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct empty_stack : std::exception {
    const char* what() const noexcept;
};

template <typename T>
class threadsafe_stack {
   private:
    std::stack<T> data;
    mutable std::mutex m;

   public:
    threadsafe_stack() {}

    // Copy-able (assuming stack elements can be copied)
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    // delete assignment operator
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
    }

    // the use of shared_ptr allows the stack to take care of the
    // memory-allocation issues and avoid excessive calls to `new` and `delete`
    // if desired
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        // check for empty before trying to pop() value
        if (data.empty()) throw empty_stack();
        // allocate return value before modifying stack
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T& value) {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        value = data.top();
        data.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
