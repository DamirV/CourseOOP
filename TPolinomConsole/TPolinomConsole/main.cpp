#include "TPolinom.h"


void main()
{
	setlocale(LC_ALL, "Russian");

	TPolinom tp1;
	TPolinom tp2;
	TPolinom tp3;

	TMonom tm;

	int flag;

	while (1) {

		system("CLS");

		cout<<  "          МЕНЮ              \n\n"
			 << "(1) Работа с полиномом №1\n"
		     << "(2) Работа с полиномом №2\n"
			 << "(3) Работа с полиномами №1 и №2\n";
			

		cout<<"(0) Завершить работу\n" << endl;

		cout << "Полином №1 = " << tp1 << endl;
		cout << "Полином №2 = " << tp2 << endl;
		cout << "Результат работы над полиномами = "<< tp3 <<endl << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:

			while (1)
			{

				system("CLS");

				cout << "         РАБОТА С ПОЛИНОМОМ №1\n" << endl
					<< "(1) Прибавить моном к полиному №1\n"
					<< "(2) Умножить полином №1 на моном\n"
					<< "(3) Прибавить к полиному №1 полином №2\n"
					<< "(4) Домножить полином №2 на полином №1\n"
					<< "(5) Очистить полином №1\n"
					<< "(0) Вернуться в МЕНЮ\n" << endl;

				cout << "Полином №1 = " << tp1 << endl;
				cout << "Полином №2 = " << tp2 << endl;
				cout << "Результат работы над полиномами = " << tp3 << endl << endl;

				cin >> flag;

				switch (flag)
				{
				case 1:

					cout << "Прибавить моном к полиному №1\n";
					cout << "Введите моном: ";
					cin >> tm;
					tp1 += tm;
					break;

				case 2:

					cout << "Умножить полином №1 на моном\n";
					cout << "Введите моном: ";
					cin >> tm;
					tp1 = tp1 * tm;
					break;

					case 3:

						cout << "Прибавить к полиному №1 полином №2?\n";
						cout << "(1) да\n(!1) нет\n";
						cin >> flag;

						if (flag == 1)
						{
							tp1 = tp1+tp2;
						}
						break;

						break;


					case 4:

						cout << "Домножить полином №2 на полином №1?\n";
						cout << "(1) да\n(!1) нет\n";
						cin >> flag;

						if (flag == 1)
						{
							tp1 = tp1*tp2;
						}
						break;


				case 5:


					cout << "Очимтить полином №1?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp1.ClrTPolinom();
					}

					break;

				default:

					break;

				}


				if (flag == 0)
				{
					break;
				}
			}

			break;

		case 2:

			while (1)
			{

				system("CLS");

				cout << "         РАБОТА С ПОЛИНОМОМ №2\n" << endl
					<< "(1) Прибавить моном к полиному №2\n"
					<< "(2) Умножить полином №2 на моном\n"
					<< "(3) Прибавить к полиному №2 полином №1\n"
					<< "(4) Домножить полином №1 на полином №2\n"
					<< "(5) Очистить полином №2\n"
					<< "(0) Вернуться в МЕНЮ\n" << endl;

				cout << "Полином №1 = " << tp1 << endl;
				cout << "Полином №2 = " << tp2 << endl;
				cout << "Результат работы над полиномами = " << tp3 << endl << endl;

				cin >> flag;

				switch (flag)
				{
				case 1:

					cout << "Прибавить моном к полиному №2\n";
					cout << "Введите моном: ";
					cin >> tm;
					tp2 += tm;
					break;

				case 2:

					cout << "Умножить полином №2 на моном\n";
					cout << "Введите моном: ";
					cin >> tm;
					tp2 = tp2 * tm;
					break;


				case 3:

					cout << "Прибавить к полиному №2 полином №1?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp2 = tp2 + tp1;
					}
					break;

					break;


				case 4:

					cout << "Домножить полином №1 на полином №2?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp2 = tp1*tp2;
					}
					break;


				case 5:


					cout << "Очимтить полином №2?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp2.ClrTPolinom();
					}

					break;

				default:

					break;

				}


				if (flag == 0)
				{
					break;
				}
			}

			break;

		case 3:
			
			while (1)
			{

				system("CLS");

				cout << "         РАБОТА С ПОЛИНОМОМАМИ №1 и №2\n" << endl
					<< "(1) Сложить полиномы №1 и №2\n"
					<< "(2) Перемножить полиномы №1 и №2\n"
					<< "(3) Очистить результат\n"
					<< "(0) Вернуться в МЕНЮ\n" << endl;

				cout << "Полином №1 = " << tp1 << endl;
				cout << "Полином №2 = " << tp2 << endl;
				cout << "Результат работы над полиномами = " << tp3 << endl << endl;

				cin >> flag;

				switch (flag)
				{
				case 1:

					cout << "Сложить полиномы №1 и №2 ?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp3 = tp1 + tp2;
					}
					
					break;

				case 2:

					cout << "Перемножить полиномы №1 и №2 ?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp3 = tp1 * tp2;
					}

					break;


				case 3:
					cout << "Очистить результат?\n";
					cout << "(1) да\n(!1) нет\n";
					cin >> flag;

					if (flag == 1)
					{
						tp3.ClrTPolinom();
					}

					break;

				default:

					break;

				}


				if (flag == 0)
				{
					break;
				}
			}

			break;

		case 0:

			return;


		default:
			break;
		
		}

	}
		
		


		



}