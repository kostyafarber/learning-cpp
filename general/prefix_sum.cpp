#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {3, 4, 5, 8, 1, 0};
    vector<int> res = {0};
    
    for (int i = 1; i < vec.size(); i++) {
        res.push_back(vec.at(i - 1));
        int sum = res.at(i) + res.at(i - 1);
        res.at(i) = sum;

    }

    for (auto num: res) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}