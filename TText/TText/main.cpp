#include "TText.h"
#include "TLink.h"
//#include <system.h>
TMem TLink::mem;

void main()
{
	setlocale(LC_ALL, "Russian");
	char flag;
	TText txt;
	TLink:: InitMem(100);
	txt.Read("filer.txt");
	txt.Reset();

	while (true)
	{
		system("cls");
		cout << "          MAIN" << endl;
		cout << "__________________________________________________________________________" << endl;
		cout << "(1)��������� �� ������; (2)������ � �������; (3)������ � �������; (0)�����";
		cout << endl;
		cout << "__________________________________________________________________________" << endl;

		txt.Print();
		cin >> flag;
		switch (flag)
		{
		case '1':
			while (true)
			{
				system("cls");
				cout << "       ��������� �� ������" << endl;
				cout << "____________________________________________________" << endl;
				cout << "(1)������; (2)����; (3)�����; (4)� ������; (0)� ����" << endl;
				cout << "____________________________________________________" << endl;
				txt.Print();
				cin >> flag;
				switch (flag)
				{
				case '1':
					txt.ToNext();
					break;
				case '2':
					txt.ToDown();
					break;
				case '3':
					txt.ToPrev();
					break;
				case '4':
					txt.ToFirst();
					break;
				}

				if (flag == '0')
				{
					break;
				}
			}
			break;

		case '2':
			while (true)
			{
				system("cls");
				cout << "       ������ � �������" << endl;
				cout << "______________________________________________________________________" << endl;
				cout << "(1)������� ��������� �������; (2)������� ���������� �������; (0)� ����" << endl;
				cout << "(3)�������� ��������� �������; (4)�������� ���������� �������;" << endl;
				cout << "(5)�������� ��������� ������; (6)�������� ���������� ������;" << endl;
				cout << "______________________________________________________________________" << endl;
				txt.Print();
				cin >> flag;
				switch (flag)
				{
				case '1':
					txt.DelNext();
					break;

				case '2':
					txt.DelDown();
					break;

				case '3':
					char tempchn[100];
					cin.getline(tempchn, 100);
					txt.InsNextLine(tempchn);
					break;

				case '4':
					char tempchd[100];
					cin.getline(tempchd, 100);
					txt.InsDownLine(tempchd);
					break;

					case '5':
						char tempchns[100];
						cin.getline(tempchd, 100);
						txt.InsNextSection(tempchd);
						break;

					case '6':
						char tempchds[100];
						cin.getline(tempchd, 100);
						txt.InsDownSection(tempchd);
						break;

				}
				if (flag == '0')
				{
					break;
				}

			}
			break;

		case '3':
			while (true)
			{
				system("cls");
				cout << "       ������ � �������" << endl;
				cout << "_______________________________________________________" << endl;
				cout << "(1)�������; (2)���������;(3)��������� ������; (0)� ����" << endl;
				cout << "_______________________________________________________" << endl;
				txt.Print();
				cin >> flag;
				switch (flag)
				{
				case '1':
					txt.Read("filer.txt");
					txt.Reset();
					break;

				case '2':
					txt.Save("files.txt");
					break;
				

				case '3':
					system("cls");
						
					TLink:: PrintFreeTLinks();
					TLink:: MemClr(txt);
					cout<<"__________________________________________________"<<endl;
					TLink:: PrintFreeTLinks();
				    system("pause");
					break;
				}
				if (flag == '0')
				{
					break;
				}
			}
			break;
		case '0':


			return;

		default:
			break;
		}


	}
}

