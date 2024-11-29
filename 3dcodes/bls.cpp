#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

// Product class 
class product {
protected:
    string name;
    double price;
    int stock;
    int id;
public:
    product(string n, double p, int s,int id) : name(n), price(p), stock(s), id(id) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }
    void setStock(int s) { stock = s; }

    void display() const {
        cout <<" "<< "Product: " << setw(10) << name 
             << "  | Price: $" << fixed << setprecision(2) << price << endl;
    }
    int getid() const{
        return id;
    }
    virtual ~product() {}
};

// Furniture class derived from Product
class furniture : public product {
    
public:
    furniture(string n, double p, int i,int id) : product(n, p, i,id) {}
};

// Electronics class derived from Product
class electronics : public product {
public:
string warrenty="1 Year from the date of purchase";
    electronics(string n, double p, int i,int id) : product(n, p, i,id) {}
    void printWarrenty(){
               cout<<"-------------------------------------------------"<<endl;
               cout<<"Your Product warrenty is "<<warrenty<<". "<<endl;
               cout<<"-------------------------------------------------"<<endl;
    }
};

//Food class which is derived from the product class
class Food: public product {
public:
    Food(string n, double p, int i,int id) : product(n, p, i,id) {}
};
//cloth class derived from the product class
class Cloth : public product {
public:
    Cloth(string n, double p, int i,int id) : product(n, p, i,id) {}
};

bool login(string username, string password) {
    string correctUsername = "admin"; 
    string Username="Customer";
    string userpassword="user123";
    string correctPassword = "password123";  
    if (username == correctUsername && password == correctPassword) {
        return true;
    } else if(username == Username && password == userpassword) {
        return true;
    }else{
        return false;
    }
}
//cart class to add and display the bill 
class cart {

private:
    vector<pair<product&, int>> items; // Store references to products

public:
    void addprod(product &p, int quantity){
        if(p.getStock() >= quantity){
            items.push_back(make_pair(ref(p), quantity)); // Store reference to product
            p.setStock(p.getStock()-quantity);  // Update the original product's stock
            //p.added(quantity);
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

    void remove_from_cart() {
    if (items.empty()) {
        cout << "--------------------------------------------------------------" << endl;
        cout << "Your cart is empty, you need to fill it up with something next time." << endl;
        return;
    }

    cout << "\n                    -- CART ITEMS--                            " << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << "----------------------------------------------------------------" << endl;
        cout << i + 1;
        items[i].first.display();
    }

    cout << "\n1. Remove product from cart(y) or anyother character?" << endl;
     char choice3;
    cin >> choice3;

    if (choice3 =='y' ) {
        int choice5;
        cout << "Enter the number of the product you want to remove from the cart: ";
        cin >> choice5;

        // Ensure the choice is within the range of the cart items
        if (choice5 < 1 || choice5 > items.size()) {
            cout << "Invalid choice! Please enter a valid choice." << endl;
        } else {
            // Restore stock of the original product before removing
            items[choice5 - 1].first.setStock(items[choice5-1].first.getStock()+items[choice5 - 1].second);  // Restoring stock
            items.erase(items.begin() + choice5 - 1);  // Remove from cart
            cout << "Product removed successfully!" << endl;
        }
    } else {
        cout << "Invalid choice! Please enter a valid choice." << endl;
    }
}

    void totalprice(){
        double total = 0;
        for (int i = 0; i < items.size(); i++) {
            total+=items[i].first.getPrice()*items[i].second;
        }
    cout<<"|   TOTAL PRICE OF YOUR CART IS : "<<setprecision(2)<<fixed<<"Rs. "<<total<<"/-                  |"<<endl;
    items.clear();
    }
};

class user{
  protected:
  string username;
  string password;
  string role;

  public:
  user(string n,string p,string r){
    username=n;
    password=p;
    role=r;
  }
  string getrole() const{return role;}
};
//customer class which is derived from the user class
class customer:public user{
public:
   customer(string n,string p):user(n,p,"customer"){}
};
//admin clas which is derived from the user class
class admin:public user{
public:
admin(string n,string p):user(n,p,"admin"){}
};

void adminmenu(vector<product*>& products) {
    int choice;
    do {
        cout << "\n+------------------- ADMIN MENU -------------------+" << endl;
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. View All Products\n";
        cout << "4. Exit Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new product
                cout<<"Which category product are you going to add? "<<endl;
                cout<<"1. Electronics\n2.Furniture\n3.Food Items\n4.Clothings"<<endl;
                string name;
                int choice2;
                cin>>choice2;
                double price;
                int stock;
                // int id;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product stock: ";
                cin >> stock;
               
                // Add product as electronics type by default for simplicity
                switch (choice2)
                {
                case 1:
                products.push_back(new electronics(name, price, stock,101));
                cout << "Product added successfully!" << endl;
                    break;
                case 2:
                products.push_back(new furniture(name, price, stock,201));
                cout << "Product added successfully!" << endl;
                break;
                case 3:
                products.push_back(new Food(name, price, stock,301));
                cout << "Product added successfully!" << endl;
                break;
                case 4:
                products.push_back(new Cloth(name, price, stock,101));
                cout << "Product added successfully!" << endl;
                break;
                default:
                cout<<"Sorry to mention that we are not able to add product of this category"<<endl;
                    break;
                }
                break;
            }
            case 2: {
                // Remove a product by name
                cout << "Enter the name of the product to remove: ";
                string removename;
                cin.ignore();
                getline(cin, removename);

                bool found = false;
                for (int i = 0; i < products.size(); i++) {
              if (products[i]->getName() == removename) {
               delete products[i];  // Free memory
               products.erase(products.begin() + i);  // Remove from vector
                 cout << "Product removed successfully!" << endl;
               found = true;
              break;
                       }
              }

                if (!found) {
                    cout << "Product not found!" << endl;
                }
                break;
            }
            case 3: {
                // Display all products
                cout << "\n+------------------- PRODUCT LIST -------------------+" << endl;
                for (int i = 0; i < products.size(); i++) {
                   products[i]->display(); 
                   cout<<" Stock: "<<products[i]->getStock()<<"Units"<<endl;
                   cout << "-----------------------------------------------------" << endl;
                }
                cout << "-----------------------------------------------------" << endl;
                break;
            }
            case 4:
                cout << "Exiting Admin Menu..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);
}



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
    string username, password;
    bool loggedin = false;
    cart c1;
    vector<product*> products;

