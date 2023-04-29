//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::mutex mtx;
//std::condition_variable cv;
//int shared_variable = 0;
//bool thread1_turn = true;
//
//void increment(int times, bool is_thread1) {
//    std::unique_lock<std::mutex> lock(mtx);
//    for (int i = 0; i < times; ++i) {
//        cv.wait(lock, [is_thread1] { return thread1_turn == is_thread1; });
//        ++shared_variable;
//        std::cout << "Thread " << (is_thread1 ? "1" : "2") << " incremented to " << shared_variable << std::endl;
//        thread1_turn = !thread1_turn;
//        cv.notify_all();
//    }
//}
//
//int main() {
//    const int iterations = 500;
//
//    std::thread t1(increment, iterations, true);
//    std::thread t2(increment, iterations, false);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Shared variable: " << shared_variable << std::endl;
//
//    return 0;
//}
