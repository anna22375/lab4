#ifndef _head_
#define _head_

#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

//---------------------------------------------------------------
const int max_amount = 100; // Максимальное количество элементов
const int max_value = 100; // Максимальное значение элемента
ofstream fout("output.txt");// Открываем файл вывода

//---------------------------------------------------------------
int Solution(vector<int>, int); // Функция нахождения решения
void MinSolution(vector<int>, int, int, int&); // Рекурсивная Функция нахождения минимального решения
void error(int a); // Для создания сообщений об ошибках

//---------------------------------------------------------------
// Функция нахождения решения
int** Solution(vector<int> arr, int amount_arr, int** M)
{
	// Проверка введенных данных
	if (!(amount_arr > 1 && amount_arr <= max_amount))
		error(1);
	for (size_t i = 0; i < arr.size(); i++)
	if (arr[i] > max_value)
		error(1);
	fout << "Введённый массив: ";
	copy(arr.begin(), arr.end(), ostream_iterator<int>(fout, " "));
	fout << endl;
	for (int i = 0; i < amount_arr; i++)	//делаем нуоли на главной диагонали
		M[i][i + 1] = 0;
	for (int l = 3; l < amount_arr + 1; l++) // по столбцу
	{
		for (int i = 0; i < amount_arr - l + 1; i++) // по строке
		{
			int min = numeric_limits<int>::max();
			fout << endl << "Считаем ячейку: (" << i << "," << i + l - 1 << ")" << endl;
			cout << endl << "Считаем ячейку: (" << i << "," << i + l - 1 << ")" << endl;
			for (int k = i + 1; k < i + l - 1; k++)
			{
				fout << "M[" << i << "][" << i + l - 1 << "] = " << "M[" << i << "][" << k << "] + M[" << k << "][" << i + l - 1 << "] + a[" << k << "]*(a[" << i << "] + a[" << i + l - 1 << "]) = " << setw(3) << M[i][k] << " + " << setw(3) << M[k][i + l - 1] << " + " << arr[k] << "*(" << arr[i] << "+" << arr[i + l - 1] << ") = " << M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]) << endl;
				cout << "M[" << i << "][" << i + l - 1 << "] = " << "M[" << i << "][" << k << "] + M[" << k << "][" << i + l - 1 << "] + a[" << k << "]*(a[" << i << "] + a[" << i + l - 1 << "]) = " << setw(3) << M[i][k] << " + " << setw(3) << M[k][i + l - 1] << " + " << arr[k] << "*(" << arr[i] << "+" << arr[i + l - 1] << ") = " << M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]) << endl;
				if (min > M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]))	// выбираем минимальное
					min = M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]);
			}
			fout << "Минимальное: " << min << endl;
			cout << "Минимальное: " << min << endl;
			M[i][i + l - 1] = min; // записываем минимум в ячйку
		}
	}
	return M; //возвращаем
}

//---------------------------------------------------------------
// Для создания сообщений об ошибках
void error(int a)
{
	system("cls");
	cout << "Ошибка!  ";
	switch (a)
	{
	case 1: cout << "Некорректный ввод!" << endl;
		break;
	case 2: cout << "Слишком большое число!" << endl;
	}
	system("pause");
	exit(1);
}

#endif

