#include <iostream>
#include <vector>

using namespace std;

int lomuto_partition(int start, int end, vector<int>& vec) {
    int i = start - 1;
    int pivot = vec.at(end);

    for (int j = start; j < end - 1; j++) {
        if (vec.at(j) <= pivot) {
            i++;
            swap(vec.at(j), vec.at(i));
        }
    }
    i++;
    swap(vec.at(i), vec.at(end));
    return i;
}

void print(vector<int>& vec) {
    for (auto &num: vec) {
        cout << num << " ";
    }

    cout << endl;
}

int main() {
    vector<int> example = {5, 2, 0, 1, 3};

    print(example);

    int p = lomuto_partition(0, example.size() - 1, example);

    cout << "Partition point is: " << p << endl;
    print(example);
    return 0;
}