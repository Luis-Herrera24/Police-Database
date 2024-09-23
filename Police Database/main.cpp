//
//  main.cpp
//  Police Database
//
//  Created by Luis Herrera on 9/22/24.
//

#include "DepartmentHeader.hpp"

int main() {
   
    PoliceDepartment sheriffDepartment;
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
    
    /*sheriffDepartment.findPoliceOfficer(5145);
     sheriffDepartment.findPoliceOfficer(4325);
    */
    sheriffDepartment.displayAllPolice();
    sheriffDepartment.removePoliceOfficer(5145);
    sheriffDepartment.displayAllPolice();
    
    return 0;
}
