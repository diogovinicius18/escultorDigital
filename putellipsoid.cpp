#include "putellipsoid.h"
#include "cmath"

PutEllipsoid::PutEllipsoid(int dxe,int dye,int dze,int centroXe, int centroYe, int centroZe
                           , int raioXe, int raioYe, int raioZe, int re, int ge, int be, float alphae){
    centroX = centroXe;
    centroY = centroYe;
    centroZ = centroZe;
    raioX = raioXe;
    raioY = raioYe;
    raioZ = raioZe;
    r = re;
    g = ge;
    b = be;
    alpha = alphae;
    dx = dxe;
    dy = dye;
    dz = dze;
}
PutEllipsoid::~PutEllipsoid(){

}
void PutEllipsoid::draw(Sculptor &d){
    double raioPutX = raioX/1.0, raioPutY = raioY/1.0, raioPutZ = raioZ/1.0, distancia;
    d.SetColor(r, g, b, alpha);
    for(int i=0; i < dx; i++)
        for(int j=0; j < dy; j++)
            for(int k=0; k < dz; k++){
                distancia = (i - centroX/1.0)*(i - centroX/1.0)/(raioPutX*raioPutX)+(j - centroY/1.0)*
                        (j - centroY/1.0)/(raioPutY*raioPutY) +
                        (k - centroZ/1.0)*(k - centroZ/1.0)/(raioPutZ*raioPutZ);
                if(distancia <= 1.0){
                    d.PutVoxel(i,j,k);
                }
            }
}
