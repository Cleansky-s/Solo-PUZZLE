#ifndef COORDENADA
#define COORDENADA
const int DIM_MAX = 64;
typedef struct {
	int x;
	int y;
}tCoor;

bool operator == (tCoor c1, tCoor c2);
bool operator != (tCoor c1, tCoor c2);
tCoor operator + (tCoor c1, tCoor c2);


#endif