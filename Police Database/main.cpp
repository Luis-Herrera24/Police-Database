//
//  main.cpp
//  Police Database
//
//  Created by Luis Herrera on 9/22/24.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

class PoliceDepartment{
    
};

class Police{
private:
    string policeName;
    int policeBadge;
    string policeDistrict;
    
public:
    Police (){}
    Police (const string& name, int badge, const string& district):policeName(name), policeBadge(badge), policeDistrict (district){}
    
    void setPoliceName(const string& name){policeName = name;}
    void setPoliceBadge(int badge){policeBadge = badge;}
    void setPoliceDistrict(const string& district){ policeDistrict = district;}
    
    string getPoliceName() const {return policeName;}
    int getPoliceBadge() const {return policeBadge;}
    string getPoliceDistrict() const {return policeDistrict;}
    
    void displayOfficerInfo()const {
        cout << "POLICE OFFICER: " << policeName
        << " BADGE #: " << policeBadge
        << "ASSIGNED DISTRICT: " << policeDistrict << endl;
    }
};


int main(int argc, const char * argv[]) {
   
    return 0;
}
