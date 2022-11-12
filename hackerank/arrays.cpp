#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    
    vector<int> nums;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        cout << nums[i] << " ";
    }
     
}
