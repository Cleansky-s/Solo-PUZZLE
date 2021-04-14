#include "JuegoPM.h"
using namespace std;

int main() {
	tJuegoPM jpm;
	bool fin = false;
	if (cargar(jpm)) {
		mostrar(jpm);
	}
	else cout << "Cant load , Try again" << endl;
}
