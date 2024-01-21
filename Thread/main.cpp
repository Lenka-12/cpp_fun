#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <signal.h>

bool bStop = false;
class RealTimeThreadManager {
public:
    RealTimeThreadManager() : threadPaused(false) {}

    void startThread() {
        thread = std::thread(&RealTimeThreadManager::threadFunction, this);
    }

    void pauseThread() {
        {
            std::unique_lock<std::mutex> lock{mutex};
            std::cout << "Pausing....\n";
            threadPaused = true;
            lock.unlock();
        }
    }

    void resumeThread() {
        {
            std::unique_lock<std::mutex> lock{mutex};
            std::cout << "Resuming...............................................................................\n";
            threadPaused = false;
            lock.unlock();
        }
        conditionVariable.notify_one();  // Notify the thread to check the condition
    }

    void Stop(){
        stopRequested.store(true);
    }

    ~RealTimeThreadManager() {
        if (thread.joinable()) {
            thread.join();
        }
    }

    // RAII class for automatically joining the thread
    class ThreadJoiner {
    public:
        explicit ThreadJoiner(RealTimeThreadManager& manager) : manager(manager) {}
        ~ThreadJoiner() {
            manager.Stop();
            std::cout << "Done\n";
        }

    private:
        RealTimeThreadManager& manager;
    };

private:
    void threadFunction() {
        int i=0;
        while (!stopRequested.load()) {
            {
                    i++;
                    {
                    std::unique_lock<std::mutex> lock{mutex};
                

            
                    std::cout << "Real-time Thread running!\n";

                

                    // Check if the thread is paused
                    if(threadPaused){
                        conditionVariable.wait(lock, [this] { return !threadPaused; });

                    }


                }
                
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    std::thread thread;
    std::mutex mutex;
    std::condition_variable conditionVariable;
    std::atomic<bool> stopRequested;
    bool threadPaused;
};
void PStop(int sig){
    bStop = true;
}
int main() {


        signal(SIGINT,PStop);

        RealTimeThreadManager manager;

        // Start the thread
        manager.startThread();  

        RealTimeThreadManager::ThreadJoiner joiner{manager};

        
        std::this_thread::sleep_for(std::chrono::seconds(5));
        manager.pauseThread();

    
        std::this_thread::sleep_for(std::chrono::seconds(1));
        manager.resumeThread();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        manager.pauseThread();


        std::this_thread::sleep_for(std::chrono::seconds(2));
        manager.resumeThread();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        while(true){
            if(bStop){
                break;
            }

        }


    return 0;
}
