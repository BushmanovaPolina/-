#include <iostream>
#include <string>
int input_int(int min, int max);
float input_float(float min, float max);
template < typename T >
int poisk(T *mas, T key,int size) {
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == key) return i;
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
		if (flg == count)return i;
	}
}
template<typename T>
	void output(T *arr, int size){
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " "
			std::cout << std::endl;
	}
	int main() {
		system("chcp 1251> null");
		std::cout << "Выберите тип данных с которым хотите работать : \n1-int\n2-float\n3-char*" << std::endl;
		int answ = input_int(0,3);
		switch (answ-1) {
		case 0: {
			int s1 = input_int(0, 10);
			int* masi;
		masi = new int[s1];
		for (int i = 0; i < s1; i++) {
			masi[i] = input_int(0, 1000);
		}
		output(masi, s1);
		delete[]masi; break;
		}
		case 1: {int s2 = input_int(0, 10);
			float *masf;
		masf = new float[s2];
		for (int i = 0; i < s2; i++) {
			masf[i] = input_float(0, 1000);
		}
		output(masf, s2);
		float d = 3;
		int g=poisk(masf,d,s2);
		std::cout << "\n" << g;
		delete[]masf;
		break; }
			case2: {int s3 = input_int(0, 10);
				char* ms[10];
		ms[10] = new char[s3];
		for (int i = 0; i < s3; i++) {
			std::cin >> ms[i][10];
		}
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
	
