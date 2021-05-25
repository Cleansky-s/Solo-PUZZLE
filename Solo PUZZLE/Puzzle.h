#ifndef JUEGOPM
#define JUEGOPM
#include "Matriz.h"
#include <iostream>
#include <iomanip>


typedef struct {
    tMatrizChar Matriz;
    tMatrizChar Matriz_Des;
    string nombre;
    string file;
    int Num_Max_Acc;
    string Modo;
}tPuzzle;

void mainPuzzle(int num, tPuzzle& jpm);
bool iniciar(tPuzzle& jpm, string modo, int num);
bool cargar(tPuzzle& jpm);
void mostrar(tPuzzle const& jpm);
bool jugar(tPuzzle& jpm);
void accion(tPuzzle& jpm);


#endif