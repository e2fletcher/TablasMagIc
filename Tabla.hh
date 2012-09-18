#ifndef TABLA_HH_
#define TABLA_HH_

#include <string>
using namespace std;

class Tabla {
public:
	Tabla(int);
	~Tabla();
	string Print(int);
	int Quantite();

private:
	int *(*_tabla);
	int _maxQNumbers;
	int _maxNumber;
	int _maxDigits;
	int _quantite;
	int _maxRows;
	void _generateTablas();
	int _numbersDigits(int n);
	bool _isInclude(int n1, int n2);

};

#endif
