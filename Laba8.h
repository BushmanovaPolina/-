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
			cout << "Ошибка" << endl;
		}
	}
};

template<typename T>
class Node
{
public:
	Node<T>* pNext;
	T data;
	Node(T data = T(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class Iterator : public Node<T>
{
	Node<T>* pointer;
	friend class automobile;
public:
	Iterator()
	{
		this->pointer = nullptr;
	}
	Iterator(Node<T>* element)
	{
		this->pointer = element;
	}
	~Iterator()
	{
		this->pointer = nullptr;
	}
	Iterator operator+(int n)
	{
		return (pointer + n);
	}
	Iterator operator++(int n)
	{
		pointer = pointer->pNext;
		return pointer;
	}
	T &operator*()
	{
		return pointer->data;
	}
	bool operator!= (const Iterator& it)
	{
		return pointer != it.pointer;
	}
	T get_data() {
		return pointer->data;
	}
};


template<typename T>
class Stack :public Node<T>
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
	T& operator[](const int index);
	void push(T data);
	friend class File;
	Iterator<T> begin()
	{
		return head;
	}
	Iterator<T> end()
	{
		Node<T>* current = this->head;
		for (int i = 0; i < Size - 1; i++)
		{
			current = current->pNext;
		}
		return current;
	}
	void output(Iterator<T> begin, Iterator<T> end) {
		Iterator<T> it = begin;
		for (it; it != end; it++) {
			cout << *it << endl;
		}
		cout << *end << endl;
	}
private:
	int Size;
	Node<T>* head;
	friend ostream& operator<<(ostream& out, const Node<T>& node);
};

class ATS
{
private:
	int day;
	int month;
	int year;
	string kod;
	string country;
	int time;
	string tariff;
	long int number_c;
	long long int number_a;
public:
	ATS(int _day,int _month,int _year,string _country, string _kod, string _tariff, int _time, long int _number_c, long long int _number_a)
	{
		day = _day;
		month = _month;
		year = _year;
		country = _country;
		kod = _kod;
		tariff = _tariff;
		number_c = _number_c;
		number_a = _number_a;
		time = _time;
	}
	ATS() {
		day = 0;
		month = 0;
		year = 0;
		country = " ";
		kod = " ";
		tariff = " ";
		number_c = 0;
		number_a = 0;
		time = 0;
	}
	~ATS() {};
	friend void output(ATS& ats);
	friend class File;
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
	void Sort_time(int n, Stack<ATS>& st);
	void Sort_day(int n, Stack<ATS>& st);
	void ReadTextBin();
	int Del(int index, int n, Stack<ATS>& st);
};

