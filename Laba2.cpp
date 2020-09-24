#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;
class automobile {
private:
	int id;
	string name;
	int mileage;
public:
	automobile() {
		this->id = 0;
		this->name = ' ';
		this->mileage = 0;
	}
	automobile(int ID, string fio) {
		this->id = ID;
		this->name = fio;
		this->mileage = 0;
	}
	~automobile() {};
	friend void print(automobile &avto);
	friend class STO;
};
void print(automobile &avto) {
	cout << "���������� ����� ���������� - " << avto.id << endl;
	cout << "��� ��������� ���������� - " << avto.name << endl;
	cout << "������ ���������� - " << avto.mileage << endl;
}
class STO {
private:
	int Mileage;
public:
	STO() {
		this->Mileage = 0;
	}
	STO(int Mil) {
		this->Mileage = Mil;
	}
	~STO() {};
	void input_mileage() {
		bool a = true;
		do
		{
			cout << "������� ������ ���������� - ";
			cin >> Mileage;
			if (cin.fail())
				cout << "��������� �������" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);
		STO m(Mileage);
	};
	void install_mileage(automobile &avto) {
		avto.mileage = Mileage;
	}
};
int main() {
	system("chcp 1251>null");
	int ID;
	string fio;
	bool a = true;
	do
	{
		cout << "������� id: ";
		cin >> ID;
		if (cin.fail())
			cout << "��������� �������" << endl;
		else
			a = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (a);
	cout << "������� ��� ��������� ���������� - ";
	cin >> fio;
	automobile a1(ID, fio);
	STO m1;
	print(a1);
	cout << "========================================" << endl;
	m1.input_mileage();
	m1.install_mileage(a1);
	cout << "========================================" << endl;
	print(a1);
	return 0;
}