#include"laba7.h"

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
	while (1) {
		cout << "Выберите с каким типом данных хотите работать?\n1)int\n2)double\n3)char\n4)Пользовательский класс STO\n";
		int variant = 0;
		cin >> variant;
		switch (variant) {
		case 1: {
			Stack<int> st1;
			int n;
			int* value1;
			cout << "Введите количество элементов: " << endl;
			try
			{
				cin >> n;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			value1 = new int[n];
			cout << "Введите значения в стэк (int): " << endl;
			for (int i = 0; i < n; i++)
			{
				try
				{
					cin >> value1[i];
					if (cin.fail())
					{
						throw 1;
					}
				}
				catch (int i)
				{
					Exception ex(i);
					ex.Print();
					return 0;
				}
				st1.push(value1[i]);
			}
			Iterator<int> it1=st1.begin(),it2=st1.end();
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			st1.output(it1, it2);
			cout << "__________________________________________" << endl;
			cout << "Отсортированный стэк:" << endl;
			Sort(n, value1);
			for (int i = 0; i < n; i++)
			{
				cout << value1[i] << "  ";
			}
			cout << " " << endl;
			cout << "Удаление элемента\n";
			st1.pop();
			cout << "Добавьте элемент в стэк" << endl;
			int temp;
			try
			{
				cin >> temp;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			st1.push(temp);
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			st1.output(st1.begin(), st1.end());
			delete[] value1;
			break; }
		case 2: {
			int n;
			Stack<double> st2;
			double* value2;
			cout << "Введите количество элементов: " << endl;
			try
			{
				cin >> n;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			value2 = new double[n];
			cout << "Введите значения в стэк (double): " << endl;
			for (int i = 0; i < n; i++)
			{
				try
				{
					cin >> value2[i];
					if (cin.fail())
					{
						throw 2;
					}
				}
				catch (int i)
				{
					Exception ex(i);
					ex.Print();
					return 0;
				}
				st2.push(value2[i]);
			}
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			st2.output(st2.begin(), st2.end());
			cout << "__________________________________________" << endl;
			cout << "Отсортированный стэк :" << endl;
			Sort(n, value2);
			for (int i = 0; i < n; i++)
			{
				cout << value2[i] << "  ";
			}
			cout << " " << endl;
			cout << "Удаление элемента\n";
			st2.pop();
			cout << "Добавьте элемент в стэк" << endl;
			double temp;
			try
			{
				cin >> temp;
				if (cin.fail())
				{
					throw 2;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			st2.push(temp);
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			st2.output(st2.begin(), st2.end());
			delete[] value2;
			break; }
		case 3: {int n;
			Stack<char> st3;
			char* value3;
			cout << "Введите количество элементов: " << endl;
			try
			{
				cin >> n;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			value3 = new char[n];
			cout << "Введите значения в стэк (char): " << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> value3[i];
				st3.push(value3[i]);
			}
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			Iterator<char> it=st3.begin(),it2=st3.end();
			st3.output(it, it2);
			cout << "__________________________________________" << endl;
			cout << "Отсортированный стэк :" << endl;
			Sort(n, value3);
			for (int i = 0; i < n; i++)
			{
				cout << value3[i] << "  ";
			}
			cout << " " << endl;
			cout << "Удаление элемента\n";
			st3.pop();
			cout << "Добавьте элемент в стэк" << endl;
			char temp;
				cin >> temp;
			st3.push(temp);
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			it = st3.begin(), it2 = st3.end();
			st3.output(it, it2);
			delete[] value3; 
			break; }
		case 4: {
			Stack<automobile> avto;
			int n;
			cout << "Введите количество элементов: " << endl;
			try
			{
				cin >> n;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			automobile *value4 = new automobile[n];
			for (int i = 0; i < n; i++) {
				cout << "Введите данные об автомобиле\n";
				input_id(value4[i]);
				cout << "_________________________\n";
				avto.push(value4[i]);
			}
			Iterator<automobile> it1=avto.begin(),it2=avto.end();
			cout << "__________________________________________" << endl;
			cout << "Стэк : " << endl;
			for (it1;it1!=it2; it1++)
			{
				automobile temp = it1.data;
				temp.print();
			}
			automobile temp = it2.get_data();
			temp.print();
			delete[] value4;
			break; }
		default: {
			cout << "Нет такого варианта\n";
		}
		}
		cout << "Хотите продолжить? Да-1/Нет-0\n";
		int answ;
		cin >> answ;
		if (answ != 1)break;
	}
	return 0;
}
