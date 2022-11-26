#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& vec) {
    for (auto &num: vec) {
        cout << num << " ";
    }

    cout << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Lomuto partiton scheme
int partition(int start, int end, vector<int>& vec) {
    int i = start;
    int pivot = vec.at(end);
    
    for (int j = i; j < end; j++) {
        if (vec.at(j) < pivot) {
            swap(vec.at(j), vec.at(i));
            i++;
        }
    }
    swap(vec.at(i), vec.at(end));
    return i;
}

void partition_sort(int start, int end, vector<int>& vec) {
    if (start >= end) {
        return;
    }

    int p = partition(start, end, vec);
    partition_sort(start, p - 1, vec);
    partition_sort(p + 1, end, vec);

}

int main() {
    vector<int> test = {5, 1, 2, 7, 6, 4};
    print(test);
    partition_sort(0, test.size() - 1, test);
    print(test);

    return 0;
}