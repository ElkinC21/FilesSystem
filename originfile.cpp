#include "originfile.h"

OriginFile::OriginFile(string name,QDateTime createDate,QDateTime updateDate,bool isDir,string path,QDateTime deleteDate, int size) {
    this->name=name;
    this->createDate=createDate;
    
}
