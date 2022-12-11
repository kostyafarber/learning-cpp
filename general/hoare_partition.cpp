#include <iostream>
#include <vector>

using namespace std;

int h_partition(int start, int end, vector<int>& vec) {
    // int pivot = vec.at(start);
    int pivot = vec.at(end);
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

int main() {

    vector<int> test = {0, 1};
    h_partition(0, 1, test);
    return 0;
}