#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

bool isArmstrong(int num){
    int copynum = num;
    int count = 0;

    // Count digits
    int temp = num;
    while (temp > 0) {
        count++;
        temp /= 10;
    }

    int sum = 0;
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += round(pow(digit, count));  // round to handle float errors
        temp /= 10;
    }

    return sum == copynum;
}

 // int k = to_string(num).length(); // Get number of digits

int main(){
    int t;
    cout << "Enter num: ";
    cin >> t;
    bool result = isArmstrong(t);
    cout << result;  // prints 1 if Armstrong, else 0
    return 0;
}

