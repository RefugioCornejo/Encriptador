//
//  main.cpp
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "FileManager.h"
#include "Conversor.h"
#include "KeyGen.h"
#include "Encryption.h"
#include <tbb/tbb.h>
#include <time.h>

int **matrix;
int**key;
int ** encryptar(int **matrix,int n,int ** key);

int main(int argc, const char * argv[])
{
    FileManager filemanager;
    Conversor   convert;
    KeyGen      keyGen;
   
    //***********************GET FILE TO ENCRYPT AND EXPORT TO MEMORY**************************************************
    filemanager.loadInput("/Users/RCO/Google\ Drive/8vo/Programación\ Concurrente\ y\ Distribuida/Encryption/Encryption/MyFile.txt");
    string input= filemanager.getInput();
    //cout<<input<<endl;
    size_t length = input.size();
    cout<<length<<" Caracteres "<<endl;
    double n = sqrt(length);
    int N = ceil(n);
    cout<<"Matrix de "<<N<<"x"<<N<<endl;
    clock_t begin, end;
    double time_spent;
    
    begin = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<"Generating matrixes for encryption.."<<endl;
    matrix=convert.toMatrix(input, N, N);
    //***********************GENERATE ENCRYPTION KEY & ENCRYPT***********************************************************
    key=keyGen.GenerateKey(N);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<"Execution time : "<<time_spent<<" seconds"<<endl;
    cout<<"Encrypting....."<<endl;
    cout<<"Sequential"<<endl;
    begin = clock();
    int **encrypted,**encrypted2;
    EncryptionManager encrypt(matrix,N,key);
    encrypted=encrypt.encrypt(matrix, N, N, key);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<"Execution time : "<<time_spent<<" seconds"<<endl;
    begin = clock();
    encrypted2=encryptar(matrix,N,key);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<"Execution time : "<<time_spent<<" seconds"<<endl;
     filemanager.saveFile("/Users/RCO/Google\ Drive/8vo/Programación\ Concurrente\ y\ Distribuida/Encryption/Encryption/Encrypted.txt", encrypted, N, N);
     filemanager.saveFile("/Users/RCO/Google\ Drive/8vo/Programación\ Concurrente\ y\ Distribuida/Encryption/Encryption/Encrypted2.txt", encrypted2, N, N);
 
    

    // ****************************DECRYPTION****************************************************************************
    filemanager.readEncryptedFile("/Users/RCO/Google\ Drive/8vo/Programación\ Concurrente\ y\ Distribuida/Encryption/Encryption/Encrypted2.txt",N);
    cout<<endl<<endl;
    int ** crypto = filemanager.getCryptograph();
    double**newKey =convert.toDouble(key, N);
    cout<<encrypt.decrypt(newKey, crypto,N)<<endl;
    //*****************************Clean up memory....*******************************************************************!
    convert.destoyMatrix(matrix, N, N);
    convert.destoyMatrix(key, N, N);
    convert.destoyMatrix(encrypted, N, N);
    
    return 0;
}

int ** encryptar(int **matrix,int n,int ** key)
{
    tbb::task_scheduler_init init(tbb::task_scheduler_init);
    //Conversor convert;
    EncryptionManager encrypt(matrix,n,key);
    tbb::parallel_for ( tbb::blocked_range2d<size_t>(0, n, n, 0, n, n),encrypt);
    
    return encrypt.encryptedMessage;
}



