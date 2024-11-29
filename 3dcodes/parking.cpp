#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
using namespace std;

//class vehicle which is used inherit properties
class vehicle{
    private:
    string model;
    string number;
    string color;
    int wheels;

    public:
    vehicle(string model, string number, string color, int wheels): model(model),number(number),color(color),wheels(wheels){}
    string get_model() const{
        return model;
    }
    string get_number() const{
        return number;
    }
    string get_color() const{
        return color;
    }
    int  get_wheels() const{
        return wheels;
    }
    void save_to_file(ofstream &file){
          file << model << " " << number << " " << color << " " << wheels << endl;
    }
};

//creating a car class for cars 4 wheeler
 class car:public vehicle{
    public:
    car(string model,string number,string color,int wheels):vehicle(model,number,color,wheels){}
 };

 //creating a class for bikes 2wheeler
 class bike:public vehicle{
    public:
    bike(string model,string number,string color,int wheels):vehicle(model,number,color,wheels){}
 };

//for vehicles over  4 wheeler
class heavy:public vehicle{
    public:
    heavy(string model,string number,string color,int wheels):vehicle(model,number,color,wheels){}
};

//for three wheeler
class  three:public vehicle{
    public:
    three(string model,string number,string color,int wheels):vehicle(model,number,color,wheels){}
};


 class parking{
    private:
    vehicle *slot[15];
    int capacity;
    int count;// to keep track on how many slots are filled
    public:
    parking(int capacity):capacity(capacity),count(0){
        for(int i=0;i<capacity;i++){//initialize all slots as empty
            slot[i]=nullptr;
        }
    }

    //function to add a vehicle
    void add_vehicle(vehicle* v) {
    bool added = false;
    for (int i = 0; i < capacity; i++) {
        if (slot[i] == nullptr) {  // Check for the first available slot
            slot[i] = v;
            cout << "Vehicle added to slot " << i + 1 << endl;
            added = true;
            count++;
            break;
        }
    }
       if (!added) {
        cout << "Parking lot is full" << endl;
       }
    }

    
    //function to remove a vehicle
    void remove_vehicle(string number){
        bool found=false;
        for(int i=0;i<capacity;i++){
            if(slot[i]!=nullptr && slot[i]->get_number()==number){
                found=true;
                cout << "Vehicle with number: " << number<< " removed from slot " << i + 1 << endl;
                delete slot[i]; // Free up the memory
                slot[i] = nullptr; //marking up the place again empty
                count--;
                break;
            }
        }
        if(!found){
            cout<<"vehicle with "<<number<<"  not found"<<endl;
        }
    }

    //display the vehicle with their details;
    void display() {
        system("cls");
    // Define dimensions for the chessboard (2D array)
    const int rows = 3;  // Number of rows
    const int cols = 5;  // Number of columns

    // Print header for columns
    cout << "Parking Slots:\n";
    for (int i = 0; i < cols; ++i) {
        cout << "    Slot " << i + 1 << "\t";
    }
    cout << endl;

    // Print each row
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int index = r * cols + c;  // Calculate index for 1D array representation
            if (index < capacity && slot[index] != nullptr) {
                int wheels = slot[index]->get_wheels();
                string category;
                if (wheels == 2) category = "2-wheeler";
                else if (wheels == 3) category = "3-wheeler";
                else if (wheels == 4) category = "4-wheeler";
                else category = ">4 wheels";

                cout << "[X] " << category << " - " << slot[index]->get_model() << " - " << slot[index]->get_number() << "\t";  // Filled slot
            } else {
                cout << "[ ] Empty\t";  // Empty slot
            }
        }
        cout << endl;  // New line for the next row
    }
}

//method to save in a file
// void saveto(const string & filename) {
//     ofstream file(filename);
//     if(file.is_open()){
//         for(int i=0;i<capacity;i++){
//             if(slot[i]!=nullptr){
//                 slot[i]->save_to_file(file);
//             }
//         }
//         file.close();
//         cout<<"Parking data saved to "<<filename<<endl;
//      }else{
//         cout<<"Unable to open file"<<endl;
//      }
//    }

   //loading data for the file
//    void load_to(const  string & filename) {
//     ifstream file(filename);
//     if(file.is_open()){
//         string model,number,color;
//         int wheels;
//         while(file>>model>>number>>color>>wheels){
//             if (wheels == 2) {
//                     add_vehicle(new bike(model, number, color, wheels));
//                 } else if (wheels == 3) {
//                     add_vehicle(new three(model, number, color, wheels));
//                 } else if (wheels == 4) {
//                     add_vehicle(new car(model, number, color, wheels));
//                 } else if (wheels > 4) {
//                     add_vehicle(new heavy(model, number, color, wheels));
//                 }
//         }
//         file.close();
//         cout<<"Parking data loaded from "<<filename<<endl;
//     }else{
//         cout<<"Unable to open file"<<endl;
//     }
//    }

};

bool validate_password(const string& input_password) {
    const string correct_password = "nuclear_destroyer"; // Set your desired password here
    return input_password == correct_password;
}


int main(){
parking park(15);
string  password;
cout<<"Enter the password"<<endl;
cin>>password;
if(!validate_password(password)){cout<<"Password is wrong"<<endl;return 0;}

system("cls");
  while (true) {
        cout << "1. Add vehicle" << endl;
        cout << "2. Remove a vehicle" << endl;
        cout << "3. Print parking lot" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:{
                system("cls");
                string model,number, color;
                int wheels;
                cout << "Enter the number of wheels (2/3/4/>4): ";
                cin >> wheels;
                cout << "Enter the vehicle's model: ";
                cin >> model;
                cout << "Enter the vehicle's number: ";
                cin >> number;
                cout << "Enter the vehicle's color: ";
                cin >> color;
                if(wheels==2){
                    park.add_vehicle(new bike(model,number,color,wheels));
                }else if(wheels==3){
                    park.add_vehicle(new three(model,number,color,wheels));
                }else if(wheels==4){
                    park.add_vehicle(new car(model,number,color,wheels));
                }else if(wheels>4){
                    park.add_vehicle(new heavy(model,number,color,wheels));
                }else{
                    cout<<" you cant park a vehicle with that many wheels in this place"<<endl;
                }
                cout<<endl;
                break;
            }
            case 2:{
                system("cls");
                string number;
                cout<<"Enter the number of your vehicle: ";
                cin>>number;
                park.remove_vehicle(number);
                cout<<endl;
                break;
            }
            case 3:{
                system("cls");
                park.display();
                cout<<endl;
                break;
            }
            // case 4:{
            //     system("cls");
            //     park.saveto("parking_data.txt");
            //     cout<<endl;
            //     break;
            // }
            case 4:
            return 0;
            default:
            cout<<endl;
            cout<<"invalid choice"<<endl;
        } 
    }
         return 0;
}
