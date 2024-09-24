//
//  main.cpp
//  Police Database
//
//  Created by Luis Herrera on 9/22/24.
//

#include "DepartmentHeader.hpp"
void enteringOfficersInfo();

int main() {
    
    enteringOfficersInfo();

    return 0;
}
void enteringOfficersInfo(){
    
    PoliceDepartment Sheriff_Department;
    
    string fullname;
    int badge = 100;
    string district;
    string rank;
    int numberOfPolice;
    
    cout << "How many police officers would you like to enter into the system?" << endl;
    cin >> numberOfPolice;
    cin.ignore();
    
    Police* policeList = new Police[numberOfPolice];
    
    for (int i = 0; i < numberOfPolice; i++){
        cout << "Please enter the Officers full name:" << endl;
        getline(cin, fullname);
        cout << "Please enter the Officers rank:" << endl;
        getline(cin, rank);
        cout << "Please enter the Officers assigned district:" << endl;
        getline(cin, district);
        
        policeList[i] = Police(fullname,badge,district,rank);
        
        Sheriff_Department.addPoliceOfficer(policeList[i]);
        Sheriff_Department.exportInfoToFile("OfficerList.txt");
        badge++;
    }
    badge = badge;
}


/*PoliceDepartment sheriffDepartment;
// string (name) , int (badge) , string (district), string (rank)
Police officer1("Luis Herrera", 5145, "East", "Deputy");
Police o2("Allison Mich", 4546, "west","Sr. Deputy");
// Test creating a blank officer
Police test;

sheriffDepartment.addPoliceOfficer(officer1);
sheriffDepartment.addPoliceOfficer(o2);
sheriffDepartment.addPoliceOfficer(test);

sheriffDepartment.updatePoliceName(4546, "Allison Micho");
sheriffDepartment.updatePoliceRank(5145, "Captain");
sheriffDepartment.updatePoliceDistrict(4546, "West");
sheriffDepartment.updatePoliceName(1234, "J. W Bush");
sheriffDepartment.updatePoliceRank(3567, "Master");
sheriffDepartment.updatePoliceDistrict(3246, "Central");

sheriffDepartment.findPoliceOfficer(5145);
 sheriffDepartment.findPoliceOfficer(4325);

sheriffDepartment.displayAllPolice();
sheriffDepartment.removePoliceOfficer(5145);
sheriffDepartment.displayAllPolice();
*/
