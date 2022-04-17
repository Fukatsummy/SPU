#include<iostream>
using  namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE=5;
	int arr[SIZE];
	int minRand, maxRand;
	do
	{
		cout << "������� ����������� ��������� �����:  "; cin >> minRand;
		cout << "������� ������������ ��������� �����: "; cin >> maxRand;
		if (minRand >= maxRand)cout << "Error:����� ����������� ��� �����!" << endl;
	} while (minRand >= maxRand);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	//���������� �������
	for (int i = 0; i < SIZE; i++)//�������� �������
	{
		for (int j=i+1; j < SIZE; j++)//���������� �������
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	//����� ���������������� ������� �� �����
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

}