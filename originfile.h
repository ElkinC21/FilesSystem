#ifndef ORIGINFILE_H
#define ORIGINFILE_H
#include <iostream>
#include <QDateTime>

using std::string;

class OriginFile
{
protected:
    string name;
    QDateTime createDate;
    QDateTime updateDate;
    bool isDir;
    string Path;
    QDateTime deleteDate;
    int size;

public:
    OriginFile(string name,QDateTime createDate,QDateTime updateDate,bool isDir,string path,QDateTime deleteDate, int size);
    virtual ~OriginFile();
    string getName(){
        return name;
    }
    QDateTime getCreateDate(){
        return createDate;
    }
    QDateTime getUpdateName(){
        return updateDate;
    }
    bool getIsDir(){
        return isDir;
    }
    string getpath(){
        return Path;
    }
    QDateTime getDeleteDate(){
        return deleteDate;
    }
    virtual int getSize()=0;
};

#endif // ORIGINFILE_H
