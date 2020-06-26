#include "adminHondurasSop.h"

adminHondurasSop::adminHondurasSop(string nom)
{
	fileName=nom;
}

bool adminHondurasSop::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}
bool adminHondurasSop::cerrarLectura(){
	inputFile.close();
	return !inputFile.is_open();
}


bool adminHondurasSop::guardarSoldadosSoporte(SoldadosSoporte* sol){
	
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
 		
 		//guardar blindaje
 		outputFile.write(reinterpret_cast<char*>(&sol->blindaje), (int)sizeof(int) );
 		
 		//guardar camuflaje
 		outputFile.write(reinterpret_cast<char*>(&sol->camuflaje), (int)sizeof(int) );
				
		return true;
	}else
		return false;
}

bool adminHondurasSop::abrirEscritura(int modoEscritura){
	modo = modoEscritura;
	if(modo == 1)
		outputFile.open(fileName.c_str(), std::ios::app | std::ios::binary);
	else
		outputFile.open(fileName.c_str(), std::ios::binary);
			
	return outputFile.is_open();
}

bool adminHondurasSop::abrirLectura(){
	inputFile.open(fileName.c_str(),std::ios::binary);
			return inputFile.is_open();
	
}
vector<SoldadosSoporte*> adminHondurasSop::leerSoldadosSoporte(){
	vector<SoldadosSoporte*> retValue;
	 
	while(!inputFile.eof()){
		int nameSize=0;
		int vida=0;
		int fuerza=0;
		int blin=0;
		int camu=0;
		
		
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
		
		//leer el blindaje
		inputFile.read(reinterpret_cast<char*>(&blin),sizeof(int));
		
		//leer el camuflaje
		inputFile.read(reinterpret_cast<char*>(&camu),sizeof(int));
		
		retValue.push_back(new SoldadosSoporte(nombre, vida, fuerza, blin, camu));
	
	}
	 
	return retValue;
}


adminHondurasSop::~adminHondurasSop()
{
}
