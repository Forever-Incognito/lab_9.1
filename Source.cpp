//lab_9.1

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <Windows.h>

using namespace std;

enum Specialnist{KN, IF, ME, FI, TN};

string specialnistStr[] = { "КН", "ІФ", "МЕ", "ФІ", "ТР" };

struct Student
{
	string prizv;
	int kyrs;
	Specialnist specialnist;
	int fizuka;
	int matem;
	union 
	{
		int prog;
		int chuzel_met;
		int pedag;
	};

};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Average(Student* p, const int N);
void Searchfiz(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << " Введіть кількість студентів = "; cin >> N;
	cout << endl;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	Average(p, N);
	Searchfiz(p, N);

	return 0;
}

void Create(Student* p, const int N)
{
	int specialnist;

	for (int i = 0; i < N; i++)
	{
		cout << " Студент № " << i + 1 << " : " << endl;
		cin.sync();

		cout << "   прізвище : "; cin>> p[i].prizv;
		cout << "   курс : "; cin >> p[i].kyrs;
		cout << "   спеціальність (0-КН, 1-ІФ, 2-МЕ, 3-ФІ, 4-ТН) : "; cin >> specialnist;
		cout << "   фізика : "; cin >> p[i].fizuka;
		cout << "   математика : "; cin >> p[i].matem;

		p[i].specialnist = (Specialnist)specialnist;

		switch (p[i].specialnist)
		{
			case KN:
				cout << "   програмування: "; cin >> p[i].prog;
				break;
			case IF:
				cout << "   чисельні методи : "; cin >> p[i].chuzel_met;
				break;
			case ME:
			case FI:
			case TN:
				cout << "   педагогіка : "; cin >> p[i].pedag;
				break;
		}
		
		cout << endl;
	}

}

void Print(Student* p, const int N)
{

	cout << "================================================================================" << endl;
	cout << "| № |   Прізвище   | Курс | Спеціальність | Фіз. | Мат. | Про. | Чис. мет.|Пед.|" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1;
		cout << "| " << setw(12) << left << p[i].prizv<< " ";
		cout << "| " << setw(4) << right << p[i].kyrs << " ";
		cout << "| " << setw(14) << left << specialnistStr[ p[i].specialnist ];
		cout << "| " << setw(4) << left << p[i].fizuka << " ";
		cout << "| " << setw(4) << right << p[i].matem << " ";

		switch (p[i].specialnist)
		{
		case KN:
			cout << "| " << setw(4) << setprecision(2) << fixed << right << p[i].prog << " |" <<
				setw(11) << right << "|" << setw(5) << right << "|" << endl;
			break;
		case IF:
			cout << "| " << setw(6) << setprecision(2) << fixed << right << " |" << right << p[i].chuzel_met <<
				setw(10) << right << "|" << setw(5) << right << "|" << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << "| " << setw(6) << setprecision(2) << fixed << right << " |" <<
				setw(11) << right << "|" << setw(4) << right << p[i].pedag << "|" << endl;
			break;
		}
	}

	cout << "================================================================================" << endl;
	cout << endl;
}

void Average(Student* p, const int N)
{
	int f = 0;
	int m = 0;
	int pr = 0;
	int cm = 0;
	int pd = 0;

	double F = 0.;
	double M = 0.;
	double PR = 0.;
	double CM = 0.;
	double PD = 0.;

	for (int i = 0; i < N; i++)
	{
		f += p[i].fizuka;
		m += p[i].matem;
		pr += p[i].prog;
		cm += p[i].chuzel_met;
		pd += p[i].pedag;
		
	}

	F = f / N;
	M = m / N;
	PR = pr / N;
	CM = cm / N;
	PD = pd / N;

	cout << " Среднє арифметичне по таким предметам : " << endl;
	cout << " Фізика : " << F << endl;
	cout << " Математика : " << M << endl;
	cout << " Програмування : " << PR << endl;
	cout << " Числові методи : " << CM << endl;
	cout << " Педагогіка : " << PD << endl;
	cout << endl;
}

void Searchfiz(Student* p, const int N)
{
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		if (p[i].fizuka > 3)
			k++;
	}

	cout << "Кількість студентів, які отримали 5, або 4 з фізики : " << k << endl;

}
