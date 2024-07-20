#include<iostream>
#include<conio.h>

using namespace std;

class Nod
{
private:
	int numar;
	Nod* urm;
public:
	void adaugare_in_fata(Nod*& nou, int valoare);
	void adaugare_in_spate(Nod*& prim, int valoare);
	void adaugare_pe_parcurs(Nod*& prim, int valoare);
	friend void stergere_nod(Nod* nod, int );
	void afisare(Nod *);
};

Nod * ultim, * nod;

void Nod::adaugare_in_fata(Nod*& prim, int valoare)
{
	Nod* nod1;
	//daca lista este vida (prim==0) se aloca primul Nod
	if (!prim)
	{
		prim = new Nod;
		cout << "informatie Nod= ";
		cin >> prim->numar;
		//la creare primul si ultimul Nod vor fi identici
		ultim = prim;
		ultim->urm = NULL;

	}

	else
	{
		//se aloca un nou Nod
		nod1 = new Nod;
		//se completeaza campul informatie utila
		cout << "Informatie Nod= ";
		//se adauga inaintea primului nod
		cin >> nod1->numar;
		//noul nod devine primul
		nod1->urm = prim;
		prim = nod1;
	}
}

void Nod:: adaugare_in_spate(Nod*& prim, int valoare)
{
	Nod* nod1;
	if (!prim)
	{		//daca lista este vida (prim==0) se aloca primul Nod
		prim = new Nod;
		cout << "informatie Nod= ";
		cin >> prim->numar;
		//la creare primul si ultimul Nod vor fi identici
		ultim = prim;
		ultim->urm = NULL;
	}
	//altfel se adauga un nou element la sfarsit
	else
	{
		//se aloca un nou Nod
		nod1 = new Nod;
		//se completeaza campul informatie utila
		cout << "informatie Nod= ";
		cin >> nod1->numar;
		//se adauga dupa ultimul Nod
		ultim->urm = nod1;
		//noul nod devine ultimul
		ultim = nod1;
	}
	ultim->urm = NULL;
}

void Nod::adaugare_pe_parcurs(Nod*& prim, int valoare)
{
	Nod* nod2, * nod1;
	cout<< "informatie Nod= ";
	cin >> valoare;
	if (!prim)
	{
		prim = new Nod;
		prim->numar = valoare;
		ultim = prim;
		ultim->urm = NULL;
	}
	else if (prim->numar>valoare)
	{
		nod2 = new Nod;
		nod2->numar = valoare;
		nod2->urm = prim;
		prim = nod2;
	}
	else
	{
		nod1 = prim;
		while (nod1->urm != NULL && nod1->urm->numar < valoare)
			nod1 = nod1->urm;
		nod2 = new Nod;
		nod2->numar = valoare;
		nod2->urm = nod1->urm;
		nod1->urm = nod2;
	}
}

void stergere_nod(Nod* nod, int valoare)
{
	Nod* nod1, * nod2;
	cout << "ce valoare? ";
	cin >> valoare;
	if (nod->numar == valoare)
	{
		nod2 = nod;
		nod = nod->urm;
	}
	else
	{
		nod1 = nod;
		while (nod1->urm->numar != valoare)
			nod1 = nod1->urm;
		nod2 = nod1->urm;
		nod1->urm = nod2->urm;
		if (nod2 == ultim)
			ultim = nod1;
	}
	delete nod2;
}

void Nod::afisare(Nod* nod1)
{
	while (nod1)
	{
		cout << nod1->numar << " ";
		nod1 = nod1->urm;
	}
	cout << endl;
}

int main()
{
	int i,caz;
	Nod lista;
	while (true)
	{
		cout << "ce doresti? " << endl;
		cout << "0. iesire" << endl;
		cout << "1. adaugare_in_fata" << endl;
		cout << "2. adaugare_in_spate" << endl;
		cout << "3. adaugare_pe_parcurs" << endl;
		cout << "4. stergere_nod" << endl;
		cout << "5. afisare" << endl;
		cin >> caz;

		switch (caz)
		{
		case 0:
			exit(0);
			break;
		case 1:
			for(i=0;i<3;i++)
				lista.adaugare_in_fata(nod, i);
			break;
		case 2:
			for (i = 0; i < 3; i++)
				lista.adaugare_in_spate(nod, i);
			break;
		case 3:
			for (i = 0; i < 3; i++)
				lista.adaugare_pe_parcurs(nod, i);
			break;
		case 4:
			stergere_nod(nod, 3);
			break;
		case 5:
			lista.afisare(nod);
			break;
		default:
			cout << "optiune gresita";
			break;
		}
	}

	return 0;
}