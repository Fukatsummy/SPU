#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	cout << "Hello Files";
	std::ofstream fout;     // Создаем поток
	fout.open("File.txt", std::ios_base::app);  //Открываем поток
	fout << "Hello Files" << endl;  //Используем поток
	fout.close();           //После использования потока, его обязвтельно нужно закрыть

	system("notepad File.txt"); //открыает блокнот вместе с консолью

#endif // WRITE_TO_FILE
	
	char sz_filename[FILENAME_MAX] = {};
	cout << "Введите имя файла: "; cin.getline(sz_filename, FILENAME_MAX);

	if (strstr(sz_filename, ".txt") == NULL)
	{
		strcat(sz_filename, ".txt");
	}

	ifstream fin(sz_filename);
	if (fin.is_open())
	{
		const int SIZE = USHRT_MAX;
		char buffer[SIZE] = {}; // Буфер чтения
		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);//  вывод в консоль с пробелами
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	char  sz_command[FILENAME_MAX] = "start notepad ";
	strcat(sz_command, sz_filename);
	system(sz_command);
}