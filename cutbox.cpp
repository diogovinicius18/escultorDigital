#include "cutbox.h"

CutBox::CutBox(int dxe,int dye,int dze,int xie,int yie,int zie,int xfe,int yfe,int zfe){
    xi=xie;
    yi=yie;
    zi=zie;
    xf=xfe;
    yf=yfe;
    zf=zfe;
    dx=dxe;
    dy=dye;
    dz=dze;
}
CutBox::~CutBox(){

}
void CutBox::draw(Sculptor &d){

    int tamX, tamY, tamZ;

    if(xf > dx)
        tamX = dx;
    else
        tamX = xf;

    if(yi > dy)
        tamY = dy;
    else
        tamY = yf;

    if(zi > dz)
        tamZ = dz;
    else
        tamZ = zf;

    for(int i=xi; i<tamX; i++)
        for(int j=yi; j<tamY; j++)
            for(int k=zi; k<tamZ; k++)
                d.CutVoxel(i,j,k);
}
