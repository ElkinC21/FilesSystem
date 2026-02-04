#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "originfile.h"
#include <vector>
using std::vector;
class Directory:public OriginFile
{


public:
    Directory(string name,QDateTime createDate,QDateTime updateDate,bool isDir,string path,QDateTime deleteDate, int size);
  vector<OriginFile*>hijos;

    int getSize()override;
};

#endif // DIRECTORY_H
