#include <cstdlib>  
#include <iostream>
#include <chrono>  
#include <windows.h>

using namespace std;


void fillArray(int array[][10], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = rand() % 31 - 10;
        }
    }
}


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
//        Sorting algorithm by choice
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
//          Shaker sorting
//++++++++++++++++++++++++++++++++++++++++++
void shakerSort(int array[10][10]) {
    int N = 10;
    int left = 0;
    int right = N - 1;
    bool isSwapped = true;

    while (isSwapped) {
        isSwapped = false;

        for (int i = left; i < right; i++) {
            for (int j = 0; j < N && j <= i; j++) { 
                if (array[j][i] < array[j][i + 1]) {
                    swap(array[j][i], array[j][i + 1]);
                    isSwapped = true;
                }
            }
        }

        for (int i = right; i > left; i--) {
            for (int j = 0; j < N && j <= i - 1; j++) {
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

    srand(time(0)); 

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 10;
    int array[N][N];
    int iterations1 = 0;
    int iterations2 = 0;


    int Method;
    std::cout << "\t1. * Ñîðòóâàííÿ âèáîðîì  * \n\t";
    std::cout << "2. * Øåéêåðíå ñîðòóâàííÿ * \n\t";
    std::cout << "Îáåð³òü ìåòîä ñîðòóâàííÿ(1-2)--> ";
    cin >> Method;

    //***********************************************************************
    //*****************       Selection sorting method      *****************
    //***********************************************************************

    if (Method == 1) {

        auto start = std::chrono::high_resolution_clock::now();

    
        fillArray(array, N);

       
        cout << "Ïî÷àòêîâèé ìàñèâ:" << endl;
        printArray(array, N);

    
        for (int i = 0; i < N / 2; i++) {
            selectionSort(array);
        }

    
        cout << "Ìîäèô³êîâàíèé ìàñèâ:" << endl;
        printArray(array, N);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "×àñ âèêîíàííÿ: " << duration << " íñ" << std::endl;

    }

    //***********************************************************************
    //********************     Shaker sorting method     ********************
    //***********************************************************************

    if (Method == 2) {

        auto start = std::chrono::high_resolution_clock::now();


        fillArray(array, N);


        cout << "Ïî÷àòêîâèé ìàñèâ:" << endl;
        printArray(array, N);

        shakerSort(array);

        cout << "Ìîäèô³êîâàíèé ìàñèâ: " << endl;
        printArray(array, N);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "×àñ âèêîíàííÿ: " << duration << " íñ " << std::endl;

    }
    return 0;
}
