#ifndef LICENCEOFFICE_H_INCLUDED
#define LICENCEOFFICE_H_INCLUDED
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
class Office{
private:
    string licenceType;
    int validity;
    string license_Id;
public:
    Office(){license_Id=generateLicencPlateNum();};
    void IssueLinsence(){};
    void ExpireLicence(){};
    string generateLicencPlateNum(void);
    void showLicenceDetails(){
        cout<<"Licence Number "<<license_Id<<endl;
    }
      ostream & getAllDetailsAtOnce(ostream &streamject)
    {
        streamject<<licenceType<<"-"<<validity<<"-"<<license_Id<<"\n";

        return streamject;
    }
    void getDetails(){
    cout<<"
    }
};

string Office::generateLicencPlateNum(){
      srand(time(0));
    vector <string > string_constants={"GC","GS","GW","GR","GT"};
    vector <string > num_contants={"0","1","2","3","4","5","6","7","8","9"};
    string results="";
    //add a string_const;

    results+=string_constants[rand()%string_constants.size()];
    while(results.size()<10){
        results+=num_contants[rand()%num_contants.size()];
    }

return results;
}



#endif // LICENCEOFFICE_H_INCLUDED
