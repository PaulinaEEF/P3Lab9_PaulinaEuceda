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
int SoldadosAsalto::atacar(bool tipo){
	if(tipo){
		//es un doldado de asalto
		return pFuerza * 10;
	}else{
		return pFuerza * (10+(velocidad*2));
	}
}
bool SoldadosAsalto::defender(int){
	
}

SoldadosAsalto::~SoldadosAsalto()
{
}
