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
	bool operator== (const Iterator& it)
	{
		return pointer == it.pointer;
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
	Iterator<T> begin()
	{
		return head;
	}
	Iterator<T> end()
	{
		Node<T>* current = this->head;
		for (int i = 0; i < Size-1; i++)
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

class automobile {
private:
	int id;
	string name;
	int mileage;
public:
	automobile() {
		this->id = 0;
		this->name = ' ';
			this->mileage=0;
	}
	automobile(int ID, string fio,int mil) {
		this->id = ID;
		this->name = fio;
		this->mileage = mil;
	}
	~automobile() {};
    void print(){
			cout << "Уникальный номер автомобиля - " << this->id << endl;
			cout << "ФИО владельца автомобиля - " << this->name << endl;
			cout<<"Пробег автомобиля - "<<this->mileage<<endl;
		}
	friend class Stack<automobile>;
	friend void input_id(automobile &avt);
	friend void set_id(int ID, string fio,int mil, automobile &avto) {
		avto.id = ID;
		avto.name = fio;
		avto.mileage = mil;
	};
};
void input_id(automobile &avto) {
	int ID,mil;
	string fio;
		cout << "Введите id: ";
		try {
			cin >> ID;
			if (cin.fail())
				throw 1;
		}
		catch (int i) {
			Exception ex(i);
			ex.Print();
			return;
		}
	cout << "Введите ФИО владельца автомобиля - ";
	cin >> fio;
		cout << "Введите пробег: ";
		try {
			cin >> mil;
			if (cin.fail()) throw 1;
		}
		catch (int i) {
			Exception ex(i);
			ex.Print();
			return;
		}
	set_id(ID, fio,mil, avto);

};
