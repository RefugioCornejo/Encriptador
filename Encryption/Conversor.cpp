//
//  EncryptionAlgorithm.cpp
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#include "Conversor.h"
#include <math.h>

int ** Conversor::toMatrix(string input,int rows,int col)
{
    int **matrix = new int*[rows];
    int offset=0;
    for(int i=0; i<rows; i++)
    {
        matrix[i]=new int[col];
        for(int j=0; j<col; j++)
        {
            if(offset<input.length())
            {
                int value= (int)input[offset];
                matrix[i][j]=value;
                offset++;
            }
            else
            {
                matrix[i][j]=0;
            }
        }
    }
    
    return matrix;
}
void Conversor::printMatrix(int **Matrix, int rows, int col)
{
    for(int i=0; i<rows; i++)
    {
        cout<<"[ ";
        for(int j=0; j<col; j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }

}
void Conversor::printMatrix(double **Matrix, int rows, int col)
{
    for(int i=0; i<rows; i++)
    {
        cout<<"[ ";
        for(int j=0; j<col; j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    
}
string Conversor::toString(int ** matrix, int rows, int cols)
{
    string output;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j]!=0)
                output+=(char)matrix[i][j];
        }
    }
    return output;
}

void Conversor::destoyMatrix(int ** matrix, int rows, int col)
{
    for(int i=0; i<rows; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    
}

int ** Conversor::createMatrix(int ** matrix, int n)
{
    matrix = new int*[n];
    for(int i=0; i<n; i++)
    {
        matrix[i]=new int[n];
    }
    return matrix;
}
double ** Conversor::createMatrix(double ** matrix, int n)
{
    matrix = new double*[n];
    for(int i=0; i<n; i++)
    {
        matrix[i]=new double[n];
    }
    return matrix;
}

double** Conversor::toDouble(int **matrix, int n)
{
    double ** cast;
    cast = new double*[n];
    for(int i=0; i<n; i++)
    {
        cast[i]=new double[n];
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            cast[i][j]=matrix[i][j];
        }
    
    }
    return cast;
}
int** Conversor::toInt(double **matrix, int n)
{
    int ** cast;
    cast = new int*[n];
    for(int i=0; i<n; i++)
    {
        cast[i]=new int[n];
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            double num = matrix[i][j];
            cast[i][j]=round(num);
        }
        
    }
    return cast;
}
double ** Conversor::createIdentity(double ** matrix, int n)
{
    matrix = new double*[n];
    for(int i=0; i<n; i++)
        matrix[i]=new double[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                matrix[i][j]=1;
            else
                matrix[i][j]=0;
        }
    }
    return matrix;
}




