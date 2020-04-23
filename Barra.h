#pragma once
class Barra
{
private:
	int x, y, dx, dy, l, puntos;
	char lado;
public:
	Barra();
	~Barra();
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dy(int nuevo);
	void cambiar_l(int nuevo);//Longitud
	void cambiar_lado(char nuevo);//Longitud
	void cambiar_puntos(int nuevo);

	int retornar_x();
	int retornar_y();
	int retornar_dy();
	int retornar_l();
	int retornar_lado();
	int retornar_puntos();

	void Dibujar();
	void Borrar();
	void ActualizarPuntos();

};

