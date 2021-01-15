#include <iostream>

//we pass a final action function to this struct
template<typename F> struct final_action {
    //clean is a function object
    F clean;
    final_action(F f) : clean(f) {}
    ~final_action() { clean(); }
};

//helper function to create an instance of the final_action
template<class F>
final_action<F> finally(F f) {
    return final_action<F>(f);
}

void foo() {
    try {
        // initializations
        auto finally_action = finally([&]{ std::cout << "hello"; });
		// problematic code

		// upon leaving scope, the finally destructur calls the
		// final_action destructor, which calls the function object stored

	} catch (...) {
		// exception handler
	}
}

int main() {
    foo();
    return 0;
}