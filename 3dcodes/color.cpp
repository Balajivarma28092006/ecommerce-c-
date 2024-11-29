#include<iostream>
#include<windows.h>
using namespace std;
char a=1;
char b=92;
void mfs(){
    cout<<"    *"<<endl;
    cout<<"   ***"<<endl;
    cout<<"  ***** "<<endl;
    cout<<" *******"<<endl;
    cout<<"*********"<<endl;
    cout<<" *******"<<endl;
    cout<<"  *****"<<endl;
    cout<<"   ***"<<endl;
   cout<<"    *"<<endl;
}
int main(){
    system("cls");
    for(; ;){
        mfs();
        system("color 08");
        Sleep(500);
        system("color 07");
        Sleep(500);
        system("color 06");
        Sleep(500);
        system("color 05");
        Sleep(500);
        system("color 04");
        Sleep(500);
        system("color 03");
        Sleep(500);
        system("color 02");
        Sleep(500);
        system("color 01");
        Sleep(500);
        system("cls");
    }
    mfs();
    return 0;
}
