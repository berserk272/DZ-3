#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>
using namespace std;
//1
double M(double s, double p, double n) {
    if (p == 0.0) {
        return s / (12.0 * n);
    }
    double r = p / 100.0;
    double chislitel = s * r * pow(1.0 + r, n);
    double znamenatel = 12.0 * (pow(1.0 + r, n) - 1.0);
    return chislitel / znamenatel;
}
double P(double s, double m, double n) {
    double p = 0.0;
    double left = -100.0, right = 100.0;
    double error = 0.0001;
    while (left <= right) {
        double mid = (left + right) / 2.0;
        double monthlyPayment = M(s, mid, n);
        if (abs(monthlyPayment - m) <= error) {
            p = mid;
            break;
        }
        else if (monthlyPayment < m) {
            left = mid + error;
        }
        else {
            right = mid - error;
        }
    }
    return p;
}
void Zaem() {
    cout << "ДЗ 3. Задание 1 Заём." << "\n";
    double s, p, n;
    cout << "Введите значение для переменной S (сумма займа): ";
    cin >> s;
    cout << "Введите значение для переменной p (процент): ";
    cin >> p;
    cout << "Введите значение для переменной n (количество лет): ";
    cin >> n;
    if (s <= 0) {
        cout << "Некорректное значение для переменной S (сумма займа). Сумма займа должна быть больше нуля." << "\n";
    }
    if (n <= 0) {
        cout << "Некорректное значение для переменной n (количество лет). Количество лет должно быть положительным числом." << "\n";
    }
    double m = M(s, p, n);
    cout << "Ежемесячная плата (m) = " << m << endl;
}
//2
void Ssuda() {
    double s, m, n;
    cout << "\n" << "ДЗ 3. Задание 2 Ссуда." << "\n";
    cout << "Введите значение для переменной S (сумма займа): ";
    cin >> s;
    cout << "Введите значение для переменной m (месячная плата): ";
    cin >> m;
    cout << "Введите значение для переменной n (количество лет): ";
    cin >> n;

    if (s <= 0) {
        cout << "Некорректное значение для переменной S (сумма займа). Сумма займа должна быть больше нуля." << endl;
    }
    if (m <= 0) {
        cout << "Некорректное значение для переменной m (месячная плата). Месячная плата должна быть больше нуля." << endl;
    }
    if (n <= 0) {
        cout << "Некорректное значение для переменной n (количество лет). Количество лет должно быть положительным числом." << endl;
    }
    double p = P(s, m, n);   
    cout << "Процентная ставка (p) = " << p << "%" << endl;
}
//3
void writeFile() {
    ofstream file("Text.txt");
    if (!file) {
        cout << "Не получилось открыть файл при записи." << endl;
    }
    string text;
    cout << "Введите текст для файла: ";
    getline(cin, text);
    file << text;
    file.close();
}
void readFile() {
    ifstream file("Text.txt");
    if (!file) {
        cout << "Не получилось открыть файл при чтении." << endl;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void Fail() {
    cout << "ДЗ 3. Задание 3 Файл." << "\n";
    writeFile();
    readFile();
    remove("Text.txt");
}
//4
void filterNumbers() {
    ifstream file("data.txt");
    if (!file) {
        cout << "Ошибка при открытии файла." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        string numbers = "";
        for (char c : line) {
            if (isdigit(c)) {
                numbers += c;
            }
            if (isalpha(c)) {
                numbers += ' ';
            }
        }
        cout << "Числа из файла: " << numbers << endl;
    }
    file.close();
}
void Filter() {
    cout << "\n" << "ДЗ 3. Задание 4 Фильтр. " << "\n";
    ofstream file("data.txt");
    if (!file) {
        cout << "Ошибка при создании файла." << endl;
    }
    string userInput;
    cout << "Введите текст: ";
    getline(cin, userInput);
    file << userInput;
    file.close();
    filterNumbers();
    remove("data.txt");
}
//5
bool prov(char c) {
    return isalpha(static_cast<unsigned char>(c));
}
void Sortirovka() {
    cout << "\nДЗ 3 Задание 5 Сортировка\n";
    string text;
    cout << "Введите строку, которую мы отсортируем: ";
    getline(cin, text);
    string norm;
    norm.reserve(text.size());
    copy_if(text.begin(), text.end(), back_inserter(norm), prov);

    if (norm.empty()) {
        cout << "В введенной строке не было найдено ни одной буквы." << endl;
    }
    else {
        cout << "Изначальная строка: " << norm << endl;

        transform(norm.begin(), norm.end(), norm.begin(), [](char c) {
            return tolower(static_cast<unsigned char>(c));
            });
        sort(norm.begin(), norm.end());
        cout << "Отсортированная строка: " << norm << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    //Zaem();
    //Ssuda();
    //Fail();
    //Filter();
    Sortirovka();
    return 0;
}