#include "Soldado.h"

Soldado::Soldado(string nom, int vida, int fuerza)
{
	nombre = nom;
	pVida = vida;
	pFuerza = fuerza;
}


string Soldado::getNombre(){
	return nombre;
}
int Soldado::getPVida(){
	return pVida;
}
int Soldado::getPFuerza(){
	return pFuerza;
}

Soldado::~Soldado()
{
}
