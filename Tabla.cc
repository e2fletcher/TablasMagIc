#include "Tabla.hh"
#include <cmath>
#include <sstream>

Tabla::Tabla(const unsigned int& n){
	_maxQNumbers = pow(2, n - 1);
	_maxNumber = pow(2, n) - 1;
	_maxDigits = _numbersDigits(_maxNumber);
	_quantite = n;
	_maxRows = floor(sqrt(_maxQNumbers));
	_numbersCforRow = (_maxRows * _maxDigits) + 3 * (_maxRows - 1);
	_generateTablas();
}

unsigned int Tabla::Quantite(){
	return _quantite;
}

string Tabla::Print(unsigned int n){
	n = n - 1;
	ostringstream t;
	
	// Linea Borde de tabla
	string l;
	for(int i = 1; i <= _numbersCforRow; ++i)
		if(i == _numbersCforRow)
			l += "-\n";
		else
			l += "-";
	t << l;
	// End linea borde de tabla

	for(int i = 0; i < _maxQNumbers; ++i){
		// Espacio para numeros con menos digitos q _maxDigits
		if(_numbersDigits(_tabla[n][i]) < _maxDigits){
			for(int j = 0; j < (_maxDigits - _numbersDigits(_tabla[n][i])); ++j)
				t << " ";
		}

		t << _tabla[n][i];
		
		// Raya entre números y fin de linea para cada fila
		if((i + 1) % _maxRows == 0 || (i + 1) == _maxQNumbers)
			t << "\n";
		else
			t << " - ";
	}
	
	// Linea borde de tabla
	t << l;
	
	return t.str();
}

void Tabla::_generateTablas(){
	// Incializando matriz para guardar tabla
	_tabla = new unsigned int*[_quantite];
	for(int i = 0; i < _quantite; ++i){
		_tabla[i] = new unsigned int[_maxQNumbers];
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

unsigned int Tabla::_numbersDigits(unsigned int n){
    int cont = 0, res, sum = 0;
    while(n != 0){
        res = n % 10;
        sum = sum + res;
        n = n / 10;
        cont++;
    }
    return cont;
}

bool Tabla::_isInclude(unsigned int n1, unsigned int n2){
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
