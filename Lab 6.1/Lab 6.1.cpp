
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct letters {
	double grade_of_the_letter; // оценка письма
	int ind_sender; // индекс отправителя
	char* surname_sender; // Фамилия отправителя
	char* name_sender; // Имя отправителя
	int ind_reciever; // Индекс получателя
	char* surname_reciever; // Фамилия получателя
	char* name_reciever; // Имя получателя
};

int getValueint()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		cin >> a;

		if (cin.fail()) { // если предыдущее извлечение оказалось неудачным,
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";

		}
		else // если всё хорошо, то возвращаем a
			return a;
	}
}

double getValuedouble()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		double a;
		cin >> a;

		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
		}
		else // если всё хорошо, то возвращаем a
			return a;
	}
}

char* getValuechar() {
	char* a = new char[10];
	cin >> a;
	return a;
}

void fun1(int i, letters* a) { // добавить новое письмо
	cout << "Введите оценку письма\t";
	a[i].grade_of_the_letter = getValuedouble();

	cout << "Введите индекс отправителя\t";
	a[i].ind_sender = getValueint();

	cout << "Введите фамилия отправителя\t";
	a[i].surname_sender = getValuechar();

	cout << "Введите имя отправителя\t";
	a[i].name_sender = getValuechar();

	cout << "Введите индекс получателя\t";
	a[i].ind_reciever = getValueint();

	cout << "Введите фамилия получателя\t";
	a[i].surname_reciever = getValuechar();

	cout << "Введите имя получателя\t";
	a[i].name_reciever = getValuechar();
	cout << "-------------------------------------------------------------------------------\n";
}

void fun2(int f, letters* a) { // распечатать информацию о письмах

	cout << "-------------------------------------------------------------------------------\n";

	cout << "Оценка письма" << setw(16) << a[f].grade_of_the_letter << endl; 
	cout << "Индекс отправителя" << setw(11) << a[f].ind_reciever << endl;
	cout << "Фамилия отправителя" << setw(10) << a[f].surname_sender << endl;
	cout << "Имя отправителя" << setw(14) << a[f].name_sender << endl;
	cout << "Индекс получателя" << setw(12) << a[f].ind_reciever << endl;
	cout << "Фамилия получателя" << setw(11) << a[f].surname_reciever << endl;
	cout << "Имя получателя" << setw(15) << a[f].surname_reciever << endl;
	cout << "-----------------------------------------------------------------------------\n";
	
}

void fun3 (int max,letters* a) { // найти все письма отправителя
	cout << "Введите Фамилию отправителя ";
	char* s = new char[10];
	s = getValuechar();
	for (int i = 0; i < max; i++)
	{
		if (strcmp(s, a[i].surname_sender) == 0) fun2(i, a);

	}
	delete[]s;
}

void fun4 (int max, letters* a) { // найти все письма с оценкой большей заданного
	cout << "Введите оценку ";
	double zxc = getValuedouble();
	for (int i = 0; i < max; i++)
	{
		if (zxc < a[i].grade_of_the_letter ) fun2(i, a);

	}
}



int main() {
	setlocale(0, "ru");
	// Вывод темы задания
	cout << "Тема задания:\nСоздать структуру letter и реализовать функции\n1)добавить новое письмо\n2)распечатать информацию о письме в табличном виде\n3)Найти все письма заданного отправителя(отправитель – это фамилия + имя) результат вывести на экран\n4)найти все письма с оценкой большей заданного, результат сортировать по алфавиту(по получателю), запомнить в массиве и вывести на экран";
	cout << "\n_______________________________________________________________________________________________\n";
	cout << "Введите количество писем ";
	int l = getValueint();
	while (l < 1) {
		cout << "Вы ввели некорректное число! Попробуйте еще раз ";
		l = getValueint();
	}
	letters* a = new letters[l];
	int current_letter = 0;
	cout << "Добавить новое письмо  .............................1\n";
	cout << "Распечатать информацию о письме  ...................2\n";
	cout << "Найти все письма отправителя  ......................3\n";
	cout << "Найти все письма с оценкой большей заданного  ......4\n";
	cout << "Распечатать все письма  ............................5\n";
	cout << "Выход из программы  ................................6\n";
	cout << ".....................................................\n";
	cout << "Введите номер функции ";
	
	int n = getValueint();
	while (n != 5) {
		switch (n)
		{
		case 1:
			if (current_letter < l) fun1(current_letter, a);
			else cout << "Превышен лимит писем\n";
			current_letter++;
			break;
		case 2:
			cout << "Введите номер письма ";
			int r;
			r = getValueint();
			r--;


			fun2(r,a);
			break;
		case 3:
			fun3(current_letter,a);
			break;
		case 4:
			fun4(current_letter,a);
			break;
		default:
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
			break;
		}
		cout << "Введите номер функции ";
		n = getValueint();
	}
	for (int i = 0; i < l; i++)
	{
		delete[]a[i].name_reciever;
		delete[]a[i].surname_reciever;

		delete[]a[i].name_sender;
		delete[]a[i].surname_sender;

	}
	delete[] a;
}