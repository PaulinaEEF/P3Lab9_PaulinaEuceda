#ifndef SOLDADOSSOPORTE_H
#define SOLDADOSSOPORTE_H

#include "Soldado.h"

class SoldadosSoporte : public Soldado
{
	public:
		SoldadosSoporte(string, int, int, int, int);
		
		int getBlindaje();
		int getCamuflaje();
		int atacar(bool);
		bool defender(int);
		
		~SoldadosSoporte();
	protected:
		int blindaje, camuflaje;
};

#endif
