
#include "pch.h"
#include "Rectangulo.h"
using namespace System;
using namespace std;
Rectangulo::Rectangulo() {}
Rectangulo::~Rectangulo() {}
void Rectangulo::cambiar_x(int nuevo) { x = nuevo; }
void Rectangulo::cambiar_y(int nuevo) { y = nuevo; }
void Rectangulo::cambiar_dx(int nuevo) { dx = nuevo; }
void Rectangulo::cambiar_dy(int nuevo) { dy = nuevo; }
void Rectangulo::cambiar_a(int nuevo) { a = nuevo; }
void Rectangulo::cambiar_l(int nuevo) { l = nuevo; }
void Rectangulo::cambiar_Barra(Barra* nuevo) { objBarra = nuevo; };
int Rectangulo::retornar_x() { return x; }
int Rectangulo::retornar_y() { return y; }
int Rectangulo::retornar_dx() { return dx; }
int Rectangulo::retornar_dy() { return dy; }
int Rectangulo::retornar_a() { return a; }
int Rectangulo::retornar_l() { return l; }
Barra* Rectangulo::retornar_Barra() { return objBarra; };


void Rectangulo::Dibujar() {
	objBarra->Dibujar();
}


void Rectangulo::Borrar() {
	objBarra->Borrar();
}


void Rectangulo::Mover(int LimiteSuperior, int LimiteInferior, int direccion) {
	Borrar();

	if ((y + dy) <= LimiteSuperior && (direccion == 1)) dy = 0;
	if (y + objBarra->retornar_l() - 1 + dy >= LimiteInferior && direccion == 0) dy = 0;
	// Si está en la parte de abajo o arriba le pongo dy=0 para que no se mueva.


	y += dy;

	objBarra->cambiar_dy(dy);
	objBarra->cambiar_y(objBarra->retornar_y() + objBarra->retornar_dy()); // y + = dy de la barra

	Dibujar();
}