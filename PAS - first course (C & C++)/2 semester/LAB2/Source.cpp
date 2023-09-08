#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

double sum_recursive(int n);
double sum_iterative(int n);

//Обчислення за допомогою рекурсії
double sum_recursive(int n) {
    if (n == 1.0) {
        return 0.0;
    }
    else {
        return sum_recursive(n - 1) + (3.0 * n) / (n - 1) - n * n;
    }
}
//Обчислення за допомогою циклу
double sum_iterative(int n) {
    double sum = 0.0;
    for (int i = 2; i <= n; i++) {
        sum += (3.0 * i) / (i - 1) - i * i;
    }
    return sum;
}

int main() {
   
    int sum = 0;

    int n;
    std::cout << "Enter a value for 'n' --> ";
    cin >> n;

    auto start_time = std::chrono::steady_clock::now();
    std::cout << "\nSum recursive = " << sum_recursive(n) << std::endl;
    auto end_time = std::chrono::steady_clock::now();
    auto time_recursive = duration_cast<nanoseconds>(end_time - start_time).count();
    cout << "Time: " << time_recursive << " ns" << std::endl;

    start_time = std::chrono::steady_clock::now();
    std::cout << "\nSum non-recursive = " << sum_iterative(n) << std::endl;
    end_time = std::chrono::steady_clock::now();
    auto time_iterative = duration_cast<nanoseconds>(end_time - start_time).count();

    cout << "Time: " << time_iterative << " ns" << endl;

    return 0;
}
