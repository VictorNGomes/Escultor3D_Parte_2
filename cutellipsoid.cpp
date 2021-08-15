#include "cutellipsoid.h"
#include <cmath>
CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

CutEllipsoid::~CutEllipsoid()
{

}

void CutEllipsoid::draw(Sculptor &s)
{
    for(int i=0; i<=s.getX(); i++){
        for(int j=0; j<=s.getY(); j++){
             for(int k=0; k<=s.getZ(); k++){
                    if(  (pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) < 1 ){
                        s.cutVoxel(i,j,k);
                    }

            }
        }
      }
}

