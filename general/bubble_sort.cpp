#include <vector>
#include <iostream>

using namespace std;

vector<int> bubble_sort(vector<int>& vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    bool swapped = true;

    while (swapped == true) {
        for (int i = 0; i <= vec.size() - 2; i++) {
            swapped = false;
            if (vec.at(i) > vec.at(i + 1)) {
                swap(vec.at(i), vec.at(i + 1));
                swapped = true;
            }
        }
    }
    return vec;
}

void print(vector<int>& vec) {
    for (auto &num: vec) {
        cout << num << " ";
    }

    cout << endl;
}

int main() {
    vector<int> test = {4, 2, -1, 6, 2};
    print(test);
    bubble_sort(test);
    print(test);
    return 0;
}