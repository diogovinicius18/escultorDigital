#ifndef PUTBOX_H
#define PUTBOX_H


#include "figurageometrica.h"
#include "sculptor.h"

class PutBox : public FiguraGeometrica{
protected:
    int xi, yi, zi, xf, yf, zf, dx, dy, dz;
    int r, g, b;
    float alpha;
public:
    PutBox(int dxe,int dye,int dze,int xie,int yie,int zie,int xfe,int yfe,int zfe,int re,int ge,int be,float alphae);
    ~PutBox();
    void draw(Sculptor &d);
};
#endif // PUTBOX_H
