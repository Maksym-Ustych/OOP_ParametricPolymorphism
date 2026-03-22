#include <iostream>
#include <locale>
using namespace std;

class Chislo {
private:
    long n; // розмірність масиву

public:
    // Конструктор
    Chislo(long value = 0) {
        n = value;
        cout << "Конструктор класу Chislo" << endl;
    }

    // Деструктор
    virtual ~Chislo() {
        cout << "Деструктор класу Chislo" << endl;
    }

    // Встановлення значення
    void setN(long value) {
        n = value;
    }

    // Отримання значення
    long getN() const {
        return n;
    }

    // Віртуальна функція обчислення факторіала
    virtual long long factorial(long x) {
        long long f = 1;
        for (long i = 1; i <= x; i++) {
            f *= i;
        }
        return f;
    }
};

class Matrix : public Chislo {
public:
    long arr[100];

    // Конструктор
    Matrix(long size = 0) : Chislo(size) {
        cout << "Конструктор класу Matrix" << endl;
    }

    // Деструктор
    ~Matrix() {
        cout << "Деструктор класу Matrix" << endl;
    }

    // Введення елементів масиву
    void input() {
        for (long i = 0; i < getN(); i++) {
            cout << "Введіть елемент [" << i << "]: ";
            cin >> arr[i];
        }
    }

    // Виведення факторіалів елементів масиву
    void showFactorials(Chislo* p) {
        cout << endl;
        cout << "Факторіали елементів масиву:" << endl;
        for (long i = 0; i < getN(); i++) {
            cout << arr[i] << "! = " << p->factorial(arr[i]) << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "");
    system("chcp 65001 > nul");

    long size;
    cout << "Введіть розмірність масиву (не більше 100): ";
    cin >> size;

    if (size <= 0 || size > 100) {
        cout << "Помилка: некоректна розмірність масиву." << endl;
        return 1;
    }

    Matrix m(size);

    cout << endl;
    cout << "Введення елементів масиву:" << endl;
    m.input();

    Chislo* p;
    p = &m;

    m.showFactorials(p);

    return 0;
}