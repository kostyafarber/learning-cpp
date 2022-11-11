#include <iostream>

using namespace std;

int main() {
    
    int small_room;
    int large_room;

    const double small_room_price = 25;
    const double large_room_price = 35;
    const double sales_tax = 0.06;
    cout << "What number of small rooms would you like cleaned? " << endl;
    cin >> small_room; 
    cout << "What number of large rooms would you like cleaned? " << endl;
    cin >> large_room;


    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_room << endl;
    cout << "Number of large rooms: " << large_room << endl;
    cout << "Price per small room: " << small_room_price << endl;
    cout << "Price per large room: " << large_room_price << endl;

    double gross_cost = (large_room_price * large_room) + (small_room_price * small_room);
    double tax_cost = (gross_cost * sales_tax);
    double net_cost = gross_cost + tax_cost;

    cout << "Cost: " << gross_cost << endl;
    cout << "Tax: " << tax_cost << endl;
    cout << "================================================================" << endl;
    cout << "Cost: " << net_cost << endl;
    cout << "This estimate is valid for 30 days" << endl;

    return 0;
}