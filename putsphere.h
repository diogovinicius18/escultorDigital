#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica
{
protected:
    int centroX, centroY, centroZ, raio;
    int r, g, b, dx, dy, dz;
    float alpha;
public:
    PutSphere(int dxe, int dye, int dze, int centroXe, int centroYe, int centroZe, int raioe, int re, int ge, int be, float alphae);
    ~PutSphere();
    void draw(Sculptor &d);
};

#endif // PUTSPHERE_H
