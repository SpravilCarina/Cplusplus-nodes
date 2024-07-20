#include<iostream>
#include<conio.h>

using namespace std;

class A
{
private:
	int m;
public:
	friend class B;
	friend void afisare();
};

class B
{
public:
	void afisare()
	{
		A a;
		a.m = 255;
		cout << "este prietena si poate sa ii acceseze private" << a.m;
	}
};

void afisare()
{
	A a;
	a.m = 300;
	cout << "nu este membru dar are acces" << a.m;

}

int main()
{
	B b;
	b.afisare();
	afisare();
	getch();
	return 0;
}