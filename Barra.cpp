#include "pch.h"
#include "Barra.h"
#include <iostream>

using namespace System;
using namespace std;

Barra::Barra() {};
Barra::~Barra() {};
void Barra::cambiar_x(int nuevo) { x = nuevo; };
void Barra::cambiar_y(int nuevo) { y = nuevo; };
void Barra::cambiar_dy(int nuevo) { dy = nuevo; };
void Barra::cambiar_l(int nuevo) { l = nuevo; };
void Barra::cambiar_lado(char nuevo) { lado = nuevo; };
void Barra::cambiar_puntos(int nuevo) { puntos = nuevo; };

int Barra::retornar_x() { return x; };
int Barra::retornar_y() { return y; };
int Barra::retornar_dy() { return  dy; };
int Barra::retornar_l() { return  l; };
int Barra::retornar_lado() { return  lado; };
int Barra::retornar_puntos() { return  puntos; };


void Barra::Dibujar() {
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Black;

	for (int i = 0; i < l; i++) {//Para dibujar la longitud
		Console::SetCursorPosition(x, y + i);
		cout << (char)219;
	}
}

void Barra::Borrar() {
	for (int i = 0; i < l; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << " ";
	}
}

void Barra::ActualizarPuntos() {
	int x;
	if (lado == 'i') x = 12;
	else if (lado == 'd') x = 109;
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::SetCursorPosition(x, 3);
	cout << "Puntos: " << puntos;
}