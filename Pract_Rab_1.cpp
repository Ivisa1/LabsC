#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    /* Задание 1 - кол-во байтов в памяти у разных типо данных */

    // вывод размеров типов данных в байтах
    cout << "Размер типа int: " << sizeof(int) << "\n" 
    << "Размер типа short int: " << sizeof(short int) << "\n"
    << "Размер типа long int: " <<  sizeof(long int) << "\n"
    << "Размер типа float: " << sizeof(float) << "\n"
    << "Размер типа double: " << sizeof(double) << "\n"
    << "Размер типа long double: " << sizeof(long double) << "\n"
    << "Размер типа char: " << sizeof(char) << "\n"
    << "Размер типа bool: " << sizeof(bool) << endl; 

    /* Задание 2 - двоичное представление в памяти int */

    int numberInt;
    cout << "Введите число типа int: ";
    cin >> numberInt; // ввод целого числа
    int order = 32; // количество разрядов
    int mask = 1 << order - 1; // маска побитового сравнения (смещаем влево на 31 бит)
    cout << "Ваше число типа int в двоичном виде: ";

    for (int i = 1; i <= order; i++){ // вывод двоичного представления
		putchar(numberInt & mask ? '1' : '0'); 
		numberInt <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0 || i == 1) // Разделение на байты (8 битов) или отделение знакового бита
		{
			putchar(' ');
		}
	}
    cout << '\n'; // переход на новую строку

    /* Задание 3 - двоичное представление в памяти float */

    union{ // объединение переменных
        float numberFloat; // значение для представления
        int numberIntForFloat; // переменная int, находящаяся в объединении с числом float
    };

    cout << "Введите число типа float: ";
    cin >> numberFloat; // ввод числа типа float
    cout << "Ваше число типа float в двоичном виде: ";
    // маска для int и float одинаковая

    for (int i = 1; i <= order; i++){ // вывод двоичного представления
		putchar(numberIntForFloat & mask ? '1' : '0'); 
		numberIntForFloat <<= 1; // Побитовый сдвиг числа
		if (i  == 9 || i == 1) // Разделение на байты (8 битов) или отделение знакового бита
		{
			putchar(' ');
		}
	}

    cout << '\n'; // переход на новую строку

    /* Задание 4 - двоичное представление в памяти double */

    union // объединение int и double
    {
        double numberDouble; // число типа double
        int numberIntForDouble[2]; // переменная int, находящаяся в объединении с числом float (2 штуки, т.к. в один инт double не вместить) 
    };

    cout << "Введите число типа double: ";
    cin >> numberDouble;
    cout << "Ваше число типа double в двоичном виде: ";

    for (int j = 1; j >= 0 ; j--){ // определяет, какой int брать
        for (int i = 1; i <= 32; i++){
            mask = 1 << order * 2 - i; // маска для double
            putchar(numberIntForDouble[j] & mask ? '1' : '0');
            if ((i == 1 && j == 1) || (i == 12 && j == 1)){ // Разделение на байты (8 битов) или отделение знакового бита
                putchar(' ');
            }
        }
    }

    cout << '\n'; // переход на новую строку

	return 0;
}