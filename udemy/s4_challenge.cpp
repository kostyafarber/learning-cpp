#include <iostream>

int main() {
    
    int fav_num;
    std::cout << "Enter your favourite number betweem 1 and 100: ";
    std::cin >> fav_num;

    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "No really!!, " <<  fav_num << " is my favourite number!" << std::endl;
    return 0;
}