#include "cutvoxel.h"

CutVoxel::CutVoxel(int xe,int ye,int ze){
    xi = xe;
    yi = ye;
    zi = ze;
}
CutVoxel::~CutVoxel(){

}
void CutVoxel::draw(Sculptor &d){
    d.CutVoxel(xi, yi, zi);
}
