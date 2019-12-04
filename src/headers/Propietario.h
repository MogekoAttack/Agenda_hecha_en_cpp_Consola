#ifndef HEADERS_PROPIETARIO_H
#define HEADERS_PROPIETARIO_H
#include <iostream>
#include "Persona.h"

using namespace std;

struct Propietario:public Persona{
public:
	int nro;
	struct Propietario *sgte;
	void modPerfil(int);
	void verPerfil(int);
	void nvaNota();
	void verNota();
	void nvoRecordatorio();
	void verRecordatorio();
	void Notificaciones();
	void fechas();
};


typedef struct Propietario *Tlista_propietario;

Tlista_propietario propietario1;

void insertarFinal(Tlista_propietario &lista, int valor,string nombre,string apellido_1,string apellido_2,string tel_casa,string tel_celular,string tel_oficina){
    Tlista_propietario t, q = new(struct Propietario);

    q->nro  = valor;
    q->nombre = nombre;
	q->apellido_1 = apellido_1;
	q->apellido_2 = apellido_2;
	q->tel_casa = tel_casa;
	q->tel_oficina = tel_oficina;
	q->tel_celular = tel_celular;
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

void VerListaPropietario(Tlista_propietario lista,int id_propietario){
     while(lista != NULL&&id_propietario==1){
          cout << "Nombre: " <<lista->nombre << endl;
          cout << "Apellido paterno: " <<lista->apellido_1 << endl;
          cout << "Apellido materno: " <<lista->apellido_2 << endl;
          cout << "Telefono de casa: " <<lista->tel_casa << endl;
          cout << "Telefono celular: " <<lista->tel_celular << endl;
          cout << "Telefono de oficina: " <<lista->tel_oficina << endl;
          lista = lista->sgte;
     }
}

void Propietario::modPerfil(int id_propietario){
	string nombre,apellido_1,apellido_2,tel_casa,tel_celular,tel_oficina;
	cout<<"Nombre: ";
		cin.ignore();
		getline(cin,nombre);
		cout<<"Apellido Paterno: ";
		cin.ignore();
		getline(cin,apellido_1);
		cout<<"Apellido Materno: ";
		cin.ignore();
		getline(cin,apellido_2);
		cout<<"Telefono de casa: ";
		cin.ignore();
		getline(cin,tel_casa);
		cout<<"Telefono celular: ";
		cin.ignore();
		getline(cin,tel_celular);
		cout<<"Telefono de oficina: ";
		cin.ignore();
		getline(cin,tel_oficina);
	insertarFinal(propietario1,id_propietario,nombre,apellido_1,apellido_2,tel_casa,tel_celular,tel_oficina);
}

void Propietario::verPerfil(int id_propietario){
	VerListaPropietario(propietario1,id_propietario);
}
#endif
