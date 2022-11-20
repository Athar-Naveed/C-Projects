#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <mmsystem.h>
using namespace std;
class Metro
{
	string cnic,reg_by; int amount, fare_per_person, no_of_persons, ymount; time_t ct;
public:

	Metro() :cnic(""), reg_by(""), ct(0), amount(0), fare_per_person(20), no_of_persons(0), ymount(0) {}
	string getcnic() { return cnic; }
	int getamount() { return amount; }
	int getper() { return no_of_persons; }
	void setamount(int am) { amount += am; }
	void setnoper(int noper) { ymount = noper * fare_per_person; }
	int getnoper() {
		amount -= ymount;
		return ymount;
	}
	int getfpp() { return fare_per_person; }
	void settime() {
		ct = time(0);
		ctime(&ct);
	}
	string gettime() { return ctime(&ct); }
	string getreg() { return reg_by; }
	void welcome() {
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}for (int i = 0; i < 30; i++) {
			cout << "=";
		}cout << "\n";
		cout << "\t\t\t\t\t   Welcome to Metro Service \t\t\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}
		for (int i = 0; i < 30; i++)
		{
			cout << "=";
		}cout << endl;
	}
	void awelcome() {
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}for (int i = 0; i < 43; i++) {
			cout << "=";
		}cout << "\n";
		cout << "\t\t\t\t\t   Welcome to Metro Services (Admin Panel) \t\t\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}
		for (int i = 0; i < 43; i++)
		{
			cout << "=";
		}cout << endl;
	}
	void info(string cn) {
		cnic = cn;
		cout << "Please enter user`s amount: "; cin >> amount;
	}

	void display() {
		cout << "Your current amount is: " << amount;
	}
	void want(string cn, string reg) {
		cnic = cn;
		this->reg_by = reg;
	}
};
int main() {
	Metro m;
	int key;
	m.welcome();
	do
	{
	a:	cout << "1. Admin Panel \n2. Scan Card \n";
		cout << "Please choose your option: "; cin >> key;
		if (key == 1)
		{
			system("cls");
			m.awelcome();
			int k;
			cout << "1. User Registration \n2. Update Amount \n3. User travel record \n";
			cout << "4. Wanted List \n";
			cout << "Please choose your option: "; cin >> k;
			if (k == 1)
			{
				string cn; int count = 0;
				system("cls");
				m.awelcome();
				cout << "Please enter users CNIC: "; cin >> cn;
				ifstream f("E:\\Metro Project\\reg_users.dat");
				while (f.read((char*)&m, sizeof(m)))
				{
					if (cn == m.getcnic()) {
						cout << "CNIC already exists. \n";
						Sleep(3000);
						system("cls");
						m.welcome();
						count++;
					}
				}
				f.close();
				if (count == 0)
				{
					m.info(cn);
					ofstream u("E:\\Metro Project\\reg_users.dat", ios::app);
					u.write((char*)&m, sizeof(m));
					u.close();
					cout << "User Registered. \n";
					Sleep(3000);
					system("cls");
					m.welcome();
				}
				else { goto a; }

			}
			else if (k == 2) {
				system("cls");
				m.welcome();
				string cn; int am, count = 0;
				cout << "Please enter users CNIC: "; cin >> cn;
				ifstream f("E:\\Metro Project\\reg_users.dat");
				while (f.read((char*)&m, sizeof(m)))
				{
					if (cn == m.getcnic()) {
						cout << "Users current amount is: " << m.getamount() << endl;
						cout << "Please enter new amount: "; cin >> am;
						ofstream u("E:\\Metro Project\\reg_users1.dat");
						m.setamount(am);
						u.write((char*)&m, sizeof(m));
						ifstream f("E:\\Metro Project\\reg_users.dat");
						while (f.read((char*)&m, sizeof(m))) {
							u.write((char*)&m, sizeof(m));
						}u.close(); count++;
					}
					else { cout << "Record not found. \n"; }
				}f.close();
				Sleep(3000);
				if (count >= 1)
				{
					remove("E:\\Metro Project\\reg_users.dat");
					rename("E:\\Metro Project\\reg_users1.dat", "E:\\Metro Project\\reg_users.dat");
				}
			}
			else if (k == 3) {
				system("cls");
				m.awelcome();
				string cn;
			e:cout << "Please enter users CNIC: "; cin >> cn;
				if (cn.length() == 13) {
					ifstream f("E:\\Metro Project\\travelled.dat");
					while (f.read((char*)&m, sizeof(m)))
					{
						if (cn == m.getcnic()) {
							cout << "Users amount is: " << m.getamount() << endl;
							cout << "No. of passengers travelled: " << (m.getnoper() / 20) << endl;
							cout << "Time and Date at which user tavelled: " << m.gettime() << endl;
						}
						else { cout << "Travel Record not found. \n"; }
					}f.close();
					char opt;
					cout << "Press any key to continue: ";
					if (cin >> opt)
					{
						system("cls");
						m.welcome();
						goto a;
					}
					else { goto a; }
				}
				else {
					cout << "CNIC can`t be more or less than 13. \n";
					goto e;
				}
			}
			else if (k == 4) {
				system("cls");
				m.awelcome();
				int opt;
				cout << "1. See Wanted List \n2. Add Card to Wanted List \n3. Remove Card from Wanted List \n";
				cin >> opt;
				if (opt == 1)
				{
					int i = 1; char op;
					system("cls");
					m.awelcome();
					ifstream d("E:\\Metro Project\\wanted.dat");
					d.seekg(0, ios::end);
					int file_size = d.tellg();
					if (file_size != 0)
					{
						ifstream d("E:\\Metro Project\\wanted.dat");
						cout << "=======================================================================================\n";
						cout << "Sr. no. \t\t\t Wanted CNIC \t\t\t Registered as Wanted by \n\n";
						while (d.read((char*)&m, sizeof(m))) {
							cout << i++ << " \t\t\t\t " << m.getcnic() << " \t\t\t\t " << m.getreg() << endl << endl;
							cout << "=======================================================================================\n";
						}
					}
					else {
						cout << "\nYeah!! Not a Single Wanted Person.. \n";
					}
					d.close();
					cout << "Press any key to exit: ";
					if (cin >> op)
					{
						system("cls");
						m.welcome();
					}
				}
				else if (opt == 2) {
					string cn,reg_by;
					cout << "Please enter Wanted CNIC: "; cin >> cn;
					if (cn.length() == 13)
					{
						cout << "Please enter the CNIC of the person, who wants the card (Even if it is police): ";
						cin >> reg_by;
						m.want(cn,reg_by);
						ofstream w("E:\\Metro Project\\wanted.dat", ios::app);
						w.write((char*)&m, sizeof(m));
						cout << "CNIC entered in wanted list. \n";
						w.close();
					}
					else { cout << "CNIC can`t be more or less than 13 digits. \n"; }
					Sleep(3000);
					system("cls");
					m.welcome();
				}
				else if (opt == 3) {
					string cn; char op; int count = 0;
				f:cout << "Please enter CNIC you want to remove: "; cin >> cn;
					ifstream d("E:\\Metro Project\\wanted.dat");
					while (d.read((char*)&m, sizeof(m)))
					{
						if (cn == m.getcnic()) {
							cout << "CNIC found. \n";
							cout << "Do you really want to remove it? (y/n) "; cin >> op;
							if (op == 'y')
							{
								ofstream r("E:\\Metro Project\\wanted1.dat");
								ifstream d("E:\\Metro Project\\wanted.dat");
								while (d.read((char*)&m, sizeof(m)))
								{
									if (cn != m.getcnic()) {
										r.write((char*)&m, sizeof(m));
									}
								}r.close(); count++;
							}
							else { goto a; }
						}
						else {
							cout << "CNIC not found. \n";
							cout << "Do you want to try again? (y/n) "; cin >> op;
							if (op == 'y') {
								goto f;
							}
							else { goto a; }
						}
					}d.close();
					system("cls");
					m.welcome();
					if (count >= 1)
					{
						remove("E:\\Metro Project\\wanted.dat");
						rename("E:\\Metro Project\\wanted1.dat", "E:\\Metro Project\\wanted.dat");
					}
				}
			}
		}
		else if (key == 2) {
			string cn; int count = 0, noper, val, val1;
			cout << "Please enter your CNIC: "; cin >> cn;
			ifstream d("E:\\Metro Project\\wanted.dat");
			while (d.read((char*)&m,sizeof(m)))
			{
				if(cn != m.getcnic()){
					ifstream f("E:\\Metro Project\\reg_users.dat");
					while (f.read((char*)&m, sizeof(m)))
					{
						if (cn == m.getcnic()) {
							ofstream u("E:\\Metro Project\\travelled.dat", ios::app);
							cout << "Your current amount is: " << m.getamount() << endl;
							val = m.getamount();
							cout << "Please enter number of passengers (including you, if not, enter 1): "; cin >> noper;
							m.setnoper(noper);
							if (val >= (m.getfpp() * noper) && val != 0)
							{
								val1 = val - m.getnoper();
								ofstream d("E:\\Metro Project\\reg_users1.dat");
								cout << "Your new amount is: " << val1 << endl;
								m.settime();
								u.write((char*)&m, sizeof(m));
								u.close();
								for (int i = 1; i < noper + 4; i++)
								{
									cout << "Your gate will remain open for: ";
									cout << i << "s"; Sleep(1000); system("cls"); m.welcome();
								}
								d.write((char*)&m, sizeof(m));
								if (cn != m.getcnic())
								{
									d.write((char*)&m, sizeof(m));
								}d.close(); count++;
							}
							else {
								cout << "Please recharge your account. \n"; Sleep(3000);
							}
						}
						else {
							cout << "Your card couldn`t be scanned.\n";
							Sleep(3000);
						}
					}f.close();
					system("cls");
					m.welcome();
					if (count >= 1)
					{
						remove("E:\\Metro Project\\reg_users.dat");
						rename("E:\\Metro Project\\reg_users1.dat", "E:\\Metro Project\\reg_users.dat");
					}
				}
				else {
					cout << "Pakry gaye. \n";
					PlaySound(TEXT("E:\\Metro Project\\virus_found.wav"), NULL, SND_SYNC);
					system("cls");
					m.welcome();
				}
			}
			
		}
	} while (key != 0);
	system("cls");
	m.welcome();
	cout << "\n\t\t\t\t\t||Metro Service Ended Here|| \t\t\t\t\n";
	exit(0);
}