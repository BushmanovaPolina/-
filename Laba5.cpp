#include <iostream>
#include <string>
#include <windows.h>
 
class Human {
protected :
	std::string name;
	int age;
public:
	Human(){
		this->name = ' ';
		this->age = 0;
	}
	Human(std::string n, int a) {
		this->name = n;
		this->age = a;
	}
	virtual ~Human() {};
	virtual int count_stag() = 0;
	virtual void output() = 0;
		
};
class employee :virtual public Human{
protected:
	int salary;
	std::string position;
	int stag;
public:
	employee(){
		this->salary = 0;
		this->stag = 0;
		this->position = ' ';
	}
	employee(int s,std::string p,std::string n,int a,int st){
		this->name = n;
		this->age = a;
		this->salary = s;
		this->position = p;
		this->stag = st;
	}
	~employee() = default;
	void output() {
		std::cout << "\nФИО сотрудника - "<<name<<"\nВозраст сотрудника - "<<age<<"\nДолжность сотрудника - " << position << "\nЗарплата - " << salary << "$\nСтаж работы - "<<stag;
	}
	int count_stag() {
		return stag;
	}
};
class education : virtual public Human {
protected:
	std::string sphere;
	int training_period;
public:
	education() {
		this->sphere = ' ';
		this->training_period = 0;
		
	}
	education(std::string sf, int tp, std::string n, int a) {
		this->sphere = sf;
		this->training_period = tp;
		this->name = n;
		this->age = a;
	}
	~education() = default;
};
class work : virtual public education {
protected:
	std::string profession;
	int experiance;
public:
	work(){
		this->profession = ' ';
		this->experiance = 0;
	}
	work(std::string prof, int exp) {
		this->profession = prof;
		this->experiance = exp;
	}
	work(std::string prof, int exp,std::string n,int a, std::string sf, int tp) {
		this->profession = prof;
		this->experiance = exp;
		this->sphere = sf;
		this->training_period = tp;
		this->name = n;
		this->age = a;
	}
	~work() = default;
	void output() {
		std::cout << "\nФИО человека - " << name << "\nВозраст человека - " << age << "\nОбразование\nСфера - " << sphere << "\nПериод обучения - " << training_period<<"\nПрофессия - " << profession << "\nОпыт работы - " << experiance;
	}
	int count_stag() {
		return experiance;
	}
};
int input_int(int max) {
	int a = 0;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	while (!(std::cin >> a) || a > max || a < 0) {
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Повторите ввод\n";
	};return a;
}
int main() {
	system("chcp 1251>null");
	Human** people = new Human*[10];
	int flag = 1, var = 0,tp,age,exp,s,st,i=0,number;
	std::string fio,sf,prof,pos;
	while (flag != 0 && i!=10) {
		std::cout << "Выберите действие:\n1)Добавить сотрудника предриятия\n2)Добавить человека,который пришел наниматься\n3)Вывести информацию про людей\n4)Вывести стаж работы определенного человека\n5)Выход из программы\n";
		switch (var = input_int(6)) {
		case(1): 
			std::cout << "Введите ФИО работника - ";
			std::cin >> fio;
			std::cout << "Введите возраст работника - ";
			age = input_int(100);
			std::cout << "Введите зарплату работника - ";
			s = input_int(1000000);
			std::cout << "Введите должность работника - ";
			std::cin >> pos;
			std::cout << "Введите стаж работника - ";
			st = input_int(age - 16);
			people[i] = new employee(s, pos, fio, age, st);
			i++;
			break;
		case(2):std::cout << "Введите ФИО человека - ";
			std::cin >> fio;
			std::cout << "Введите возраст человека - ";
			age = input_int(100); 
			std::cout << "Введите сферу образования - ";
			std::cin >> sf;
			std::cout << "Введите период обучения - ";
			tp = input_int(age - 16);
			std::cout << "Введите профессию - ";
			std::cin >> prof;
			std::cout << "Введите опыт работы - ";
			exp = input_int(age - 16);
			people[i] = new work(prof, exp, fio, age, sf, tp);
			i++; 
			break;
		case(3):for (int j = 0; j < i; j++) {
			std::cout << "\n===============================================================================";
			std::cout << "\nЧеловек №" << j + 1;
			people[j]->output();
		}system("pause");
				break;
		case(4):std::cout << "Введи номер человека,чей стаж хотите вывести - ";
			number = input_int(i);
			std::cout << "Стаж человека,которого вы выбрали - " << people[number-1]->count_stag();
			system("pause");
			break;
		case(5):flag = 0; break;
		}
		system("CLS");
	}
	delete [10]people;
	return 0;
}
