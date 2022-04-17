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
		cout << "Введите минимальное случайное число:  "; cin >> minRand;
		cout << "Введите максимальное случайное число: "; cin >> maxRand;
		if (minRand >= maxRand)cout << "Error:Будте внимательны при вводе!" << endl;
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
	//Сортировка массива
	for (int i = 0; i < SIZE; i++)//выбирает элемент
	{
		for (int j=i+1; j < SIZE; j++)//перебирает элемент
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	//Вывод отсортированного массива на экран
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

}