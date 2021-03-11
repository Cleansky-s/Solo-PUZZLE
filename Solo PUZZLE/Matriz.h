#ifndef MATRIZ
#define MATRIZ
using namespace std;
typedef struct {
    Matriz Matriz;
    tColor Color;
}tMatrizChar;


bool cargar(tMatrizChar& mat, istream& ent) {
    int num_F, num_C;
    bool estado;
    cin >> num_C >> num_F;
    if (!cin) {
        estado = false;
    }
    else {
        estado = true;
        for (int i = 0; i < num_C; i++) {
            for (int j = 0; j < num_F; j++) {
                ent >> mat.Matriz[i][j];
            }
        }
    }
    return estado;
}
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {
    int i;
    bool tue;
    return tue;
}
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