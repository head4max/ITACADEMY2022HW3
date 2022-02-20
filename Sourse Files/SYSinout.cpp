#include "../Header Files/SYSinout.h"

void showMenuItems()
{
std::cout << "------Action with your shop cart-----------" << std::endl;
std::cout << "1. Add item to your shop cart" << std::endl;
std::cout << "2. Cancel some item from your shop cart" << std::endl;
std::cout << "3. Show products list" << std::endl;
std::cout << "4. Show products of your shop cart" << std::endl;
std::cout << "0. Exit (get your bill)" << std::endl;
std::cout << "-------------------------------------------" << std::endl;
}

void showErrorIn() {
    std::cout << "Not correct input, Try again";
}

int getQuantityProduct() {
    int qty = 0;
    std::cout << "Enter quantity of want-to-buy product:";
    std::cin >> qty;
    return qty;
}

int getIndexOfProduct() {
    int idx = 0;
    std::cout << std::endl << "Enter index of want-to-buy product:";
    std::cin >> idx;
    return idx;
}

bool isInputContinue() {
    char answer = 'n';
    std::cout << std::endl << "Enter y/n to continue or finish operation:";
    std::cin >> answer;
    return answer=='y';
}
