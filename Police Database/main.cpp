//
//  main.cpp
//  Police Database
//
//  Created by Luis Herrera on 9/22/24.
//

#include <iostream>
#include <map>
using namespace std;

class Police{
private:
    string officerName;
    int officerBadge;
    string officerDistrict;
    
public:
    Police (){}
    Police (const string& name, int badge, const string& district):officerName(name), officerBadge(badge), officerDistrict (district){}
    
    void setPoliceName(const string& name){officerName = name;}
    void setPoliceBadge(int badge){officerBadge = badge;}
    void setPoliceDistrict(const string& district){ officerDistrict = district;}
    
    string getPoliceName() const {return officerName;}
    int getPoliceBadge() {return officerBadge;}
    string getPoliceDistrict() const {return officerDistrict;}
    
};


int main(int argc, const char * argv[]) {
   
    return 0;
}
