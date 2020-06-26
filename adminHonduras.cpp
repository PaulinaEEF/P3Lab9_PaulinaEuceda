#include "adminHonduras.h"

adminHonduras::adminHonduras(string nom)
{
	fileName=nom;
}

bool adminHonduras::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}
bool adminHonduras::cerrarLectura(){
	inputFile.close();
	return !inputFile.is_open();
}
bool adminHonduras::guardarSoldadosAsalto(SoldadosAsalto* sol){
	
	if(outputFile.is_open()){
		
 		int sizeNombre = sol->nombre.size();
 		//guardar size nombre
 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
 		
		//guardar el nombre 
		outputFile.write(sol->nombre.data(),sizeNombre);
		
		//guardar vida
 		outputFile.write(reinterpret_cast<char*>(&sol->pVida), (int)sizeof(int) );
 		
 		//guardar fuerza
 		outputFile.write(reinterpret_cast<char*>(&sol->pVida), (int)sizeof(int) );
 		
 		//guardar velocidad
 		outputFile.write(reinterpret_cast<char*>(&sol->velocidad), (int)sizeof(int) );
 		
 		//guardar fuerza extra
 		outputFile.write(reinterpret_cast<char*>(&sol->fuerzaE), (int)sizeof(int) );
				
		return true;
	}else
		return false;
}



bool adminHonduras::abrirEscritura(int modoEscritura){
	modo = modoEscritura;
	if(modo == 1)
		outputFile.open(fileName.c_str(), std::ios::app | std::ios::binary);
	else
		outputFile.open(fileName.c_str(), std::ios::binary);
			
	return outputFile.is_open();
}

bool adminHonduras::abrirLectura(){
	inputFile.open(fileName.c_str(),std::ios::binary);
			return inputFile.is_open();
	
}

vector<SoldadosAsalto*> adminHonduras::leerSoldadosAsalto(){
	vector<SoldadosAsalto*> retValue;
	 
	while(!inputFile.eof()){
		//cout<<"entra\n";
		int nameSize=0;
		int vida=0;
		int fuerza=0;
		int velo=0;
		int fuE=0;
		
		
		//leer el tamaño del nombre 
		inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
		
		char buffer[100];
		//leer el nombre
		inputFile.read(buffer,nameSize);
		
		string nombre(buffer, nameSize);
		
		//leer la vida
		inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
		if(vida==0){
			break;
		}
		
		//leer la fuerza
		inputFile.read(reinterpret_cast<char*>(&fuerza),sizeof(int));
		
		//leer la velocidad
		inputFile.read(reinterpret_cast<char*>(&velo),sizeof(int));
		
		//leer la fuerza extra
		inputFile.read(reinterpret_cast<char*>(&fuE),sizeof(int));
		
		retValue.push_back(new SoldadosAsalto(nombre, vida, fuerza, velo, fuE));
	
	}
	 
	return retValue;
}

adminHonduras::~adminHonduras()
{
}
