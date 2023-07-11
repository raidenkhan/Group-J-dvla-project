#ifndef FILE_OPERATIONS_H_INCLUDED
#define FILE_OPERATIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
//#include "Driver.h"
//#include "LicenceOffice.h"
using namespace std;
class FileManager{
private:
    string filePath;
public:
    FileManager(){};
    FileManager(string fpth):filePath(fpth){};
    bool searchInfile(string toFind);
    void writeTofile(Office &,Driver &,string date);

    void genExpiredUsersFile(void);
    void readFromfile(Driver &drivObj,Office & offbj);//READ FROM THE FILE INTO THE GENERIC OBJECTS
    vector <string> breakWithDelims(string ,char);//BREAK A STRING INTO DELIMS
    vector <string> breakIntoLines(string text);//BREAK MULTI LINE FILE STREAM INTO VECTOR OF LINES
    vector <string> fetchUserData();
    string getStreamBuffAsString(void);//RETURN FILES STREAM BUFFER AS STRING FOR MANIPULATION
    void updateFile(Driver &,Office &);//UPDATE THE DATA FILE ANYTIME THE USER RENEWS THE LICENSE

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
void FileManager::writeTofile(Office & ofobj, Driver & drivobj,string date=""){
    ofstream outfle(filePath,ios::app);
    drivobj.getAllDetailsAtOnce(outfle);
    ofobj.getAllDetailsAtOnce(outfle);
    outfle<<date<<endl;

}
string FileManager::getStreamBuffAsString(){
    ifstream inputFile(filePath);
    ostringstream text;
    text<<inputFile.rdbuf();
    inputFile.close();
    return text.str();
}
void FileManager::readFromfile(Driver &drivobj,Office &offobj){//MAKE A READ FROM THE FILE INTO THE OBJECTS

    vector <string> readingLines=breakIntoLines(getStreamBuffAsString());
    //ask if they'll like to search in file or select from a list---would implement later

    cout<<setw(60)<<"Available Users"<<endl;
    for(int i=0;i<readingLines.size();i++){
        cout<<" ["<<i+1<<"] ";Static::smoothEffect(breakWithDelims(readingLines[i])[0]);
        cout<<endl;
    }
    int choice=0;
    cout<<">> ";
    cin>>choice;cout<<endl;
    if(choice-1>=0&&choice<=readingLines.size()){
        string line=readingLines[choice-1];
        vector <string> separatedInfo=breakWithDelims(line);

        //all this lines is to pass the arguments into the driver object from the file as
        //Driver(string nm,int ag,string nat,string sx)
        drivobj=Driver(separatedInfo[0],stoi(separatedInfo[2]),separatedInfo[1],separatedInfo[3]);//put the info int the driver object;

          //all this lines is to pass the arguments into the office object from the file as
        //    Office(string linctype,int val,string lincId,string issued)
        offobj=Office(separatedInfo[4],stoi(separatedInfo[5]),separatedInfo[6],separatedInfo[7]+"-"+line.substr(line.size()-5,line.size()));
        //7+8 to get the total date

    }

}

void FileManager::updateFile(Driver &drivobj,Office& offobj){

    ///ALGORITHM
    //-GET ALL THE USER STREAM DATA
    //-CHECK FOR USER WITH MATCHING DETAILS--NAMES SPECIFICALLY
    //COPY ALL THE USER DATA INTO A TEMP FILE
    //DELETE THE CURRENT FILE AND RENAME THE TEMP FILE TO THE NEW FILE
  string AlluserData=  getStreamBuffAsString();
 ostringstream textStream;
drivobj.getAllDetailsAtOnce(textStream);
string dataToFind=textStream.str();
vector<string> lines=breakIntoLines(AlluserData);
ofstream tempfile("temp.txt");
for(int i=0;i<lines.size();i++){
    if(dataToFind==lines[i].substr(0,dataToFind.size())){
        //cout<<"Line stream : "<<lines[i]<<endl;
    }else{
    tempfile<<lines[i]<<endl;
    }
}
//close the file
tempfile.close();
//remove the original file
remove("DVLA.txt");
//rename the original file to the old file
rename("temp.txt","DVLA.txt");

}
vector <string> FileManager::fetchUserData(){
    string allUsers=getStreamBuffAsString();
    vector <string> rtnvalue=breakIntoLines(allUsers);
    return rtnvalue;
}
/*void FileManager::genExpiredUsersFile(){
    vector <string> users=fetchUserData();
    vector <string> analyTicContainer;
    string timeNow=Static::getCurrenTime();


    filePath="Expired.txt";
    for(auto user: users){
            analyTicContainer=breakWithDelims(user);

            if(Static::compareTimes(timeNow,analyTicContainer[8],))
    }
}

*/


#endif // FILE_OPERATIONS_H_INCLUDED
