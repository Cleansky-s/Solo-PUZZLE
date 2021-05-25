#include "Puzzle.h"

using namespace std;



void mainPuzzle(int num, tPuzzle& jpm) {
	bool fin = false;
	if (iniciar(jpm, jpm.Modo, num)) {
		while (!fin) {
			mostrar(jpm);
			jugar(jpm);
			
			if (jpm.Matriz.Matriz == jpm.Matriz_Des.Matriz) {
				fin = true;
				cout << "Has conseguido!!!" << endl;
			}
			else if (jpm.Num_Max_Acc == 0) {
				fin = true; 
				mostrar(jpm);
				cout << "No has conseguido resolver el puzzle :-(" << endl;
			}
			pausa();
		}
	}
	else cout << "No hemos encontrado el archivo :-(" << endl;
}
bool iniciar(tPuzzle& jpm, string modo, int num) {
	bool estado = true;
	int d = num;
	if (d == 0) {
		jpm.Modo = "1D";
	}
	else if (d == 1){
		jpm.Modo = "2D";
	}
	else estado = false;
	return estado;
}
bool cargar(tPuzzle& jpm) {
	ifstream entrada;
	entrada.open(jpm.file);
	bool estado = entrada.is_open();
	if (estado&&cargar(jpm.Matriz, entrada)&&cargar(jpm.Matriz_Des, entrada)) {
		entrada >> jpm .Num_Max_Acc;
		entrada.close();
	}
	else estado = false;
	return estado; 
}
void mostrar(tPuzzle const& jpm) {
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
bool jugar(tPuzzle& jpm) {
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
void accion(tPuzzle& jpm) {
	string accion;
	cin >> accion;
	int n, m;
	tCoor pos1, pos2;
	if (jpm.Modo == "1D") {  // Si es igual a 1D
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
	else if (jpm.Modo == "2D") {// Si es igual a 2D
		if (accion == "VV") {
			voltearV(jpm.Matriz);
		}
		else if (accion == "SA") {
			cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y;
			swap(jpm.Matriz, pos1, pos2);
		}
		else if (accion == "VH") {
			voltearH(jpm.Matriz);
		}
		else if (accion == "RD") {
			rotarD(jpm.Matriz);
		}
		else { cout << "Has introducido mal" << endl; }
	}
}


