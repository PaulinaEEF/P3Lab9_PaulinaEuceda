#ifndef SOLDADOSASALTO_H
#define SOLDADOSASALTO_H

#include "Soldado.h"

class SoldadosAsalto : public Soldado
{
	public:
		SoldadosAsalto(string, int, int, int, int);
		
		int getVelocidad();
		int getFuerzaE();
		int atacar(bool);
		bool defender(int);
		
		~SoldadosAsalto();
	protected:
		int velocidad, fuerzaE;
};

#endif
