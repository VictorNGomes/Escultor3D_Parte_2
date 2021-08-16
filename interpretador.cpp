#include<interpretador.h>
#include<string>
#include<vector>
#include<FiguraGeometrica.h>
#include<sstream>
#include<fstream>
#include<iostream>
#include<putvoxel.h>
#include<cutvoxel.h>
#include<putbox.h>
#include<cutbox.h>
#include<putsphere.h>
#include<cutsphere.h>
#include<putellipsoid.h>
#include<cutellipsoid.h>
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
        std :: cout<< "Arquivo nao abriu " << std::endl;
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


                     else if(token.compare("putbox")==0){
                                       int x0,y0,z0,x1,y1,z1;
                                       float r, g, b, a;
                                       ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                                       Figuras.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r, g, b, a));

                               }
                    else if(token.compare("cutbox")==0){
                        int x0,y0,z0,x1,y1,z1;
                        ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                        Figuras.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
                  }

                    else if(token.compare("putsphere")==0){
                        int xcenter,ycenter,zcenter,radius;
                        float r, g, b, a;
                        ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                        Figuras.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a ));

                }

                    else if(token.compare("cutsphere")==0){
                        int xcenter,ycenter,zcenter,radius;
                        ss >> xcenter >> ycenter >> zcenter >> radius;
                        Figuras.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));

                }

                    else if(token.compare("putellipsoid")==0){
                        int xcenter, ycenter, zcenter, rx, ry, rz;
                        float r, g, b, a;
                        ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                        Figuras.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz,r, g, b, a));

                }

                    else if(token.compare("cutellipsoid")==0){
                        int xcenter, ycenter, zcenter, rx, ry, rz;
                        ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                        Figuras.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));

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
