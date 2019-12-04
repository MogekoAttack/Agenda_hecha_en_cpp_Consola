#ifndef HEADERS_TERCERO_H
#define HEADERS_TERCERO_H
#include <iostream>
#include "Propietario.h"

using namespace std;

struct Tercero:public Persona{
public:
	struct Tercero *sgte;
	string notas;
	void NvoTercero(int id_tercero);
	void VerTercero();
	void BorrarTercero();
};

typedef struct Tercero *Tlista_tercero;

Tlista_tercero tercero;

void insertarFinal(Tlista_tercero &lista, int valor,string nombre,string apellido_1,string apellido_2,string tel_casa,string tel_celular,string tel_oficina,string nota){
    Tlista_tercero t, q = new(struct Tercero);
    q->nro  = valor;
    q->nombre = nombre;
	q->apellido_1 = apellido_1;
	q->apellido_2 = apellido_2;
	q->tel_casa = tel_casa;
	q->tel_oficina = tel_oficina;
	q->tel_celular = tel_celular;
	q->notas = nota;
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

void VerListaTercero(Tlista_tercero lista){
     int i = 0;

     while(lista != NULL){
          cout <<' '<< i+1 <<") " << "Nombre: " <<lista->nombre << endl;
          cout <<' '<< i+1 <<") " << "Apellido paterno: " <<lista->apellido_1 << endl;
          cout <<' '<< i+1 <<") " << "Apellido materno: " <<lista->apellido_2 << endl;
          cout <<' '<< i+1 <<") " << "Telefono de casa: " <<lista->tel_casa << endl;
          cout <<' '<< i+1 <<") " << "Telefono celular: " <<lista->tel_celular << endl;
          cout <<' '<< i+1 <<") " << "Telefono de oficina: " <<lista->tel_oficina << endl;
          cout <<' '<< i+1 <<") " << "Notas: " <<lista->notas << endl;
          lista = lista->sgte;
          i++;
     }
}

void eliminarElemento(Tlista_tercero &lista, int valor){
    Tlista p, ant;
    p = lista;

    if(lista!=NULL){
        while(p!=NULL){
            if(p->nro==valor){
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void Tercero::VerTercero(){
	VerListaTercero(tercero);
}

void Tercero::NvoTercero(int id_tercero){
	string nombre,apellido_1,apellido_2,tel_casa,tel_celular,tel_oficina,notas;
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
	cout<<"Nota: ";
	cin.ignore();
	getline(cin,notas);
	insertarFinal(tercero,id_tercero,nombre,apellido_1,apellido_2,tel_casa,tel_celular,tel_oficina,notas);
}

void Tercero::BorrarTercero(){
	int id_tercero;
	cout<<"Ingrese el ID del contacto a eliminar"<<endl;
	cin>>id_tercero;
	eliminarElemento(tercero,id_tercero);
}
#endif
