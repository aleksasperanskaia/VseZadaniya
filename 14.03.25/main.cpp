#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready=false;
bool processed=false;

void worker_thread() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Worker thread started\n";
    std::unique_lock lk(m);
    cv.wait(lk, []{ return ready; });
    std::cout << "Worker thread is processing\n";
    data += " after processing";
    processed = true;
    std::cout << "Worker thread signals processing complete\n";
    lk.unlock();
    cv.notify_one();
}

void master_thread() {
    std::cout << "Master thread start\n";
    data = "Example data";{
        std::lock_guard lk(m);
        ready = true;
        std::cout << "Master thread signals data ready for processing\n";
    }
    cv.notify_one();{
        std::unique_lock lk(m);
        cv.wait(lk, []{ return processed; });
    }
    std::cout << "In Master thread again data " << data << "\n";
}

int main()
{
    std::thread worker(worker_thread);
    std::thread master(master_thread);

    worker.join();
    master.join();

    return 0;
}
