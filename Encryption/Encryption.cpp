//
//  MatrixManager.cpp
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#include "Encryption.h"
#include "Conversor.h"
#include <math.h>

int ** EncryptionManager::encrypt(int ** message, int rows, int col, int ** key)
{
    Conversor helper;

    int **encryptedMessage;
    encryptedMessage=helper.createMatrix(encryptedMessage, rows);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            for (int k=0; k<rows; k++) {
                encryptedMessage[i][j]+= message[i][k]*key[k][j];
            }
        }
    }
 return encryptedMessage;
}
string EncryptionManager::decrypt(double** key, int ** message, int N)
{
    Conversor helper;
    
    double **encryptedMessage;
    double **privateKey = Inverse(key);
    encryptedMessage=helper.createMatrix(encryptedMessage, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <N; j++) {
            for (int k=0; k<N; k++) {
                encryptedMessage[i][j]+= message[i][k]*privateKey[k][j];
            }
        }
    }
    int **mess=helper.toInt(encryptedMessage, N);
   string mensaje= helper.toString(mess, N, N);

    return mensaje;
}

double**  EncryptionManager::Inverse(double** key){

    Conversor convert;
    double** Identity, temp;
    Identity=convert.createIdentity(Identity, this->n);
   
    for(int k=0;k<n;k++)
    {
        temp=key[k][k];
        for(int j=0;j<n;j++){
            key[k][j]/=temp;
            Identity[k][j]/=temp;
        }
        for(int i=0;i<n;i++)
        {
            temp=key[i][k];
            for(int j=0;j<n;j++)
            {
                if(i==k)
                    break;
                key[i][j]-=key[k][j]*temp;
                Identity[i][j]-=Identity[k][j]*temp;                      
            }
        }
    }
    return Identity;
}
