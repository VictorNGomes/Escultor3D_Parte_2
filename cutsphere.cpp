#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &s)
{
    for(int i=0; i<=s.getX(); i++){
        for(int j=0; j<=s.getY(); j++){
             for(int k=0; k<=s.getZ(); k++){
                    if( ( pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2) ) < pow(radius,2) ){
                        s.cutVoxel(i,j,k);
                    }

            }
        }
    }
}

