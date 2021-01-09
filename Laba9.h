#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <Windows.h>
#include <fstream>
namespace MySpace {
	class automobile;
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
				std::cout << "Ошибка ввода! Введено не число типа int!" << std::endl;
			}
			if (this->error == 2)
			{
				std::cout << "Ошибка ввода! В ФИО не может быть цифр!" << std::endl;
			}
			if (this->error == 3)
			{
				std::cout << "Ошибка! Файл не открылся или его не существует! " << std::endl;
			}
			if (this->error == 4)
			{
				std::cout << "Ошибка! Стэк пуст! " << std::endl;
			}
		}
	};
	class Algorithm {
	public:
		void first();
		void second(std::vector<automobile>::iterator begin, std::vector<automobile>::iterator end);
		std::vector<automobile>::iterator third(std::vector<automobile>::iterator begin, std::vector<automobile>::iterator end);
	};
	class automobile {
	private:
		int id;
		std::string name;
		int meliage;

	public:
		automobile() {
			this->id = 0;
			this->name = ' ';
			this->meliage = 0;
		}
		automobile(int ID, std::string fio,int mel) {
			this->id = ID;
			this->name = fio;
			this->meliage = mel;
		}
		~automobile() {};
		void print() {
			std::cout << "Уникальный номер автомобиля - " << this->id << std::endl;
			std::cout << "ФИО владельца автомобиля - "<< this->name << std::endl;
			std::cout << "Пробег автомобиля - " << this->meliage << std::endl;
		}
		friend void Algorithm::second(std::vector<automobile>::iterator begin, std::vector<automobile>::iterator end);
		friend std::vector<automobile>::iterator Algorithm::third(std::vector<automobile>::iterator begin, std::vector<automobile>::iterator end);
		friend void input_id(automobile &avt);
	 void set_id(int ID, std::string fio,int mel) {
			id = ID;
		    name = fio;
			meliage = mel;
		};
	};
	void input_id(automobile &avto) {
		int ID;
		std::string fio;
		bool a = true;
		do
		{
			std::cout << "Введите id: ";
			std::cin >> ID;
			if (std::cin.fail())
				std::cout << "Повторите попытку" << std::endl;
			else
				a = false;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		} while (a);
		std::cout << "Введите ФИО владельца автомобиля - ";
		std::cin >> fio;
		int j = 0;
		while (fio[j]) {
			try {
				if (fio[j] > '0' || fio[j] < '9')
					throw 2;
			}
			catch (int i) {
				Exception ex(i);
				ex.Print();
				exit(0);
			}
		}
		int meliage;
		std::cout << "Введите пробег - ";
		try {
			std::cin >> meliage;
			if (std::cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			exit(0);
		}
		avto.set_id(ID, fio,meliage);
	};

}
void MySpace::Algorithm::second(std::vector<automobile>::iterator begin, std::vector<automobile>::iterator end) {
	std::vector<automobile>::iterator it;
	std::cout << "Введите id автомобиля, который хотите найти" << std::endl;
	int id;
	std::cin >> id;
	it = begin;
	int flg = 0;
	while (it != end) {
		automobile avto;
		avto = *it;
		if (avto.id == id) {
			std::cout << "===================================================" << std::endl;
			std::cout << "Искомый автомобиль : \n";
			avto.print();
			std::cout << "===================================================" << std::endl;
			std::cout << std::endl;
			flg++;
			break;
		}
		else it++;
	}
		if (flg != 1) { std::cout << "Нет такого автомобиля\n";}
	
}

std::vector<MySpace::automobile>::iterator MySpace::Algorithm::third(std::vector<automobile>::iterator begin, std::vector<automobile>::iterator end) {
	std::vector<automobile>::iterator it;
	std::cout << "Введите id автомобиля, который хотите удалить" << std::endl;
	int id;
	std::cin >> id;
	std::cout << "===================================================" << std::endl;
	it = begin;
	int flg = 0;
	while (it != end) {
		automobile avto;
		avto = *it;
		if (avto.id == id) {
			std::cout << "Искомый автомобиль : \n";
			avto.print();
			std::cout << "===================================================" << std::endl;
			std::cout << std::endl;
			flg++;
			break;
		}
		else it++;
	}
	try {
		if (flg == 0) { std::cout << "Нет такого автомобиля,выход из программы\n"; throw 1; }
		else return it;
	}
	catch (int i) {
		if (i == 1)
			exit(0);
		}
}
