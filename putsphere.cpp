#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutSphere::~PutSphere()
{

}

void PutSphere::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);
    for(int i=0; i<=s.getX(); i++){
        for(int j=0; j<=s.getY(); j++){
             for(int k=0; k<=s.getZ(); k++){
                    if( ( pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2) ) < pow(radius,2) ){
                        s.putVoxel(i,j,k);
                    }

            }
        }
    }
}

