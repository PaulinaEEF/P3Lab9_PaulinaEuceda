#ifndef SOLDADO_H
#define SOLDADO_H

#include<string>

using std::string;

class adminHonduras;
class Soldado
{
	public:
		Soldado(string, int, int);
		
		string getNombre();
		int getPVida();
		int getPFuerza();
		
		virtual int atacar(bool)=0;
		virtual bool defender(int)=0;
		
		~Soldado();
	protected:
		string nombre;
		int pVida, pFuerza;
		friend class adminHonduras;
};

#endif
