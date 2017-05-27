#ifndef _head_
#define _head_

#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

//---------------------------------------------------------------
const int max_amount = 100; // ������������ ���������� ���������
const int max_value = 100; // ������������ �������� ��������
ofstream fout("output.txt");// ��������� ���� ������

//---------------------------------------------------------------
int Solution(vector<int>, int); // ������� ���������� �������
void MinSolution(vector<int>, int, int, int&); // ����������� ������� ���������� ������������ �������
void error(int a); // ��� �������� ��������� �� �������

//---------------------------------------------------------------
// ������� ���������� �������
int** Solution(vector<int> arr, int amount_arr, int** M)
{
	// �������� ��������� ������
	if (!(amount_arr > 1 && amount_arr <= max_amount))
		error(1);
	for (size_t i = 0; i < arr.size(); i++)
	if (arr[i] > max_value)
		error(1);
	fout << "�������� ������: ";
	copy(arr.begin(), arr.end(), ostream_iterator<int>(fout, " "));
	fout << endl;
	for (int i = 0; i < amount_arr; i++)	//������ ����� �� ������� ���������
		M[i][i + 1] = 0;
	for (int l = 3; l < amount_arr + 1; l++) // �� �������
	{
		for (int i = 0; i < amount_arr - l + 1; i++) // �� ������
		{
			int min = numeric_limits<int>::max();
			fout << endl << "������� ������: (" << i << "," << i + l - 1 << ")" << endl;
			cout << endl << "������� ������: (" << i << "," << i + l - 1 << ")" << endl;
			for (int k = i + 1; k < i + l - 1; k++)
			{
				fout << "M[" << i << "][" << i + l - 1 << "] = " << "M[" << i << "][" << k << "] + M[" << k << "][" << i + l - 1 << "] + a[" << k << "]*(a[" << i << "] + a[" << i + l - 1 << "]) = " << setw(3) << M[i][k] << " + " << setw(3) << M[k][i + l - 1] << " + " << arr[k] << "*(" << arr[i] << "+" << arr[i + l - 1] << ") = " << M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]) << endl;
				cout << "M[" << i << "][" << i + l - 1 << "] = " << "M[" << i << "][" << k << "] + M[" << k << "][" << i + l - 1 << "] + a[" << k << "]*(a[" << i << "] + a[" << i + l - 1 << "]) = " << setw(3) << M[i][k] << " + " << setw(3) << M[k][i + l - 1] << " + " << arr[k] << "*(" << arr[i] << "+" << arr[i + l - 1] << ") = " << M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]) << endl;
				if (min > M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]))	// �������� �����������
					min = M[i][k] + M[k][i + l - 1] + arr[k] * (arr[i] + arr[i + l - 1]);
			}
			fout << "�����������: " << min << endl;
			cout << "�����������: " << min << endl;
			M[i][i + l - 1] = min; // ���������� ������� � �����
		}
	}
	return M; //����������
}

//---------------------------------------------------------------
// ��� �������� ��������� �� �������
void error(int a)
{
	system("cls");
	cout << "������!  ";
	switch (a)
	{
	case 1: cout << "������������ ����!" << endl;
		break;
	case 2: cout << "������� ������� �����!" << endl;
	}
	system("pause");
	exit(1);
}

#endif

