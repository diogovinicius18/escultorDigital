#ifndef PUTVOXEL_H
#define PUTVOXEL_H


#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica
{
protected:
    int x, y, z;
    int r, g, b;
    float alpha;
public:
    PutVoxel(int xe,int ye,int ze,int re,int ge,int be,float alphae);
    ~PutVoxel();
    void draw(Sculptor &d);
};

#endif // PUTVOXEL_H
