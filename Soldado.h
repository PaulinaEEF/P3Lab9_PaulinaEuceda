#ifndef SOLDADO_H
#define SOLDADO_H

#include<iostream>

using std::string;
using std::cout;

class adminHonduras;
class Soldado
{
	public:
		Soldado(string, int, int);
		
		string getNombre();
		int getPVida();
		int getPFuerza();
		
		virtual int atacar(bool)=0;
		virtual bool defender(int, bool)=0;
		
		~Soldado();
	protected:
		string nombre;
		int pVida, pFuerza;
		friend class adminHonduras;
};

#endif
