#include "pch.h"
#include <conio.h>
#include <ctime>
#include "Pelota.h"
#include "Rectangulo.h"
#include "Funciones.h"
using namespace System;
using namespace std;

bool IniciarJuego();

int main()
{
    Console::SetWindowSize(130, 40);
    Console::CursorVisible = false;
    while (IniciarJuego()) {
        system("cls");
        IniciarJuego();
    }
    _getch();
}

bool IniciarJuego() {
    CrearMapa();
    srand(time(NULL));
    //Creo los rectángulos y les doy las medidas
    char tecla;
    Rectangulo* rectangulo1 = new Rectangulo();
    rectangulo1->cambiar_a(1);
    rectangulo1->cambiar_l(3);
    rectangulo1->cambiar_x(12);
    rectangulo1->cambiar_y(6);

    Rectangulo* rectangulo2 = new Rectangulo();
    rectangulo2->cambiar_a(1);
    rectangulo2->cambiar_l(3);
    rectangulo2->cambiar_x(116);
    rectangulo2->cambiar_y(6);

    //Creo las barras, les doy medidas y las inserto en el rectangulo
    Barra* Jugador1 = new Barra();
    Jugador1->cambiar_x(rectangulo1->retornar_x());
    Jugador1->cambiar_y(rectangulo1->retornar_y());
    Jugador1->cambiar_l(5);
    Jugador1->cambiar_lado('i');
    Jugador1->cambiar_puntos(0);
    rectangulo1->cambiar_Barra(Jugador1);

    Barra* Jugador2 = new Barra();
    Jugador2->cambiar_x(rectangulo2->retornar_x());
    Jugador2->cambiar_y(rectangulo2->retornar_y());
    Jugador2->cambiar_l(5);
    Jugador2->cambiar_lado('d');
    Jugador2->cambiar_puntos(0);
    rectangulo2->cambiar_Barra(Jugador2);

    //Creo la pelota
    Pelota* objPelota = new Pelota();
    objPelota->cambiar_x(64);
    objPelota->Reset();//Le doy los valores restantes aleatorios



    //Dibujo los rectángulos
    rectangulo1->Dibujar();
    rectangulo2->Dibujar();

    //Pongo los puntajes
    Jugador1->ActualizarPuntos();
    Jugador2->ActualizarPuntos();

    int repeticiones = 0;
    int velocidad = 10000000;
    /*
    Velocidades:
    Estándar: 10000000
    Velocidad 1: velocidad * 2
    Velocidad 2: velocidad * 1.6
    Velocidad 3: Velocidad * 1.3
    Velocidad 4: Velocidad
    Velocidad 5: Velocidad * 0.7
    */

    while (1) {
        //Movimiento de la pelota
        if (repeticiones == velocidad) {
            objPelota->Mover(Jugador1, Jugador2);// Le mando a los jugadores para que la pelota sepa donde están
            
            repeticiones = 0;
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == 'w') {
                rectangulo1->cambiar_dy(-1);
                rectangulo1->Mover(4, 35, 1);
            }
            if (tecla == 's') {
                rectangulo1->cambiar_dy(1);
                rectangulo1->Mover(4, 35, 0);
            }
            if (tecla == 'o') {
                rectangulo2->cambiar_dy(-1);
                rectangulo2->Mover(4, 35, 1);
            }
            if (tecla == 'l') {
                rectangulo2->cambiar_dy(1);
                rectangulo2->Mover(4, 35, 0);
            }
        }
        }

        repeticiones++;
        if (Jugador1->retornar_puntos() == 10) {
            objPelota->Borrar();
            Console::SetCursorPosition(33, 19);
            Console::ForegroundColor = ConsoleColor::White;
            cout << "WINNER!!";
            break;
        }
        else if (Jugador2->retornar_puntos() == 10) {
            objPelota->Borrar();
            Console::SetCursorPosition(87, 19);
            Console::ForegroundColor = ConsoleColor::White;
            cout << "WINNER!!";
            break;
        }
    }

    Console::SetCursorPosition(42, 37);
    Console::ForegroundColor = ConsoleColor::White;
    cout << "Pulse cualquier tecla para reiniciar el juego";
    _sleep(2000);
    for (;;) {
        if (_kbhit()) return 1;
    }

    
}
