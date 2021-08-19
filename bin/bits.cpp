#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string bits = "0000";
    cout << bits << "\n";
    while(true){
        for (int i=3; i>=0; i-=1){
            string bits = "0000";
            bits[i] = '1';
            for (int j=0; j<=200000000; j++){
            }
            cout << bits << "\n";
        }    
        /*
        for (int i=0; i<=4; i++){
                string bits = "0000";
                bits[i] = '1';
                for (int j=0; j<=200000000; j++){
                }
            cout << bits << "\n";
        }*/
    }
}
