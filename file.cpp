#include "file.h"

File::File(string name,QDateTime createDate,QDateTime updateDate,bool isDir,string path,QDateTime deleteDate, int size):OriginFile
    (name,createDate,updateDate,isDir,path,deleteDate,size)
{}
int File::getSize(){
    return text.length();
}
int File::getdataBytes(){
    return ((size+(4096-1))/4096)*4096;
}
