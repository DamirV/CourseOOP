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

		cout<<  "          ����              \n\n"
			 << "(1) ������ � ��������� �1\n"
		     << "(2) ������ � ��������� �2\n"
			 << "(3) ������ � ���������� �1 � �2\n";
			

		cout<<"(0) ��������� ������\n" << endl;

		cout << "������� �1 = " << tp1 << endl;
		cout << "������� �2 = " << tp2 << endl;
		cout << "��������� ������ ��� ���������� = "<< tp3 <<endl << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:

			while (1)
			{

				system("CLS");

				cout << "         ������ � ��������� �1\n" << endl
					<< "(1) ��������� ����� � �������� �1\n"
					<< "(2) �������� ������� �1 �� �����\n"
					<< "(3) ��������� � �������� �1 ������� �2\n"
					<< "(4) ��������� ������� �2 �� ������� �1\n"
					<< "(5) �������� ������� �1\n"
					<< "(0) ��������� � ����\n" << endl;

				cout << "������� �1 = " << tp1 << endl;
				cout << "������� �2 = " << tp2 << endl;
				cout << "��������� ������ ��� ���������� = " << tp3 << endl << endl;

				cin >> flag;

				switch (flag)
				{
				case 1:

					cout << "��������� ����� � �������� �1\n";
					cout << "������� �����: ";
					cin >> tm;
					tp1 += tm;
					break;

				case 2:

					cout << "�������� ������� �1 �� �����\n";
					cout << "������� �����: ";
					cin >> tm;
					tp1 = tp1 * tm;
					break;

					case 3:

						cout << "��������� � �������� �1 ������� �2?\n";
						cout << "(1) ��\n(!1) ���\n";
						cin >> flag;

						if (flag == 1)
						{
							tp1 = tp1+tp2;
						}
						break;

						break;


					case 4:

						cout << "��������� ������� �2 �� ������� �1?\n";
						cout << "(1) ��\n(!1) ���\n";
						cin >> flag;

						if (flag == 1)
						{
							tp1 = tp1*tp2;
						}
						break;


				case 5:


					cout << "�������� ������� �1?\n";
					cout << "(1) ��\n(!1) ���\n";
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

				cout << "         ������ � ��������� �2\n" << endl
					<< "(1) ��������� ����� � �������� �2\n"
					<< "(2) �������� ������� �2 �� �����\n"
					<< "(3) ��������� � �������� �2 ������� �1\n"
					<< "(4) ��������� ������� �1 �� ������� �2\n"
					<< "(5) �������� ������� �2\n"
					<< "(0) ��������� � ����\n" << endl;

				cout << "������� �1 = " << tp1 << endl;
				cout << "������� �2 = " << tp2 << endl;
				cout << "��������� ������ ��� ���������� = " << tp3 << endl << endl;

				cin >> flag;

				switch (flag)
				{
				case 1:

					cout << "��������� ����� � �������� �2\n";
					cout << "������� �����: ";
					cin >> tm;
					tp2 += tm;
					break;

				case 2:

					cout << "�������� ������� �2 �� �����\n";
					cout << "������� �����: ";
					cin >> tm;
					tp2 = tp2 * tm;
					break;


				case 3:

					cout << "��������� � �������� �2 ������� �1?\n";
					cout << "(1) ��\n(!1) ���\n";
					cin >> flag;

					if (flag == 1)
					{
						tp2 = tp2 + tp1;
					}
					break;

					break;


				case 4:

					cout << "��������� ������� �1 �� ������� �2?\n";
					cout << "(1) ��\n(!1) ���\n";
					cin >> flag;

					if (flag == 1)
					{
						tp2 = tp1*tp2;
					}
					break;


				case 5:


					cout << "�������� ������� �2?\n";
					cout << "(1) ��\n(!1) ���\n";
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

				cout << "         ������ � ������������ �1 � �2\n" << endl
					<< "(1) ������� �������� �1 � �2\n"
					<< "(2) ����������� �������� �1 � �2\n"
					<< "(3) �������� ���������\n"
					<< "(0) ��������� � ����\n" << endl;

				cout << "������� �1 = " << tp1 << endl;
				cout << "������� �2 = " << tp2 << endl;
				cout << "��������� ������ ��� ���������� = " << tp3 << endl << endl;

				cin >> flag;

				switch (flag)
				{
				case 1:

					cout << "������� �������� �1 � �2 ?\n";
					cout << "(1) ��\n(!1) ���\n";
					cin >> flag;

					if (flag == 1)
					{
						tp3 = tp1 + tp2;
					}
					
					break;

				case 2:

					cout << "����������� �������� �1 � �2 ?\n";
					cout << "(1) ��\n(!1) ���\n";
					cin >> flag;

					if (flag == 1)
					{
						tp3 = tp1 * tp2;
					}

					break;


				case 3:
					cout << "�������� ���������?\n";
					cout << "(1) ��\n(!1) ���\n";
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