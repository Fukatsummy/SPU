#include"stdafx.h"
#define delimiter "\n-----------------------------------------------------------\n"
#include"FillRand.h"
#include"Print.h"
#include"Sort.h"
#include"Statistic.h"


void main()
{
	setlocale(LC_ALL, "");

	const int n = 5;
	int arr[n];
	//int minRand, maxRand;
	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее арифметическое: " << Avg(arr, n) << endl;
	cout << "Минимальное значение: " << minValueIn(arr, n) << endl;
	cout << "Максимальное значение: " << maxValueIn(arr, n) << endl;

	cout << delimiter << endl;

	const int m = 8;
	double brr[m];
	//int minRand, maxRand;
	FillRand(brr, m);
	Print(brr, m);
	Sort(brr, m);
	Print(brr, m);
	cout << "Сумма элементов массива: " << Sum(brr, m) << endl;
	cout << "Среднее арифметическое: " << Avg(brr, m) << endl;
	cout << "Минимальное значение: " << minValueIn(brr, m) << endl;
	cout << "Максимальное значение: " << maxValueIn(brr, m) << endl;
}
