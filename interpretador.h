#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include<string>
#include<FiguraGeometrica.h>
#include<vector>

class Interpretador{
protected:
    int dimx,dimy,dimz;

public:
    Interpretador();
    std::vector<FiguraGeometrica*> Parse(std::string arq);
    int getX();
    int getY();
    int getZ();
};

#endif // INTERPRETADOR_H
