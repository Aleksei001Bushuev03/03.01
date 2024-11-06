#include <iostream>
#include <Windows.h>

class Calculator {
private:
    double num1;
    double num2;

public:
    Calculator() : num1(0), num2(0) {}

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            std::cout << "Неверный ввод для num1! Попробуйте еще раз.\n";
            return false;
        }
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            std::cout << "Неверный ввод для num2! Попробуйте еще раз.\n";
            return false;
        }
    }

    double add() const {
        return num1 + num2;
    }

    double multiply() const {
        return num1 * num2;
    }

    double subtract_1_2() const {
        return num1 - num2;
    }

    double subtract_2_1() const {
        return num2 - num1;
    }

    double divide_1_2() const {
        if (num2 != 0) {
            return num1 / num2;
        }
        else {
            std::cout << "Деление на ноль невозможно!\n";
            return 0;
        }
    }

    double divide_2_1() const {
        if (num1 != 0) {
            return num2 / num1;
        }
        else {
            std::cout << "Деление на ноль невозможно!\n";
            return 0;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Calculator calc;
    double input1, input2;

    while (true) {
        std::cout << "Введите num1: ";
        std::cin >> input1;
        if (!calc.set_num1(input1)) {
            std::cin.clear();            
            std::cin.ignore(10000, '\n'); 
            continue; 
        }

        std::cout << "Введите num2: ";
        std::cin >> input2;
        if (!calc.set_num2(input2)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue; 
        }

        std::cout << "num1 + num2 = " << calc.add() << "\n";
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << calc.multiply() << "\n";

        if (input2 != 0) {
            std::cout << "num1 / num2 = " << calc.divide_1_2() << "\n";
        }
        else {
            std::cout << "num1 / num2: Деление на ноль невозможно.\n";
        }

        if (input1 != 0) {
            std::cout << "num2 / num1 = " << calc.divide_2_1() << "\n";
        }
        else {
            std::cout << "num2 / num1: Деление на ноль невозможно.\n";
        }
    }


    return 0;
}
