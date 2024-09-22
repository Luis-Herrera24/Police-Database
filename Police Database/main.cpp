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

class PoliceDepartment{
private:
    map<int, Police> policeOfficerDB;
    
public:
    void addPoliceOfficer(const Police& officer){
        policeOfficerDB[officer.getPoliceBadge()] = officer;
    }
    
    void remorePoliceOfficer(int badge){
        auto policeIteration = policeOfficerDB.find(badge);
        if(policeIteration != policeOfficerDB.end()){
            cout << "Police Officer: "
            << policeIteration -> second.getPoliceName() << " was removed from the system" << endl;
            policeOfficerDB.erase(badge);
        }
        else cout << "Police Officer with badge #: " << badge << " was not located." << endl;
    }
    void displayAllPolice(){
        for(auto& pair : policeOfficerDB){
            pair.second.displayOfficerInfo();
            cout << endl;
        }
        if(policeOfficerDB.empty()){
            cout << "This Police Department has no active police officers" << endl;
        }
    }
    
};

int main(int argc, const char * argv[]) {
   
    return 0;
}
