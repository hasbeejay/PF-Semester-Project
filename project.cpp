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

// Generate a random ticket number
int generateTicket() {
    return rand() % 100000 + 10000;
}

// Process car sales
void carSale(vector<Car>& cars, int& carsSold) {
    cout << "    ============================================================" << endl;
    cout << "    Let's Start the Sale Process!" << endl;

    char sellAnother;
    do {
        Car newCar; // Create a new car object to store details
        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Enter car model: ";
        cin.ignore();
        getline(cin, newCar.model); 
        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Enter car year: ";
        cin >> newCar.year; 
        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Enter asking price: $";
        cin >> newCar.price;
        
        int suggestedPrice = newCar.price * 0.975; // Suggest a selling price 2.5% less than the asking price
        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Suggested selling price: $";
        cout.precision(2);
        cout << fixed << suggestedPrice << endl;

        char confirm;
        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Do you want to sell the car? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            int buyerContact = rand() % 100000000 + 1000000; // Generate a random buyer contact number
            cout << "    -----------------------------------------------------------" << endl;
            cout << "\n    Car is listed for sale! Contact the buyer at: " << buyerContact << endl;
            cars.push_back(newCar); // Add the car to the vector of cars
            carsSold++; // Increment the count of cars sold

            // Save the sold car details to a file
            ofstream saleFile("sold_cars.txt", ios::app);
            if (saleFile) {
                saleFile << "Model: " << newCar.model << ", Year: " << newCar.year
                         << ", Price: $" << newCar.price << ", Suggested Price: $"
                         << suggestedPrice << endl;
                saleFile.close();
            }
        } else {
            cout << "    -----------------------------------------------------------" << endl;
            cout << "\n    Car will not be listed for sale.\n";
        }

        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Do you want to sell another car? (y/n): ";
        cin >> sellAnother;

    } while (sellAnother == 'y' || sellAnother == 'Y');

    // Save the total number of cars sold to a file
    ofstream salesRecord("sales_record.txt", ios::app);
    if (salesRecord) {
        salesRecord << "Total cars sold: " << carsSold << endl;
        salesRecord.close();
    }
}

// Process car purchases
void carPurchase(int& carsBought) {
    cout << "    ============================================================" << endl;
    cout << "    Let's Start the Purchase Process!" << endl;

    vector<Car> availableCars; // Store the available cars in a vector
    ifstream file("cars_for_sale.txt"); // Read the available cars from file
    if (!file) {
        cout << "    -----------------------------------------------------------" << endl;
        cout << "    Error: Unable to open cars_for_sale.txt.\n";
        return;
    }

    string model;
    int year, price;
    while (file >> model >> year >> price) { // Read car details from the file
        availableCars.push_back({model, year, price});
    }
    file.close();

    if (availableCars.empty()) {
        cout << "    -----------------------------------------------------------" << endl;
        cout << "    No cars available for sale at the moment.\n";
        return;
    }

    char buyAnother;
    do {
        cout << "    Available cars for sale:\n\n";
        cout << "    No.    \tModel & Year    \tPrice\n";
        cout << "    -----------------------------------------------------------\n\n";

        for (size_t i = 0; i < availableCars.size(); ++i) { // Display all cars
            cout << "    " << i + 1 << "    \t" << availableCars[i].model 
                 << " \t" << availableCars[i].year 
                 << "    \t$"  << availableCars[i].price << endl;
        }

        int choice;
        cout << "    -----------------------------------------------------------" << endl;
        cout << "    Enter the number of the car you want to buy: ";
        cin >> choice;

        if (choice < 1 || choice > availableCars.size()) {
            cout << "    Invalid choice. Please try again.\n";
            continue;
        }

        Car purchasedCar = availableCars[choice - 1]; // Get the chosen car
        availableCars.erase(availableCars.begin() + (choice - 1)); // Remove it from the list

        cout << "    -----------------------------------------------------------" << endl;
        cout << "    Purchase is on the way successfully! \n\n    Your ticket number is: " << generateTicket() << endl;
        cout << "\n\n    Please visit the counter with ticket number and \n    pay the amount to get the paperwork done." << endl;

        // Save purchased car details to a file
        ofstream purchasedFile("purchased_cars.txt", ios::app);
        if (purchasedFile) {
            purchasedFile << "Model: " << purchasedCar.model 
                          << ", Year: " << purchasedCar.year 
                          << ", Price: $" << purchasedCar.price << endl;
            purchasedFile.close();
        }

        carsBought++; // Increment the number of cars bought

        cout << "    -----------------------------------------------------------" << endl;
        cout << "\n    Do you want to buy another car? (y/n): ";
        cin >> buyAnother;

    } while (buyAnother == 'y' || buyAnother == 'Y');

    // Update the cars_for_sale.txt file with the remaining cars
    ofstream updatedFile("cars_for_sale.txt");
    if (updatedFile) {
        for (const auto& car : availableCars) {
            updatedFile << car.model << " " << car.year << " " << car.price << endl;
        }
        updatedFile.close();
    }

    // Save the total number of cars purchased to a file
    ofstream purchaseRecord("purchase_record.txt", ios::app);
    if (purchaseRecord) {
        purchaseRecord << "Total cars purchased: " << carsBought << endl;
        purchaseRecord.close();
    }
}