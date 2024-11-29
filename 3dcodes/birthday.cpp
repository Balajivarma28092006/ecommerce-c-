#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<windows.h>

using namespace std;
void matrix(const string& message){
    int len=message.length();
    string display(len,' ');
    for(int i=0;i<len;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=i;k++){
                if(k==i){
                    display[k]='A'+rand()%26;
                }else{
                    display[k]=message[k];
                }
            }
            cout<<"\r"<<display<<flush;
            usleep(60000);
        }
        display[i]=message[i];
        system("color 03");
        cout<<"\r"<<display<<flush;
        system("color 02");
     }
   cout<<endl;
}
int main(){
    system("cls");
    srand(time(0));
    string message="HAPPY BIRTHDAY TO IRFAN";
    cout<<"Suprise for you......."<<endl;
    int n;
    cout<<"how many time you wnat me to say happy bithday to ya: ";
    cin>>n;
        usleep(500000);
    matrix(message);
    system("color 08");
        Sleep(500);
     system("color 08");
        Sleep(500); 
        system("color 0A");
        Sleep(500); 
        system("color 0B");
        Sleep(500); 
        system("color 0C");
        Sleep(500); 
        system("color 05");
        Sleep(500); 
        system("color 07");
        Sleep(500); 
        system("color 01");
        Sleep(500);
     usleep(500000);
    matrix(message);
    system("color 08");
        Sleep(500);
     system("color 08");
        Sleep(500); 
        system("color 0A");
        Sleep(500); 
        system("color 0B");
        Sleep(500); 
        system("color 0C");
        Sleep(500); 
        system("color 05");
        Sleep(500); 
        system("color 07");
        Sleep(500); 
        system("color 01");
        Sleep(500);
    system("cls");
    cout<<"Once Again Many more Happy returns of the day!!!!"<<endl;
    return 0;
}