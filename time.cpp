#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>

void display_time() {
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&current_time);

        std::cout << "\rCurrent time: " 
                  << std::put_time(local_time, "%I:%M:%S %p") << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    display_time();
    return 0;
}
