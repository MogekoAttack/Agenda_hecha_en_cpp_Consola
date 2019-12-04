#ifndef HEADERS_PERSONA_H
#define HEADERS_PERSONA_H
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Persona{
public:
	//Datos
	int nro;
	string nombre, apellido_1,apellido_2,direccion,tel_casa,tel_celular,tel_oficina;
	struct Persona *sgte;
};

typedef struct Persona *Tlista;

void insertarFinal(Tlista &lista, int valor,string nombre,string apellido_1,string apellido_2,string tel_casa,string tel_celular,string tel_oficina,string nota){
    Tlista t, q = new(struct Persona);

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

void VerListaPersona(Tlista lista){
     int i = 0;
     while(lista != NULL){
          cout <<' '<< i+1 <<") " << "Nombre: " <<lista->nombre << endl;
          cout <<' '<< i+1 <<") " << "Apellido paterno: " <<lista->apellido_1 << endl;
          cout <<' '<< i+1 <<") " << "Apellido materno: " <<lista->apellido_2 << endl;
          cout <<' '<< i+1 <<") " << "Telefono de casa: " <<lista->tel_casa << endl;
          cout <<' '<< i+1 <<") " << "Telefono celular: " <<lista->tel_celular << endl;
          cout <<' '<< i+1 <<") " << "Telefono de oficina: " <<lista->tel_oficina << endl;
          lista = lista->sgte;
          i++;
     }
}
#endif
