#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;

// Product class 
class product {
private:
    string name;
    double price;
    int stock;
    double discount; // Added discount member
public:
    product(string n, double p, int s, double d = 0) : name(n), price(p), stock(s), discount(d) {}
    string getName() const { return name; }
    double getPrice() const { return price * (1 - discount / 100); } // Apply discount when getting price
    int getStock() const { return stock; }
    void setStock(int s) { stock -= s; }
    void display() const {
        cout << "Product: " << setw(10) << name 
             << "  | Price: $" << fixed << setprecision(2) << getPrice() 
             << "  | Stock: " << stock << " units" << endl;
    }
    void added(int n){
        this->stock -= n;
    }
};

// Furniture class derived from Product
class furniture : public product {
public:
    furniture(string n, double p, int i, double d) : product(n, p, i, d) {}
};

// Electronics class derived from Product
class electronics : public product {
public:
    electronics(string n, double p, int i, double d) : product(n, p, i, d) {}
};

bool login(string username, string password) {
    string correctUsername = "admin"; 
    string correctPassword = "password123";  
    return (username == correctUsername && password == correctPassword);
}

// Cart class to add and display the bill 
class cart {
private:
    vector<pair<product&, int>> items; // Store references to products

public:
    void addprod(product &p, int quantity){
        if(p.getStock() >= quantity){
            items.push_back(make_pair(ref(p), quantity)); // Store reference to product
            p.setStock(quantity);  // Update the original product's stock
            cout << "Added " << quantity << " of " << p.getName() << " to the cart." << endl;
        } else {
            cout << "Insufficient stock for " << p.getName() << "!" << endl;
        }
    }

    void view() const{
        if(items.empty()) {
            cout << "--------------------------------------------------------------" << endl;
            cout << "Your cart is empty, you need to fill it up with something next time." << endl;
            cout << "--------------------------------------------------------------" << endl;
        } else {
            cout << "\n+------------------- CART SUMMARY -------------------+" << endl;
            cout << "| Product Name      | Price | Quantity | Total Price |" << endl;
            cout << "+-------------------+-------+----------+-------------+" << endl;
            for (int i = 0; i < items.size(); i++) {
                cout << "| " << items[i].first.getName() << " | " << items[i].first.getPrice() << " | " 
                     << items[i].second << " | " << items[i].first.getPrice() * items[i].second << " |" << endl;
            }
        }
    }
    
    void totalprice() const {
        double total = 0;
        for (int i = 0; i < items.size(); i++) {
            total += items[i].first.getPrice() * items[i].second;
        }
        cout << "|   TOTAL PRICE OF YOUR CART IS : " << setprecision(2) << fixed << total << "$                  |" << endl;
    }
};

// User class for the users
class user {};

