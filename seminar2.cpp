#include <iostream>

using namespace std;

struct Tara {
	char* denumire;
	int nrLocuitori;
	string capitala;
	bool areIesireLaMare;
};

//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru 
//citirea unui vector

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume: " << pt->denumire << endl;
	cout << "Nr Locuitori: " << pt->nrLocuitori << endl;
	cout << "Capitala: " << pt->capitala << endl;
	cout << "Are iesire la mare: " << (pt->areIesireLaMare ? "Da" : "NU") << endl << endl;
	/*pt->areIesireLaMare) {
		cout << "Are iesire la mare "<< endl;
	}
	else {
		cout << "Nu are iesire la mare " << endl;
	}
	// operator ternar:
	pt->areIesireLaMare ? "Da" : "NU";*/
}


Tara* citirePointerLaTara() {
	Tara* p = new Tara();
	cout << "Capitala: ";
	cin >> p->capitala;
	cout << "Denumire: ";
	char buffer[100];
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);
	cout << "Nr locuitori: ";
	cin >> p->nrLocuitori;
	cout << "Are iesire la mare? (0-NU; 1-DA)";
	cin >> p->areIesireLaMare;

	return p;
}

int main() {

	Tara tara;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nrLocuitori = 200;

	afisarePointerLaTara(pTara);

	delete[]pTara->denumire;
	delete pTara;

	/* Tarara p2Tara = citirePointerLaTara();
	afisarePointerLaTara(p2Tara); */

	Tara * vector;
	vector = new Tara[2];
	int nrPointeri = 2;
	//vector de pointeri

	delete[]vector;

	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];

	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointerLaTara();
	}
	// procesare

	for (int i = 0; i < nrPointeri; i++) {
		afisarePointerLaTara(pointeri[i]);
	}

	for (int i = 0; i < nrPointeri; i++) {
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}

	delete[] pointeri;




	return 0;
}