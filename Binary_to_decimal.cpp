#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinaryMethod(int n){

    int binaryno = 0;
    int i = 0;
    while(n>0){
        int bit = n % 2;
        binaryno = bit*pow(10, i++) + binaryno;
            n = n / 2;
    }
    return binaryno;
}

int main(){
    char ch = 255;
    cout <<ch << endl;
    int n;
    cin >> n;
    int binary = decimalToBinaryMethod(n);
    cout << binary << endl;

    return 0;
}