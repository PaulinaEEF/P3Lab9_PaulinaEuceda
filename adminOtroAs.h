#ifndef ADMINOTROAS_H
#define ADMINOTROAS_H

#include "SoldadosAsalto.h"

#include<string>
#include<fstream>
#include<vector>
#include<iostream>
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::cout;

class adminOtroAs
{
	public:
		adminOtroAs(string);
		
		bool cerrarEscritura();
		bool cerrarLectura();
		bool guardarSoldadosAsalto(SoldadosAsalto*);
		bool abrirEscritura(int);
		bool abrirLectura();
		vector<SoldadosAsalto*> leerSoldadosAsalto();
		
		~adminOtroAs();
	protected:
		string fileName;
		ofstream outputFile;
		int modo;
		ifstream inputFile;
};

#endif
