#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> selection_sort(vector<int> &nums) {
    
    for (int i = 0; i < nums.size(); i++) {
        int idx = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[idx]) {
                idx = j;
            }
        }
        swap(nums[i], nums[idx]);       
    }

    return nums;
}

void print_vector(const vector<int> &vec) {
    for (auto &num: vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> test = {4, 6, 2, 1, 7, 8, 10, -1, 3, 16};

    cout << "Unsorted vec: " << endl;
    print_vector(test);
    
    auto start = high_resolution_clock::now();
    selection_sort(test);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);


    cout << "Time for this function to run is: " << duration.count() << endl;
    print_vector(test);

    return 0;
}