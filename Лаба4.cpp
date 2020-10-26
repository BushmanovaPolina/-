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
	~Human() = default;
	void output_human() {
		std::cout << "ФИО человека - " << name << "\nВозраст человека - " << age;
	}
};
class employee :virtual public Human{
protected:
	int salary;
	std::string position;
public:
	employee(){
		this->salary = 0;
		this->position = ' ';
	}
	employee(int s,std::string p){
		this->salary = s;
		this->position = p;
	}
	~employee() = default;
	void output_employee() {
		std::cout << "\n===================================================================================";
		std::cout << "\nДолжность сотрудника - " << position << "\nЗарплата - " << salary << "$";
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
	education(std::string sf, int tp) {
		this->sphere = sf;
		this->training_period = tp;
	}
	~education() = default;
	void output_education() {
		std::cout << "\n===================================================================================";
		std::cout << "\nОбразование\nСфера - " << sphere << "\nПериод обучения - " << training_period;
	}
};
class company : virtual public employee {
protected:
	std::string type;
	int number;
public:
	company(){
		this->type = ' ';
		this->number = 0;
	}
	company(std::string t,int num){
		this->type = t;
		this->number = num;
	}
	~company() = default;
	void output_company() {
		std::cout << "\n===================================================================================";
		std::cout << "\nТип предприятия - " << type << "\nКоличество работников - " << number;
	}
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
	~work() = default;
	void output_work() {
		std::cout << "\n===================================================================================";
		std::cout << "\nПрофессия - " << profession << "\nОпыт работы - " << experiance;
	}
};
class otdel_kadrov :virtual public company, virtual public work {
protected:
	std::string vacancy;
	int amount_vacancies;
public:
	otdel_kadrov() {
		this->amount_vacancies = 0;
		this->vacancy = ' ';
	}
	otdel_kadrov(std::string v, int av,std::string prof,int exp, std::string t, int num, std::string sf, int tp, int s, std::string p, std::string n, int a){
		this->amount_vacancies = av;
		this->vacancy = v;
		this->name=n;
		this->age = a;
		this->number = num;
		this->experiance = exp;
		this->salary = s;
		this->position = p;
		this->training_period = tp;
		this->profession = prof;
		this->sphere = sf;
		this->type = t;
	}
	void output_otdel_kadrov() {
		std::cout << "\n===================================================================================";
		std::cout << "\nКолличество свободных вакансий - " << amount_vacancies << "\nСвободные вакансии - "<<vacancy;
	}
	~otdel_kadrov() = default;
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
	std::cout << "Введите ФИО работника - ";
	std::string fio;
	std::cin >> fio;
	std::cout << "Введите возраст работника - ";
	int age=input_int(100);
	std::cout << "Введите сферу образования - ";
	std::string sf;
	std::cin >> sf;
	std::cout << "Введите период обучения - ";
	int tp = input_int(age-16);
	std::cout << "Введите профессию - ";
	std::string prof;
	std::cin >> prof;
	std::cout << "Введите опыт работы - ";
	int exp = input_int(age - 16);
	std::cout << "Введите должность - ";
	std::string pos;
	std::cin >> pos;
	std::cout << "Введите зарплату - ";
	int s = input_int(10000000);
	std::cout << "Введите тип предприятия - ";
	std::string t;
	std::cin >> t;
	std::cout << "Введите кол-во работников на предприятии - ";
	int num = input_int(1000);
	std::cout << "Введите количество свободных вакансий - ";
	int av = input_int(20);
	std::cout << "Введите свободные вакансии - ";
	std::string v;
	std::cin >> v;
	otdel_kadrov otdel(v,av,prof,exp,t,num,sf,tp,s,pos,fio,age);
	system("CLS");
	otdel.output_human();
	otdel.output_education();
	otdel.output_work();
	otdel.output_employee();
	otdel.output_company();
	otdel.output_otdel_kadrov();
	std::cout << "\n";
	return 0;
}
