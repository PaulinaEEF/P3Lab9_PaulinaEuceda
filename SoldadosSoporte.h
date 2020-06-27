#ifndef SOLDADOSSOPORTE_H
#define SOLDADOSSOPORTE_H

#include "Soldado.h"

class adminHondurasSop;
class adminOtroSop;
class SoldadosSoporte : public Soldado
{
	public:
		SoldadosSoporte(string, int, int, int, int);
		
		int getBlindaje();
		int getCamuflaje();
		int atacar(bool);
		bool defender(int, bool);
		
		~SoldadosSoporte();
	protected:
		int blindaje, camuflaje;
		friend class adminHondurasSop;
		friend class adminOtroSop;
};

#endif
