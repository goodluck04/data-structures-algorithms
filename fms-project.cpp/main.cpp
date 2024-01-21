#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Medicine {
private:
    std::string name;
    int quantity;
    float price;

public:
    Medicine(const std::string& name, int quantity, float price)
        : name(name), quantity(quantity), price(price) {}

    const std::string& getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    float getPrice() const {
        return price;
    }

    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }
};

class Pharmacy {
private:
    std::vector<Medicine> medicines;

public:
    void addMedicine(const Medicine& medicine) {
        medicines.push_back(medicine);
    }

    void sellMedicine(const std::string& medicineName, int quantity) {
        auto it = std::find_if(medicines.begin(), medicines.end(),
            [&](const Medicine& m) { return m.getName() == medicineName; });

        if (it != medicines.end()) {
            if (it->getQuantity() >= quantity) {
                it->updateQuantity(it->getQuantity() - quantity);
                std::cout << "Sold " << quantity << " units of " << medicineName << std::endl;
            } else {
                std::cout << "Insufficient stock for " << medicineName << std::endl;
            }
        } else {
            std::cout << "Medicine not found: " << medicineName << std::endl;
        }
    }

    void displayStock() const {
        std::cout << std::setw(20) << "Medicine Name" << std::setw(15) << "Quantity" << std::setw(10) << "Price" << std::endl;
        std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;

        for (const Medicine& medicine : medicines) {
            std::cout << std::setw(20) << medicine.getName()
                      << std::setw(15) << medicine.getQuantity()
                      << std::setw(10) << std::fixed << std::setprecision(2) << medicine.getPrice()
                      << std::endl;
        }
    }
};

int main() {
    Pharmacy pharmacy;

    // Adding Medicines
    Medicine paracetamol("Paracetamol", 100, 5.0);
    Medicine ibuprofen("Ibuprofen", 50, 7.5);
    Medicine aspirin("Aspirin", 75, 3.0);

    pharmacy.addMedicine(paracetamol);
    pharmacy.addMedicine(ibuprofen);
    pharmacy.addMedicine(aspirin);
    

    // Selling Medicines
    pharmacy.sellMedicine("Paracetamol", 20);
    pharmacy.sellMedicine("Ibuprofen", 60); // Try to sell more than available

    // Displaying Stock
    pharmacy.displayStock();

    return 0;
}
