#include <iostream>
#include "figurageometrica.h"
#include "sculptor.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"




using namespace std;

int main()
{
    Sculptor c(10, 10, 10);
    PutBox b1(10, 10, 10, 1, 1, 1, 3, 5, 3, 0.5, 0.5, 0.5, 1.0);
    PutEllipsoid b2(10, 10, 10, 5, 5, 5, 2, 5, 3, 0.5, 0.5, 0.5, 1.0);
    PutSphere  b3 (10, 10, 10, 7, 7, 7, 3, 0.5, 0.5, 0.5, 1.0);


    b1.draw(c);
    b2.draw(c);
    b3.draw(c);


    c.PutVoxel(1, 1, 1);
    c.CutVoxel(1, 1, 1);
    c.WriteOFF("diogo");
    c.WriteVECT("diogo");

    return 0;
}
