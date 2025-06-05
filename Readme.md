
# 🚗 Automobile Management System

An end-semester project developed for the Programming Fundamentals Lab, this C++ application serves as an **Automobile Management System**. It facilitates the management of car inventories, sales, purchases, and inspection requests through a console-based interface.

## 📁 Project Structure

```
PF-Semester-Project/
├── project.cpp                 # Main source code
├── project.exe                 # Compiled executable (Windows)
├── cars_for_sale.txt           # List of available cars
├── sold_cars.txt               # List of sold cars
├── purchased_cars.txt          # List of purchased cars
├── purchase_record.txt         # Records of purchases
├── sales_record.txt            # Records of sales
├── inspection_requests.txt     # Pending inspection requests
├── description.txt             # Project description
└── .github/workflows/
    └── c-cpp.yml               # GitHub Actions workflow for C/C++ builds
```

## 🛠️ Features

* **Inventory Management**: Add, view, and remove cars from the inventory.
* **Sales & Purchases**: Record sales and purchases with detailed logs.
* **Inspection Requests**: Manage and track inspection requests.
* **Data Persistence**: All records are stored in text files for simplicity.

## 🚀 Getting Started

### Prerequisites

* A C++ compiler (e.g., GCC, Clang, or MSVC)

### Compilation

To compile the project:

```bash
g++ project.cpp -o project
```

### Execution

After compilation, run the executable:

```bash
./project
```

*Note: On Windows, use `project.exe` instead.*

## 📄 File Descriptions

* `cars_for_sale.txt`: Contains details of cars currently available for sale.
* `sold_cars.txt`: Logs of cars that have been sold.
* `purchased_cars.txt`: Logs of cars that have been purchased.
* `purchase_record.txt`: Detailed records of purchase transactions.
* `sales_record.txt`: Detailed records of sales transactions.
* `inspection_requests.txt`: List of cars pending inspection.
* `description.txt`: Provides an overview of the project.

## 🤝 Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

