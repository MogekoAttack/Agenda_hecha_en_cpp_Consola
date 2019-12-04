#ifndef HEADERS_FECHA_H
#define HEADERS_FECHA_H
#include <iostream>
#include "Tercero.h"
using namespace std;

struct Fecha{
public:
	string dato_adicional;
	int dia,mes,anio,hora,minuto,contador;
	struct Fecha *sgte;
	//Función para comprobar que los datos de una fecha sean correctos
	bool verifDatos();
	void verFecha();
	void insertFecha();
	void setFecha(int);
};

typedef struct Fecha *Tlista_fecha;

Tlista_fecha Fecha1;

void insertarFinal(Tlista_fecha &lista,int dia,int mes,int anio,string dato_adicional,int contador){
    Tlista_fecha t, q = new(struct Fecha);
    //Se vacian los datos ingresados en la lista
    q->dia  = dia;
    q->mes  = mes;
    q->anio  = anio;
    q->dato_adicional  = dato_adicional;
    q->contador = contador;

    q->sgte = NULL;

    if(lista==NULL){
        lista = q;
    }
    else{
        t = lista;
        while(t->sgte!=NULL){
            t = t->sgte;
        }
        t->sgte = q;
    }
}

void VerListaFecha(Tlista_fecha lista){
     int i = 0;
     while(lista != NULL){
    	 cout <<"=================================" << endl;
    	 cout <<"=========Fecha "<<i<<" ==========" << endl;
    	 cout <<' '<<"Día: " <<lista->dia << endl;
    	 cout <<' '<<"Mes: " <<lista->mes << endl;
    	 cout <<' '<<"Año: " <<lista->anio << endl;
		 cout <<' '<<"Dato adicional: " <<lista->dato_adicional << endl;
		 cout <<"================================="<<endl;
         lista = lista->sgte;
         i++;
     }
}

void Fecha::setFecha(int contador){
	insertarFinal(Fecha1,dia,mes,anio,dato_adicional,contador);
}

void Fecha::verFecha(){
	VerListaFecha(Fecha1);
}

void Fecha::insertFecha(){
	cout<<"Día: ";
	cin>>dia;
	cout<<"Mes: ";
	cin>>mes;
	cout<<"Año: ";
	cin>>anio;
	cout<<"Dato adicional: ";
	cin.ignore();
	getline(cin,dato_adicional);
}

//Función para comprobar que los datos de una fecha sean correctos
bool Fecha::verifDatos(){
	bool correcto;
	if(mes>=1&&mes<=12){
		if(mes==1||mes==3||mes==5||mes==7||mes==10||mes==12){
			if(dia>=1&&dia<=30){
				if(anio>0){
					correcto = true;
				}
			}
		}else{
			if(dia>=1&&dia<=30){
				if(anio>0){
					correcto = true;
				}
			}
		}
	}else{
		cout<<"\nAlgun dato es incorrecto"<<endl;
		correcto = false;
	}
	return correcto;
}
#endif
