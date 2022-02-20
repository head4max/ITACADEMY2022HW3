#include <iostream>
#include "Header Files/ShopCart.h"
#include "Header Files/SYSinout.h"
#include <clocale>
#include <string>
#include <iomanip>
//#include <windows.h>


int main() {
    setlocale(LC_ALL, "Russian");
    //setlocale(0, "");
    //SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);

    std::string name = "My first name";
    std::cout << std::setfill(' ') << std::setw(15) << std::left << name << "  35" << std::endl;
    std::cout << "53" << " 67" << std::endl;

    shca::ShopCart::printProducts();

    bool isContinue = true;
    int menu = 0;

    shca::ShopCart shop;

    shop.addProduct(shca::Products::BREAD, 100);
    shop.addProduct(shca::Products::APPLE, 4);
    shop.addProduct(shca::Products::MEAT, 4);
    shop.addProduct(shca::Products::SUGAR, 2);
    shop.addProduct(shca::Products::SOUR_CREAM, 15);
    shop.addProduct(shca::Products::ORANGE, 30);
    shop.addProduct(shca::Products::MILK, 19);

    do {
        showMenuItems();
        std::cin >> menu;
        if (!std::cin) {
            showErrorIn();
            continue;
        }

        switch (menu) {
            case 1:
                while (true) {
                    int idx = getIndexOfProduct();
                    int qty = getQuantityProduct();
                    if (idx > 0 and idx < 11 and qty > 0)
                        shop.addProduct(static_cast<shca::Products>(idx - 1), qty);
                    if (!isInputContinue())
                        break;
                }
                break;
            case 2:
                while (true) {
                    int idx = getIndexOfProduct();
                    int qty = getQuantityProduct();
                    if (idx > 0 and idx < 11 and qty > 0)
                        shop.cancelProduct(static_cast<shca::Products>(idx - 1), qty);
                    if (!isInputContinue())
                        break;
                }
                break;
            case 3:
                shca::ShopCart::printProducts();
                break;
            case 4:
                shop.printShopCart(shca::Products::UNKNOWN);
                break;
            default:
                isContinue = false;
        }

    } while (isContinue);

    shca::Products choose_product = shca::Products::UNKNOWN;

    std::vector<shca::Products> vec_prod = shop.getMaxDiscount();
    if (vec_prod.empty())
        std::cout << "your score is 0" << std::endl;
    else if (vec_prod.size() == 1)
        //std::cout << "your score is " << shca::ShopCart::getName(vec_prod.at(0)) << std::endl;
        choose_product = vec_prod[0];
    else {
        std::cout << "We have some products with potential maximum discount in your shop cart. " << std::endl;
        std::cout << "Please, choose one product to calculate total score:" << std::endl;
        for (int i = 0; i < vec_prod.size(); ++i)
            std::cout << i + 1 << ". " << shca::getName(vec_prod[i]) << std::endl;

        int choose_item = 0;
        std::cin >> choose_item;


        if (choose_item > 0 and choose_item <= vec_prod.size())
            choose_product = vec_prod[choose_item - 1];
        else
            choose_product = vec_prod[0];
    }

    shop.printShopCart(choose_product);

    std::cout << std::setfill(' ') << std::setw(5) << std::left << "";
    std::cout << std::setfill(' ') << std::setw(15) << std::left << "Total";
    std::cout << std::setfill(' ') << std::setw(13) << std::left << " : ";
    std::cout << shop.getTotalBill(choose_product) << std::endl;
    std::cout << std::endl;

    return 0;
}
