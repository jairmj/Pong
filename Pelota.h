#pragma once

#include "Barra.h"



class Pelota
{
private:
	int x, y, dx, dy;

public:
	Pelota();
	~Pelota();
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dy(int nuevo);
	void cambiar_dx(int nuevo);

	int retornar_x();
	int retornar_y();
	int retornar_dy();
	int retornar_dx();

	void Dibujar();
	void Borrar();
	void Mover(Barra* Barra1, Barra* Barra2);
	void Reset();
};

