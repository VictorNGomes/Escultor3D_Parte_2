#include<interpretador.h>
#include<string>
#include<vector>
#include<FiguraGeometrica.h>
#include<sstream>
#include<fstream>
#include<iostream>
#include<putvoxel.h>
#include<cutvoxel.h>
Interpretador::Interpretador(){




}

std::vector<FiguraGeometrica*> Interpretador::Parse(std::string arq)
{


    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;
    std::vector<FiguraGeometrica*> Figuras;

    fin.open(arq);

    if(!fin.is_open()){
        std :: cout<< "Arquivo não abriu " << std::endl;
        exit(0);
    }

    while (fin.good()) {
        std::getline(fin,s); //pega a linha e joga na string s

            ss.clear();
            ss.str(s);
            ss>>token;


                if(token.compare("dim")==0){
                    ss >> dimx >> dimy >> dimz;
                    std::cout<<"dimencao lida"<<std::endl;
                }
                    else if(token.compare("putvoxel")==0){
                        int x0,y0,z0;
                        float r, g, b, a;
                        ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                        Figuras.push_back(new Putvoxel(x0,y0,z0,r, g, b, a));
                        std::cout<<"voxel criado"<<std::endl;
                    }
                    else if(token.compare("cutvoxel")==0){
                        int x0,y0,z0;
                        ss >> x0 >> y0 >> z0;
                        Figuras.push_back(new CutVoxel(x0,y0,z0));
                        std::cout<<"voxel cortado"<< std::endl;


                }


    }
    return Figuras;
}

int Interpretador::getX()
{
    return dimx ;
}

int Interpretador::getY()
{
    return dimy;
}

int Interpretador::getZ()
{
    return dimz;
}
