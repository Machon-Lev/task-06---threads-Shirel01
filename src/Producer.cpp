
#include <thread>
#include <future>
#include <string>
#include <unordered_map>
#include <chrono>
#include <exception>
//#include "Colors.cpp"
#include "Colors.h"
#include <iostream>
using namespace std;
extern std::unordered_map<std::string, std::ostream& (*)(std::ostream& s)> Colors;
extern std::mutex mtx;
extern std::condition_variable cv;
extern bool allFinished;

void producer(int thread_id) {
    double value = thread_id * 10000.0;
    while (value > 0) {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << Colors["blue"] << value << " :sent tid<" << thread_id << ">" << Colors["white"] << std::endl;
        lock.unlock();
        cv.notify_one();
        value /= 10.0;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulating some work
    }
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << Colors["red"] << "Thread " << thread_id << " finished." << Colors["white"] << std::endl;
    lock.unlock();
    cv.notify_one();
}