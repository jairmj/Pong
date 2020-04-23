#pragma once

#include "Barra.h"
class Rectangulo
{
private:
	int x, y, dx, dy, a, l;
	//x,y coordenadas iniciales, a altura desde y, l largo desde x
	Barra* objBarra;
public:

	Rectangulo();
	~Rectangulo();
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dx(int nuevo);
	void cambiar_dy(int nuevo);
	void cambiar_a(int nuevo);
	void cambiar_l(int nuevo);
	void cambiar_Barra(Barra* nuevo);

	int retornar_x();
	int retornar_y();
	int retornar_dx();
	int retornar_dy();
	int retornar_a();
	int retornar_l();
	Barra* retornar_Barra();

	void Dibujar();
	void Borrar();
	void Mover(int LimiteSuperior, int LimiteInferior, int direccion);
};

