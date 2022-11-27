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

int h_partition(int start, int end, vector<int>& vec) {
    int pivot = vec.at(start);
    int i = start - 1;
    int j = end + 1;

    while (1) {
        do {
            i++;
        } while (vec.at(i) < pivot);

        do {
            j--;
        } while (vec.at(j) > pivot);
        

        if (i >= j) {
            return j;
        }

        swap(vec.at(i), vec.at(j));
    }  
}

void partition_sort(int start, int end, vector<int>& vec) {
    if (start >= end) {
        return;
    }

    // int p = partition(start, end, vec);
    // partition_sort(start, p - 1, vec);
    // partition_sort(p + 1, end, vec);
    int p = h_partition(start, end, vec);
    partition_sort(start, p, vec);
    partition_sort(p + 1, end, vec);

}

int main() {
    vector<int> test = {5, 1, 2, 7, -2, 0, 6};
    print(test);
    partition_sort(0, test.size() - 1, test);
    print(test);

    return 0;
}