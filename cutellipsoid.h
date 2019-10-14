#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"
#include "sculptor.h"


class CutEllipsoid : public FiguraGeometrica
{
protected:
    int centroX, centroY, centroZ;
    int raioX, raioY, raioZ;
    int dx, dy, dz;
public:
    CutEllipsoid(int dxe,int dye,int dze,int centroXe,int centroYe,int centroZe,int raioXe,int raioYe,int raioZe);
    virtual ~CutEllipsoid();
    void draw(Sculptor &d);
};

#endif // CUTELLIPSOID_H
