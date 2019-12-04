#ifndef HEADERS_NOTIFICACION_H_
#define HEADERS_NOTIFICACION_H_
#include <iostream>
#include "Nota.h"
using namespace std;
struct Notificacion{
public:
	int cantidad_fechas=0,cantidad_notas=0;
	//struct Notificacion *sgte;
	void agregar_fecha(int);
	void agregar_nota(int);
	void ver_notificaciones();
};

void Notificacion::agregar_fecha(int cantidad_fecha){
	cantidad_fechas = cantidad_fecha;
}

void Notificacion::agregar_nota(int cantidad_nota){
	cantidad_notas = cantidad_nota;
}

void Notificacion::ver_notificaciones(){
	string noti = "Fechas: ";
	string noti2 = "Notas: ";
	cout<<noti<<cantidad_fechas<<"\n"<<noti2<<cantidad_notas<<"\n";
}

#endif /* HEADERS_NOTIFICACION_H_ */
