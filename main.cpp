#include "buss.h"
 
int main() {
    const int MAX_BUSES = 5;
    Bus buses[MAX_BUSES];
 
    int choice;
 
    while (true) {
        cout << "\n\n";
        cout << "\t\t***SIMPLE BUS RESERVATION SYSTEM***";
        cout << "\n\n";
        cout << "\t\t\t1. Add New Bus\n\t\t\t"
            << "2. Make Reservation\n\t\t\t"
            << "3. View Reservation\n\t\t\t"
            << "4. Show Available Buses\n\t\t\t"
            << "5. Exit";
        cout << "\n\t\t\tEnter your Choice: ";
 
        cin >> choice;
 
        switch (choice) {
        case 1:
            buses[0].addNewBus();
            break;
 
        case 2:
            int busIndex;
            cout << "Enter Bus Index: ";
            cin >> busIndex;
            if (busIndex >= 0 && busIndex < MAX_BUSES) {
                buses[0].makeReservation(buses, busIndex);
            }
            else {
                cout << "Invalid Bus Index.\n";
            }
            break;
 
        case 3:
            buses[0].viewBusDetails();
            break;
 
        case 4:
            buses[0].showAvailableBuses(buses);
            break;
 
        case 5:
            cout << "Exiting the program. Thank you!\n";
            return 0;
 
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
 
    return 0;
}