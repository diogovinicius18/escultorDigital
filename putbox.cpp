#include "putbox.h"

PutBox::PutBox(int dxe, int dye, int dze, int xie, int yie, int zie, int xfe, int yfe, int zfe, int re, int ge, int be, float alphae){
    xi = xie;
    yi = yie;
    zi = zie;
    xf = xfe;
    yf = yfe;
    zf = zfe;
    dx= dxe;
    dy= dye;
    dz= dze;
    r = re;
    g = ge;
    b = be;
    alpha=alphae;
}
PutBox::~PutBox(){

}
void PutBox::draw(Sculptor &d){

    int tamX, tamY, tamZ;
    d.SetColor(r, g, b,alpha);

    if(xf > dx)
        tamX = dx;
    else
        tamX = xf;

    if(yf > dy)
        tamY = dy;
    else
        tamY = yf;

    if(zf > dz)
        tamZ = dz;
    else
        tamZ = zf;

    for(int i=xi; i<tamX; i++)
        for(int j=yi; j<tamY; j++)
            for(int k=zi; k<tamZ; k++)
                d.PutVoxel(i,j,k);
}
