#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a; 
    cin >> b;
    string maps[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 

    for (int i = a; i <= b; i++ ) {
        if (i >= 1 && i <= 9) {
            cout << maps[i - 1] << endl;
        }
        
        else if (i > 9 && i % 2 == 0) {
            cout << "even" << endl;
        }
        
        else {
            cout << "odd" << endl;
        }
    }
    return 0;
}