// Admin class derived from User
class admin : public user {
public:
    void adminMenu(vector<product*>& products) {
        string username, password;
        cout << "Enter Admin Username: ";
        cin >> username;
        cout << "Enter Admin Password: ";
        cin >> password;

        if (username == "admin" && password == "password123") {
            int choice;
            do {
                cout << "\nAdmin Menu:\n";
                cout << "1. Add Product\n";
                cout << "2. Remove Product\n";
                cout << "3. View All Products\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    string name;
                    double price;
                    int stock;
                    double discount;

                    cout << "Enter product name: ";
                    cin >> name;
                    cout << "Enter product price: ";
                    cin >> price;
                    cout << "Enter product stock: ";
                    cin >> stock;
                    cout << "Enter discount percentage: ";
                    cin >> discount;

                    // Add new product based on type
                    if (name == "Laptop" || name == "Smartphone" || name == "Television") {
                        products.push_back(new electronics(name, price, stock, discount));
                    } else {
                        products.push_back(new furniture(name, price, stock, discount));
                    }
                    cout << "Product added successfully!\n";
                    break;
                }
                case 2: {
                    string name;
                    cout << "Enter product name to remove: ";
                    cin >> name;
                    for (auto it = products.begin(); it != products.end(); ++it) {
                        if ((*it)->getName() == name) {
                            delete *it; // Free memory
                            products.erase(it); // Remove from vector
                            cout << "Product removed successfully!\n";
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    cout << "\n+------------------- ALL PRODUCTS -------------------+" << endl;
                    for (size_t i = 0; i < products.size(); i++) {
                        products[i]->display(); // Display each product with the discounted price
                    }
                    break;
                }
                case 4:
                    cout << "Exiting admin menu.\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                }
            } while (choice != 4);
        } else {
            cout << "Incorrect username or password!\n";
        }
    }
};

void printtitle(const string& title) {
    cout << "==============================================================" << endl;
    cout << "||                    " << title << "                    ||" << endl;
    cout << "==============================================================" << endl;
}

void printwelcomemessage() {
    cout << "\n+------------------------------------------------------------+" << endl;
    cout << "|       *** WELCOME TO THE AMAZING E-COMMERCE SYSTEM ***      |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "|                                                            |" << endl;
    cout << "|  Please log in with your credentials to continue.           |" << endl;
    cout << "|                                                            |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
}

int main() {
    char shopping;
    printwelcomemessage();
    string username, password;
    bool loggedin = false;
    cart c1;
    vector<product*> products; // Vector to hold products

    // Adding initial products
    products.push_back(new electronics("Laptop", 1000.0, 10, 10)); // 10% discount
    products.push_back(new electronics("Smartphone", 600.0, 15, 5)); // 5% discount
    products.push_back(new furniture("Sofa", 800.0, 10, 15)); // 15% discount
    products.push_back(new furniture("Table", 300.0, 20, 10)); // 10% discount
    products.push_back(new furniture("Chair", 100.0, 30, 20)); // 20% discount

    while (!loggedin) {
        printwelcomemessage();
        cout << "\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "\nLogin successful! Welcome, " << username << "." << endl;
            loggedin = true;  // Set to true once login is successful
        } else {
            cout << "\n+------------------------------------------------------------+" << endl;
            cout << "|                *** LOGIN FAILED! ***                       |" << endl;
            cout << "|       Incorrect username or password. Try again.            |" << endl;
            cout << "+------------------------------------------------------------+" << endl;
        }
    }

    do {
        cout << "\nPress Enter to view all products..." << endl;
        cin.ignore();  
        cin.get();     
        printtitle("ELECTRONICS PRODUCTS");
        for (size_t i = 0; i < products.size(); i++) {
            products[i]->display();
        }
        cout << "--------------------------------------------------------------" << endl;

        int choice, quantity, value;
        cout << "1. Electronics\n2. Furniture\n" << endl;
        cout << "Which category do you need to buy: ";
        cin >> value;

        if (value == 1) {
            cout << "Which product would you like to add to the cart?" << endl;
            cout << "1. Laptop\n2. Smartphone\n3. Television\n";
            cout << "Enter the number of the product: ";
            cin >> choice;
            cout << "Enter the quantity: "; 
            cin >> quantity;

            switch (choice) {
                case 1:
                    c1.addprod(*products[0], quantity);
                                         break;
                case 2:
                    c1.addprod(*products[1], quantity);
                    break;
                case 3:
                    cout << "Television not available in stock!" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } else if (value == 2) {
            cout << "Which product would you like to add to the cart?" << endl;
            cout << "1. Sofa\n2. Table\n3. Chair\n";
            cout << "Enter the number of the product: ";
            cin >> choice;
            cout << "Enter the quantity: "; 
            cin >> quantity;

            switch (choice) {
                case 1:
                    c1.addprod(*products[2], quantity);
                    break;
                case 2:
                    c1.addprod(*products[3], quantity);
                    break;
                case 3:
                    c1.addprod(*products[4], quantity);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } else {
            cout << "Invalid category!" << endl;
        }

        cout << "Would you like to view your cart? (Y/N): ";
        cin >> shopping;
        if (shopping == 'Y' || shopping == 'y') {
            c1.view();
            c1.totalprice();
        }

        cout << "Do you want to continue shopping? (Y/N): ";
        cin >> shopping;
    } while (shopping == 'Y' || shopping == 'y');

    // Admin menu call
    admin adminUser;
    adminUser.adminMenu(products);

    // Clean up memory
    for (size_t i = 0; i < products.size(); i++) {
        delete products[i]; // Free memory for each product
    }

    return 0;
}
