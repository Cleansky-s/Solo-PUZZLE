#include "Matriz.h"
#include <iostream>
#include <fstream>
using namespace std;

bool cargar(tMatrizChar& mat, istream& ent) {
    bool estado;
    ent >> mat.rango_x >> mat.rango_y; //Guarda los rangos
    if (!cin) {
        estado = false;
    }
    else {
        estado = true;
        for (int i = 0; i < mat.rango_x; i++) {
            for (int j = 0; j < mat.rango_y; j++) {
                ent >> mat.Matriz[i][j]; //Guarda los datos para imagenes
            }
        }
    }
    return estado;
}
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {//Sobrecargar ==
    bool estado = false;
    int i = 0;

    if (mat1.rango_x == mat2.rango_x && mat1.rango_y == mat2.rango_y) { //Deben tener el mismo numero de filas y columnas
        estado = true;

        while (estado && i < mat1.rango_x) {  // y comprueba casilla a casilla que coincidan
            int j = 0;

            while (estado && j < mat1.rango_y) {

                if (mat1.Matriz[i][j] != mat2.Matriz[i][j]) {
                    estado = false;
                }

                j++;
            }
            i++;
        }
    }
    return estado;
} bool win(tMatrizChar const& mat1, tMatrizChar const& mat2) {//Sobrecargar ==
    bool estado = false;
    int i = 0;

    if (mat1.rango_x == mat2.rango_x && mat1.rango_y == mat2.rango_y) { //Deben tener el mismo numero de filas y columnas
        estado = true;

        while (estado && i < mat1.rango_x) {  // y comprueba casilla a casilla que coincidan
            int j = 0;

            while (estado && j < mat1.rango_y) {

                if (mat1.Matriz[i][j] != mat2.Matriz[i][j]) {
                    estado = false;
                }

                j++;
            }
            i++;
        }
    }
    return estado;
}
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
    bool estado = false;
    uint8 aux;
    if (pos2.x > mat.rango_x || pos2.y > mat.rango_y) { //No puede ser mayor que los rangos
    }
    else {
        aux = mat.Matriz[pos1.x][pos1.y];  //Guarda el primer variable  **
        mat.Matriz[pos1.x][pos1.y] = mat.Matriz[pos2.x][pos2.y]; //Primer variable igual a otra
        mat.Matriz[pos2.x][pos2.y] = aux; //Segunda variable igual a primera
    }
    return estado;
}
bool swapC(tMatrizChar& mat, int f1, int f2) {
    bool estado = true;
    uint8 aux;
    if (f1 > mat.rango_x || f2 > mat.rango_x) {
        estado = false;
    }
    else {
        for (int i = 0; i < mat.rango_y; i++) {   //**Linea 46
            aux = mat.Matriz[i][f1];
            mat.Matriz[i][f1] = mat.Matriz[i][f2];
            mat.Matriz[i][f2] = aux;
        }
    }
    return estado;
}
bool swapF(tMatrizChar& mat, int c1, int c2){   
    bool estado = true;
    uint8 aux[100];
    if (c1 > mat.rango_y || c1 > mat.rango_y) {
        estado = false;
    }
    else {
        for (int i = 0; i < mat.rango_y; i++) { //**Linea 46
            aux[i] = mat.Matriz[i][c1];
            mat.Matriz[i][c1] = mat.Matriz[i][c2];
            mat.Matriz[i][c2] = aux[i];
        }
    }
    return estado;
}
bool swapD(tMatrizChar& mat, int d) {
    bool estado = true;
    uint8 aux;
    if (mat.rango_x != mat.rango_y || d >= mat.rango_y || d <= -mat.rango_x) {
        estado = false;
    }
    else {
        int i = 0;
        for (int j = d; j < mat.rango_y; j++) {  //d es el diagonal
            aux = mat.Matriz[i][j];          //**Linea 46
            mat.Matriz[i][j] = mat.Matriz[j][i];
            mat.Matriz[j][i] = aux;
            i++;
        }
    }
    return estado;
}
bool voltearF(tMatrizChar& mat, int f) {
    bool estado = true;
    uint8 aux[100];
    
    if (f > mat.rango_x) {
        estado = false;
    }
    else {
        for (int i = 0; i < mat.rango_x; i++) { //**Linea 95, misma logica
            int j = mat.rango_x - 1;
            aux[i] = mat.Matriz[f][i]; //linea 46
            mat.Matriz[f][i] = mat.Matriz[f][j];
            mat.Matriz[f][j] = aux[i];
            j--;
        }
    }
    return estado;
}
bool voltearC(tMatrizChar& mat, int c){
    bool estado = true;
    uint8 aux[100];

    if (c > mat.rango_y) {
        estado = false;
    }
    else {
        for (int i = 0; i < mat.rango_y; i++) {
            int j = mat.rango_x - 1; //Liena 95
            aux[i] = mat.Matriz[i][c];
            mat.Matriz[i][c] = mat.Matriz[j][c];
            mat.Matriz[j][c] = aux[i];
            j--;
        }
    }
    return estado;
}
bool voltearD(tMatrizChar& mat, int d) {
    bool estado = true;
    uint8 aux[100];
    if (d > mat.rango_x || d > mat.rango_y || mat.rango_x != mat.rango_y) {
        estado = false;
    }
    else {
        int j = 0;
        int m = mat.rango_x - d;
        int n = mat.rango_x - 1;
        for (int i = d; i < mat.rango_x; i++) {
            aux[j] = mat.Matriz[j][i];
            mat.Matriz[j][i] = mat.Matriz[m][n];
            mat.Matriz[m][n] = aux[j];
            m--;
            n--;
            j++;
        }
    }
    return estado;
}
void voltearV(tMatrizChar& mat) {
        uint8 aux;
        int medio = mat.rango_x / 2;
        for (int i = 0; i < medio; i++) {
            for(int j = 0;j < mat.rango_x;j++){
                aux = mat.Matriz[j][i];
                mat.Matriz[j][i] = mat.Matriz[j][mat.rango_x - i - 1];
                mat.Matriz[j][mat.rango_x - i - 1] = aux;
        }
    }
}
void voltearH(tMatrizChar& mat) {
    uint8 aux[100];
    int n;
    int medio = mat.rango_y / 2;
    for (int i = 0; i < mat.rango_x; i++) {
        n = 0;
        for (int j = mat.rango_y - 1; j >= medio; j--) {
            aux[i] = mat.Matriz[n][i];
            mat.Matriz[n][i] = mat.Matriz[j][i];
            mat.Matriz[j][i] = aux[i];
            n++;
        }
    }

}
void rotarD(tMatrizChar& mat) {
    tMatrizChar m;
    m.rango_x = mat.rango_y;
    m.rango_y = mat.rango_x;
    int d = mat.rango_x / 2;
    for (int i = 0; i < m.rango_x; i++) {
        for (int j = 0; j < m.rango_y; j++) {
            m.Matriz[i][j] = mat.Matriz[mat.rango_x - j - 1][i];
        }
    }
    mat = m;
}
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) {  //He intentado muchas veces y no he salido
    bool estado = true;
    unsigned char aux;
    if (pos1.x < 1 || pos1.x > mat.rango_y - 2 || pos1.y < 1 || pos1.y > mat.rango_x - 2 ||
        pos2.x < 1 || pos2.x > mat.rango_y - 2 || pos2.y < 1 || pos2.y > mat.rango_x - 2 ||
        (abs(pos1.x - pos2.x) < 3 && abs(pos1.y - pos2.y) < 3))
        estado = false;   //Comprueba que las áreas de las coordenadas se encuentren en la matriz y no se solapen
    else {

        for (int i = 1; i > -2; i--) {

            for (int j = -1; j < 2; j++) {

                if (i == 0 && j == 0)
                    j++;

                aux = mat.Matriz[pos1.y + i][pos1.x + j];
                mat.Matriz[pos1.y + i][pos1.x + j] = mat.Matriz[pos2.y + i][pos2.x + j];
                mat.Matriz[pos2.y + i][pos2.x + j] = aux;
            }
        }
    }

    return estado;
}
bool VoltearID(tMatrizChar& mat) { //Same
    bool estado = true; unsigned char aux;
    if (mat.rango_x != mat.rango_y)
        estado = false;   //Comprueba que la matriz sea cuadrada
    else {

        for (int j = 1; j < mat.rango_y; j++)
            for (int i = 0; i < j; i++) {
                aux = mat.Matriz[i][j];
                mat.Matriz[i][j] = mat.Matriz[j][i];
                mat.Matriz[j][i] = aux;
            }
    }

    return estado;
}
