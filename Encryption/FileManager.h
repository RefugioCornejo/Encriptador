//
//  FileManager.h
//  Encryption
//
//  Created by Refugio Cornejo on 3/29/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#ifndef FileManager_h
#define FileManager_h
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class FileManager
{
    private :
    string input;
    int ** cryptograph;

    public:
    void loadInput(string path);
    string getInput();
    bool saveFile(string path, int ** crypto, int row, int col);
    int ** getCryptograph();
    void  readEncryptedFile(string path,int n);
    
};
#endif /* FileManager_h */