    electronics p1[3] = {
        {"Laptop", 1000.0, 10,101},
        {"Smartphone", 600.0, 15,101},
        {"Television", 1200.0, 5,101}
    };

    furniture f1[3] = {
        {"Sofa", 800.0, 10,201},
        {"Table", 300.0, 20,201},
        {"Chair", 100.0, 30,201}
    };
    
     Food F1[3] = {
        {"Rice 25kg", 800.0, 10,301},
        {"Wheat 25kg", 300.0, 20,301},
        {"Grams 1kg", 100.0, 30,301}
    };

     Cloth C1[3] = {
        {"T-shirt", 800.0, 10,401},
        {"Pijamas", 300.0, 20,401},
        {"Pants", 100.0, 30,401}
    };
    // Add initial products to vector
    for (int i = 0; i < 3; i++) {
    products.push_back(new electronics(p1[i]));
    products.push_back(new furniture(f1[i]));
    products.push_back(new Food(F1[i]));
    products.push_back(new Cloth(C1[i]));
}

    // Continuous login loop
    while (true) {
        // Reset login state for new session
        loggedin = false;

        // Login process
        while (!loggedin) {
            printwelcomemessage();
            cout << "\nUsername: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (login(username, password)) {
                cout << "\nLogin successful! Welcome, " << username << "." << endl;
                loggedin = true;

                if (username == "admin") {
                    // Admin tasks
                    adminmenu(products);  // Direct to admin menu if admin logs in
                } else if (username == "Customer") {
                    // User shopping experience
                    

                    do {
                        cout << "\nPress Enter to view all products..." << endl;
                        cin.ignore();
                        cin.get();

                        int category;
                        cout << "1. Electronics\n2. Furniture\n3.Food items\n4.Clothing\n5. Show All\n";
                        cout << "Which category would you like to buy from? ";
                        cin >> category;

                        printtitle("AVAILABLE PRODUCTS");
                        for (int i = 0; i < products.size(); i++) {
                            if ((category == 1 && products[i]->getid() == 101) ||
                                (category == 2 && products[i]->getid() == 201) ||
                                (category == 3 && products[i]->getid() == 301) ||
                                (category == 4 && products[i]->getid() == 401) ||
                                category == 5) {
                                cout << i + 1 << ". ";
                                products[i]->display();
                             }else if(category>5){
                                cout<<"Invalid choice"<<endl;
                                break;
                             }else{};
                        }
                           int choice, quantity;
                        cout << "Which product would you like to add to the cart? Enter the number: ";
                        cin >> choice;
                        cout << "Enter the quantity: ";
                        cin >> quantity;

                        if (choice >= 1 && choice <= products.size()) {
                            c1.addprod(*products[choice - 1], quantity);
                        } else {
                            cout << "Invalid product choice!" << endl;
                        }

                        cout << "\nWould you like to continue shopping? (y/n): ";
                        cin >> shopping;
                        cout<<"---------------------------------------------------"<<endl;
                        cout<<"Want to remove a product from the cart? (y/n): "<<endl;;
                        char choice1;
                        cin>>choice1;
                         cout<<"---------------------------------------------------"<<endl;
                        if(choice1=='y'||choice1=='Y'){
                            c1.remove_from_cart();
                        }
                    } while (shopping == 'y' || shopping == 'Y');

                    cout << "\nFinal Cart Contents:" << endl;
                    c1.view();
                    cout << "-----------------------------------------------------------" << endl;
                    c1.totalprice();
                    cout << "\nThank you for shopping with us! Goodbye!" << endl;
                }

            } else {
                cout << "\n+------------------------------------------------------------+" << endl;
                cout << "|                *** LOGIN FAILED! ***                       |" << endl;
                cout << "|       Incorrect username or password. Try again.           |" << endl;
                cout << "+------------------------------------------------------------+" << endl;
            }
        }

        // Ask if the user wants to log in again or exit
        char choice;
        cout << "\nDo you want to log in again? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    }
    for (int i = 0; i < products.size(); i++) {
        delete products[i];
    }
    return 0;
}
