#ifndef ListP
#define ListP
#include "Puzzle.h"

const int MAX_PUZZLES = 100;
const int MODO = 2;

typedef tPuzzle* tArrayPuzzles[MAX_PUZZLES];

struct tListaPuzzles {
	tArrayPuzzles puzzle;
	int cont;
};
typedef tListaPuzzles tPuzzlesReunidos[MODO];


void inicializar(tPuzzlesReunidos& jr);
bool cargar(tPuzzlesReunidos& jr);
void guardar(const tPuzzlesReunidos& listas);
int elegirPuzzle(tListaPuzzles& lp);
bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p);
void ordernar(tListaPuzzles& l,int op);
void mostrar(tListaPuzzles& l);
void mainPuzzlesReunidos(tPuzzlesReunidos& t);
#endif