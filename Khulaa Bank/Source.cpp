#include "Header.h"
int main() {
	Khulaa k;
	k.welcome();
	int num;
	do
	{
		cout << "1. Khulaa Admin \n2. Khulaa \n3. Press 0: To Exit \n";
		cout << "Please choose your option: "; cin >> num;
		if (num == 1)
		{
			int opt;
			system("cls");
			k.awelcome();
			cout << "1. Register Admin \n2. Update List \n";
			cout << "Please enter your option here: "; cin >> opt;
			if (opt == 1)
			{
				k.info();
				ofstream f("E:\\Khulaa Bank\\Admin Registration.dat", ios::app);
				f.write((char*)&k, sizeof(k));
				f.close();
				cout << "\nAdmin Registered. \n";
				Sleep(1000);
				system("cls");
				k.welcome();
			}
			else if (opt == 2) {
				system("cls");
				k.awelcome();
				string nam; int pass;
				cout << "Please enter your name: "; cin >> nam;
				cout << "Please enter your password: "; cin >> pass;
				ifstream dd("E:\\Khulaa Bank\\Admin Registration.dat");
				while (dd.read((char*)&k, sizeof(k)))
				{
					if (nam == k.getname() && pass == k.getpass()) {
						ifstream d("E:\\Khulaa Bank\\Available Amount.dat");
						while (d.read((char*)&k, sizeof(k)))
						{
							cout << "Remaining number of ten notes: " << k.geten() << endl;
							cout << "Remaining number of twenty notes: " << k.getwenty() << endl;
							cout << "Remaining number of fifty notes: " << k.getfifty() << endl;
							cout << "Remaining number of hundred notes: " << k.gethund() << endl;
							cout << "Remaining number of five hundred notes: " << k.getfhund() << endl;
							cout << "Remaining number of thousand notes: " << k.gethan() << endl;
						}d.close();
						cout << "======================================================\n";
						k.update_list();
						ofstream w("E:\\Khulaa Bank\\Available Amount.dat");
						w.write((char*)&k, sizeof(k));
						w.close();
					}
				}dd.close();
			}

		}
		else if (num == 2) {
			system("cls");
			k.welcome();
			ifstream d("E:\\Khulaa Bank\\Available Amount.dat");
			while (d.read((char*)&k, sizeof(k))) {
				cout << "Remaining number of ten notes: " << k.geten() << endl;
				cout << "Remaining number of twenty notes: " << k.getwenty() << endl;
				cout << "Remaining number of fifty notes: " << k.getfifty() << endl;
				cout << "Remaining number of hundred notes: " << k.gethund() << endl;
				cout << "Remaining number of five hundred notes: " << k.getfhund() << endl;
				cout << "Remaining number of thousand notes: " << k.gethan() << endl;
			}d.close();
			cout << "======================================================\n";
			k.amount();
			ofstream kk("E:\\Khulaa Bank\\Available Amount.dat");
			kk.write((char*)&k, sizeof(k));
			kk.close();
			system("cls");
			k.welcome();
		}


	} while (num != 0);
	system("cls");
	k.welcome();
	cout << "\n\t\t\t\t   || Program Execution ended successfully. || \t\t\t\t\t\n";
	exit(0);
}