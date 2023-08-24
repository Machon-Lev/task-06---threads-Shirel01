#include <iostream>
#include <vector>
#include "consumer.cpp"
#include "producer.cpp"
#include "Colors.h"
using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool allFinished = false;
int main() {
    std::vector<std::future<void>> producer_futures;
    for (int i = 0; i < 2; ++i) {
        try {
            std::future<void> future = std::async(std::launch::async, producer, i);
            producer_futures.emplace_back(std::move(future));
        }
        catch (const std::exception& e) {
            std::cout << "Exception in producer " << i << ": " << e.what() << std::endl;
        }
    }

    std::future<void> consumer_future = std::async(std::launch::async, consumer);

    for (auto& future : producer_futures) {
        try {
            future.wait();
        }
        catch (const std::exception& e) {
            std::cout << "Exception while waiting for producer: " << e.what() << std::endl;
        }
    }

   
    {
        std::lock_guard<std::mutex> lock(mtx);
        allFinished = true;
    }
    cv.notify_one();

    try {
        consumer_future.wait();
    }
    catch (const std::exception& e) {
        std::cout << "Exception while waiting for consumer: " << e.what() << std::endl;
    }

    return 0;
}