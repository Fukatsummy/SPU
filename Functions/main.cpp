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
	cout << "����� ��������� �������: " << Sum(arr, n) << endl;
	cout << "������� ��������������: " << Avg(arr, n) << endl;
	cout << "����������� ��������: " << minValueIn(arr, n) << endl;
	cout << "������������ ��������: " << maxValueIn(arr, n) << endl;

	cout << delimiter << endl;

	const int m = 8;
	double brr[m];
	//int minRand, maxRand;
	FillRand(brr, m);
	Print(brr, m);
	Sort(brr, m);
	Print(brr, m);
	cout << "����� ��������� �������: " << Sum(brr, m) << endl;
	cout << "������� ��������������: " << Avg(brr, m) << endl;
	cout << "����������� ��������: " << minValueIn(brr, m) << endl;
	cout << "������������ ��������: " << maxValueIn(brr, m) << endl;
}
