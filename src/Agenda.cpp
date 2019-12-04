#include <iostream>
#include <stdlib.h>
#include "headers/Nota.h" //Aqui se "inician" todos los objetos del programa

using namespace std;

int menu_principal(int,int,bool);
void getTercero(); //Sirve para obtener la lista de los contactos
void rmTercero(); //Borra el contaco mediante al ID ingresada
void setPersona(int); //Crea un nuevo contacto
void setPropietario(int); //Ingresa los datos del propietario de la agenda
void getPropietario(int); //Obtiene los datos del propietario de la agenda
bool setFecha(int); //Registra una nueva fecha en la agenda
void getFecha(); //Obtiene la lista completa de fechas ingresadas en la agenda
void setNota(); //Regsita una nueva nota en la agenda
void getNota(); //Obtiene la lista completa de notas ingresadas en la agenda

//Incio de la función principal
int main(){
	int opc,id_contacto=1,id_propietario=1;
	int cantidad_fechas=0,cantidad_notas=0;
	bool perfil=false; //Con este booleano se confirma si ya se hizo el registro del propietario
	do{
		//system("cls");
		opc = menu_principal(cantidad_fechas,cantidad_notas,perfil);
		switch(opc){
		case 1:
			if(id_contacto>1){
				getTercero();
			}else{
				cout<<"No hay ningún contacto registrado por el momento"<<endl;
			}
			break;
		case 2:
			setPersona(id_contacto);
			id_contacto++;
			break;
		case 3:
			perfil=true;
			setPropietario(id_propietario);
			break;
		case 4:
			getPropietario(id_propietario);
			break;
		case 5:
			if(setFecha(cantidad_fechas)){
				cantidad_fechas++;
			}
			//setNotificacion_fecha(cantidad_fechas);
			break;
		case 6:
			if(cantidad_fechas>0){
				getFecha();
			}else{
				cout<<"\nNo hay ninguna fecha registrada :)\n";
			}
			break;
		case 7:
			cantidad_notas++;
			setNota();
			//setNotificacion_nota(cantidad_notas);
			break;
		case 8:
			if(cantidad_notas>0){
				getNota();
			}else{
				cout<<"\nNo hay ninguna nota agregada :)\n";
			}
			break;
		case 9:
			rmTercero();
			id_contacto--;
			break;
		case 0:
			cout<<endl<<"Adios :)";
			break;
		default:
			cout<<"Seleccione una opción válida\n\n\n";
			break;
		}
	}while(opc!=0);
	return 0;
}

//Inicia la función menu, retorna el valor que se usara en el switch para el menú
int menu_principal(int cantidad_fechas,int cantidad_notas,bool perfil){
	int opc;
	string msg1="\n"
				"1.-Ver contactos\n"
				"2.-Nuevo contacto\n"
				"3.-Modificar perfil\n"
				"4.-Ver datos del perfil\n"
				"5.-Nueva fecha\n"
				"6.-Ver fechas\n"
				"7.-Nueva nota\n"
				"8.-Ver notas\n"
				"9.-Borrar contacto\n"
				"0.-Salir :)\n";
	cout<<msg1;
	//Se colocan las notificaciones de fechas y notas registradas
	cout<<endl<<"Fechas: "<<cantidad_fechas<<endl<<"Notas: "<<cantidad_notas<<endl;
	if(perfil==false){
		cout<<"No ha rellenado sus propios campos, ingrese 3 para hacerlo"<<endl;
	}
	cin>>opc;
	return opc;
}

void getTercero(){
	Tercero tercero1;
	tercero->VerTercero();
}


void rmTercero(){
	Tercero tercero1;
	tercero1.BorrarTercero();
}

void setPersona(int id_contacto){
	Tercero tercero1;
	tercero1.NvoTercero(id_contacto);
}

void setPropietario(int id_propietario){
	Propietario propietario1;
	propietario1.modPerfil(id_propietario);
}

void getPropietario(int id_propietario){
	Propietario propietario1;
	propietario1.verPerfil(id_propietario);
}

bool setFecha(int contador_fechas){
	bool correcto=false;
	Fecha fecha1;
	fecha1.insertFecha();
	correcto = fecha1.verifDatos();
	if(correcto==true){
		fecha1.setFecha(contador_fechas);
	}
	return correcto;
}

void getFecha(){
	Fecha fecha1;
	fecha1.verFecha();
}

void setNota(){
	Nota nota1;
	nota1.nvaNota();
}

void getNota(){
	Nota nota1;
	nota1.verNota();
}
