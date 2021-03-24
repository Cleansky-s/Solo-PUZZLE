#ifndef COORDENADA
#define COORDENADA

const int DIM_MAX = 64;
typedef struct {
	int t[DIM_MAX][DIM_MAX];
}tCoor;
bool operator == (tCoor c1, tCoor c2) {
	if (c1 == c2) {
		return true;
	}
}
bool operator != (tCoor c1, tCoor c2);
tCoor operator + (tCoor c1, tCoor c2);


#endif