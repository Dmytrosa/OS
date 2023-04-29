//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//#include <ctime>
//#include <chrono>
//
//std::mutex mtx;
//
//struct MatrixMultiplicationData {
//    std::vector<std::vector<int>>* A;
//    std::vector<std::vector<int>>* B;
//    std::vector<std::vector<int>>* C;
//    int x_start;
//    int x_end;
//    int y_start;
//    int y_end;
//};
//
//void multiply(MatrixMultiplicationData data) {
//    int m = data.B->size();
//
//    for (int x = data.x_start; x < data.x_end; ++x) {
//        for (int y = data.y_start; y < data.y_end; ++y) {
//            int sum = 0;
//            for (int i = 0; i < m; ++i) {
//                sum += (*data.A)[x][i] * (*data.B)[i][y];
//            }
//            (*data.C)[x][y] = sum;
//        }
//    }
//}
//int main() {
//    int n = 500, m = 200, k = 300;
//
//    srand(time(0));
//
//    std::vector<std::vector<int>> A(n, std::vector<int>(m)), B(m, std::vector<int>(k)), C(n, std::vector<int>(k, 0));
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            A[i][j] = rand() % 10;
//        }
//    }
//
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < k; ++j) {
//            B[i][j] = rand() % 10;
//        }
//    }
//
//    for (int num_threads_test = 1; num_threads_test <= std::thread::hardware_concurrency(); ++num_threads_test) {
//        int block_size = n / num_threads_test;
//
//        auto start = std::chrono::high_resolution_clock::now();
//
//        std::vector<std::thread> threads;
//        for (int i = 0; i < num_threads_test; ++i) {
//            int x_start = i * block_size;
//            int x_end = (i == num_threads_test - 1) ? n : x_start + block_size;
//            MatrixMultiplicationData data{ &A, &B, &C, x_start, x_end, 0, k };
//            threads.push_back(std::thread(multiply, data));
//        }
//
//        for (auto& thread : threads) {
//            thread.join();
//        }
//
//        auto end = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//
//        std::cout << "Time taken with " << num_threads_test << " threads: " << duration << " ms" << std::endl;
//    }
//
//    return 0;
//}