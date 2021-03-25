#include "JuegoPM.h"

using namespace std;


void mainJuegoPM();
int menu();
bool iniciar(tJuegoPM& jpm, string modo, int num);
bool cargar(tJuegoPM& jpm);
void mostrar(tJuegoPM const& jpm) {
	for (int i = -1; i <= jpm.Matriz.rango_x;i++) {
		for (int j = -1; j < jpm.Matriz.rango_y; j++) {
			
		}
	}
}
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);
