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
		//es un soldado de asalto
		return pFuerza * 10;
	}else{
		return pFuerza * (10+(velocidad*2));
	}
}
bool SoldadosAsalto::defender(int ataque, bool tipo){
	if(tipo){
		//soldado de asalto
		pVida -= ataque;
		
	}else{
		pVida -= (ataque/fuerzaE);
	}
	cout<<pVida<<" vida en asalto\n";
	if(pVida<=0){
		return true;
	}
	else{
		return false;
	}
}

SoldadosAsalto::~SoldadosAsalto()
{
}
