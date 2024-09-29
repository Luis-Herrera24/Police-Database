#include <iostream>
#include "departmentHeader.hpp"

int main() {
    PoliceDepartment policeDepartment;
    
    // Create the database table if it doesn't exist
    policeDepartment.createPoliceTable();
    
    int choice;
    do {
        cout << endl << "Police Database Menu:" << endl;
        cout << "1. Add Police Officer" << endl;
        cout << "2. Display All Officers" << endl;
        cout << "3. Find Officer by Badge Number" << endl;
        cout << "4. Update Officer" << endl;;
        cout << "5. Remove Officer by Badge Number" << endl;
        cout << "6. Delete Database" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, district, rank;
                int badge;

                cout << "Enter Officer's Name: ";
                cin.ignore();  // Clear the input buffer
                getline(cin, name);
                badge = policeDepartment.getLastBadge() + 1;  // Increment badge number
                cout << "Enter Officer's District: ";
                getline(cin, district);
                cout << "Enter Officer's Rank: ";
                getline(cin, rank);

                Police officer(name, badge, district, rank);
                policeDepartment.addPoliceOfficer(officer);
                break;
            }
            case 2:
                policeDepartment.displayAllPolice();
                break;

            case 3: {
                int badge;
                cout << "Enter Badge Number to find: ";
                cin >> badge;
                policeDepartment.findPoliceOfficer(badge);
                break;
            }
            case 4: {
                int badge;
                string name, district, rank;

                cout << "Enter Badge Number to update: ";
                cin >> badge;
                cout << "Enter new Name (or leave blank): ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new District (or leave blank): ";
                getline(cin, district);
                cout << "Enter new Rank (or leave blank): ";
                getline(cin, rank);

                policeDepartment.updatePoliceName(badge, name);
                policeDepartment.updatePoliceDistrict(badge, district);
                policeDepartment.updatePoliceRank(badge, rank);
                break;
            }
            case 5: {
                int badge;
                cout << "Enter Badge Number to remove: ";
                cin >> badge;
                policeDepartment.removePoliceOfficer(badge);
                break;
            }
            case 6: {
                policeDepartment.deleteT();
            }
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

