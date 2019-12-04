#ifndef HEADERS_NOTA_H_
#define HEADERS_NOTA_H_
#include <iostream>
#include <fstream>
#include "Fecha.h"
using namespace std;
struct Nota{
public:
	string evento;
	int notificacion,contador;
	struct Nota *sgte;
	void nvaNota();
	void verNota();
};

typedef struct Nota *Tlista_nota;

Tlista_nota Nota1;

void insertarFinal(Tlista_nota &lista,string evento){
    Tlista_nota t, q = new(struct Nota);

    q->evento  = evento;

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

void verNotas(Tlista_nota lista){
	int i=0;
	while(lista != NULL){
		cout <<"=================================" << endl;
		cout <<"======= Nota "<<i+1<<" ==========" << endl;
		cout <<' '<<lista->evento << endl;
		cout <<"================================="<<endl;
		lista = lista->sgte;
		i++;
	}
}

void Nota::nvaNota(){
	cout<<"Ingrese su nota:"<<endl;
	cin.ignore();
	getline(cin,evento);
	insertarFinal(Nota1,evento);
}

void Nota::verNota(){
	verNotas(Nota1);
}
#endif /* HEADERS_NOTA_H_ */
