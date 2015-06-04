#pragma once

#include <iostream>
#include <functional>
#include <chrono>

namespace timed {

template<typename F, typename... Args>
auto time(F&& f, Args&&... args) {
    auto start = std::chrono::steady_clock::now();
    f(std::forward<Args>(args)...);
    return std::chrono::steady_clock::now() - start;
}

template<long Rep, long Period>
double seconds(const std::chrono::duration<long, std::ratio<Rep, Period>>& duration) {
    return static_cast<double>(duration.count()) / static_cast<double>(Period);
}

} // namespace timed
