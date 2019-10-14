#include "cutsphere.h"


CutSphere::CutSphere(int dxe,int dye,int dze,int centroXe,int centroYe,int centroZe,int raioe){

    centroX = centroXe;
    centroZ = centroYe;
    centroX = centroZe;
    raio = raioe;
    dx = dxe;
    dy = dye;
    dz = dze;
}
CutSphere::~CutSphere(){

}
void CutSphere::draw(Sculptor &d){

    double rd = raio/1.0, distancia;

    for(int i=0; i < dx; i++)
        for(int j=0; j < dy; j++)
            for(int k=0; k < dz; k++){
                distancia = (i - centroX/1.0)*(i - centroX/1.0)/(rd*rd)+(j - centroY/1.0)*(j - centroY/1.0)/(rd*rd)+
                (k - centroZ/1.0)*( k- centroZ/1.0)/(rd*rd);
                if(distancia <= 1.0)
                    d.CutVoxel(i, j, k);
            }
}
