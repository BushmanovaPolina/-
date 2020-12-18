#include <iostream>
#include <string>
int input_int(int min, int max);
float input_float(float min, float max);
template < typename T >
int poisk(T *mas, T key,int size) {
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == key) return i+1;
		i++;
	}
	return 0;
}
int poisk(char** mas,char* str,int size) {
	int j = 0, flg = 0,count =0;
	for (int i = 0; i < size; i++)
	{
		while (!mas[size][j] || !str[j])
		{
			count++;
			if (mas[size][j] = str[j])
				flg++;
		}
		if (flg == count)return i+1;
	}
}
template<typename T>
	void output(T *arr, int size){
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
			std::cout << std::endl;
	}
	void output(char**ms, int size) {
		for (int i = 0; i < size; i++)
			std::cout << ms[i] << std::endl;
	}
	int main() {
		system("chcp 1251> null");
		std::cout << "Выберите тип данных с которым хотите работать : \n1-int\n2-float\n3-char*" << std::endl;
		int answ = input_int(0,4);
		switch (answ-1) {
		case 0: {
			int s1 = input_int(0, 10);
			int* masi;
		masi = new int[s1];
		for (int i = 0; i < s1; i++) {
			masi[i] = input_int(0, 1000);
		}
		output(masi, s1);
		int ikei = input_int(0, 1000);
		int g = poisk(masi, ikei, s1);
		std::cout << g << std::endl;
		delete[]masi; break;
		}
		case 1: {int s2 = input_int(0, 10);
			float *masf;
		masf = new float[s2];
		for (int i = 0; i < s2; i++) {
			masf[i] = input_float(0, 1000);
		}
		output(masf, s2);
		float fkey = input_float(0,1000);
		int g=poisk(masf,fkey,s2);
		std::cout << "\n" << g;
		delete[]masf;
		break; }
		case 2: {int s3 = input_int(0, 10);
				char** ms;
				ms = new char*[s3]; 
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				for (int i = 0; i < s3; i++)
				{ms[i] = new char[10];
				std::cin >> ms[i];
				}
				char* ckey = new char[10];
				std::cin >> ckey;
				int c = poisk(ms, ckey, s3);
		output(ms, s3);
		delete[]ms;
		break; }
		}
		return 0;
	}
	int input_int(int min, int max) {
		int a = 0;
		while (!(std::cin >> a) || a > max || a < min) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Повторите ввод\n";
		}
		return a;
	}
	float input_float(float min, float max) {
		float a = 0;
		while (!(std::cin >> a) || a > max || a < min) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Повторите ввод\n";
		}
		return a;
	}
	
