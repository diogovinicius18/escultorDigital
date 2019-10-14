#include "putvoxel.h"

PutVoxel::PutVoxel(int xe, int ye, int ze, int re, int ge, int be, float alphae){
    x = xe;
    y = ye;
    z = ze;
    r = re;
    g = ge;
    b = be;
    alpha=alphae;
}
PutVoxel::~PutVoxel(){

}
void PutVoxel::draw(Sculptor &d){
    d.SetColor(r, g, b, alpha);
    d.PutVoxel(x, y, z);
}
