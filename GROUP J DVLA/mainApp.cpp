#include <iostream>
#include <vector>
#include "Driver.h"
#include "LicenceOffice.h"
#include "File_Operations.h"
#include <ctime>
using namespace std;
void startingInterFace(void);
int main(){
    auto t=time(nullptr);
    auto tm=*localtime(&t);
    cout<<put_time(&tm,"%d-%m-%Y %H-%M-%S")<<endl;
/*
    Driver dr("Emmanuel",32,"Ghana","Corrolla","M");
    Office off;
    FileManager fpth1("testDir.txt");
    fpth1.writeTofile(off,dr);
*/
Driver generic_Driver;
Office generic_Office;
cout<<"DVLA GHANA"<<endl;
cout<<"[1] Register User [2] Verify User Licence [3] Edit User Data [4] Read User Data"<<endl;
char input;
cin>>input;
switch(input){
case '1':
    generic_Driver.getDetails();
    generic_Office.getDetails();
return 0;}
void startingInterFaceInterface(){
cout<<"DVLA GHANA"<<endl;
cout<<"[1] Register User [2] Verify User Licence [3] Edit User Data [4] Read User Data"<<endl;
char input;
cin>>input;
switch(input){
case '1':
    g

}
}
