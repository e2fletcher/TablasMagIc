#ifndef TABLA_HH_
#define TABLA_HH_

#include <string>
using namespace std;

class Tabla {
public:
	Tabla(const unsigned int&);
//	~Tabla();
	string Print(unsigned int);
	unsigned int Quantite();

private:
	unsigned int *(*_tabla);
	unsigned int _maxQNumbers;
	unsigned int _maxNumber;
	unsigned int _maxDigits;
	unsigned int _quantite;
	unsigned int _maxRows;
	unsigned int _numbersCforRow;
	void _generateTablas();
	unsigned int _numbersDigits(unsigned int n);
	bool _isInclude(unsigned int n1,unsigned  int n2);

};

#endif
