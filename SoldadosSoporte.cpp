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
bool SoldadosSoporte::defender(int ataque, bool tipo){
	if(tipo){
		//soldado de asalto
		pVida -= (ataque/(blindaje*2));
	}else{
		pVida -= ataque;
	}
	cout<<pVida<<" vida en soporte\n";
	if(pVida<=0){
		return true;
	}
	else{
		return false;
	}
}

SoldadosSoporte::~SoldadosSoporte()
{
}
