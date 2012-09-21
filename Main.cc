#include "Tabla.hh"

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

void help(){
	cout << "gtablas versión: \"1.0\" (Generador de tablas mágicas)\n";
	cout << "\t\t\te2fletcher@gmail.com\n\n";
	cout << "Sintaxis: gtablas <numero de tablas>\n";
}

int main(int argc, char** argv){
	if(argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 || atoi(argv[1]) == 0){
		help();
		return 0;
	}

	Tabla t(atoi(argv[1]));

	for(int i = 1; i <= t.Quantite(); ++i){
		cout << t.Print(i) << endl;
	}
	//t.~Tabla();
	return 0;
} 
