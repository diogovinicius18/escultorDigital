#include "putsphere.h"
#include <math.h>

PutSphere::PutSphere(int dxe,int dye,int dze,int centroXe, int centroYe, int centroZe, int raioe, int re, int ge, int be, float alphae){

    dx = dxe;
    dy = dye;
    dz = dze;
    centroX = centroXe;
    centroY = centroYe;
    centroZ = centroZe;
    raio = raioe;
    r = re;
    g = ge;
    b = be;
    alpha = alphae;

}
PutSphere::~PutSphere(){

}
void PutSphere::draw(Sculptor &d){
    double rd = raio/1.0, distancia;

    d.SetColor(r, g, b, alpha);
    for(int i=0; i < dx; i++)
        for(int j=0; j < dy; j++)
            for(int k=0; k<dz; k++){
                distancia = (i - centroX/1.0)*(i - centroX/1.0)/(rd*rd)+(j - centroY/1.0)*( j- centroY/1.0)/(rd*rd)+
                        (k - centroZ/1.0)*(k - centroZ/1.0)/(rd*rd);
                if(distancia <= 1.0){
                    d.PutVoxel(i,j,k);
                }
            }
}
