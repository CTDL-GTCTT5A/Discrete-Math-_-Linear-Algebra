#include<iostream>
#include"KarnaughMap/McCluskeyAlgorithm.h"
#include"Vector/Vector.h"
#include"CalculateMatrix/Matrix.h"

using namespace std;



int main()
{
	McCluskeyAlgorithm mc;
	Vector vt;
	Matrix mt;

	int choose;


	while (1) {
		system("cls");
		cout << "_______________________________________________\n\n"
			<< " +++++++++++++++ MAIN-MENU +++++++++++++++ \n"
			<< "\t1. Solve KarnaughMap Problem.\n"
			<< "\t2. Solve Vector Problem.\n"
			<< "\t3. Solve Matrix Problem.\n"
			<< "\t0. To exit.\n"
			<< "_________________________________________________\n"
			<< "\t+ You choose ? ";

		cin >> choose;

		switch (choose)
		{
			case 0:
			{
				cout << "\tThank for using !\n";
				return 0;
			}
			case 1:
			{
				mc.Main_Menu();
				break;
			}
			case 2:
			{
				vt.main_menu();
				break;
			}
			case 3:
			{
				mt.MainMenu();
				break;
			}
		}
	}
	

	system("pause");
	return 0;
}