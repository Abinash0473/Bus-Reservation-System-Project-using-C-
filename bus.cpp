#include "buss.h"
 
void Bus::addNewBus() {
    cout << "Enter Bus Number: ";
    cin >> bus_number;
 
    cout << "\nEnter Driver's Name: ";
    cin >> bus_driver;
 
    cout << "\nArrival Time: ";
    cin >> bus_arrival;
 
    cout << "\nDeparture Time: ";
    cin >> bus_depart;
 
    cout << "\nFrom: ";
    cin >> b_from;
 
    cout << "\nTo: ";
    cin >> b_to;
 
    clearSeats();
    cout << "\nNew Bus Added Successfully.\n";
}
 
void Bus::makeReservation(Bus buses[], int busIndex) {
    showSeatAvailability(busIndex);
 
    cout << "Enter Seat Number for Reservation: ";
    int seatNumber;
    cin >> seatNumber;
 
    if (seatNumber < 1 || seatNumber > 32) {
        cout << "Invalid seat number. Please enter a number between 1 and 32.\n";
        return;
    }
 
    int row = (seatNumber - 1) / 4;
    int col = (seatNumber - 1) % 4;
 
    if (buses[busIndex].bus_seat[row][col] == "Empty") {
        cout << "Enter Passenger's Name: ";
        cin >> buses[busIndex].bus_seat[row][col];
        cout << "Reservation Successful!\n";
    }
    else {
        cout << "The seat is already reserved. Please choose another seat.\n";
    }
}
 
void Bus::clearSeats() {
    for (int x = 0; x < 8; x++) {
        for (int z = 0; z < 4; z++) {
            bus_seat[x][z] = "Empty";
        }
    }
}
 
void Bus::viewBusDetails() {
    displayLine('*');
    cout << "Bus Number: \t" << bus_number
        << "\nDriver: \t" << bus_driver << "\t\tArrival Time: \t"
        << bus_arrival << "\tDeparture Time:" << bus_depart
        << "\nFrom: \t\t" << b_from << "\t\tTo: \t\t" << b_to << "\n";
    displayLine('*');
 
    showSeatAvailability(0);  // Display seat availability for this bus
}
 
void Bus::showAvailableBuses(Bus buses[]) {
    displayLine('*');
    cout << "Available Buses:\n";
    for (int i = 0; i < 5; i++) {
        if (!buses[i].bus_number.empty()) {
            cout << "Bus Number: " << buses[i].bus_number << "\tDriver: " << buses[i].bus_driver
                << "\tFrom: " << buses[i].b_from << "\tTo: " << buses[i].b_to << "\n";
        }
    }
    displayLine('_');
}
 
void Bus::showSeatAvailability(int busIndex) {
    cout << "Seat Availability:\n";
    int seatNumber = 1;
 
    for (int x = 0; x < 8; x++) {
        for (int z = 0; z < 4; z++) {
            cout << setw(5) << left << seatNumber << ".";
            cout << setw(10) << left << bus_seat[x][z];
            seatNumber++;
        }
        cout << "\n";
    }
 
    cout << "\nThere are " << (32 - seatNumber + 1) << " Seats Available in Bus Number: " << bus_number << "\n";
}
 
void Bus::displayLine(char ch) {
    for (int x = 80; x > 0; x--) {
        cout << ch;
    }
    cout << '\n';
}