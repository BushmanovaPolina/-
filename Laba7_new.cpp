#include"Laba7_new.h"

template<typename T>
Stack<T>::Stack()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::pop()
{
	try
	{
		if (Size == 0)
		{
			throw 4;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void Stack<T>::clear()
{
	while (Size)
	{
		pop();
	}
}

template<typename T>
T& Stack<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void Stack<T>::push(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void Sort(int n, T* ms)
{
	int j;
	T m;
	for (int i = 1; i < n; ++i)
	{
		j = i - 1;
		m = ms[i];
		while (j >= 0 && m < ms[j])
		{
			ms[j-- + 1] = ms[j];
		}
		ms[j + 1] = m;
	}
}
template<typename T>
ostream& operator<<(ostream& out, const Node<T>& node)
{
	out << node.data;
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const Iterator<T>& it)
{
	out << *it;
	return out;
}

int main()
{
	system("chcp 1251 >null");
	Stack<automobile> avto;
	avto.push(automobile(11111, "Иванов Иван Иванович", 200));
	avto.push(automobile(66666, "Павлов Павел Павлович", 400));
	avto.push(automobile(22222, "Константинов Константин Константинович", 700));
	avto.push(automobile(44444, "Игорев Игорь Игоревич", 300));
	avto.push(automobile(55555, "Николаев Николай Николаевич", 500));
	avto.push(automobile(33333, "Владимиров Владимир Владимирович", 600));
	Iterator<automobile> it1 = avto.begin(), it2 = avto.end();
	while (1) {
		cout << "Выберите действие\n1)Просмотреть элементы стэка\n2)Сортировать по id\n3)Сортировать по пробегу\n4)Добавить новый автомобиль\n5)Удалить автомобили удовлетворяющие условию\n6)Найти автомобиль по id\n";
		int variant = 0;
		it1 = avto.begin(), it2 = avto.end();
		try {
			cin >> variant;
			if (cin.fail()) throw 1;
		}
		catch(int i){
			Exception ex(i); 
			ex.Print();
			return 0;
		}
		switch (variant) {
		case 1: {
			
			try {
				if (it1 == nullptr) throw 3;
			}
			catch (int i) {
				Exception ex(i);
				ex.Print();
				return 0;
			}
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			for (it1; it1 != it2; it1++)
			{
				automobile temp = it1.get_data();
				temp.print();
			}
			automobile temp = it2.get_data();
			temp.print();
			break; }
		case 2: {
			int n = avto.GetSize();
			automobile *ms=new automobile[n];
			it1 = avto.begin(), it2 = avto.end();
			int i = 0;
			while (it1 != it2) {
				ms[i] = it1.get_data();
				it1++;
				i++;
		}
			ms[i] = it2.get_data();
			int *ms1 = new int[n];
			for (int j = 0; j < n; j++) {
				ms1[j] = ms[j].get_id();
			}
			Sort(n, ms1);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (ms[j].get_id() == ms1[i])
					{
						avto[i] = ms[j];
					}
				}
			}
			it1 = avto.begin();
			for (it1; it1 != it2; it1++)
			{
				automobile temp = it1.get_data();
				temp.print();
			}
			automobile temp = it2.get_data();
			temp.print();
			delete[] ms;
			delete[] ms1;
			break; }
		case 3: {
			int n = avto.GetSize();
			automobile *ms = new automobile[n];
			it1 = avto.begin(), it2 = avto.end();
			int i = 0;
			while (it1 != it2) {
				ms[i] = it1.get_data();
				it1++;
				i++;
			}
			ms[i] = it2.get_data();
			int *ms1 = new int[n];
			for (int j = 0; j < n; j++) {
				ms1[j] = ms[j].get_mileage();
			}
			Sort(n, ms1);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (ms[j].get_mileage() == ms1[i])
					{
						avto[i] = ms[j];
					}
				}
			}
			it1 = avto.begin();
			for (it1; it1 != it2; it1++)
			{
				automobile temp = it1.get_data();
				temp.print();
			}
			automobile temp = it2.get_data();
			temp.print();
			delete[] ms;
			delete[] ms1;
			break; }
		case 4: {
			automobile temp;
				cout << "Введите данные об автомобиле\n";
				input_id(temp);
				cout << "_________________________\n";
				avto.push(temp);
			break; }
		case 5: {
			cout << "Введите id для поиска: ";
			int ID;
			try {
				cin >> ID;
				if (cin.fail()) throw 1;
			}
			catch (int i) {
				Exception ex(i);
				ex.Print();
				return 0;
			}
			it1 = avto.begin();
			int flg = 0;
			automobile temp;
			while (it1 != it2) {
				temp = *it1;
				if (temp.get_id() == ID)
				{
					cout << "Автомобиль, который удаляется\n======================================================\n";
					temp.print();
				   avto.Del(it1);
					flg++;
				}
				it1++;
			}
			temp = *it2;
	if (temp.get_id() == ID)
			{
				cout << "Автомобиль, который удаляется\n======================================================\n";
				temp.print();
				avto.Del(it2);
				flg++;
				break;
			}
	        if (flg == 0)
			cout << "Такого автомобиля нет\n";
			break;
		}
		case 6: {
			cout << "Введите id для поиска: ";
			int ID;
			try {
				cin >> ID;
				if (cin.fail()) throw 1;
			}
			catch (int i) {
				Exception ex(i);
				ex.Print();
				return 0;
			}
			it1 = avto.begin();
			int flg = 0;
			automobile temp;
			while (it1 != it2) {
				temp = *it1;
				if (temp.get_id() == ID)
				{
					temp.print();
					flg++;
					break;
				}
				it1++;
			}
			temp = *it2;
			if (flg == 0) if (temp.get_id() == ID)
			{
				temp.print();
				break;
			}
			else cout << "Такого автомобиля нет\n";
			break;
		}
		default: {
			cout << "Нет такого варианта\n";
		}
		}
		cout << "Хотите продолжить? Да-1/Нет-0\n";
		int answ;
		cin >> answ;
		if (answ != 1)break;
		system("CLS");
	}
	return 0;
}
