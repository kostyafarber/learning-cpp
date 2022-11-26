#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(const vector<int> &vec) {
    for (auto &num: vec) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> insertion_sort(vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        int j = i + 1;

        // use vec.at(j) so you get an out of bounds error
        while (j > 0 && vec.at(j - 1) > vec.at(j)) {
            swap(vec.at(j - 1), vec.at(j));
            j--;
        }
    }
    return vec;
}

int main() {
    vector<int> test = {7, 5, 4, 3, -1, 5, 4, 2, 0};
    print(test);
    insertion_sort(test);
    print(test);
    return 0;
}