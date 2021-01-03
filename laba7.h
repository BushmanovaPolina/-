#pragma once
#include <iostream>
#include <string>
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
		if (this->error == 1)
		{
			cout << "Ошибка ввода! Введено не число типа int!" << endl;
		}
		if (this->error == 2)
		{
			cout << "Ошибка ввода! Введено не число типа double!" << endl;
		}if (this->error == 4)
		{
			cout << "Ошибка! Стэк пуст! " << endl;
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
	T get_data() {
		return data;
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
		return *(pointer + n);
	}
	Node operator++(int n)
	{
		return *pointer++;
	}
	Iterator operator*()
	{
		return *pointer;
	}
	bool operator!= (const Iterator& it)
	{
		return pointer != it.pointer;
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
	Iterator<T> begin()
	{
		return (this->head);
	}
	Iterator<T> end()
	{
		Node<T>* current = this->head;
		for (int i = 0; i < Size; i++)
		{
			current = current->pNext;
		}
		return current;
	}
private:
	int Size;
	Node<T>* head;
	friend ostream& operator<<(ostream& out, const Node<T>& node);
};
class automobile {
private:
	int id;
	string name;
public:
	automobile() {
		this->id = 0;
		this->name = ' ';
	}
	automobile(int ID, string fio) {
		this->id = ID;
		this->name = fio;
	}
	~automobile() {};
    void print(){
			cout << "Уникальный номер автомобиля - " << this->id << endl;
			cout << "ФИО владельца автомобиля - " << this->name << endl;
		}
	friend class Stack<automobile>;
	friend void input_id(automobile &avt);
	friend void set_id(int ID, string fio, automobile &avto) {
		avto.id = ID;
		avto.name = fio;
	};
};
void input_id(automobile &avto) {
	int ID;
	string fio;
	bool a = true;
	do
	{
		cout << "Введите id: ";
		cin >> ID;
		if (cin.fail())
			cout << "Повторите попытку" << endl;
		else
			a = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (a);
	cout << "Введите ФИО владельца автомобиля - ";
	cin >> fio;
	set_id(ID, fio, avto);
};
