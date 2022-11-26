#include <iostream>

using namespace std;

int main() {
    int my_array[5] = {1, 2, 3, 4, 5};

    cout << "Reference to the first element: " << &my_array[0] << endl;
    cout <<  "Printing array name: " << my_array << endl;

    int *my_array_ptr = {nullptr};
    my_array_ptr = my_array;
    cout << "Printing the pointer to my array: " << my_array_ptr << endl;

    cout << "Memory location of the first element: " << &my_array[0] << endl;
    cout << "Memory location of the second element: " << &my_array[1] << endl;
    cout << "Increment pointer by 1: " << (my_array_ptr + 1) << endl;
    cout << "Increment pointer by 1 and dereference it: " << *(my_array_ptr + 1) << endl;

    cout << (my_array[1] == *(my_array_ptr + 1)) << endl;
    return 0;
}