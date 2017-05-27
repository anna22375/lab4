#include <iostream>
#include <stdlib.h>
#include <locale> //���������
#include <fstream>// ������ � �������
#include <vector>// �������
#include <iterator>// ������ � ���������
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
	srand(time(nullptr)); // ��� ������������
	int item, check; // ������� ������� � ��� ��������
	do
	{

		ifstream fin("input.txt"); // ��������� ���� �����
		vector<int> arr; // ������ �����
		cout << "�������:\n���� ������������������ ����� ������������� ����� a1, a2, ..., an. \n�� ���� �������� ����������� ������� ����� (����� �������) �����. \n���������  �������� ����� ������������ ����� ����� �� ����� �������� �����. \n��������� ������� ��� �����, ����� �������, ���, ����� ��������� ��������� ���� �����������. \n����������� n<=100, ai<=100. \n1 - ������ ������ ������.\n2 - ������ ������ �� �����.\n3 - ������ ������ ��������� �����." << endl;
		switch (_getch())
		{
		case '1':		//���� ������
			do
			{
				system("cls");				// ������ �����
				cout << "������� ������: "; // ����������
				copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " ")); // ������� ������ �� ����� �� ������ ����
				cout << "\n������� ���-�� ��-��� (max=100): " << arr.size() << "\n������� �����: ";
				cin >> item; // ���� ����� �������������
				if (!cin)	// ���� �� �����
					error(1);
				while (item > 100)	// ���� ������� �������
				{
					cout << "������� ������� �����!\n ������� ����� �� ������ 100:";
					cin >> item;
					if (!cin)
						error(1);
				}
				arr.insert(arr.end(), item); // ������� ����� � ����� �������
				cout << "������� Enter, ����� ������ ��� ���� �����.\n������� Space, ����� ���������� ���������� ���������";
				check = _getch() - 32;
			} while (check);
			break;
		case '2':	//�� �����
			system("cls");
			while (!fin.eof())
			{
				fin >> item;			// ���� ����� �� �����
				if (!fin || item > 100 || arr.size() > 100)	// � ����� �� �� �����
					error(1);								// ���� ������� ������� ������
				arr.insert(arr.end(), item);		// ������� ����� � ����� �������
			}
			break;
		case '3': //��������
			system("cls");
			cout << "����� ������  ������ �� ������? (max = 100)\n������� �����: ";
			cin >> item; // ���������� �������� ��������� ������������
			if (item > 100)
				error(1);
			for (int i = 0; i < item; i++) // ������� ��������� �������� � ����� �������
				arr.insert(arr.end(), rand() % 99 + 1);
			break;
		default:
			error(1);
		}
		int** M = new int *[arr.size()];	//������ ��������� ������
		for (size_t i = 0; i < arr.size(); i++)
			M[i] = new int[arr.size()];
		system("cls");
		cout << "�������� ������: ";
		copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " ")); // ����� ������� �� �����
		cout << "\n��������...";
		cout << endl;
		time_t start_time = clock();	//�������� ����
		int** solution = Solution(arr, arr.size(), M); // �������
		time_t end_time = clock();		//�������� �����
		time_t total_time = end_time - start_time; //�������
		cout << endl;
		fout << endl;
		for (int c = 0; c < (arr.size() - 1) * 8; c++)
		{
			cout << "-";
			fout << "-";
		}
		cout << endl;
		fout << endl;
		for (size_t i = 0; i < arr.size(); i++)		//����� ������� �� �����
		{
			cout << "| ";								//����� ������� � ����
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
		cout << endl << "������������� �������: " << M[0][arr.size() - 1] << endl << "�����: " << total_time << "��" << endl;
		fout << endl << "������������� �������: " << M[0][arr.size() - 1] << endl << "�����: " << total_time << "��" << endl;
		fin.close();	// ��������� ���� �����
		fout.close();	// ��������� ���� ������
		arr.clear();	// ������� �������
		cout << "\n1 - ������ ���������� �������\n0 - �������� ���������� ���������";
		check = _getch() - 48;
		system("cls");
	} while (check);
	return 0;
}

