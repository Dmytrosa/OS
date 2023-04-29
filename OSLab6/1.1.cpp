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
//    int x;
//    int y;
//};
//
//void multiply(MatrixMultiplicationData data) {
//    int sum = 0;
//    int n = data.A->size();
//    int m = data.B->size();
//    int k = (*data.B)[0].size();
//
//    for (int i = 0; i < m; ++i) {
//        sum += (*data.A)[data.x][i] * (*data.B)[i][data.y];
//    }
//
//    mtx.lock();
//    std::cout << "[" << data.x << "," << data.y << "]=" << sum << std::endl;
//    (*data.C)[data.x][data.y] = sum;
//    mtx.unlock();
//}
//
//void printMatrix(const std::vector<std::vector<int>>& matrix, const std::string& name) {
//    std::cout << "Matrix " << name << ":" << std::endl;
//    for (const auto& row : matrix) {
//        for (const auto& element : row) {
//            std::cout << element << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    int n = 3, m = 2, k = 4;
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
//    std::vector<std::thread> threads;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < k; ++j) {
//            MatrixMultiplicationData data{ &A, &B, &C, i, j };
//            threads.push_back(std::thread(multiply, data));
//        }
//    }
//
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    printMatrix(A, "A");
//    printMatrix(B, "B");
//    printMatrix(C, "C");
//
//    return 0;
//}
