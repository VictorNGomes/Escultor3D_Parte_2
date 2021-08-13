#include <iostream>
#include<interpretador.h>
#include<string>
#include<vector>
#include<FiguraGeometrica.h>
#include<sculptor.h>

using namespace std;

int main()
{
    std::vector<FiguraGeometrica*> Figs;

    Interpretador parse;



    Figs = parse.Parse("voxel.txt");

    Sculptor *s1;

    s1 = new Sculptor(parse.getX(), parse.getY(), parse.getZ());

    for (size_t i = 0;i<Figs.size();i++){

        Figs[i]->draw(*s1); //chama o metodo draw de cada figura
    }

    s1->writeOFF((char*)"saida.off");
    std::cout<< "Aquivo de saida criado"<<std::endl;


}
