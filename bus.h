#pragma once
#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;
 
class Bus {
    string bus_number;
    string bus_driver;
    string bus_arrival;
    string bus_depart;
    string b_from;
    string b_to;
    string bus_seat[8][4];
 
public:
    void addNewBus();
    void makeReservation(Bus buses[], int busIndex);
    void clearSeats();
    void viewBusDetails();
    void showAvailableBuses(Bus buses[]);
    void showSeatAvailability(int busIndex);
    void displayLine(char ch);
};