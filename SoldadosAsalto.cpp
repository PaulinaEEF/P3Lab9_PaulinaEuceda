#include "SoldadosAsalto.h"

SoldadosAsalto::SoldadosAsalto(string nom, int vida, int fuerza, int velo, int fuer):Soldado(nom, vida, fuerza)
{
	velocidad = velo;
	fuerzaE = fuer;
}

int SoldadosAsalto::getVelocidad(){
	return velocidad;
}
int SoldadosAsalto::getFuerzaE(){
	return fuerzaE;
}
int SoldadosAsalto::atacar(bool){
	
}
bool SoldadosAsalto::defender(int){
	
}

SoldadosAsalto::~SoldadosAsalto()
{
}
