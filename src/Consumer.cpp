#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <unordered_map>
#include <chrono>
#include <exception>
//#include "Colors.cpp"
#include "Colors.h"

extern std::unordered_map<std::string, std::ostream& (*)(std::ostream& s)> Colors;
extern std::mutex mtx;
extern std::condition_variable cv;
extern bool allFinished;
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return allFinished; });
        break;
    }
    std::cout << Colors["yellow"] << "Consumer: All threads finished." << Colors["white"] << std::endl;
}

