#include "timed.hpp"
#include <iostream>
#include <thread>

int main() {
    auto x = timed::time([]{
        volatile auto x = 0;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        for (std::size_t idx = 0; idx < 1000; ++idx)
            x += idx;
    });

    std::cout << timed::seconds(x) << std::endl;

    return 0;
}
