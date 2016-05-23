//
//  KeyGen.cpp
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#include "KeyGen.h"
#include "Conversor.h"
#include <fstream>
static bool isprime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int ** KeyGen:: GenerateKey(int rows, int cols)
{

    int cont=0;
    int ** privateKey;
    Conversor helper;
    privateKey=helper.createMatrix(privateKey, rows);
    for(int num = 2,i=0,j=0; cont<rows*cols; num++){
        if(isprime(num))
        {
            cont++;
            privateKey[i][j++] = num;
            if(j == cols){
                j = 0;
                i++;
            }
        }
    }
    
    return privateKey;
}

int ** KeyGen:: GenerateKey(int n)
{
    int ** privateKey;
    Conversor helper;
    privateKey=helper.createMatrix(privateKey,n);
    ifstream file("/Users/RCO/Google\ Drive/8vo/Programación\ Concurrente\ y\ Distribuida/Encryption/Encryption/Primes.txt");
    if(file.good())
    {
        int num;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                file.read((char *)&num, sizeof(int));
                privateKey[i][j]=num;
            }
        
    }
    else{
    
        cout<<"Error could not load the file"<<endl;
    }
    
    return privateKey;
}

