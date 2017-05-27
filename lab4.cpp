#include <iostream>
#include <stdlib.h>
#include <locale> //кириллица
#include <fstream>// работа с файлами
#include <vector>// векторы
#include <iterator>// работа с векторами
#include "head.h"
#include <conio.h>
#pragma warning(disable: 4244)
#pragma warning(disable: 4018)
using namespace std;

//---------------------------------------------------------------
int main()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr)); // для рандомизации
	int item, check; // Элемент массива и для проверки
	do
	{

		ifstream fin("input.txt"); // открываем файл ввода
		vector<int> arr; // Массив чисел
		cout << "Задание:\nДана последовательность целых положительных чисел a1, a2, ..., an. \nЗа одну операцию разрешается удалить любое (кроме крайних) число. \nСтоимость  операции равна произведению этого числа на сумму соседних чисел. \nТребуется удалить все числа, кроме крайних, так, чтобы суммарная стоимость была минимальной. \nОграничения n<=100, ai<=100. \n1 - ввести массив руками.\n2 - ввести массив из файла.\n3 - ввести массив случайных чисел." << endl;
		switch (_getch())
		{
		case '1':		//ввод руками
			do
			{
				system("cls");				// чистим экран
				cout << "Текущий массив: "; // информация
				copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " ")); // выводит массив на экран на каждом шаге
				cout << "\nТекущее кол-во эл-тов (max=100): " << arr.size() << "\nВведите число: ";
				cin >> item; // ввод числа пользователем
				if (!cin)	// если не число
					error(1);
				while (item > 100)	// если слишком большое
				{
					cout << "Слишком большое число!\n Введите число не больше 100:";
					cin >> item;
					if (!cin)
						error(1);
				}
				arr.insert(arr.end(), item); // вставка числа в конец вектора
				cout << "Нажмите Enter, чтобы ввести ещё одно число.\nНажмите Space, чтобы продолжить выполнение программы";
				check = _getch() - 32;
			} while (check);
			break;
		case '2':	//из файла
			system("cls");
			while (!fin.eof())
			{
				fin >> item;			// ввод числа из файла
				if (!fin || item > 100 || arr.size() > 100)	// в файле не те числа
					error(1);								// либо слишком большой массив
				arr.insert(arr.end(), item);		// вставка числа в конец вектора
			}
			break;
		case '3': //случайно
			system("cls");
			cout << "Какой длинны  массив вы хотите? (max = 100)\nВведите число: ";
			cin >> item; // количество символов требуемых ползователем
			if (item > 100)
				error(1);
			for (int i = 0; i < item; i++) // вставка случайных символов в конец вектора
				arr.insert(arr.end(), rand() % 99 + 1);
			break;
		default:
			error(1);
		}
		int** M = new int *[arr.size()];	//создаём двумерный массив
		for (size_t i = 0; i < arr.size(); i++)
			M[i] = new int[arr.size()];
		system("cls");
		cout << "Введённый массив: ";
		copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " ")); // вывод вектора на экран
		cout << "\nВычисляю...";
		cout << endl;
		time_t start_time = clock();	//засекаем врем
		int** solution = Solution(arr, arr.size(), M); // Решение
		time_t end_time = clock();		//отсекаем время
		time_t total_time = end_time - start_time; //считаем
		cout << endl;
		fout << endl;
		for (int c = 0; c < (arr.size() - 1) * 8; c++)
		{
			cout << "-";
			fout << "-";
		}
		cout << endl;
		fout << endl;
		for (size_t i = 0; i < arr.size(); i++)		//вывод таблицы на экран
		{
			cout << "| ";								//вывод таблицы в файл
			for (size_t j = 0; j < arr.size() - 1; j++)
			{
				if (i <= j)
				{
					cout << "----- | ";
					fout << "----- | ";
				}
				else
				{
					cout << setw(5) << M[j][i] << " | ";
					fout << setw(5) << M[j][i] << " | ";
				}
			}
			fout << endl;
			cout << endl;
			for (int c = 0; c < (arr.size() - 1) * 8; c++)
			{
				cout << "-";
				fout << "-";
			}
			cout << endl;
			fout << endl;
		}
		cout << endl << "Окончательное решение: " << M[0][arr.size() - 1] << endl << "Время: " << total_time << "мс" << endl;
		fout << endl << "Окончательное решение: " << M[0][arr.size() - 1] << endl << "Время: " << total_time << "мс" << endl;
		fin.close();	// закрываем файл ввода
		fout.close();	// закрываем файл вывода
		arr.clear();	// очистка вектора
		cout << "\n1 - начать выполнение сначала\n0 - окончить выполнение программы";
		check = _getch() - 48;
		system("cls");
	} while (check);
	return 0;
}

