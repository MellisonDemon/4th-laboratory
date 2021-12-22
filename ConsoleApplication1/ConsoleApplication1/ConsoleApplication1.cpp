#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//===1 ВВОД ТЕКСТА==//

	char text[1000];
	int punct[11] = { 33, 34, 39, 40, 41, 44, 45, 59, 59, 63, 96 };
	cout << "Введите текст: ";
	cin.getline(text, 1000, '\n');
	if (int(text[strlen(text) - 1]) != 46)
	{
		cout << "Ошибка. Перезапустите программу и поставьте точку в конце строки." << endl;
	}
	else
	{
		cout << "Текст для работы: ";
		for (int i = 0; i < strlen(text); i++)
		{
			cout << text[i];
		}
		cout << endl;

		//===2 ПРАВКА ТЕКСТА==//

		//2.1 лишние пробелы.
		for (int i = 0; i < strlen(text); i++)
		{
			if (int(text[i]) == 32)
			{
				while (text[i] == text[i + 1])
				{
					for (int j = i + 1; j < strlen(text); j++)
					{
						text[j] = text[j + 1];
					}
				}
			}
		}
		cout << "Текст без лишних пробелов: ";
		for (int i = 0; i < strlen(text); i++)
		{
			cout << text[i];
		}
		cout << endl;

		//2.2 лишние знаки.
		for (int i = 0; i < strlen(text); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (int(text[i]) == punct[j])
				{
					while (int(text[i]) == int(text[i + 1]))
					{
						for (int k = i + 1; k < strlen(text); k++)
						{
							text[k] = text[k + 1];
						}
					}
				}
			}
		}

		for (int i = 0; i < strlen(text); i++)
		{
			if (int(text[i]) == 46)
			{
				if (int(text[i]) == int(text[i + 1]) && int(text[i]) == int(text[i + 2]))
				{
					i += 3;
				}
				else
				{
					if (int(text[i]) == int(text[i + 1]))
					{
						for (int l = i + 1; l < strlen(text); l++)
						{
							text[l] = text[l + 1];
						}
					}
				}
			}
		}

		for (int i = 0; i < strlen(text); i++)
		{
			if (int(text[i]) == 46)
			{
				if (int(text[i]) == int(text[i + 1]) && int(text[i]) == int(text[i + 2]) && int(text[i]) == int(text[i + 3]))
				{
					while (int(text[i + 3]) != 32)
					{
						for (int l = i + 1; l < strlen(text); l++)
						{
							text[l] = text[l + 1];
						}
					}
				}
			}
		}
		cout << "Текст без лишних знаков препинания: ";
		for (int i = 0; i < strlen(text); i++)
		{
			cout << text[i];
		}
		cout << endl;

		//2.3 регистр.
		if (-33 < int(text[0]) && int(text[0]) < 0)
		{
			text[0] = char(int(text[0]) - 32);
		}

		for (int i = 1; i < strlen(text); i++)
		{
			if (int(text[i]) < -32)
			{
				text[i] = char(int(text[i]) + 32);
			}
		}

		for (int i = 2; i < strlen(text); i++)
		{
			if ((int(text[i - 2]) == 33 || int(text[i - 2]) == 63 || int(text[i - 2]) == 46) && (-33 < int(text[i])) && (int(text[i]) < 0))
			{
				text[i] = char(int(text[i]) - 32);
			}
		}
		cout << "Текст с исправленным регистром букв: ";
		for (int i = 0; i < strlen(text); i++)
		{
			cout << text[i];
		}
		cout << endl;

		//===3 ПОВОРОТ==//
		//(1) Вывести на экран слова последовательности в обратном порядке.
		int lengthWord = 0;

		cout << "Строка, с напечатанными в обратном порядке словами: ";
		for (int i = 0; i < strlen(text); i++)
		{
			if (int(text[i]) < 0 || (47 < int(text[i]) && int(text[i]) < 58))
			{
				lengthWord += 1;
			}
			else
			{
				if (lengthWord > 0)
				{
					for (int j = i - 1; j > i - lengthWord - 1; j--)
					{
						cout << text[j];
					}
				}
				cout << text[i];
				lengthWord = 0;
			}

		}
		cout << endl;

		//===4 СТРОЧНЫЕ БУКВЫ==//
		//(1)Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.

		cout << "Строка, каждое слово в которой начинается с большой буквы: ";
		cout << text[0];
		for (int i = 1; i < strlen(text); i++)
		{
			if (int(text[i - 1]) == 32 && int(text[i]) < 0 && -33 < int(text[i]))
			{
				cout << char(int(text[i]) - 32);
			}
			else
			{
				cout << text[i];
			}
		}
		cout << endl;


		//===5 ПОИСК ПОДСТРОКИ==//
		//(1)Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.
		char text1[1000];
		cout << "Введите подстроку, которую хотите найти: ";
		cin.getline(text1, 1000, '\n');

		cout << "Позиции текста, которые содержат введённую Вами подстроку (считая, что позиция первой буквы – 0): ";
		for (int i = strlen(text1) - 1; i < strlen(text); i++)
		{
			for (int j = strlen(text1) - 1; j > -1; j--)
			{
				for (int k = i; k > i - strlen(text1); k--)
				{
				repeat:
					if (int(text[k]) == int(text1[j]))
					{
						if (j == 0)
						{
							cout << k << " ";
						}
						else
						{
							k--;
							j--;
							goto repeat;
						}
					}
					else
					{
						goto skip;
					}
				}
			skip:
				break;
			}

		}
		cout << endl;
	}
	system("pause");
	return 0;
}