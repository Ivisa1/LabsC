#include <iostream>

using namespace std;

int main(){
    /* Задание 1 - кол-во байтов в памяти у разных типо данных */
    cout << sizeof(int) << " " << sizeof(short int) << " " << sizeof(long int) << " "
    << sizeof(float) << " " << sizeof(double) << " " << sizeof(long double) << " "
    << sizeof(char) << " " << sizeof(bool) << endl; // вывод размеров типов данных в байтах

    /* Задание 2 - двоичное представление в памяти целого числа */
    int numberInt;
    cout << "Введите число типа int: ";
    cin >> numberInt; // ввод целого числа
    unsigned int order = 32; // количество разрядов
    unsigned int mask = 1 << order - 1; // маска побитового сравнения (смещаем влево на 31 бит)
    cout << "Ваше число типа int в двоичном виде: ";
    for (int i = 1; i <= order; i++)
	{
		putchar(numberInt & mask ? '1' : '0'); 
		numberInt <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0) // Разделение на байты (8 битов)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0) // отделение знакового бита
		{
			putchar(' ');
		}
	}

    /* Задание 3 - двоичное предсптавление в памяти float */

    /* Задание 4 - двоичное представление в памяти double */
	return 0;
}