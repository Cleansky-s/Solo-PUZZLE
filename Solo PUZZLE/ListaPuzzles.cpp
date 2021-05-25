#include "ListaPuzzles.h"
#include <string>
void inicializar(tPuzzlesReunidos& jr){

	for (int i = 0; i < MAX_PUZZLES; i++) {
		jr[0].puzzle[i] = NULL;
		jr[1].puzzle[i] = NULL;
	}
	jr[0].cont = 0;
	jr[1].cont = 0;
}
bool cargar(tPuzzlesReunidos& jr) {
	ifstream entrada;
	entrada.open("D://c//datosPuzzles.txt");
	bool estado = entrada.is_open();
	if (estado) {
		for (int i = 0; i < 2; i++) {
			entrada >> jr[i].cont;
			entrada.ignore();
			for (int j = 0; j < jr[i].cont; j++) {
				jr[i].puzzle[j] = new tPuzzle;
				getline(entrada, jr[i].puzzle[j]->nombre);
				getline(entrada, jr[i].puzzle[j]->file);
				cargar(*jr[i].puzzle[j]);
			}
		}
		entrada.close();
	}
	else cout << "No encuentra el fichero" << endl;
	return estado;
}
void guardar(const tPuzzlesReunidos& listas) {
	fstream salida;
	salida.open("datosPuzzles.txt");
	bool estado = salida.is_open();
	if (estado) {
		for (int i = 0; i < MODO; i++) {
			salida << listas[i].cont << "\n";
			for (int j = 0; j < listas[i].cont; j++) {
				salida << listas[i].puzzle[j]->nombre << "\n";
				salida << listas[i].puzzle[j]->file << "\n";
			}
		}
	}
}
int elegirPuzzle(tListaPuzzles& lp) {
	mostrar(lp);
	int op;
	cout << "\n" << "Elige un reto:";
	cin >> op;
	while (op < -2 || op > lp.cont) {
		cout << endl;
		cout << "No has elegido bien, vuelva a intentar:";
		cin >> op;
	}
	if (op == -1) {
		ordernar(lp, op);
		op = elegirPuzzle(lp);
	}
	else if (op == -2) {
		ordernar(lp, op);
		op = elegirPuzzle(lp);
	}
	return op;
}
bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p) {
	bool estado = false;
	int pos = l.cont - 1;
	l.cont++;
	if (l.cont < MAX_PUZZLES) {
		while (!estado && pos >= 0) {
			estado = (p->Num_Max_Acc > l.puzzle[pos]->Num_Max_Acc);
			pos--;
		}
		for (int i = pos; i < l.cont; i++) {
			l.puzzle[i] = l.puzzle[i + 1];
		}
		l.puzzle[pos] = p;
		cargar(*l.puzzle[pos]);
	}
	return estado;
}
void mostrar(tListaPuzzles& l) {
	cout << "En esta versión están disponibles los siguientes retos \n \n";
	for (int i = 0; i < l.cont; i++) {
		cout << i + 1 << " " << l.puzzle[i]->nombre << " con un maximo de " << l.puzzle[i]->Num_Max_Acc << " moviminetos" << endl;
	}
	cout << "0 Salir" << endl << "-1 Ordenar la lista de mayor a menor" << endl << "-2 Ordenar la lista de menor a mayor" << endl;
}
void ordernar(tListaPuzzles& l,int op) {
	tPuzzle* aux = NULL;
	for (int i = 0; i < l.cont / 2; i++) {
		aux = l.puzzle[i];
		l.puzzle[i] = l.puzzle[l.cont - 1 - i];
		l.puzzle[l.cont - 1 - i] = aux;
	}
}
void mainPuzzlesReunidos(tPuzzlesReunidos& t) {
	int op;
	int ops;
	int modo;
	tPuzzle opp;
	cout << "1 Resolver un puzzle - 1D" << endl
		<< "2 Resolver un puzzle - 2D" << endl
		<< "3 Añadir un puzzle al catálogo " << endl
		<< "0 Salir" << endl;

	cout << "\n\n" << "Elige una opcion " << endl;
	cin >> op;
	if (op == 1) {
		ops = elegirPuzzle(t[0]);
		if (ops!= 0) {
			mainPuzzle(op - 1,*t[0].puzzle[ops-1]);
		}
		else op = 0;

		mainPuzzlesReunidos(t);
	}
	else if (op == 2) {
		ops = elegirPuzzle(t[1]); 
		if (ops != 0) {
			mainPuzzle(op - 1, *t[1].puzzle[ops-1]);
		}
		else op = 0;

		mainPuzzlesReunidos(t);
	}
	else if (op == 3) {
		cout << "Escriba el nombre del puzzle:";
		cin >> opp.nombre;
		cout << "\n";
		cout << "Escriba nombre del fichero en que se encuentra: ";
		cin >> opp.file;
		cout << "Escriba el modo del puzzle en que se encuentra: ";
		cin >> modo;
		cout << "\n";
		tPuzzle* pointer = new tPuzzle;
		pointer = &opp;
		if (cargar(opp)) {
			insertarOrdenado(t[modo], pointer);
		}
		else
			cout << "No hemos encontrado el fichero que has introducido" << endl;
		
		mainPuzzlesReunidos(t);
	}
	else if (op == 0) {

	}
	else {
		mainPuzzlesReunidos(t);
	}
}