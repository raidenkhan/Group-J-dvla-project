#ifndef FILE_OPERATIONS_H_INCLUDED
#define FILE_OPERATIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include "Driver.h"
#include "LicenceOffice.h"
using namespace std;
class FileManager{
private:
    string filePath;
public:
    FileManager(string fpth):filePath(fpth){};
    bool searchInfile(string toFind);
    void writeTofile(Office &,Driver &);
    void readFromfile(void);
    vector <string> breakWithDelims(string ,char);
    vector <string> breakIntoLines(string text);
    void makeChanges(string checksum);//not really sure
};

///ANALAYSE AND BREAK THE FILE INPUT INTO LINES
vector <string> FileManager::breakIntoLines(string text){
vector <string> rtnVector ;
string temp="";
for(auto a : text){
    if(a!='\n'){
        temp+=a;
    }else{
    rtnVector.push_back(temp);
    temp="";
    }
}
return rtnVector;
}

///ANALYSE AND OUTPUT THE USER DATA
vector <string> FileManager::breakWithDelims(string text,char del='-'){
    vector <string> rtnvalue;
    string tmpStr="";
    for(auto a:text){
        if(a!=del){
            tmpStr+=a;
        }
        if(a==del){
           rtnvalue.push_back(tmpStr);
           tmpStr="";
        }
    }
    return rtnvalue;

}

///FIND A PARTICULAR CLIENT
bool FileManager::searchInfile(string toFind){
    ifstream inputFile(filePath);
    ostringstream text;
    text<<inputFile.rdbuf();
    vector <string> testVec=breakIntoLines(text.str());
    for(auto a :testVec ){

        if(breakWithDelims(a)[0]==toFind){
            cout<<toFind<<endl;
        }
    }
    return true;

}

///store user data
void FileManager::writeTofile(Office & ofobj, Driver & drivobj){
    ofstream outfle(filePath,ios::app);
    drivobj.getAllDetailsAtOnce(outfle);
    ofobj.getAllDetailsAtOnce(outfle);

}

#endif // FILE_OPERATIONS_H_INCLUDED
