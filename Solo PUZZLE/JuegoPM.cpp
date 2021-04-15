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
	cout << "Elegir el modo que quieras:" << endl;
	cin >> jpm.Modo;
	if (cargar(jpm)) {

	}
	else estado = false;
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
	cout << endl << "El numero de intento es " << jpm.Num_Max_Acc << endl;
}
bool jugar(tJuegoPM& jpm) {
	bool estado = true;
	if (jpm.Num_Max_Acc == 0) {
		estado = false;
	}
	else {
		cout << "Introducir el accion que quieres realizar:" << endl;
		accion(jpm);
		jpm.Num_Max_Acc = jpm.Num_Max_Acc - 1;
	}
	return estado;
}
void accion(tJuegoPM& jpm) {
	string accion;
	cin >> accion;
	int n, m;
	tCoor pos1, pos2;
	if (jpm.Modo == "1D") {
		if (accion == "SF") {
			cin >> n >> m;
			swapF(jpm.Matriz, n, m);
		}
		else if (accion == "SC") {
			cin >> n >> m;
			swapC(jpm.Matriz, n, m);
		}
		else if (accion == "SD") {
			cin >> n;
			swapD(jpm.Matriz, n);
		}
		else if (accion == "VF") {
			cin >> n;
			voltearF(jpm.Matriz, n);
		}
		else if (accion == "VC") {
			cin >> n;
			voltearC(jpm.Matriz, n);
		}
		else if (accion == "VD") {
			cin >> n;
			voltearD(jpm.Matriz, n);
		}
		else
			cout << "Has introducido mal" << endl;
	}
	else if (jpm.Modo == "2D") {
		if (accion == "VV") {
		}
		else if (accion == "SA") {
			cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y;
			swap(jpm.Matriz, pos1, pos2);
		}
		else if (accion == "VH") {
		}
		else if (accion == "RD") {
		}
		else cout << "Has introducido mal" << endl;
	}
	}

