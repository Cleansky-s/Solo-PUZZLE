#include "JuegoPM.h"

using namespace std;


int menu() {
	int opcion;
	cout << "Elegir el tipo del juego introduciendo 1 o 2, 0 para salir" << endl;
	cin >> opcion;
	while (opcion != 0) {
		if (opcion > 2) { 
			cout << "Lo sentimos, usted ha introducido el numero incorrecto, vuelva a introducir : " << endl;
			cin >> opcion; 
		}
	}
	return opcion;
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
	ifstream entrada;
	entrada.open(name);
	if (entrada.is_open()&&cargar(jpm.Matriz, entrada)&& cargar(jpm.Matriz_Des, entrada)) {
		
		entrada >> jpm .Num_Max_Acc;
		entrada.close();
	}
	else estado = false;
	return estado; 
}
void mostrar(tJuegoPM const& jpm) {
	cout << " Matriz de Origen" << endl;
	cout << "  ";
	for (int i = 0; i < jpm.Matriz.rango_x; i++) {
		cout << setw(2) << i;
	}
	cout << endl;
	for (int i = 0; i < jpm.Matriz.rango_y;i++) {
		cout << setw(2) << i;
		for (int j = 0; j < jpm.Matriz.rango_x; j++) {
			colorCTA(jpm.Matriz.Matriz[i][j] - 48, jpm.Matriz.Matriz[i][j] - 48);
			cout << "  ";
		}
		colorCTA(15, 0);
		cout << endl;
	}
	cout << endl;
	cout << " Matriz de Destinario" << endl << "  ";
	for (int i = 0; i < jpm.Matriz_Des.rango_x; i++) {
		cout << setw(2) << i;
	}
	cout << endl;
	for (int i = 0; i < jpm.Matriz_Des.rango_y; i++) {
		cout << setw(2) << i;
		for (int j = 0; j < jpm.Matriz_Des.rango_x; j++) {
			colorCTA(jpm.Matriz_Des.Matriz[i][j] - 48, jpm.Matriz_Des.Matriz[i][j] - 48);
			cout << "  ";
		}
		colorCTA(15, 0);
		cout << endl;
	}
	cout << endl << "El numero de intento es " << jpm.Num_Max_Acc;
}
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);