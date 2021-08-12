#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"


class Putvoxel: public FiguraGeometrica {
protected:
    int x, y, z;

public:
    Putvoxel(int x, int y, int z, float r, float g, float b, float a);
    ~Putvoxel();
    void draw(Sculptor &s);


};

#endif // PUTVOXEL_H
