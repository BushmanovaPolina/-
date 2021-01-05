#include "Laba8.h"

Stack::Stack()
{
	Size = 0;
	head = nullptr;
}

Stack::~Stack()
{
	clear();
}

void Stack::pop()
{
	try
	{
		if (Size == 0)
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
	ATS* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void Stack::clear()
{
	while (Size)
	{
		pop();
	}
}

ATS& Stack::operator[](const int index)
{
	int counter = 0;
	ATS* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return *current;
		}
		current = current->pNext;
		counter++;
	}
}

void Stack::push(string _date, string _kod, string _tariff, int _time, long int _number_c, long int _number_a)
{
	head = new ATS(_date, _kod, _tariff, _time, _number_c, _number_a,head);
	Size++;
}

ostream& operator<<(ostream& out, const ATS& ats)
{
	out << "Дата: " << ats.date << endl;
	out << "Код и название города: " << ats.kod << endl;
	out << "Время разговора: " << ats.time << endl;
	out << "Тариф: " << ats.tariff << endl;
	out << "Номер телефона в этом городе: " << ats.number_c << endl;
	out << "Номер телефона абонента: " << ats.number_a << endl;
	return out;
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

int File::Del(int index, int n, Stack& st)
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
	msg = new char[10];
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
	fs.read(msg, 10);
	int count = 0;
	for (int i = 0; i < 10; i++)
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

void File::Sort(int n, Stack &st)
{
	if (n == 1)
	{
		this->ReadBin(n);
		return;
	}
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
	this->ReadBin(n);
	fs2.close();
	delete[] ms;
	delete[] m;
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
	ATS ms[10];
	int i = 0;
	char c;
	while (!fs.eof())
	{
		fs.read(reinterpret_cast<char*>(&ms[i]), sizeof(ms[i]));
		/*fs.read((char*)&ms[i], sizeof(ms[i]));*/
		i++;
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
	/*fs.write(reinterpret_cast<char*>(&pr), sizeof(pr));*/
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
		cout << ats;
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
	Stack st;
	File file2("2.bin");
	string* _date;
	string* _kod;
	string* _tariff;
	int* _time;
	long int* _number_c;
	long int* _number_a;
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
		cout << "Ввод данных в файл: " << endl;
		cout << "Введите количество элементов: ";
		try
		{
			cin >> n;
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
		_date = new string[n];
		_kod = new string[n];
		_time = new int[n];
		_number_c = new long int[n];
		_number_a = new long int[n];
		_tariff = new string[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Введите элемент [" << i << "]: " << endl;
			cout << "Дата: ";
			try
			{
				cin >> _date[i];
				/*if (_date[i] < 65 || _date[i] > 67)
				{
					throw 2;
				}*/
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			cout << "Код и название города: ";
			cin >> _kod[i];
			cout << "Тариф: ";
			cin >> _tariff[i];
			cout << "Номер в городе :";
			cin >> _number_c[i];
			cout << "Номер абонента :";
			cin >> _number_a[i];
			cout << "Время: ";
			try
			{
				cin >> _time[i];
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
			ATS ats(_date[i], _kod[i], _tariff[i], _time[i],_number_c[i],_number_a[i]);
			file2.WriteBin(ats);
		}
		cout << "\nПрочитать файл - 1" << endl;
		cout << "Поиск по файлу - 2" << endl;
		cout << "Сортировка - 3" << endl;
		cout << "Удаление - 4" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "Файл: " << endl;
			file2.ReadBin(n);
		}
		if (ch == 2)
		{
			file2.Search();
		}
		if (ch == 3)
		{
			file2.Sort(n, st);
		}
		if (ch == 4)
		{
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
			k = file2.Del(index, n, st);
			n = k;
		}
		delete[] _date;
		delete[] _kod;
		delete[] _time;
		delete[] _tariff;
		delete[] _number_a;
		delete[] _number_c;
	}
	return 0;
}
