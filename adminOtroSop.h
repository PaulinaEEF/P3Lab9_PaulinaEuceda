#ifndef ADMINOTROSOP_H
#define ADMINOTROSOP_H

#include "SoldadosSoporte.h"
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::cout;

class adminOtroSop
{
	public:
		adminOtroSop(string);
		
		bool cerrarEscritura();
		bool cerrarLectura();
		bool guardarSoldadosSoporte(SoldadosSoporte*);
		bool abrirEscritura(int);
		bool abrirLectura();
		vector<SoldadosSoporte*> leerSoldadosSoporte();
		
		~adminOtroSop();
	protected:
		string fileName;
		ofstream outputFile;
		int modo;
		ifstream inputFile;
};

#endif
