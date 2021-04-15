#include "JuegoPM.h"
using namespace std;

int main() {
	tJuegoPM jpm;
	bool fin = false;
	if (iniciar(jpm,jpm.Modo,jpm.Num_Max_Acc)) {
		while (!fin) {
			mostrar(jpm); 
			jugar(jpm);
			if (jpm.Matriz == jpm.Matriz_Des) {
				fin = true;
				cout << "Has conseguido!!!" << endl;
			}
			else if (jpm.Num_Max_Acc == 0) {
				fin = true;
				cout << "No has conseguido resolver el puzzle :-(" << endl;
			}
			pausa();
		}
	}
	else errc << "Cant load the file, Try again" << endl;
}
