#include "directory.h"

Directory::Directory(string name,QDateTime createDate,QDateTime updateDate,bool isDir,string path,QDateTime deleteDate, int size):OriginFile
    (name,createDate,updateDate,isDir,path,deleteDate,size){}
int Directory::getSize(){
    return 1000;
}
