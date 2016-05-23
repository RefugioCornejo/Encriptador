//
//  EncryptionAlgorithm.h
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#ifndef Conversor_h
#define Conversor_h
#include <iostream>
using namespace std;

class Conversor
{
    public:
    int **  toMatrix(string input, int rows, int col);
    void    printMatrix(int ** matrix, int row,int col);
    void    printMatrix(double ** matrix, int row,int col);
    void    destoyMatrix(int ** matrix, int row, int col);
    string  toString(int ** matrix,int row, int col);
    int **  createMatrix(int **matrix,int n);
    double** createMatrix(double ** matrix, int n);
    double** toDouble(int ** matrix, int n);
    int**   toInt(double **matrix, int n);
    double** createIdentity(double**matrix, int n);
};

#endif /* Conversor_h */
