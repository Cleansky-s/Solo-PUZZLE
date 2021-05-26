#ifndef MATRIZ
#define MATRIZ
#include "Coordenada.h"
#include "UtilidadeSYS.h"
#include <fstream>
typedef uint8 Matriz[DIM_MAX][DIM_MAX];
typedef struct {
    Matriz Matriz;
    int rango_x;
    int rango_y;
}tMatrizChar;

bool cargar(tMatrizChar& mat, istream& ent);
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);
bool win(tMatrizChar const& mat1, tMatrizChar const& mat2);
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);
bool swapD(tMatrizChar& mat, int d);
bool voltearF(tMatrizChar& mat, int f);
bool voltearC(tMatrizChar& mat, int c);
bool voltearD(tMatrizChar& mat, int d);
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);
void rotarD(tMatrizChar& mat);
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool VoltearID(tMatrizChar& mat);


#endif
