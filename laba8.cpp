#include "Laba8.h"
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
void output(ATS& ats) {
	cout << "Дата звонка: " << ats.day << "." << ats.month << "." << ats.year << endl;
	cout << "Код и город: " << ats.kod <<" "<< ats.country << endl;
	cout << "Продолжительность звонка: " << ats.time << endl;
	cout << "Тариф: " << ats.tariff << endl;
	cout << "Номер телефона в городе: " << ats.number_c << endl << "Номер телефона абонента: " << ats.number_a << endl;
}
void InsertSort(int n, int* ms)
{
	int j;
	int m;
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
	return;
}

int File::Del(int index, int n, Stack<ATS>& st)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
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
	ATS* ms;
	ms = new ATS[n];
	for (int i = 0; i < n; i++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
	}
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	for (int i = 0; i < index; i++)
	{
		this->WriteBin(ms[i]);
	}
	for (int i = index + 1; i < n; i++)
	{
		this->WriteBin(ms[i]);
	}
	n = n - 1;
	cout << "Файл после удаления: " << endl;
	this->ReadBin(n);
	fs2.close();
	return n;
}

void File::ReadTextBin()
{
	char* msg;
	msg = new char[100];
	fstream fs;
	fs.open(path, fstream::in | fstream::binary);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs.read(msg, 100);
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		if (msg[i] >= 97 && msg[i] <= 122 || msg[i] >= 65 && msg[i] <= 90)
		{
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << msg[i];
	}
	cout << endl;
	fs.close();
}

void File::Sort_time(int n, Stack<ATS> &st)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	int* m;
	m = new int[n];
	ATS* ms;
	ms = new ATS[n];
	int i = 0;
	for (int k = 0; k < n; k++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
		m[i] = ms[i].time;
		i++;
	}
	InsertSort(n, m);
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	try
	{
		if (!fs1.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	try
	{
		if (!fs2.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "Сортировка по времени звонка:  " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ms[j].time == m[i])
			{
				this->WriteBin(ms[j]);
			}
		}
	}	
	fs2.close();
    this->ReadBin(n);
	delete[] ms;
	delete[] m;
}
void File::Sort_day(int n, Stack<ATS> &st)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	int *m2;
	m2 = new int[n];
	ATS* ms;
	ms = new ATS[n];
	int i = 0;
	for (int k = 0; k < n; k++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
		m2[i] = ms[i].day;
		i++;
	}
	InsertSort(n, m2);
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	try
	{
		if (!fs1.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	try
	{
		if (!fs2.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "Сортировка по дате:  " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ms[j].day == m2[i])
			{
				this->WriteBin(ms[j]);
			}
		}
	}
	fs2.close();
	this->ReadBin(n);
	delete[] ms;
	delete[] m2;
}


void File::Search()
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	ATS ms[5];
	int i = 0,d=0,m=0,y=0,t=0;
	while (i!=5)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
		output(ms[i]);
		cout << "=============================" << endl;
		i++;
	}
	cout << "Введите условия для поиска: \nПродолжительность звонка: ";
	cin >> t;
	cout << "\nДень: ";
	cin >> d;
	if (d > 31)throw 3;
	cout << "\nМесяц: ";
	cin >> m;
	if (m > 12)throw 3;
	cout << "\nГод: ";
	cin >> y;
	if (y > 2020)throw 3;
	long int date = d + m * 31 + y * 365;
	cout << "Результаты поиска(Звонки позже введенной даты и не короче введенного времени): " << endl;
	for (int i = 0; i < 5; i++)
	{
		long date1 = ms[i].day + ms[i].month * 31 + ms[i].year * 365;
		if(ms[i].time>t)
		if (date1>date)
		{
				cout << "____________________________________" << endl;
				output(ms[i]);
		}
	}
	fs.close();
}

void File::WriteBin(ATS ats)
{
	fstream fs;
	fs.open(path, fstream::out | fstream::binary | fstream::app);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs.write((char*)&ats, sizeof(ats));
	fs.close();
}

void File::WriteText()
{
	string msg;
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "Введите текст: ";
	cin >> msg;
	fs << msg << "\n";
	fs.close();
}

void File::ReadBin(int n)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "____________________________________" << endl;
	ATS ats;
	while (fs.read((char*)&ats, sizeof(ATS)))
	{
		output(ats);
		cout << "____________________________________" << endl;
	}
	fs.close();
}

void File::ReadText()
{
	string msg;
	fstream fs;
	fs.open(path, fstream::in);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "Файл " << path << ":" << endl;
	while (!fs.eof())
	{
		while (getline(fs, msg))
		{
			cout << msg << endl;
		}
	}
	fs.close();
}

int main()
{
	system("chcp 1251>null");
	Stack<ATS> st;
	File file2("2.bin");
	int n, index, var, ch;
	cout << "Выберите с каким файлом работать? 1-текстовый, 2-бинарный";
	cin >> var;
	if (var == 1)
	{
		system("CLS");
		cout << "Работа с текстовым файлом:" << endl;
		File file1("1.txt");
		file1.WriteText();
		file1.ReadText();
		cout << "Чтение файла в бинарном режиме: " << endl;
		file1.ReadTextBin();
	}
	if (var == 2)
	{
		system("CLS");
		ATS temp = ATS(4, 1, 2019, "Минск", "017", "A1", 360, 1234567, 80171234567);
		st.push(temp);
		temp = ATS(8, 2, 2019, "Минск", "017", "A1", 300, 1234567, 80171234567);
		st.push(temp);
		temp = ATS(14, 3, 2020, "Минск", "017", "A1", 250, 1234567, 80171234567);
		st.push(temp);
		temp = ATS(25, 5, 2021, "Минск", "017", "A1", 340, 1234567, 80171234567);
		st.push(temp);
		temp = ATS(17, 9, 2020, "Минск", "017", "A1", 400, 1234567, 80171234567);
		st.push(temp);
		fstream fs;
		fs.open("2.bin", fstream::out | fstream::binary);
		fs.close();
		for (int i = 0; i < st.GetSize(); i++) {
			file2.WriteBin(st[i]);
		}
		cout << "\nПрочитать файл - 1" << endl;
		cout << "Поиск по файлу - 2" << endl;
		cout << "Сортировка по времени - 3" << endl;
		cout << "Сортировка по дате - 4" << endl;
		cout << "Удаление - 5" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "Файл: " << endl;
			file2.ReadBin(st.GetSize());
		}
		if (ch == 2)
		{
			file2.Search();
		}
		if (ch == 3)
		{
			file2.Sort_time(st.GetSize(), st);
		}
		if (ch == 4)
		{
			file2.Sort_day(st.GetSize(), st);
		}
		if (ch == 5)
		{
			cout << "Файл до удаления: ";
			fstream fs;
			fs.open("2.bin", fstream::in | fstream::binary | fstream::out);
			try
			{
				if (!fs.is_open())
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
			cout << "____________________________________" << endl;
			ATS ats;
			while (fs.read((char*)&ats, sizeof(ATS)))
			{
				output(ats);
				cout << "____________________________________" << endl;
			}
			fs.close();
			cout << "Введите номер элемента для удаления: ";
			try
			{
				cin >> index;
				if (cin.fail())
				{
					throw 0;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			int k;
			k = file2.Del(index, st.GetSize(), st);
			n = k;
		}
	}
	return 0;
}
