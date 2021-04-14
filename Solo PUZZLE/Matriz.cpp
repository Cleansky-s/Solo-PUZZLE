#include "Matriz.h"
#include <iostream>
#include <fstream>
using namespace std;

bool cargar(tMatrizChar& mat, istream& ent) {
    bool estado;
    ent >> mat.rango_x >> mat.rango_y; 
    if (!cin) {
        estado = false;
    }
    else {
        estado = true;
        for (int i = 0; i < mat.rango_x; i++) {
            for (int j = 0; j < mat.rango_y; j++) {
                ent >> mat.Matriz[i][j];
            }
        }
    }
    return estado;
}

bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {
    int i = 0;
    int j = 0;
    bool estado = true;
    while (i < DIM_MAX && estado) {
        while (j < DIM_MAX && estado) {
            if (mat1.Matriz[i][j] == mat2.Matriz[i][j]) {
                j++;
            }
            else estado = false;
        }
        i++;
    }

    return estado;
}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
    bool estado = false;
    uint8 aux;
    if (pos2.x > mat.rango_x || pos2.y > mat.rango_y) {
    }
    else {
        aux = mat.Matriz[pos1.x][pos1.y];
        mat.Matriz[pos1.x][pos1.y] = mat.Matriz[pos2.x][pos2.y];
        mat.Matriz[pos2.x][pos2.y] = aux;
    }
    return estado;
}

bool swapF(tMatrizChar& mat, int f1, int f2) {
    bool estado = true;
    uint8 aux[100];
    f1 = f1 - 1;
    f2 = f2 - 1;
    if (f1 > mat.rango_x || f2 > mat.rango_x) {
        estado = false;
    }
    else {
        for (int i = 0; i < mat.rango_x; i++) {
            aux[i] = mat.Matriz[f1][i];
            mat.Matriz[f1][i] = mat.Matriz[f2][i];
            mat.Matriz[f2][i] = aux[i];
        }
    }
    return estado;
}

bool swapC(tMatrizChar& mat, int c1, int c2){
    bool estado = true;
    uint8 aux[100];
    c1 = c1 - 1;
    c1 = c1 - 1;
    if (c1 > mat.rango_y || c1 > mat.rango_y) {
        estado = false;
    }
    else {
        for (int i = 0; i < mat.rango_y; i++) {
            aux[i] = mat.Matriz[i][c1];
            mat.Matriz[i][c1] = mat.Matriz[i][c2];
            mat.Matriz[i][c2] = aux[i];
        }
    }
    return estado;
}

bool swapD(tMatrizChar& mat, int d) {
    bool estado = true;
    uint8 aux[100];
    d = d - 1;
    if (d > mat.rango_y || d > mat.rango_y || mat.rango_x != mat.rango_y) {
        estado = false;
    }
    else {
        for (int i = d; i < mat.rango_x; i++) {
            int j = mat.rango_x - 1;
            aux[i]= mat.Matriz[i][i];
            mat.Matriz[i][i] = mat.Matriz[j][j];
            mat.Matriz[j][j] = aux[i];
            j--;
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
        for (int i = 0; i < mat.rango_x; i++) {
            int j = mat.rango_x - 1;
            aux[i] = mat.Matriz[f][i];
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
            int j = mat.rango_x - 1;
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
    if (d > mat.rango_y || d > mat.rango_y || mat.rango_x != mat.rango_y) {
        estado = false;
    }
    else {
        for (int i = d; i < mat.rango_x; i++) {
            int j = 0;
            aux[i] = mat.Matriz[i][j];
            j++;
        }
    }
    return estado;
}
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);
void rotarD(tMatrizChar& mat);
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool VoltearID(tMatrizChar& mat);
