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
	Stack<automobile> avto;
	avto.push(automobile(11111, "Иванов Иван Иванович", 100));
	avto.push(automobile(22222, "Константинов Константин Константинович", 200));
	avto.push(automobile(33333, "Владимиров Владимир Владимирович", 300));
	avto.push(automobile(44444, "Игорев Игорь Игоревич", 400));
	avto.push(automobile(55555, "Николаев Николай Николаевич", 500));
	avto.push(automobile(66666, "Павлов Павел Павлович", 600));
	Iterator<automobile> it1 = avto.begin(), it2 = avto.end();
	while (1) {
		cout << "Выберите действие\n1)Просмотреть элементы стэка\n2)Сортировать по id\n3)Сортировать по пробегу\n4)Добавить новый автомобиль\n5)Удалить автомобили удовлетворяющие условию\n6)Найти автомобиль по id\n";
		int variant = 0;
		try {
			it1 = avto.begin(), it2 = avto.end();
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
			break;
			break; }
		case 2: {
			break; }
		case 3: {
			break; }
		case 4: {
			automobile temp;
				cout << "Введите данные об автомобиле\n";
				input_id(temp);
				cout << "_________________________\n";
				avto.push(temp);
			break; }
		case 5: {
			break;
		}
		case 6: {
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
	}
	return 0;
}
