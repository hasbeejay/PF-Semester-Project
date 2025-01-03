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

// Main program
int main() {
    vector<Car> cars; 
    int carsSold = 0; // Tracks how many cars have been sold
    int carsBought = 0; // Tracks how many cars have been bought

    welcomeScreen();

    int choice;
    do {
        cout << "\n\n      --- Welcome Mam. Kanwal to YSKI Automotive Management System ---\n\n";
        cout << "            1. Car Sale\n";
        cout << "            2. Car Purchase\n";
        cout << "            3. Car Modifications\n";
        cout << "            4. Car Reviews and Inspections\n";
        cout << "            5. Exit\n";
        cout << "\n            Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            carSale(cars, carsSold);
            break;
        case 2:
            carPurchase(carsBought);
            break;
        case 3:
            carModifications();
            break;
        case 4:
            carReviewsAndInspections();
            break;
        case 5:
            cout << "        -----------------------------------------------------------" << endl;
            cout << "\n        Thank you for using YSKI Automotive System. Goodbye!\n";
            break;
        default:
            cout << "        -----------------------------------------------------------" << endl;
            cout << "\n        Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Display welcome message
void welcomeScreen() {
    cout << "        **************************************\n";
    cout << "        *                                    *\n";
    cout << "        *      YSKI Automotive    			  *\n";
    cout << "        *          Management System         *\n";
    cout << "        *                                    *\n";
    cout << "        **************************************\n";
}