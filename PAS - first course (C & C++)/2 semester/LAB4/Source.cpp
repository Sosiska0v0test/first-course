#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

//---------------  1  ---------------
// Considering the case of the letter

struct fibs {
    int i = 0;
    int p = 0;
    int q = 0;
    bool flag = false;
};

int getFibonacciNum(int num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return getFibonacciNum(num - 1) + getFibonacciNum(num - 2);
}

void startInit(std::vector<std::string> arr, fibs& f) {
    f.flag = false;
    int k = 0;
    int size = arr.size();

    while (getFibonacciNum(k + 1) < size) {
        k += 1;
    }

    int m = getFibonacciNum(k + 1) - (size + 1);
    f.i = getFibonacciNum(k) - m;
    f.p = getFibonacciNum(k - 1);
    f.q = getFibonacciNum(k - 2);
}

void upIndex(fibs& f) {
    if (f.p == 1) {
        f.flag = true;
    }

    f.i += f.q;
    f.p -= f.q;
    f.q -= f.p;
}

void downIndex(fibs& f) {
    if (f.q == 0) {
        f.flag = true;
    }

    int buff = f.q;
    f.i -= f.q;
    f.q = f.p - f.q;
    f.p = buff;
}

int fibonacciSearch1(std::vector<std::string> arr, std::string word) {
    fibs f;
    startInit(arr, f);
    int resIndex = -1;

    while (!f.flag) {
        if (f.i < 0) {
            upIndex(f);
        }
        else if (f.i >= arr.size()) {
            downIndex(f);
        }
        else if (arr[f.i] == word) {
            resIndex = f.i;
            break;
        }
        else if (word < arr[f.i]) {
            downIndex(f);
        }
        else if (word > arr[f.i]) {
            upIndex(f);
        }
    }

    return resIndex;
}
//---------------  2  -------------          
//       NOT case sensitive

