#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

// Structure to store car details
struct Car {
    string model;
    int year;
    double price;
};

// Structure to hold details of a service ticket
struct Ticket {
    int ticketNumber;
    string date;
    string serviceType;
    string description;
};

// Function prototypes
void welcomeScreen();
int generateTicket();
void carSale(vector<Car>& cars, int& carsSold);
void carPurchase(int& carsBought);
void carModifications();
void carReviewsAndInspections();
