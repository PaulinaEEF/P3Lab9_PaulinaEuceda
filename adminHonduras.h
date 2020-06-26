#ifndef ADMINHONDURAS_H
#define ADMINHONDURAS_H

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

class adminHonduras
{
	public:
		adminHonduras(string);
		
		bool cerrarEscritura();
		bool cerrarLectura();
		bool guardarSoldadosAsalto(SoldadosAsalto*);
		bool abrirEscritura(int);
		bool abrirLectura();
		vector<SoldadosAsalto*> leerSoldadosAsalto();
		
		~adminHonduras();
	protected:
		string fileName;
		ofstream outputFile;
		int modo;
		ifstream inputFile;
};

#endif