int fibonacciSearch2(std::vector<std::string> arr, std::string word) {
    fibs f;
    startInit(arr, f);
    int resIndex = -1;

    while (!f.flag) {
        if (f.i < 0) {
            upIndex(f);
        }
        else if (f.i >= arr.size()) {
            downIndex(f);
        }
        else {
            std::string currentWord = arr[f.i];
            std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), [](unsigned char c) { return std::tolower(c); });
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });

            if (currentWord == word) {
                resIndex = f.i;
                break;
            }
            else if (word < currentWord) {
                downIndex(f);
            }
            else if (word > currentWord) {
                upIndex(f);
            }
        }
    }

    return resIndex;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //******************************************
    //          ALPHABETICAL SORTING           * 
    //******************************************

 
    ifstream input("names.txt");

    if (!input.is_open()) {
        cerr << "Помилка відкриття файлу names.txt" << endl;
        return 1;
    }
    vector<string> names; 
 
    string name;
    while (input >> name) {
        names.push_back(name);
    }
    input.close(); 
  
    sort(names.begin(), names.end());
   
    ofstream output("Sortednames.txt");

    for (const auto& name : names) {
        output << name << endl;
    }
    output.close(); 
    cout << "* Імена відсортовано та записано у файл Sortednames.txt *\n" << endl;
    int search;
    std::cout << "* виберіть праметр пошуку послідовності символів: \n\t";
    std::cout << "1. * як окреме слово * \n\t";
    std::cout << "2. * як послідовність символів * \n\t\t";
    cin >> search;

    //----------------------------------------------------------------------------
    //         As a separate word (using the "Fibonacci Search" algorithm)       |
    //----------------------------------------------------------------------------

    if (search == 1) {
        int ans;
        std::cout << "*-- враховуючи або не враховуючи регістр літери (1 = yes / 2 = no) --*\n\t\t";
        cin >> ans;

     
        if (ans == 1) {
            std::ifstream infile("Sortednames.txt");
            std::vector<std::string> names;

            std::string line;
            while (std::getline(infile, line)) {
                names.push_back(line);
            }
            std::sort(names.begin(), names.end());
            std::string searchWord;
            std::cout << "Введіть слово: "; 
            std::cin >> searchWord;

            int index = fibonacciSearch1(names, searchWord);
            if (index != -1) {
                std::cout << "Знайдено " << searchWord << " в рядку: " << index << std::endl;
            }
            else {
                std::cout << "Ім'я " << searchWord << " не знайдено" << std::endl;
            }
        }
   
        if (ans == 2) {
            std::ifstream infile("Sortednames.txt");
            std::vector<std::string> names;

            std::string line;
            while (std::getline(infile, line)) {
                names.push_back(line);
            }

            std::sort(names.begin(), names.end());

            std::string searchWord;
            std::cout << "Введіть слово: "; 
            std::cin >> searchWord;

            int index = fibonacciSearch2(names, searchWord);
            if (index != -1) {
                std::cout << "Знайдено " << searchWord << " в рядку: " << index << std::endl;
            }
            else {
                std::cout << "Ім'я " << searchWord << " не знайдено" << std::endl;
            }
        }

        //-------------------------------------------------------------------------
        //       As a sequence of characters by the "Linear search" algorithm     |
        //-------------------------------------------------------------------------

        if (search == 2) {
            int ans2;
            std::cout << "*-- враховуючи або не враховуючи регістр літери (1 = yes / 2 = no) --*\n\t\t";
            cin >> ans2;

            //З урахуванням регістру літери
            if (ans2 == 1) {
                string search_word2; //визначається як рядок, до якого користувач вводить слово для пошуку.
                bool found2 = false; //буде встановлена як true, якщо слово буде знайдено в файлі.
                ifstream file("names.txt");
                cout << "Введіть слово: ";
                cin >> search_word2;
                string line2; //використовується для збереження рядка, який було прочитано з файлу.
                int line_num2 = 1; // використовується для збереження номера рядка, на якому було знайдено слово.
                while (getline(file, line2)) { //кожен рядок файлу по черзі читається в line2. Якщо шукане слово знаходиться в рядку 
                    if (line2.find(search_word2) != string::npos) {
                        int start_pos = line2.find(search_word2);
                        int end_pos = start_pos + search_word2.length();
                        cout << "Знайдено    ";
                        cout << line2.substr(0, start_pos); // виводимо частину рядка до знайденого слова
                        cout << "\033[33m" << line2.substr(start_pos, search_word2.length()) << "\033[0m"; // виводимо знайдену частину оранжевим кольором
                        cout << line2.substr(end_pos); // виводимо частину рядка після знайденого слова
                        cout << " в рядку --->  " << line_num2 << ": " << endl;
                        found2 = true;
                    }
                    line_num2++;
                }
                if (!found2) {
                    cout << "* Слово не знайдено *" << endl;
                }
                file.close();
            }

            //БЕЗ урахування регістру літери
            if (ans2 == 2) {
                string search_word2; // змінна "search_word2", яка зберігатиме введене користувачем слово
                bool found2 = false; // початково встановлюється в "false" і пізніше змінюється на "true", якщо слово було знайдено у файлі.
                ifstream file("names.txt"); //відкриття файлу
                cout << "Введіть слово: ";
                cin >> search_word2;
                string line2;
                int line_num2 = 1;
                while (getline(file, line2)) { // витягується кожен рядок з файлу "Sortednames.txt"
                    string lowercase_line;
                    for (char& c : line2) {
                        lowercase_line += tolower(c); // перетворюємо усі літери на малі
                    }
                    string lowercase_word;
                    for (char& c : search_word2) {
                        lowercase_word += tolower(c); // перетворюємо усі літери на малі
                    }
                    size_t pos = 0;
                    while ((pos = lowercase_line.find(lowercase_word, pos)) != string::npos) { //Пошук слова у рядку
                        line2.replace(pos, search_word2.length(), "\033[33m" + line2.substr(pos, search_word2.length()) + "\033[0m");
                        pos += 13; // додаємо 13, щоб не повторювати підстрічку
                    }
                    if (lowercase_line.find(lowercase_word) != string::npos) {
                        cout << "Знайдено    " << line2 << " в рядку --->  " << line_num2 << ": " << endl;
                        found2 = true;
                    }
                    line_num2++;//Збільшується лічильник номеру рядка.
                }
                if (!found2) {
                    cout << "* Слово не знайдено *" << endl;
                }
                file.close();
            }
        }

        return 0;
    }
}

