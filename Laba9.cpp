#include "Laba9.h"

void MySpace::Algorithm::first() {
	std::fstream task;
	task.open("task.txt", std::fstream::in);
	bool f_open = task.is_open();
	try {
		if (!f_open) throw 3;
		else std::cout << "Открылся файл task.txt\n";
	}
	catch (int i) {
		Exception ex(i);
		ex.Print();
		return;
	}
	std::vector<std::string> vec;
	std::string temp;
	while (!task.eof())
	{
		std::getline(task,temp, '=');
		vec.push_back(temp);
		std::getline(task, temp, '\n');
		vec.push_back(temp);
	}
	std::cout << "Завершилось чтение из файла task.txt\nСчитанные данные:";
	std::vector< std::string>::iterator it;
	it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " = ";
		++it;
		std::cout << *it << std::endl;
		++it;
	}
	task.close();
	std::cout << "Закрылся файл task.txt\n";
	std::fstream result;
	result.open("result.txt", std::fstream::out);
	f_open = result.is_open();
	try {
		if (!f_open) throw 3;
		else std::cout << "Открылся файл result.txt\n";
	}
	catch (int i) {
		Exception ex(i);
		ex.Print();
		return;
	}
	try {
		if (vec.size()<=0) throw 4;
	}
	catch(int i){
		Exception ex(i);
		ex.Print();
		return;
	}
	it = vec.begin();
	while (it != vec.end()) {
		++it;
		result << *it << " - ";
 		it--;
		result << *it << "\n";
		it = it + 2;
	}
	std::cout << "Произошла запись в файл result.txt\n";
	result.close();
	std::cout << "Закрылся файл result.txt\n";
}

int main() { 
	system("chcp 1251>null");
	while (1) {
		std::cout << "Выберите действие: \n1)Задание 1\n2)Задание 2\n3)Задание 3\n";
		int var;
		std::cin >> var;
		MySpace::Algorithm a;
		switch (var) {
		case 1: {a.first();
			break; }
		case 2: {
			std::vector<MySpace::automobile> vec;
			vec.push_back(MySpace::automobile(11111, "Иванов Иван Иванович", 100));
			vec.push_back(MySpace::automobile(22222, "Константинов Константин Константинович", 200));
			vec.push_back(MySpace::automobile(33333, "Владимиров Владимир Владимирович", 300));
			vec.push_back(MySpace::automobile(44444, "Игорев Игорь Игоревич", 400));
			vec.push_back(MySpace::automobile(55555, "Николаев Николай Николаевич", 500));
			vec.push_back(MySpace::automobile(66666, "Павлов Павел Павлович", 600));
			std::vector<MySpace::automobile>::iterator it;
			it = vec.begin();
			while (it != vec.end()) {
				std::cout << "Элемент векора:" << std::endl;
				MySpace::automobile avto;
				avto = *it;
				avto.print();
				std::cout << std::endl;
				++it;
			}
			a.second(vec.begin(),vec.end()); 
			std::cout << "Добавление элемента вектора" << std::endl;
			vec.push_back(MySpace::automobile(77777, "Павлов Павел Павлович", 700));
			it = vec.begin();
			while (it != vec.end()) {
				std::cout << "Элемент векора:" << std::endl;
				MySpace::automobile avto;
				avto = *it;
				avto.print();
				std::cout << std::endl;
				++it;
			}
			std::cout << "===================================================" << std::endl;
			std::cout << "Удаление элементов вектора, кроме одного" << std::endl;
			for (int i = 0; i < 6; i++) {
				vec.pop_back();
			}
			it = vec.begin();
			while (it != vec.end()) {
				std::cout << "Элемент векора:" << std::endl;
				MySpace::automobile avto;
				avto = *it;
				avto.print();
				std::cout << std::endl;
				++it;
			}
			break; }
		case 3: {std::vector<MySpace::automobile> vec;
			vec.push_back(MySpace::automobile(11111, "Иванов Иван Иванович", 100));
			vec.push_back(MySpace::automobile(22222, "Константинов Константин Константинович", 200));
			vec.push_back(MySpace::automobile(33333, "Владимиров Владимир Владимирович", 300));
			vec.push_back(MySpace::automobile(44444, "Игорев Игорь Игоревич", 400));
			vec.push_back(MySpace::automobile(55555, "Николаев Николай Николаевич", 500));
			vec.push_back(MySpace::automobile(66666, "Павлов Павел Павлович", 600));
			std::vector<MySpace::automobile>::iterator it;
			std::vector<MySpace::automobile>::iterator temp;
			it = vec.begin(); 
		    temp=a.third(vec.begin(), vec.end()); 
			vec.erase(temp);
			it = vec.begin();
			while (it != vec.end()) {
				std::cout << "===================================================" << std::endl;
				std::cout << "Элемент векора:" << std::endl;
				MySpace::automobile avto;
				avto = *it;
				avto.print();
				std::cout << std::endl;
				++it;
			}
			std::cout << "Добавление элемента вектора" << std::endl;
			vec.push_back(MySpace::automobile(77777, "Павлов Павел Павлович", 700));
			it = vec.begin();
			while (it != vec.end()) {
				std::cout << "===================================================" << std::endl;
				std::cout << "Элемент векора:" << std::endl;
				MySpace::automobile avto;
				avto = *it;
				avto.print();
				std::cout << std::endl;
				++it;
			}
			std::cout << "===================================================" << std::endl;
			std::cout << "Удаление элементов вектора, кроме одного" << std::endl;
			for (int i = 0; i < 6; i++) {
				vec.pop_back();
			}
			it = vec.begin();
			while (it != vec.end()) {
				std::cout << "===================================================" << std::endl;
				std::cout << "Элемент векора:" << std::endl;
				MySpace::automobile avto;
				avto = *it;
				avto.print();
				std::cout << std::endl;
				++it;
			}
			break; }
		default: {
			std::cout << "Нет такого действия!" << std::endl;
		}
		}
		std::cout << "Хотите продолжить? Да-1/Нет-0\n";
		int answ;
		std::cin >> answ;
		if (answ != 1)break;
		system("CLS"); 
	}
	return 0;
}
