/////////////////////a)



//#include <iostream>
//#include <thread>
//#include <mutex>
//
//std::mutex mtx;
//int shared_variable = 0;
//
//void increment(int times) {
//    for (int i = 0; i < times; ++i) {
//        mtx.lock();
//        ++shared_variable;
//        mtx.unlock();
//    }
//}
//
//int main() {
//    const int iterations = 1e9;
//
//    std::thread t1(increment, iterations);
//    std::thread t2(increment, iterations);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Shared variable: " << shared_variable << std::endl;
//
//    return 0;
//}



/////////////////////b)
//
//#include <iostream>
//#include <thread>
//
//int shared_variable = 0;
//
//void increment(int times) {
//    for (int i = 0; i < times; ++i) {
//        ++shared_variable;
//    }
//}
//
//int main() {
//    const int iterations = 1e9;
//
//    std::thread t1(increment, iterations);
//    std::thread t2(increment, iterations);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Shared variable: " << shared_variable << std::endl;
//
//    return 0;
//}
