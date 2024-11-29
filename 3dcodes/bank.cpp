#include<iostream>
using namespace std;
class bank{
    private:
    string accountholder;
    double balance;

public:
    bank(string name, double initial){
        this->accountholder=name;
        this->balance=initial;
    }
    void withdraw(double amount){
        if(amount>balance){
            cout<<"not sufficient money in the account: "<<endl;
        }else if(amount<=balance&&amount>0){
            balance-=amount;
            cout<<"withdraw succesfull !!, remaining money int he account is: "<<balance<<endl;
        }else{
         cout<<"check the amout once again."<<endl;
        }
        cout<<endl;
    }
    string getname() const{
        return accountholder;
    }
    void deposite(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"deposited sccesfully"<<" remaining money"<<balance<<endl;
        }else{
            cout<<"deposite not possible :"<<endl;
        }
    }
    void check() const{
        cout<<"amount of money in the account is : "<<balance<<"$"<<endl;
    }
};
int main(){
     int n;
     cout<<"no.of account holders:  "<<endl;
     cin>>n;
     bank* holders[n];
     for(int i=0;i<n;i++){
        string name;
        double initialbalance;
        cout<<"name of the account holder "<<i+1<<" is: ";
        cin.ignore();
        getline(cin,name);
        cout<<"initial amount is:  ";
        cin>>initialbalance;
        holders[i]=new bank(name,initialbalance);
     }
     for (int i = 0; i < n; ++i) {
        holders[i]->check();
        double amount;
        std::cout << "Enter amount to deposit for account holder " << i + 1 <<" "<<holders[i]->getname()<< " : ";
        std::cin >> amount;
        holders[i]->deposite(amount);

        double withdrawamount;
        std::cout << "Enter amount to withdraw for account holder " << i + 1 << ": ";
        std::cin >> withdrawamount;
        holders[i]->withdraw(withdrawamount);

        holders[i]->check();
        cout<<endl;
    }
}