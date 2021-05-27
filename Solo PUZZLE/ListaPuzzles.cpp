#include "ListaPuzzles.h"
#include <string>
void inicializar(tPuzzlesReunidos& jr){

	for (int i = 0; i < MAX_PUZZLES; i++) { //Iniacializar array de punteros
		jr[0].puzzle[i] = NULL;
		jr[1].puzzle[i] = NULL;
	}
	jr[0].cont = 0;
	jr[1].cont = 0;
}
bool cargar(tPuzzlesReunidos& jr) { //cargar las listas y los datos de puzzles
	ifstream entrada;
	entrada.open("datosPuzzles.txt"); 
	bool estado = entrada.is_open();
	if (estado) {
		for (int i = 0; i < 2; i++) { //cargar los datos de puzzles
			entrada >> jr[i].cont;
			entrada.ignore();
			for (int j = 0; j < jr[i].cont; j++) {
				jr[i].puzzle[j] = new tPuzzle;
				getline(entrada, jr[i].puzzle[j]->nombre);
				getline(entrada, jr[i].puzzle[j]->file);
				cargar(*jr[i].puzzle[j]); // cargar el puzzle del que encuentra en la lista de datos
			}
		}
		entrada.close(); //cierre la entrada
	}
	else cout << "No encuentra el fichero" << endl;
	return estado;
}
void guardar(const tPuzzlesReunidos& listas) { //Guarda los cambios
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
int elegirPuzzle(tListaPuzzles& lp) { //Una funcion que vuele el opcion que ha elegido el usuario
	mostrar(lp);
	int op;
	cout << "\n" << "Elige un reto:";
	cin >> op;
	borrar();
	while (op < -2 || op > lp.cont) {//si es mayor que la lista o menor que -2
		cout << endl;
		cout << "No has elegido bien, vuelva a intentar:";
		cin >> op;
	}
	if (op == -1) {  //Se ordena
		ordernar(lp, op);
		op = elegirPuzzle(lp);
	}
	else if (op == -2) {
		ordernar(lp, op);
		op = elegirPuzzle(lp);
	}
	return op;
}
bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p) { //Insertar un tPuzzle a la lista
	bool estado = false;
	int pos = l.cont - 1;
	if (l.cont < MAX_PUZZLES) { //No puede ser mayor que el maximo puzzles
		while (!estado && pos >= 0) {
			estado = (p->Num_Max_Acc > l.puzzle[pos]->Num_Max_Acc); //Se ordena de forma menor a mayor
			pos--;
		}pos += 2;
		for (int i = l.cont; i > pos; i--) {
			l.puzzle[i] = l.puzzle[i - 1];
		}
		l.cont++;
		l.puzzle[pos] = p;
		cargar(*l.puzzle[pos]);
	}
	return estado;
}
void mostrar(tListaPuzzles& l) { //Mostrar la lista de puzzles
	cout << "En esta versión están disponibles los siguientes retos \n \n";
	for (int i = 0; i < l.cont; i++) {
		cout << i + 1 << " " << l.puzzle[i]->nombre << " con un maximo de " << l.puzzle[i]->Num_Max_Acc << " moviminetos" << endl;
	}
	cout << "0 Salir" << endl << "-1 Ordenar la lista de mayor a menor" << endl << "-2 Ordenar la lista de menor a mayor" << endl;
}
void ordernar(tListaPuzzles& l,int op) { //Se ordena de forma inversa.
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
	cout << "1 Resolver un puzzle - 1D" << endl //el menu principal
		<< "2 Resolver un puzzle - 2D" << endl
		<< "3 Añadir un puzzle al catálogo " << endl
		<< "0 Salir" << endl;

	cout << "\n\n" << "Elige una opcion " << endl;
	cin >> op;   //Opcion que puede elegir
	borrar();
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
		cout << "Escriba el modo del puzzle en que se encuentra: (1:1D,2:2D)";
		cin >> modo;
		modo--;
		cout << "\n";
		tPuzzle* pointer = new tPuzzle;  //Un puntero que asigna a tPuzzle
		pointer = &opp; // Se asigna a la direccion de opp
		if (cargar(opp)) { //Si se encuentra y se puede cargar
			insertarOrdenado(t[modo], pointer);
			guardar(t); //Guarda el cambio
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