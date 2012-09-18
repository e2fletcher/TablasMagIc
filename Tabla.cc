#include "Tabla.hh"
#include <cmath>
#include <sstream>

Tabla::Tabla(int n){
	_maxQNumbers = pow(2, n - 1);
	_maxNumber = pow(2, n) - 1;
	_maxDigits = _numbersDigits(_maxNumber);
	_quantite = n;
	_maxRows = floor(sqrt(_maxQNumbers)) - 1;
	_generateTablas();
}

int Tabla::Quantite(){
	return _quantite;
}

string Tabla::Print(int n){
	n = n - 1;
	ostringstream t;
	for(int i = 0; i < _maxQNumbers; ++i){
		if(_numbersDigits(_tabla[n][i]) < _maxDigits){
			for(int j = 0; j < (_maxDigits - _numbersDigits(_tabla[n][i])); ++j)
				t << " ";
		}
		t << _tabla[n][i];
		if((i + 1) % _maxRows == 0 || (i + 1) == _maxQNumbers)
			t << "\n";
		else
			t << " - ";
	}

	return t.str();

}

void Tabla::_generateTablas(){
	// Incializando matriz para guardar tabla
	_tabla = new int*[_quantite];
	for(int i = 0; i < _quantite; ++i){
		_tabla[i] = new int[_maxQNumbers];
		// Guardando el elemento Binario
		_tabla[i][0] = pow(2, i);
	}

	int k;
	for(int j = 0; j < _quantite; ++j){
		k = 1;
		for(int i = 1; i <= _maxNumber; ++i){
			if(_isInclude(_tabla[j][0], i) && _tabla[j][0] != i){
				_tabla[j][k] = i;
				++k;
			}
		}
	}
}

int Tabla::_numbersDigits(int n){
    int cont = 0, res, sum = 0;
    while(n != 0){
        res = n % 10;
        sum = sum + res;
        n = n / 10;
        cont++;
    }
    return cont;
}

bool Tabla::_isInclude(int n1, int n2){
	int i = 0, res, coc;
	
	while(n2 > 0){
		res = n2 % 2;
		coc = n2 / 2;
		n2 = coc;
		if(res == 1){
			if(pow(2,i) == n1){
				return true;
			}
		}
		i++;
	}
	return false;
}

Tabla::~Tabla(){
	delete [] _tabla;
}
