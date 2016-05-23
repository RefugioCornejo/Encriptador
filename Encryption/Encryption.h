//
//  MatrixManager.h
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#ifndef Encryption_h
#define Encryption_h
#include <iostream>
#include <tbb/tbb.h>
#include "Conversor.h"
#include "MatrixManager.h"
using namespace std;

class EncryptionManager
{
    double** Inverse(double** key);
public:
    int **encryptedMessage;
    int **message;
    int **key;
    int n;
    int ** encrypt(int ** message, int rows, int col, int ** key);
    string decrypt(double** key, int ** message,int n);
    void operator()( const tbb::blocked_range2d<size_t>& r) const
    {
        for( size_t i=r.rows().begin(); i!=r.rows().end(); ++i )
            for( size_t j=r.cols().begin(); j!=r.cols().end(); ++j ) {
                float sum = 0;
                for( size_t k=0; k<n; ++k )
                    sum += message[i][k]*key[k][j];
                encryptedMessage[i][j] = sum;
            }
    
   }
    EncryptionManager(int ** message,int n,int ** key)
    {
        this->message=message;
        this->n=n;
        this->key=key;
        Conversor helper;
        encryptedMessage=helper.createMatrix(encryptedMessage, n);
    }
};



#endif /* EncryptionManager_h */
