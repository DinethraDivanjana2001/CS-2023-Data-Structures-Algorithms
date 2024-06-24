#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int input_1;
    int input_2;
    cin >> input_1;
    cin >> input_2;
    for (int n = input_1; n <= input_2; n++){// iteration from input_1 to input_2
        if (n<=9 && n==1){
            cout << "one"<< endl;
            
        }else if(n<=9 && n==2){
            cout << "two"<< endl;
            
        }else if(n<=9 && n==3){
            cout << "three"<<endl;
            
        }else if(n<=9 && n==4){
            cout << "four"<<endl;
            
        }else if(n<=9 && n==5){
            cout << "five"<<endl;
            
        }else if(n<=9 && n==6){
            cout << "six"<<endl;
            
        }else if(n<=9 && n==7){
            cout << "seven"<<endl;
            
        }else if(n<=9 && n==8){
            cout << "eight"<<endl;
            
        }else if(n<=9 && n==9){
            cout << "nine"<<endl;
        }else if (n>9 && n%2==0){
            cout<<"even" << endl;
        }else if (n>9 && n%2==1){
            cout<<"odd" << endl;
        }
    }
    return 0;
}
