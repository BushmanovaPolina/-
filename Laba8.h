#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h> 

using namespace std;

class Exception
{
protected:
	int error;
public:
	Exception()
	{
		error = 0;
	}
	Exception(int _error)
	{
		error = _error;
	}
	~Exception()
	{

	};
	void Print()
	{
		if (this->error == 0)
		{
			cout << "Ошибка ввода! Введён не int!" << endl;
		}
		if (this->error == 1)
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		if (this->error == 2)
		{
			cout << "Ошибка формата Даты" << endl;
		}
	}
};

class ATS
{
	string date;
	string kod;
	int time;
	string tariff;
	long int number_c;
	long int number_a;
public:
	ATS(string _date = string(), string _kod = string(), string _tariff = string(), int _time = int(), long int _number_c=long int(), long int _number_a=long int(),ATS* pNext = nullptr)
	{
		date = _date;
		kod = _kod;
		tariff = _tariff;
		number_c = _number_c;
		number_a = _number_a;
		time = _time;
		this->pNext = pNext;
	}
	friend ostream& operator<<(ostream& out, const ATS& ats);
	friend class File;
	ATS* pNext;
};

class Stack :public ATS
{
public:
	Stack();
	~Stack();
	void pop();
	void clear();
	int GetSize()
	{
		return Size;
	}
	ATS& operator[](const int index);
	void push(string date, string kod, string tariff, int time, long int number_c, long int number_a);
private:
	int Size;
	ATS* head;
	friend ostream& operator<<(ostream& out, const ATS& ats);
};

class File
{
	string path;
public:
	File()
	{
		this->path = " ";
	}
	File(string _path)
	{
		this->path = _path;
	}
	void ReadText();
	void ReadBin(int n);
	void WriteText();
	void WriteBin(ATS ats);
	void Search();
	void Sort(int n, Stack& st);
	void ReadTextBin();
	int Del(int index, int n, Stack& st);
};

