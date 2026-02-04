#ifndef FILE_H
#define FILE_H
#include "originfile.h"
class File : public OriginFile
{
private:
    string text;
    long long databytes;
public:

    File(string name,QDateTime createDate,QDateTime updateDate,bool isDir,string path,QDateTime deleteDate, int size);
    string* getText(){
        return &text;
    }
   void setText(string text){
       this->text=text;
    }
   int getSize()override;
    int getdataBytes();
};

#endif // FILE_H
