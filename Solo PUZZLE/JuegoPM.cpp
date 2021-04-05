#include "JuegoPM.h"

using namespace std;


int menu() {

}
bool iniciar(tJuegoPM& jpm, string modo, int num) {
	bool estado = true;
	cout << " Elegir el modo que quieras:" << endl;
	cin >> modo;
	cout << "Elegir el numero de acciones que quieras" << endl;
	cin >> num;
	cargar(jpm);
	return estado;
}
bool cargar(tJuegoPM& jpm) {
	string name;
	bool estado = true;
	cout << "Nombre del archivo(sin extension ni modo del juego) :" << endl;
	cin >> name;
	fstream entrada;
	entrada.open(name);
	if (entrada.is_open()&&cargar(jpm.Matriz, entrada)) {
	}
	else estado = false;
	return estado;
}
void mostrar(tJuegoPM const& jpm) {
	for (int i = -1; i <= jpm.Matriz.rango_x; i++) {
		if (i < 0) {
			cout << " ";
		}
		else cout << i;
	}
	for (int i = 0; i <= jpm.Matriz.rango_x;i++) {
		cout << i;
		for (int j = 0; j < jpm.Matriz.rango_y; j++) {
			colorCTA(jpm.Matriz.Matriz[i][j], 0);
		}
	}
}
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);
