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
    string policeRank;
    
public:
    Police (){}
    Police (const string& name, int badge, const string& district, const string rank):
    policeName(name), policeBadge(badge),policeDistrict (district), policeRank(rank){}
    
    ~ Police(){
        cout << "Police officer is being deleted" << endl;
    }
    
    void setPoliceName(const string& name){policeName = name;}
    void setPoliceBadge(int badge){policeBadge = badge;}
    void setPoliceDistrict(const string& district){ policeDistrict = district;}
    void setPoliceRank(const string& rank){ policeRank = rank;}
    
    string getPoliceName() const {return policeName;}
    int getPoliceBadge() const {return policeBadge;}
    string getPoliceDistrict() const {return policeDistrict;}
    string getPoliceRank() const {return policeRank;}
    
    void displayOfficerInfo()const {
        cout << policeRank<< " " << policeName
        << " Badge #: " << policeBadge
        << " Assigned District: " << policeDistrict << endl;
    }
};

class PoliceDepartment{
private:
    map<int, Police> policeOfficerDB;
    
public:
    void addPoliceOfficer(const Police& officer){
        policeOfficerDB[officer.getPoliceBadge()] = officer;
        cout << "ADDED: ";
        officer.displayOfficerInfo();
        cout << endl;
    }
    
    void removePoliceOfficer(int badge){
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
    void updatePoliceName(int badge,const string& name){
        auto policeIteration = policeOfficerDB.find(badge);
        if(policeIteration != policeOfficerDB.end()){
            policeIteration -> second.setPoliceName(name);
            cout << "Name of badge #: " << badge << "has been updated." << endl;
        }
        else
            cout << "Officer with badge #: " << badge << "was not found." << endl;
    }
    void updatePoliceRank(int badge, const string& rank){
        auto policeIteration = policeOfficerDB.find(badge);
        if(policeIteration != policeOfficerDB.end()){
            policeIteration -> second.setPoliceRank(rank);
            cout << "Rank for badge #: " << badge << "was updated to " << rank << endl;
        }
        else
            cout << "Officer with badge #: " << badge << "was not found." << endl;
        
    }
    void updatePoliceDistict(int badge, const string& district){
        auto policeIteration = policeOfficerDB.find(badge);
        if(policeIteration != policeOfficerDB.end()){
            policeIteration -> second.setPoliceDistrict(district);
            cout << "The disctict for officer with badge # " << badge << " has been updated." << endl;
        }
        else
            cout  << "Officer with badge #: " << badge << "was not found." << endl;
    }
    ~ PoliceDepartment(){
        cout << "Police Department is being deleted" << endl;
    }
    
};

int main(int argc, const char * argv[]) {
   
    PoliceDepartment sherrifDepartment;
    // string (name) , int (badge) , string (district), string (rank)
    Police officer1("Luis Herrera", 5145, "East", "Deputy");
    
    sherrifDepartment.addPoliceOfficer(officer1);
    
    sherrifDepartment.displayAllPolice();
    sherrifDepartment.removePoliceOfficer(5145);
    sherrifDepartment.displayAllPolice();
    
    return 0;
}
