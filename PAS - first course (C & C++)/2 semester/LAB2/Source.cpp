#include <cstdlib>  // містить "srand()" і "rand()"
#include <iostream>
#include <chrono>   // Для вирахування часу
#include <windows.h> // бібліотека для зміни кольору тексту в консолі

using namespace std;

// Функція для заповнення масиву випадковими числами
void fillArray(int array[][10], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = rand() % 31 - 10;
        }
    }
}

// виведення масиву на екран
void printArray(int array[][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i <= j) {
                cout << "\033[38;2;0;191;255m";
            }
            std::cout.width(3);
            std::cout << array[i][j] << " ";
            cout << "\033[0m";
        }
        cout << endl;
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++
//          Алгоритм сортування вибором
//+++++++++++++++++++++++++++++++++++++++++++++++

void selectionSort(int array[10][10]) {
    int N = 10;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            int max_idx = j;
            if (i <= j) {
                for (int k = j + 1; k < N; k++) {
                    if (array[i][k] > array[i][max_idx]) {
                        max_idx = k;
                    }
                }
            }
            if (max_idx != j) {
                int temp = array[i][j];
                array[i][j] = array[i][max_idx];
                array[i][max_idx] = temp;
            }
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++
//          Шейкерне сортування
//++++++++++++++++++++++++++++++++++++++++++
void shakerSort(int array[10][10]) {
    int N = 10;
    int left = 0;
    int right = N - 1;
    bool isSwapped = true;

    while (isSwapped) {
        isSwapped = false;
        // з ліва на право
        for (int i = left; i < right; i++) {
            for (int j = 0; j < N && j <= i; j++) { // обмежуємо цикл
                if (array[j][i] < array[j][i + 1]) {
                    swap(array[j][i], array[j][i + 1]);
                    isSwapped = true;
                }
            }
        }
        // з права на ліво
        for (int i = right; i > left; i--) {
            for (int j = 0; j < N && j <= i - 1; j++) { // обмежуємо цикл
                if (array[j][i] > array[j][i - 1]) {
                    swap(array[j][i], array[j][i - 1]);
                    isSwapped = true;
                }
            }
        }
        left++;
        right--;
    }
}


int main() {

    srand(time(0)); //генератор рандомних чисел

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 10;
    int array[N][N];
    int iterations1 = 0;
    int iterations2 = 0;

    // Комунікація з користувачем
    int Method;
    std::cout << "\t1. * Сортування вибором  * \n\t";
    std::cout << "2. * Шейкерне сортування * \n\t";
    std::cout << "Оберіть метод сортування(1-2)--> ";
    cin >> Method;

    //***********************************************************************
    //*****************       Метод сортування вибором      *****************
    //***********************************************************************

    if (Method == 1) {

        auto start = std::chrono::high_resolution_clock::now();

        // Заповнення масиву випадковими числами
        fillArray(array, N);

        // Виведення початкового масиву на екран
        cout << "Початковий масив:" << endl;
        printArray(array, N);

        // сортування за спаданням
        for (int i = 0; i < N / 2; i++) {
            selectionSort(array);
        }

        // Виведення модифікованого масиву на екран
        cout << "Модифікований масив:" << endl;
        printArray(array, N);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Час виконання: " << duration << " нс" << std::endl;

    }

    //***********************************************************************
    //****************     Методом шейкерного сортування     ****************
    //***********************************************************************

    if (Method == 2) {

        auto start = std::chrono::high_resolution_clock::now();

        // Заповнення масиву випадковими числами
        fillArray(array, N);

        // Виведення початкового масиву на екран
        cout << "Початковий масив:" << endl;
        printArray(array, N);

        shakerSort(array);

        cout << "Модифікований масив: " << endl;
        printArray(array, N);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Час виконання: " << duration << " нс " << std::endl;

    }
    return 0;
}
