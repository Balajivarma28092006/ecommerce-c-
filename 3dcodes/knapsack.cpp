#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class items{
    public:
    int value,weight;
    double ratio;
    items(int v,int w):value(v),weight(w),ratio((double)v/w){}
};


void sort(vector<items>item){
    int n=item.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(item[j].ratio<item[j+1].ratio){
                items temp=item[j];
                item[j]=item[j+1];
                item[j+1]=temp;
            }
        }  
    }    
}

double knapsack(int capacity,vector<items>item){
    sort(item);
    double total=0;
    for(int i=0;i<item.size();i++){
        if(capacity>=item[i].weight){
            capacity-=item[i].weight;
            total+=item[i].value;
        }else{
            total+=item[i].value*((double)capacity/item[i].weight);
            break;
        }
    }
    return total;
}

int main(){
    int capacity;
     int n;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;
    vector<items>item;
    for(int i=0;i<n;i++){
        int v,w;
        cout << "Enter the value and weight of item "<<i+1<<": ";
        cin >> v >> w;
        item.push_back(items(v,w));
    }
    double total=knapsack(capacity,item);
    cout<<"The maximum value of it is: "<<setprecision(2)<<fixed<<total<<endl;
}