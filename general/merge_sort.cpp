#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sorted_lists(vector<int>& list1, vector<int>& list2) {
    int i = 0;
    int j = 0;

    vector<int> res;
    while (i < list1.size() && j < list2.size()) {
        if (list1.at(i) >= list2.at(j)) {
            res.push_back(list2.at(j));
            j++;
        }

        if (list1.at(i) <= list2.at(j)) {
            res.push_back(list1.at(i));
            i++;
        } 
    }

    if (i < list1.size()) {
        while (i < list1.size()) {
            res.push_back(list1.at(i));
            i++;
        }
    }

    if (j < list2.size()) {
        while (j < list2.size()) {
            res.push_back(list2.at(j));
            j++;
        }
    }


    return res;
}

void merge_sort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    auto mid = start + (end - start) / 2;
    merge_sort(vec, start, mid);
    merge_sort(vec, mid + 1, end);
}

int main() {
   return 0; 
}