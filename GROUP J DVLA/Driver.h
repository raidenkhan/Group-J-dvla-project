#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std;

class Driver{
private:
    string name;
    int age;
   // string birthDate;-work on later
    string nationality;
    string sex;
    string vehicleType;
public:
    Driver(string nm,int ag,string nat,string vec,string sx):name(nm),age(ag),nationality(nat),vehicleType(vec),sex(sx){};

    ostream & getAllDetailsAtOnce(ostream &streamject)
    {
        streamject<<name<<"-"<<nationality<<"-"<<age<<"-"<<sex<<"-"<<vehicleType;
        return streamject;
    }

    void showDetails (void){

        cout<<setw(30)<<"Name "<<setw(20)<<name<<internal<<endl;
        cout<<setw(30)<<"Age "<<setw(20)<<age<<right<<endl;
        cout<<setw(30)<<"Sex "<<setw(20)<<sex<<endl;
        cout<<setw(30)<<"Nationality "<<setw(20)<<nationality<<endl;

    }


    void getDetails(){
        cout<<"Please enter your name :";cin>>name;
        cout<<endl;
        cout<<"Please enter your age :";cin>>age;
         cout<<endl;
        cout<<"Please enter your nationality :";cin>>nationality;
         cout<<endl;
        cout<<"Please enter your vehicle type :";cin>>vehicleType;
         cout<<endl;

    }

};




#endif // DRIVER_H_INCLUDED
