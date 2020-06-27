#include <iostream>
#include "Soldado.h"
#include "adminHonduras.h"
#include "adminHondurasSop.h"
#include "adminOtroSop.h"
#include "adminOtroAs.h"
#include "SoldadosAsalto.h"
#include "SoldadosSoporte.h"
#include <vector>
#include <cstdlib>
#include <ctime>

#include <conio.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	adminHonduras* binFile;
	adminHondurasSop* binFile2;
	
	adminOtroSop* binFileSO;
	adminOtroAs* binFileSA;
	//crear archivo
	binFile = new adminHonduras("HondurasAs.bin");
	binFile2 = new adminHondurasSop("HondurasSop.bin");
	
	binFileSA = new adminOtroAs("OtroAs.bin");
	binFileSO = new adminOtroSop("OtroSop.bin");
	
	vector<SoldadosAsalto*> vectorAsaltosH;
	vector<SoldadosSoporte*> vectorSoporteH;
	
	vector<SoldadosAsalto*> vectorAsaltosO;
	vector<SoldadosSoporte*> vectorSoporteO;

//	vectorAsaltosH.push_back(new SoldadosAsalto("Pau", 12, 45, 34, 67));
//	vectorAsaltosH.push_back(new SoldadosAsalto("Yuda", 28, 31, 61, 28));
//
//	vectorSoporteH.push_back(new SoldadosSoporte("Sebas", 74, 24, 64, 15));
//	vectorSoporteH.push_back(new SoldadosSoporte("Nohelia", 84, 54, 44, 53));
//	vectorSoporteH.push_back(new SoldadosSoporte("Natalia", 14, 48, 54, 53));
//	
//	vectorAsaltosO.push_back(new SoldadosAsalto("Ryan", 84, 46, 14, 53));
//	vectorAsaltosO.push_back(new SoldadosAsalto("Paul", 43, 84, 54, 56));
//
//	vectorSoporteO.push_back(new SoldadosSoporte("Walker", 34, 54, 46, 75));
//	vectorSoporteO.push_back(new SoldadosSoporte("Noah", 64, 54, 47, 45));
//	vectorSoporteO.push_back(new SoldadosSoporte("Wey", 84, 45, 41, 55));
//	
	
	bool controlSalida=true;
	
	while(controlSalida){
		int elecMenuPrin;
		cout<<"1. Crear soldado \n2. Eliminar soldados \n3. Listar soldados \n4. Guardar soldados \n5. Cargar soldados \n6. Simulación \n7. Salir \n->Ingrese la opcion que desea: ";
		cin >> elecMenuPrin;
		
		switch(elecMenuPrin){
			case 1:{//crear soldado
				int tipoP;
				cout<<"1) Crear soldado de Honduras \n2) Crear soldado de otro pais \nIngrese la opcion que desea: ";
				cin >> tipoP;
				
				cout<<endl;
			
				int tipoSol;
				cout<<"1) Crear soldado de asalto \n2) Crear soldado de soporte \nIngrese la opcion que desea: ";
				cin >> tipoSol;
			
				string nombre;
				cout<<"Ingrese el nombre del soldado: ";
				cin >> nombre;
				
				int pVida;
				cout<<"Ingrese los puntos de vida que tiene: ";
				cin >> pVida;
				
				int pFuerza;
				cout<<"Ingrese los puntos de fuerza que tiene: ";
				cin >> pFuerza;
				
				if(tipoSol == 1){//crear soldados de asalto
				
					int velocidad;
					cout<<"Ingrese los puntos de velocidad que tiene: ";
					cin >> velocidad;
					
					int fuerzaE;
					cout<<"Ingrese los puntos de fuerza extra que tiene: ";
					cin >> fuerzaE;
					
					if(tipoP == 1){
						vectorAsaltosH.push_back(new SoldadosAsalto(nombre, pVida, pFuerza, velocidad, fuerzaE));
						cout<<"Soldado creado :)";
						
					}
					else if(tipoP ==2){
						vectorAsaltosO.push_back(new SoldadosAsalto(nombre, pVida, pFuerza, velocidad, fuerzaE));
						cout<<"Soldado creado :)";
						
					}
					else{
						cout<<"Opcion no valida :(";
					}
					
				}
				else if(tipoSol == 2){//crear soldados de soporte
				
					int blindaje;
					cout<<"Ingrese los puntos de blindaje que tiene: ";
					cin >> blindaje;
					
					int camuflaje;
					cout<<"Ingrese los puntos de camuflaje que tiene: ";
					cin >> camuflaje;
					
					if(tipoP==1){
						vectorSoporteH.push_back(new SoldadosSoporte(nombre, pVida, pFuerza, blindaje, camuflaje));
						cout<<"Soldado creado :)";
						
					}else if(tipoP==2){
						vectorSoporteO.push_back(new SoldadosSoporte(nombre, pVida, pFuerza, blindaje, camuflaje));
						cout<<"Soldado creado :)";
						
					}else{
						cout<<"Opcion no valida :(";
					}
					
				}else{
					cout<<"Opcion no valida :(";
				}
				cout<<endl<<endl;
				break;
			}
			case 2:{
				//eliminar soldados
				
				int tipoP;
				cout<<"1) Eliminar soldado de Honduras \n2) Eliminar soldado de otro pais \nIngrese la opcion que desea: ";
				cin >> tipoP;
				
				
				cout<<endl;
				int tipoSol;
				cout<<"1) Eliminar soldado de asalto \n2) Eliminar soldado de soporte \nIngrese la opcion que desea: ";
				cin >> tipoSol;
				cout<<endl;
				if(tipoSol == 1){
					//eliminar soldados de asalto
					
					if(tipoP == 1){
						cout<<"Soldados de asaltos: "<<endl;
						for(int i=0;i<vectorAsaltosH.size();i++){
							cout<<i<<" "<<vectorAsaltosH[i]->getNombre()<<": Puntos de vida - "<<vectorAsaltosH[i]->getPVida()<<" Puntos de fuerza - "<<vectorAsaltosH[i]->getPFuerza()<<" Puntos de Velocidad - "<<vectorAsaltosH[i]->getVelocidad()<<" Puntos de fuerza externa - "<<vectorAsaltosH[i]->getFuerzaE()<<endl;
						}
						
					}
					else if(tipoP == 2){
						cout<<"Soldados de asaltos: "<<endl;
						for(int i=0;i<vectorAsaltosO.size();i++){
							cout<<i<<" "<<vectorAsaltosO[i]->getNombre()<<": Puntos de vida - "<<vectorAsaltosO[i]->getPVida()<<" Puntos de fuerza - "<<vectorAsaltosO[i]->getPFuerza()<<" Puntos de Velocidad - "<<vectorAsaltosO[i]->getVelocidad()<<" Puntos de fuerza externa - "<<vectorAsaltosO[i]->getFuerzaE()<<endl;
						}
					}
					
					int posEliminado;
					cout<<endl<<"Elija el indice del soldado que desea eliminar: ";
					cin >> posEliminado;
					
					if(posEliminado<0){
						cout<<"No existe ese indice"<<endl;
					}
					else{
						if(tipoP == 1){
							if(posEliminado>=vectorAsaltosH.size()){
								cout<<"No existe ese indice"<<endl;
							}else{
								vectorAsaltosH.erase(vectorAsaltosH.begin() + posEliminado);
								cout<<"Eliminado"<<endl;
							}
							
						}
						else if(tipoP == 2){
							if(posEliminado>=vectorAsaltosO.size()){
								cout<<"No existe ese indice"<<endl;
							}else{
								vectorAsaltosO.erase(vectorAsaltosO.begin() + posEliminado);
								cout<<"Eliminado"<<endl;
							}
							
						}
						
					}
					
					
				}
				else if(tipoSol == 2){
					//eliminar soldados de soporte
					cout<<"Soldados de soporte: "<<endl;
					
					if(tipoP == 1){
						
						for(int i=0;i<vectorSoporteH.size();i++){
							cout<<i<<" "<<vectorSoporteH[i]->getNombre()<<": Puntos de vida - "<<vectorSoporteH[i]->getPVida()<<" Puntos de fuerza - "<<vectorSoporteH[i]->getPFuerza()<<" Puntos de Blindaje - "<<vectorSoporteH[i]->getBlindaje()<<" Puntos de camuflaje - "<<vectorSoporteH[i]->getCamuflaje()<<endl;
						}
						
					}
					else if(tipoP == 2){
						
						for(int i=0;i<vectorSoporteO.size();i++){
							cout<<i<<" "<<vectorSoporteO[i]->getNombre()<<": Puntos de vida - "<<vectorSoporteO[i]->getPVida()<<" Puntos de fuerza - "<<vectorSoporteO[i]->getPFuerza()<<" Puntos de Blindaje - "<<vectorSoporteO[i]->getBlindaje()<<" Puntos de camuflaje - "<<vectorSoporteO[i]->getCamuflaje()<<endl;
						}
					}
					
					int posEliminado;
					cout<<endl<<"Elija el indice del soldado que desea eliminar: ";
					cin >> posEliminado;
					
					
					if(posEliminado<0){
						cout<<"No existe ese indice"<<endl;
					}
					else{
						if(tipoP == 1){
							if(posEliminado>=vectorAsaltosH.size()){
								cout<<"No existe ese indice"<<endl;
							}else{
								vectorSoporteH.erase(vectorSoporteH.begin() + posEliminado);
								cout<<"Eliminado"<<endl;
							}
							
						}
						else if(tipoP == 2){
							if(posEliminado>=vectorAsaltosO.size()){
								cout<<"No existe ese indice"<<endl;
							}else{
								vectorSoporteO.erase(vectorSoporteO.begin() + posEliminado);
								cout<<"Eliminado"<<endl;
							}
							
						}
						
					}
					
					
				}else{
					cout<<"Opcion no valida :(";
				}
				
				break;
			}
			case 3:{//listar soldados
				cout<<endl<<"Soldados de asaltos de Honduras: "<<endl;
				for(int i=0;i<vectorAsaltosH.size();i++){
					cout<<vectorAsaltosH[i]->getNombre()<<": Puntos de vida - "<<vectorAsaltosH[i]->getPVida()<<" Puntos de fuerza - "<<vectorAsaltosH[i]->getPFuerza()<<" Puntos de Velocidad - "<<vectorAsaltosH[i]->getVelocidad()<<" Puntos de fuerza externa - "<<vectorAsaltosH[i]->getFuerzaE()<<endl;
				}
				cout<<endl;
				
				cout<<"Soldados de soporte de Honduras: "<<endl;
				for(int i=0;i<vectorSoporteH.size();i++){
					cout<<vectorSoporteH[i]->getNombre()<<": Puntos de vida - "<<vectorSoporteH[i]->getPVida()<<" Puntos de fuerza - "<<vectorSoporteH[i]->getPFuerza()<<" Puntos de Blindaje - "<<vectorSoporteH[i]->getBlindaje()<<" Puntos de camuflaje - "<<vectorSoporteH[i]->getCamuflaje()<<endl;
				}
				
				
				cout<<endl<<"Soldados de asaltos de otro pais: "<<endl;
				for(int i=0;i<vectorAsaltosO.size();i++){
					cout<<vectorAsaltosO[i]->getNombre()<<": Puntos de vida - "<<vectorAsaltosO[i]->getPVida()<<" Puntos de fuerza - "<<vectorAsaltosO[i]->getPFuerza()<<" Puntos de Velocidad - "<<vectorAsaltosO[i]->getVelocidad()<<" Puntos de fuerza externa - "<<vectorAsaltosO[i]->getFuerzaE()<<endl;
				}
				cout<<endl;
				
				cout<<"Soldados de soporte de otro pais: "<<endl;
				for(int i=0;i<vectorSoporteO.size();i++){
					cout<<vectorSoporteO[i]->getNombre()<<": Puntos de vida - "<<vectorSoporteO[i]->getPVida()<<" Puntos de fuerza - "<<vectorSoporteO[i]->getPFuerza()<<" Puntos de Blindaje - "<<vectorSoporteO[i]->getBlindaje()<<" Puntos de camuflaje - "<<vectorSoporteO[i]->getCamuflaje()<<endl;
				}
				
				cout<<endl<<endl;
				break;
			}
			case 4:{//guardar soldados
				cout<<endl<<"Guardando soldados de Honduras... "<<endl<<endl;
				//abrir archivo
				binFile->abrirEscritura(1);
				for(int i=0;i<vectorAsaltosH.size();i++){
					//guardar
					binFile->guardarSoldadosAsalto(vectorAsaltosH[i]);
					
				}
				
				binFile->cerrarEscritura();
				
				binFile2->abrirEscritura(1);
				for(int i=0;i<vectorSoporteH.size();i++){
					//guardar
					binFile2->guardarSoldadosSoporte(vectorSoporteH[i]);
					
				}
				//cerrar
				binFile2->cerrarEscritura();
				
				
				cout<<endl<<"Soldados del otro pais..."<<endl;
				
				//abrir archivo
				binFileSA->abrirEscritura(1);
				for(int i=0;i<vectorAsaltosO.size();i++){
					//guardar
					binFileSA->guardarSoldadosAsalto(vectorAsaltosO[i]);
					
				}
				binFileSA->cerrarEscritura();
				
				binFileSO->abrirEscritura(1);
				for(int i=0;i<vectorSoporteO.size();i++){
					//guardar
					binFileSO->guardarSoldadosSoporte(vectorSoporteO[i]);
					
				}
				//cerrar
				binFileSO->cerrarEscritura();
				
				cout<<endl<<endl;
				
				break;
			}
			case 5:{//cargar soldados
				cout<<endl<<"Cargando soldados"<<endl<<endl;
				binFile->abrirLectura();
				
				vectorAsaltosH = binFile->leerSoldadosAsalto();
				binFile->cerrarLectura();
				
				binFile2->abrirLectura();
				
				vectorSoporteH = binFile2->leerSoldadosSoporte();
				binFile2->cerrarLectura();
				
				
				//los soldados del otro pais
				binFileSA->abrirLectura();
				
				vectorAsaltosO = binFileSA->leerSoldadosAsalto();
				binFileSA->cerrarLectura();
				
				binFileSO->abrirLectura();
				
				vectorSoporteO = binFileSO->leerSoldadosSoporte();
				binFileSO->cerrarLectura();				
				
				
				break;
			}
			case 6:{//simular
				srand((unsigned)time(0));
				int numeroRandomH;
				int numRanSolH;
				int numeroRandomO;
				int numRanSolO, vidasH=0, vidasO=0;
				
				vidasH = vectorAsaltosH.size() + vectorSoporteH.size();
				vidasO = vectorAsaltosO.size() + vectorSoporteO.size();
				
				
				bool jugar = true;
				int turnos =0;
				
				while(jugar){
					numeroRandomH = rand() % 2;
					numeroRandomO = rand() % 2;
					
					if(turnos % 2 == 0){//turno de Honduras
						
						
						if(numeroRandomH == 0){//ataca un asaltante
							if(vectorAsaltosH.size()!=0){
								cout<<"Turno de Honduras"<<endl;
								numRanSolH = rand() % vectorAsaltosH.size();
								
								
								if(numeroRandomO == 0){//defiende un asaltante
									if(vectorAsaltosO.size()!=0){
										
										cout<<"1 Ataca un asaltante hondurenio a un asaltante de otro pais"<<endl;
										
										numRanSolO = rand() % vectorAsaltosO.size();
										if(vectorAsaltosO[numRanSolO]->defender(vectorAsaltosH[numRanSolH]->atacar(true), true)){
											vectorAsaltosO.erase(vectorAsaltosO.begin() + numRanSolO);
											cout<<"Murio un asaltante :0"<<endl;
											vidasO--;
											
											if(vidasO == 0){
												cout<<"Gano Honduras"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
								
								else{//defiende un soportante
									if(vectorSoporteO.size()!=0){
										
										cout<<"2 Ataca un asaltante hondurenio a un soportante de otro pais"<<endl;
										
										numRanSolO = rand() % vectorSoporteO.size();
										if(vectorSoporteO[numRanSolO]->defender(vectorAsaltosH[numRanSolH]->atacar(false), true)){
											vectorSoporteO.erase(vectorSoporteO.begin() + numRanSolO);
											cout<<"Murio un soportante :0"<<endl;
											vidasO--;
											if(vidasO == 0){
												cout<<"Gano Honduras"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
							
							}else{
								turnos--;
							}
							
						}else{//ataca un soportante
							if(vectorSoporteH.size()!=0){
								
								numRanSolH = rand() % vectorSoporteH.size();
								
								if(numeroRandomO == 0){//defiende un asaltante
									
									if(vectorAsaltosO.size()!=0){
										
										cout<<"3 Ataca un soportante hondurenio a un asaltante de otro pais"<<endl;
										
										numRanSolO = rand() % vectorAsaltosO.size();
										
										if(vectorAsaltosO[numRanSolO]->defender(vectorSoporteH[numRanSolH]->atacar(true), false)){
											vectorAsaltosO.erase(vectorAsaltosO.begin() + numRanSolO);
											cout<<"Murio un asaltante :0"<<endl;
											vidasO--;
											if(vidasO == 0){
												cout<<"Gano Honduras"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}	
								
								}
								
								else{//defiende un soportante
									if(vectorSoporteO.size()!=0){
										
										cout<<"4 Ataca un soportante hondurenio a un soportante de otro pais"<<endl;
										
										numRanSolO = rand() % vectorSoporteO.size();
										if(vectorSoporteO[numRanSolO]->defender(vectorSoporteH[numRanSolH]->atacar(false), false)){
											vectorSoporteO.erase(vectorSoporteO.begin() + numRanSolO);
											cout<<"Murio un soportante :0"<<endl;
											vidasO--;
											if(vidasO == 0){
												cout<<"Gano Honduras"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
							}else{
								turnos--;
							}
							
						}
						
					}
					else{
						//turno del otro
						
						if(numeroRandomO == 0){//ataca un asaltante
							if(vectorAsaltosO.size()!=0){
								cout<<"Turno de otro pais"<<endl;
								numRanSolO = rand() % vectorAsaltosO.size();
								
								if(numeroRandomH == 0){//defiende un asaltante
									if(vectorAsaltosH.size()!=0){
										
										cout<<"5 Ataca un asaltante de otro pais a un asaltante hondurenio"<<endl;
										numRanSolH = rand() % vectorAsaltosH.size();
										
										if(vectorAsaltosH[numRanSolH]->defender(vectorAsaltosO[numRanSolO]->atacar(true), true)){
											vectorAsaltosH.erase(vectorAsaltosH.begin() + numRanSolH);
											cout<<"Murio un asaltante :("<<endl;
											vidasH--;
											if(vidasH == 0){
												cout<<"Gano el otro pais"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
								
								else{//defiende un soportante
									if(vectorSoporteH.size()!=0){
										
										cout<<"6 Ataca un asaltante de otro pais a un soportante hondurenio"<<endl;
										numRanSolH = rand() % vectorSoporteH.size();
										if(vectorSoporteH[numRanSolH]->defender(vectorAsaltosO[numRanSolO]->atacar(false), true)){
											vectorSoporteH.erase(vectorSoporteH.begin() + numRanSolH);
											cout<<"Murio un soportante :("<<endl;
											vidasH--;
											if(vidasH == 0){
												cout<<"Gano el otro pais"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
							}else{
								turnos--;
							}
							
							
						}else{//ataca un soportante
							if(vectorSoporteO.size()!=0){
								
								numRanSolO = rand() % vectorSoporteO.size();
								
								if(numeroRandomH == 0){//defiende un asaltante
									if(vectorAsaltosH.size()!=0){
										
										cout<<"7 Ataca un soportante de otro pais a un asaltante hondurenio"<<endl;
										numRanSolH = rand() % vectorAsaltosH.size();
										if(vectorAsaltosH[numRanSolH]->defender(vectorSoporteO[numRanSolO]->atacar(true), false)){
											vectorAsaltosH.erase(vectorAsaltosH.begin() + numRanSolH);
											cout<<"Murio un asaltante :("<<endl;
											vidasH--;
											if(vidasH == 0){
												cout<<"Gano el otro pais"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
								
								else{//defiende un soportante
									if(vectorSoporteO.size()!=0){
										
										cout<<"8 Ataca un soportante de otro pais a un soportante hondurenio"<<endl;
										numRanSolH = rand() % vectorSoporteO.size();
										if(vectorSoporteH[numRanSolH]->defender(vectorSoporteO[numRanSolO]->atacar(false), false)){
											vectorSoporteH.erase(vectorSoporteH.begin() + numRanSolH);
											cout<<"Murio un soportante :("<<endl;
											vidasH--;
											if(vidasH == 0){
												cout<<"Gano el otro pais"<<endl;
												jugar = false;
												break;
											}
										}
									}else{
										turnos--;
									}
								}
							}else{
								turnos--;
							}
							
						}
					}
					
					
					turnos++;
					cout<<endl<<endl;
					getch();
				}
				cout<<endl<<endl;
				break;
			}
			case 7:{//salir
				controlSalida = false;
				break;
			}
		}

	}
	
	return 0;
}
