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

void print(const vector<int>& vec) {
    for (auto& num: vec) {
        cout << num << " ";
    }

    cout << endl;
}

int main() {
    vector<int> test1 = {2, 4, 5, 7, 12};
    vector<int> test2 = {3, 6, 7, 12, 13,};
    
    vector<int> res = merge_sorted_lists(test1, test2);

    print(res);
    return 0;
}