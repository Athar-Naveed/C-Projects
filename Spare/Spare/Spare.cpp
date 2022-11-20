#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class Password {
	string name; char pass[10]; int count,co,coun; 
public:
	Password():name(""),pass(), count(0),co(0),coun(0) {}
	string getname() { return name; }
	void getpass(char pa[10]) {
		for (int i = 0; i < count; i++)
		{
			for (int j = i; j < i; j++)
			{
				if (pa[i] == pass[j]) {
				cout << "\nHere password matched. " << co++ << endl;
				}
				else if (pa[i] != pass[j]) {
					cout << "\nHere password doesn`t matched. " << coun++ << endl;
				}
			}
		}
		 }
	void info() {
		cout << "Please enter your name: "; cin >> name;
		cout << "Please enter your password (Range is 10): ";
		for (int i = 0; (pass[i] = _getch()) != 13; i++)
		{
			cout << "*";
			count++;
		}
	}
};
int main() {
	Password p;
	/*p.info();
	ofstream d("E:\\Spare\\password.dat", ios::app);
	d.write((char*)&p, sizeof(p));
	d.close();*/

	string na; char pa[10];
	cout << "Please enter your name to access your password: "; cin >> na;
	ifstream r("E:\\Spare\\password.dat");
	while (r.read((char*)&p,sizeof(p)))
	{
		if (na == p.getname())
		{
			cout << "Please enter your password: ";
			for (int i = 0; (pa[i] = _getch()) != 13; i++)
			{
				cout << "*";
			}
		p.getpass(pa);
		}
		else { cout << "Name not found. \n"; }
	}
	r.close();
	exit(0);
}

