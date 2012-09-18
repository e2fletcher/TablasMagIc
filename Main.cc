#include "Tabla.hh"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){
	Tabla t(atoi(argv[1]));

	for(int i = 1; i <= t.Quantite(); ++i){
		cout << t.Print(i) << endl;
	}

	return 0;
} 