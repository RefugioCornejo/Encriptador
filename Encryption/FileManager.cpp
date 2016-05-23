//
//  FileManager.cpp
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#include "FileManager.h"

using namespace std;

void FileManager::loadInput(string path)
{
    ifstream file(path);
    if(!file.good())
    {
        cout<<"Error file not found";
    }
    else
    {
        string line;
        while (getline(file,line))
        {
            input+=line+"\n";
        }
    }
    file.close();
}
bool FileManager::saveFile(string path, int **cryptograph, int row, int col)
{
    bool success = false;
    ofstream file(path.c_str());
    if(file)
    {
        success=true;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                file.write((char *)&cryptograph[i][j],sizeof(int));
            }
        }
    }
    file.close();
    return success;
}

void FileManager::readEncryptedFile(string path,int N)
{
    vector<int>elements;
    int elemnt;
    ifstream file(path);
    if(!file.good())
    {

        cout<<"Error file not found";
    }
    else
    {
        file.seekg(0,ios::end);
        long end =file.tellg();
        file.seekg(0);
        while (file.tellg()!=end)
        {
            file.read((char*)&elemnt, sizeof(int));
            elements.push_back(elemnt);
        }
        cryptograph = new int*[N];
        for(int i =0 ; i<N; i++)
        {
            cryptograph[i]=new int[N];
        }
        
        int offset=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cryptograph[i][j]=elements.at(offset);
                offset++;
            }
        }

    }
        file.close();
}

string FileManager::getInput(){return this->input;}
int ** FileManager::getCryptograph(){return this->cryptograph;}
