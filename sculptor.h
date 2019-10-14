#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include "vector"

using namespace std;

struct Voxel {
  float vermelho,verde,azul;
  float transparencia;
  bool temBloco;
};

class Sculptor
{
protected:
    Voxel ***v;
    int nLinhas, nColunas,nPlanos;
    int r,g,b;
    float a;
public:
    Sculptor(int xe,int ye,int ze);
    ~Sculptor();
    void SetColor(int r,int g,int b,float a);
    void PutVoxel(int x,int y,int z);
    void CutVoxel(int x,int y,int z);
    void WriteOFF(string arquivo);
    void WriteVECT(string arquivo);
};

#endif // SCULPTOR_H
