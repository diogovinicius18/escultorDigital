#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include "vector"
#include "sculptor.h"

Sculptor::Sculptor(int xe,int ye,int ze){
    nLinhas = xe;
    nColunas = ye;
    nPlanos = ze;

    if(nLinhas<=0 || nColunas<=0 || nPlanos<=0){
        nLinhas = 0;
        nColunas = 0;
        nPlanos = 0;
    }

    v = new Voxel**[nLinhas];

    if(v==nullptr){
        cout<<"Não foi possível alocar"<<endl;
        exit(0);
    }

    v[0] = new Voxel*[nLinhas*nColunas];

    if(v[0]==nullptr){
        cout<<"Não foi possível alocar"<<endl;
        exit(0);
    }

    v[0][0] = new Voxel[nLinhas*nColunas*nPlanos];

    if(v[0][0] == nullptr){
        cout<<"Não foi possível alocar"<<endl;
        exit(0);
    }

    for(int i=0; i< nLinhas; i++){
        if (i<(nLinhas-1))
            v[i+1] = v[i]+nColunas;
        for(int j=1; j< nColunas; j++){
            v[i][j] = v[i][j-1] + nPlanos;
            if(j==nColunas-1 && i!=(nLinhas-1))
                v[i+1][0] = v[i][j] + nPlanos;
        }
    }
    for(int i = 0; i < nLinhas; i++)
        for(int j = 0; j < nColunas; j++)
            for(int k = 0; k < nPlanos; k++)
                v[i][j][k].temBloco = false;
}

Sculptor::~Sculptor(){
    if(nLinhas==0 || nColunas==0 || nPlanos==0)
        return;

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::PutVoxel(int xe,int ye,int ze){
    if(xe < 0 || xe > nLinhas || ye < 0 || ye > nColunas || ze < 0 || ze > nPlanos){
        cout <<"Dimensoes inválidas."<<endl;
        exit(0);
    }
    else{
        v[xe][ye][ze].vermelho = r;
        v[xe][ye][ze].azul = b;
        v[xe][ye][ze].verde = g;
        v[xe][ye][ze].transparencia = a;
        v[xe][ye][ze].temBloco = true;
    }
}

void Sculptor::CutVoxel(int xe,int ye,int ze){
    if(xe < 0 || xe > nLinhas || ye < 0 || ye > nColunas || ze < 0 || ze > nPlanos){
        cout <<"Dimensoes inválidas."<<endl;
        exit(1);
    }
    else
        v[xe][ye][ze].temBloco = false;
}

void Sculptor::SetColor(int re, int ge, int be, float alphae){

    if(re>=0 || re <= 255 || ge >= 0 || ge <= 255 || be >= 0 ||be<=255 || alphae>=0 || alphae<=1 ){
        r = re;
        g = ge;
        b = be;
        a = alphae;
    }
    else{
        cout<<"Cores invalidas"<<endl;
        exit(1);
    }
}


void Sculptor::WriteOFF(string arquivo){

    int vertices=0;
    int faces=0;
    int aux=0;

    ofstream fout;



    fout.open("C:/Users/Diogo/Documents/escultorDigital/arquivos/"+arquivo+".off");

    if(fout.is_open())
        cout << "O arquivo .off foi aberto\n";
    else{
        cout << "O arquivo .off nao foi aberto\n";
        exit(1);
    }

    fout<<"OFF"<<endl;

    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].temBloco){
                    vertices = vertices+8;
                    faces = faces+6;
                }

    fout << vertices << " " << faces << " " << 0 <<endl;
    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].temBloco){
                        fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                        fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].temBloco){
                    fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].vermelho<<" "
                    <<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;
                    fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].vermelho<<" "
                    <<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].vermelho<<" "
                    <<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].vermelho<<" "
                    <<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;
                    fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].vermelho<<" "
                    <<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;
                    fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].vermelho<<" "
                    <<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;

                    aux = aux + 8;
                }

    if(fout.is_open())
        cout << "O arquivo .off foi salvo"<<endl;
}

void Sculptor::WriteVECT(string arquivo){

    int cont=0;
    ofstream fout;

    fout.open("C:/Users/Diogo/Documents/escultorDigital/arquivos//"+arquivo+".vect");

    if(fout.is_open())
        cout << "O arquivo .vect foi aberto\n";
    else{
        cout << "O arquivo .vect nao foi aberto\n";
        exit(1);
    }
    fout<<"VECT"<<endl;
    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].temBloco)
                    cont = cont+1;

    fout<<cont<<" "<<cont<<" "<<cont<<endl;

    for(int i=1; i<cont-1; i++)
        fout<<1<<" ";

    fout<<1<<endl;

    for(int i=1; i<cont-1; i++)
        fout << 1 << " ";
    fout << 1 << endl;
    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].temBloco)
                    fout << i << " " << j << " " << k << endl;

    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].temBloco)
                    fout<<v[i][j][k].vermelho<<" "<<v[i][j][k].verde<<" "<<v[i][j][k].azul<<" "<<v[i][j][k].transparencia<<endl;

    if(fout.is_open())
        cout << "O arquivo .vect foi salvo"<<endl;
}
