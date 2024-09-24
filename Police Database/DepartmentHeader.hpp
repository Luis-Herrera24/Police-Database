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
#include <fstream>
#include <sqlite3.h>

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
    
public:
    // Method that adds officer based on badge #
    void addPoliceOfficer(Police& officer){
        insertOfficerIntoDatabase(officer);
        cout << "OFFICER ADDED: ";
        officer.displayPoliceInfo();
    }
    
    // Method that list out all current officers
    void displayAllPolice(){
        displayOfficerFromDatabase();
    }
    
    //Function to find a specific officer based on badge #
    void findPoliceOfficer(int badge){}
    
    void displayAllOfficer(){}
    
    // Method to remove a specific officer based on the badge #
    void removePoliceOfficer(int badge){}
    
    // Method that updates the officers name
    void updatePoliceName(int badge,const string& name){}
    
    // Method that updates the officers district
    void updatePoliceDistrict(int badge, const string& district){}
    
    // Method that updates the officers rank
    void updatePoliceRank(int badge, const string& rank){}
    
    int readLastBadgeFromDatabase();
    void insertOfficerIntoDatabase(const Police& officer);
    void displayOfficerFromDatabase();
    void updateOfficerFromDatabase(int badge,const string& name,const string& district, const string& rank);
    void removeOfficerByBadge(int badge);
    
};

#endif
