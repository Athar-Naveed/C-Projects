#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
using namespace std;
class Khulaa {
	int ten, twenty, fifty, hund, f_hund, than, pass, n1, n2, n3, n4, n5, n6, am, sum; string name;
public:
	Khulaa() : ten(0), twenty(0), fifty(0), hund(0), f_hund(0), than(0), pass(0),
		n1(0), n2(0), n3(0), n4(0), n5(0), n6(0), am(0), sum(0), name("") {}
	string getname() { return name; }
	int getpass() { return pass; }
	int geten() { return ten; }
	int getwenty() { return twenty; }
	int getfifty() { return fifty; }
	int gethund() { return hund; }
	int getfhund() { return f_hund; }
	int gethan() { return than; }
	void welcome() {
		cout << "\t\t\t\t\t";
		for (int i = 0; i < 30; i++)
		{
			cout << "=";
		}cout << "\n";
		time_t ct = time(0);
		cout << "\t\t\t\t\t    Welcome to Khulaa Bank \t" << ctime(&ct);
		cout << "\t\t\t\t\t";
		for (int i = 0; i < 30; i++)
		{
			cout << "=";
		}cout << "\n";
	}
	void awelcome() {
		cout << "\t\t\t\t\t";
		for (int i = 0; i < 40; i++)
		{
			cout << "=";
		}cout << "\n";
		time_t ct = time(0);
		cout << "\t\t\t\t\tWelcome to Khulaa Bank (Admin Panel) \t" << ctime(&ct);
		cout << "\t\t\t\t\t";
		for (int i = 0; i < 40; i++)
		{
			cout << "=";
		}cout << "\n";
	}
	void info() {
		cout << "Please enter your name: "; cin >> name;
		cout << "Please enter your password: "; cin >> pass;
	}
	void update_list() {
		cout << "Please enter number of ten notes: "; cin >> n1;
		cout << "Please enter number of twenty notes: "; cin >> n2;
		cout << "Please enter number of fifty notes: "; cin >> n3;
		cout << "Please enter number of hundred notes: "; cin >> n4;
		cout << "Please enter number of five hundred notes: "; cin >> n5;
		cout << "Please enter number of thousand notes: "; cin >> n6;
		ten += n1; twenty += n2; fifty += n3; hund += n4; f_hund += n5; than += n6;
	}
	void withdraw() {
	e:cout << "Please enter number of ten notes: "; cin >> n1;
		cout << "Please enter number of twenty notes: "; cin >> n2;
		cout << "Please enter number of fifty notes: "; cin >> n3;
		cout << "Please enter number of hundred notes: "; cin >> n4;
		cout << "Please enter number of five hundred notes: "; cin >> n5;
		cout << "Please enter number of thousand notes: "; cin >> n6;
		sum = (n1 * 10) + (n2 * 20) + (n3 * 50) + (n4 * 100) + (n5 * 500) + (n6 * 1000);
		if (sum > am) {
			cout << "Amount being withdrawn is more than the amount deposited.\n";
			goto e;
		}
		else {
			cout << "Amount is available to be collected.\n";
			ten -= n1; twenty -= n2; fifty -= n3; hund -= n4; f_hund -= n5; than -= n6;
			Sleep(2000);
		}
	}
	void amount() {
		cout << "Please enter the amount you have deposited: "; cin >> am;
		cout << "Amount Verified.\n";
		withdraw();
	}
};
