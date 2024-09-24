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
private:
    int readLastBadgeFromDatabase(){
        sqlite3* dB; // Declared pointed db type sqlite
        
        int lastBadgeNum = 100; // Default badge number
        
        char* errMsg = nullptr; //Char pointer named errMsg used to capture any errors
        
        // attetmps to open databaase name "police_department.db" and stored in rc. if its sucessfull dB will point to the database
        int rc = sqlite3_open("police_department.dB", &dB);
        
        // checks if "rc" is non-zero which would indicate error occured. Prints error message and returns badge 100;
        if(rc){
            cerr << "Error opening database: " << sqlite3_errmsg(dB) << endl;
            return lastBadgeNum;
        }
        // query string that contains a SQL statement which will get the highest badge # in database.
        string query = "SELECT MAX(badge_number) FROM Officers;";
        
        /*executes a SQL query using pointer dB and query string above. It uses a lamda function [] passed as a callback
        void data - points to data (lastBadgeNum), int arg = # of collums (one in this case)
        char arg - array of strings that will contain one column in current row (arg[0] will contain MAX(badge_number)
        char colNames - array of strings at contain the names of columns (not used here so its ingnored) */
        sqlite3_exec(dB,query.c_str(), [](void* data, int argc, char** argv, char** colNames){
            
            // if argv is not nullptr,
            if(argv[0]){
                // data is the pointer to the lastbadgeNum data
                // stoi(argv) - converts string into an integer
                *(int*)data = stoi(argv[0]);
            }
            return 0;
            // this completes the lambda function and passes &lastBadge as the first argument (data), and &errMsg as the last argument to sqlite3_exec.
        }, &lastBadgeNum, &errMsg);
        // After the query execution, block checks if errMsg contains an error message. If it does, it prints the error message and frees the memory allocated for the error message using sqlite3_free
        if(errMsg){
            cerr << "Error opening database: " << errMsg << endl;
            sqlite3_free(errMsg);
        }
        // closes database connection
        sqlite3_close(dB);
        
        return lastBadgeNum;
    }
    
    Police getOfficerFromDatbase(int badge){
        Police officer;
        // error handing if database does not open
        sqlite3* dB;
        if(sqlite3_open("police_department.db", &dB) != SQLITE_OK){
            cout << "Error! Unable to open database" << endl;
            return officer;
        }
        string sql = "SELECT name, badge, district, rank FROM Officers WHERE badge = ?";
        // pointer to complied SQl statment declared
        sqlite3_stmt* stmt;
        
        //Error handling if string sql was not read
        if(sqlite3_prepare_v2(dB, sql.c_str(), -1,&stmt, nullptr) != SQLITE_OK){
            cout << "Error! Incorrect Statement" << endl;
            sqlite3_close(dB);
            return officer;
        }
        /* This binds the value of the badge number (passed into the function) to the first placeholder "?" in the prepared SQL query
         1 indicates that this is the first placeholder.
         */
        
        sqlite3_bind_int(stmt, 1, badge);
        //if officer is found
        if(sqlite3_step(stmt) == SQLITE_ROW){
            officer.setPoliceName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            officer.setPoliceBadge(sqlite3_column_int(stmt, 1));
            officer.setPoliceDistrict(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            officer.setPoliceRank(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        }
        sqlite3_finalize(stmt);
        sqlite3_close(dB);
        
        return officer;
    }
    
    void insertOfficerIntoDatabase(const Police& officer){
        sqlite3* dB;
        
        if(sqlite3_open("police_department.db", &dB) != SQLITE_OK){
            cout << "Error! Unable to open database" << endl;
            return;
        }
        
        string sql = "INSERT INTO Officers (name, badge, district, rank) VALUES(?,?,?,?)";
        sqlite3_stmt* stmt;
        
        if(sqlite3_prepare_v2(dB,sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
            cout << "Error! Incorrect Statement" << endl;
            sqlite3_close(dB);
            return;
        }
        sqlite3_bind_text(stmt, 1, officer.getPoliceName().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, officer.getPoliceBadge());
        sqlite3_bind_text(stmt, 3, officer.getPoliceDistrict().c_str(), -1,SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, officer.getPoliceRank().c_str(), -1, SQLITE_STATIC);
        
    }
    
    void displayOfficerFromDatabase();
    void updateOfficerFromDatabase(int badge,const string& name,const string& district, const string& rank);
    void removeOfficerByBadge(int badge);
    
    
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
    void findPoliceOfficer(int badge){
        Police officer = getOfficerFromDatbase(badge);
        if(officer.getPoliceBadge() != 0){
            officer.displayPoliceInfo();
        }
        else {
            cout << "Police officer with badge # " << badge << " was not found." << endl;
        }
    }
    
    void displayAllOfficer(){
        displayOfficerFromDatabase();
    }
    
    // Method to remove a specific officer based on the badge #
    void removePoliceOfficer(int badge){
        removeOfficerByBadge(badge);
    }
    
    // Method that updates the officers name
    void updatePoliceName(int badge,const string& name){
        updateOfficerFromDatabase(badge, name,"","");
    }
    // Method that updates the officers district
    void updatePoliceDistrict(int badge, const string& district){
        updateOfficerFromDatabase(badge, "",district,"");
    }
    // Method that updates the officers rank
    void updatePoliceRank(int badge, const string& rank){
        updateOfficerFromDatabase(badge,"","",rank);
    }
    
    
};

#endif
