#ifndef JUEGOPM
#define JUEGOPM
#include "Matriz.h"
#include <iostream>

typedef struct {
    tMatrizChar Matriz;
    int Num_Max_Acc;
    string Modo;
}tJuegoPM;

void mainJuegoPM();
int menu();
bool iniciar(tJuegoPM& jpm, string modo, int num);
bool cargar(tJuegoPM& jpm);
void mostrar(tJuegoPM const& jpm);
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);


#endif