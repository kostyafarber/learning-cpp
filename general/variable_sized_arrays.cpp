#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* 
    n = var length arrays
    q = queries
    e.g --> 1 5 n = 1, q = 5
    
    i = 1 --> a[i], a[i2], ...
    i = 2 --> a[i], a[i2], ...
    
    1. Read the values into a vector of vectors of type int.
        1.a for the number of arrays.
            for length of array.
                push back into array at index n
    2. Print the values at the given query
        2. for number of queries (i)
            read in at array at index (j) 
     */
     
    int num_arrays, queries;
    vector <vector<int>> arrays;
    
    cin >> num_arrays; 
    cin >> queries;
    
    for (int i = 0; i < num_arrays; i++) {
        vector<int> arr;
        int array_size;
        cin >> array_size;
        
        for (int j = 0; j < array_size; j++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        
        arrays.push_back(arr);      
    }
    
    for (int i = 0; i < queries; i++) {
        int row, column;
        cin >> row >> column;
        cout << arrays[row][column] << endl;       
    }
    return 0;
}