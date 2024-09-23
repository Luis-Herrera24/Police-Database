//
//  departmentHeader.hpp
//  Police Database
//
//  Created by Luis Herrera on 9/22/24.
//
#ifndef DEPARTMENT_HEADER_HPP
#define DEPARTMENT_HEADER_HPP

#include <iostream>
#include <string>
#include <map>
using namespace std;

// Police class that represents a police officer with attributes like name, badge number, district, and rank
class Police{
private:
    //Attributes of a police officer
    string policeName = "N/A";
    int policeBadge = 0;
    string policeDistrict = "Unassigned";
    string policeRank = "N/A";
    
public:
    // Default Constructor
    Police(): policeName("N/A"), policeBadge(0), policeDistrict("Unassigned"),policeRank("N/A"){}
    
    // Constructor
    Police (const string& name, const int badge, const string& district, const string& rank):
    policeName(name), policeBadge(badge),policeDistrict (district), policeRank(rank) {}
    
    /*/ Destructor
    ~ Police(){
        cout << "Police officer is being deleted" << endl;
    }*/
     
    // Setter Methods
    void setPoliceName(const string& name){policeName = name;}
    void setPoliceBadge(int badge){policeBadge = badge;}
    void setPoliceDistrict(const string& district){ policeDistrict = district;}
    void setPoliceRank(const string& rank){ policeRank = rank;}
    
    // Getter Methods
    string getPoliceName() const {return policeName;}
    int getPoliceBadge() const {return policeBadge;}
    string getPoliceDistrict() const {return policeDistrict;}
    string getPoliceRank() const {return policeRank;}
    
    // Method to display officers info
    void displayPoliceInfo()const {
        cout << policeRank<< " " << policeName
        << " Badge#: " << policeBadge
        << " District: " << policeDistrict << endl;
    }
};

class PoliceDepartment{
private:
    // A map to store police officers, where the key is the officer's badge #
    // and  value is the Police object containing the officer's details.
    map<int, Police> policeOfficerDB;
    
public:
    // Method that adds officer into a map based on badge #
    void addPoliceOfficer(const Police& officer){
        policeOfficerDB[officer.getPoliceBadge()] = officer;
        cout << "ADDED: ";
        officer.displayPoliceInfo();
    }
    
    // Helper function to find a specific officer based on badge #
    bool findPoliceOfficer(int badge, Police*& officer, const map<int, Police>& policeOfficerDB){
        auto policeIterator = policeOfficerDB.find(badge);
        if(policeIterator != policeOfficerDB.end()){
            officer = const_cast<Police*>(&(policeIterator->second));
            return true;
        }
        else {
            return false;
        }
    }
    void displayActiveOfficer(int badge){
        Police* officer = nullptr;
        if(findPoliceOfficer(badge, officer, policeOfficerDB)){
            officer -> displayPoliceInfo();
        }
        else {
             cout << "Police Officer with badge #: " << badge << " was not located." << endl;
        }
    }
    // Method to remove a specific officer based on the badge #
    void removePoliceOfficer(int badge){
        Police* officer = nullptr;
        if(findPoliceOfficer(badge, officer, policeOfficerDB)){
            cout << "Police Officer: "
            << officer -> getPoliceName() << " was removed from the system" << endl;
            policeOfficerDB.erase(badge);
        }
        else cout << "Police Officer with badge #: " << badge << " was not located." << endl;
    }
    
    // Method that list out all current officers
    void displayAllPolice(){
        for(auto& pair : policeOfficerDB){
            pair.second.displayPoliceInfo();
            cout << endl;
        }
        if(policeOfficerDB.empty()){
            cout << "This Police Department has no active police officers" << endl;
        }
    }
    
    // Method that updates the officers name
    void updatePoliceName(int badge,const string& name){
        Police* officer = nullptr;
        if(findPoliceOfficer(badge, officer, policeOfficerDB)){
            officer -> setPoliceName(name);
            cout << "Name of badge #: " << badge << " has been updated." << endl;
        }
        else
            cout << "Officer with badge #: " << badge << " was not found." << endl;
    }
    // Method that updates the officers district
    void updatePoliceDistrict(int badge, const string& district){
        Police* officer = nullptr;
        if(findPoliceOfficer(badge, officer, policeOfficerDB)){
            officer -> setPoliceDistrict(district);
            cout << "The district for officer with badge # " << badge << " was updated." << endl;
        }
        else
            cout  << "Officer with badge #: " << badge << " was not found." << endl;
    }
    // Method that updates the officers rank
    void updatePoliceRank(int badge, const string& rank){
        Police* officer = nullptr;
        if(findPoliceOfficer(badge, officer, policeOfficerDB)){
            officer -> setPoliceRank(rank);
            cout << "Rank for badge #: " << badge << " was updated to " << rank << endl;
        }
        else
            cout << "Officer with badge #: " << badge << " was not found." << endl;
    }
    /*~ PoliceDepartment(){
        cout << "Police Department is being deleted" << endl;
    }*/
    
};

#endif
