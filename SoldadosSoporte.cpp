#include "SoldadosSoporte.h"

SoldadosSoporte::SoldadosSoporte(string nom, int vida, int fuerza, int blin, int cam):Soldado(nom, vida, fuerza)
{
	blindaje = blin;
	camuflaje = cam;
}

int SoldadosSoporte::getBlindaje(){
	return blindaje;
}
int SoldadosSoporte::getCamuflaje(){
	return camuflaje;
}
int SoldadosSoporte::atacar(bool tipo){
	if(tipo){
		//es un soldado de asalto
		return pFuerza*(15+camuflaje);
	}
	else{
		return pFuerza*10;
	}
}
bool SoldadosSoporte::defender(int){
	
}

SoldadosSoporte::~SoldadosSoporte()
{
}
