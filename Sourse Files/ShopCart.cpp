#include "../Header Files/ShopCart.h"

namespace shca {

//int array_price_length = 10;
    std::array<float, price_length> shca::ShopCart::price = {0.9, 1.1, 1.3, 3.6, 1.8, 16.0, 3.0, 2.5, 2.05,
                                                             1.29, 0};
    std::array<float, 2> shca::ShopCart::product_type_discount = {0.33, 0.2};
    float shca::ShopCart::max_discount = 0.5;

    std::string getName(Products prod) {
        switch (prod) {
            case Products::BREAD:
                return "Bread";//"хлеб";
            case Products::WHITE_BREAD: {
                return "Wight Bread";//"белый хлеб";
            }
            case Products::MILK: {
                return "Milk";//"молоко";
            }
            case Products::BUTTER: {
                return "Butter";//"масло";
            }
            case Products::SOUR_CREAM: {
                return "Sour cream";//"сметана";
            }
            case Products::MEAT: {
                return "Meat";//"мясо";
            }
            case Products::ORANGE: {
                return "Orange";//"апельсины";
            }
            case Products::APPLE: {
                return "Apple";//"яблоки";
            }
            case Products::SUGAR: {
                return "Sugar";//"сахар";
            }
            case Products::PASTA: {
                return "Pasta";//"макароны";
            }
            default: {
                return "UNKNOWN";//"не известный товар";
            }
        }
    }

    float ShopCart::getPrice(Products prod) {
        return ShopCart::price[static_cast<int>(prod)];
/*
        switch (prod) {
            case Products::BREAD:
                return ShopCart::price[1];
                //break;
            case Products::WHITE_BREAD: {
                return ShopCart::price[2];
                //break;
            }
            case Products::MILK: {
                return ShopCart::price[3];
                //break;
            }
            case Products::BUTTER: {
                return ShopCart::price[4];
                //break;
            }
            case Products::SOUR_CREAM: {
                return ShopCart::price[5];
                //break;
            }
            case Products::MEAT: {
                return ShopCart::price[6];
                //break;
            }
            case Products::ORANGE: {
                return ShopCart::price[7];
                //break;
            }
            case Products::APPLE: {
                return ShopCart::price[8];
                //break;
            }
            case Products::SUGAR: {
                return ShopCart::price[9];
                //break;
            }
            case Products::PASTA: {
                return ShopCart::price[10];
                //break;
            }
            default: {
                return 0.0;
            }

        }
              */
    }

    ProductType ShopCart::getProductType(Products prod) {
        switch (prod) {
            case Products::BREAD:
            case Products::WHITE_BREAD:
            case Products::PASTA:
                return ProductType::FLOUR_PRODUCT;
            case Products::MILK:
            case Products::BUTTER:
            case Products::SOUR_CREAM:
                return ProductType::MILK_PRODUCT;
            case Products::MEAT: {
                return ProductType::MEAT;
            }
            case Products::ORANGE:
            case Products::APPLE:
                return ProductType::FRUIT;
            case Products::SUGAR: {
                return ProductType::SPICE;
            }
            default: {
                return ProductType::UNKNOWN;
            }
        }
    }

    float ShopCart::getDiscount(Products prod) {
        switch (getProductType(prod)) {
            case shca::ProductType::MILK_PRODUCT:
                return ShopCart::product_type_discount[0];
            case ProductType::FLOUR_PRODUCT:
                return ShopCart::product_type_discount[1];
            default:
                return 0;
        }
    }

    shca::ShopCart::Buy::Buy(Products
                             prod, int
                             count_product, int
                             transaction_id) {
        this->product = prod;
        this->count_product = count_product;
        this->transaction_id = transaction_id;
    }

    int ShopCart::addProduct(Products prod, int count_product) {
        this->shop_cart.emplace_back(prod, count_product, this->shop_cart.size() + 1);
        return static_cast<int>(this->shop_cart.size()) + 1;
    }

    int ShopCart::cancelProduct(Products prod, int count_product) {
        for (auto itt = this->shop_cart.begin(); itt != this->shop_cart.end(); ++itt) {
            if ((*itt).product == prod) {
                if ((*itt).count_product > count_product) {
                    (*itt).count_product -= count_product;
                    return 0;
                } else {
                    count_product -= (*itt).count_product;
                    this->shop_cart.erase(itt);
                }
            }
        }
        return count_product;
    }

    void ShopCart::printProducts() {
        auto item = Products::BREAD;
        std::cout << "------------------------------------------------------------------------------------"
                  << std::endl;
        do {
            std::cout << "| ";
            std::cout << std::setfill(' ') << std::setw(2) << std::left << (static_cast<int>(item) + 1) << ". ";
            std::cout << std::setfill(' ') << std::setw(15) << std::left << getName(item);
            std::cout << ": price = ";
            std::cout << std::setfill(' ') << std::setw(9) << std::left << ShopCart::getPrice(item) << " ";
            std::cout << "|";

            if ((static_cast<int>(item) + 1) % 2 == 0)
                std::cout << std::endl;
            else
                std::cout << "";
            item = static_cast<Products>(static_cast<int>(item) + 1);
        } while (item != Products::UNKNOWN);

        if (static_cast<int>(item) % 2 > 0)
            std::cout << std::endl;
        std::cout << "------------------------------------------------------------------------------------"
                  << std::endl;
    }

    void ShopCart::printShopCart(Products max_discount_prod) {
        std::cout << "-----------------score of your shop cart---" << std::endl;
        if (this->shop_cart.empty()) {
            std::cout << "Your shop cart is empty" << std::endl;
            std::cout << "-------------------------------------------" << std::endl;
            return;
        }
        //for (auto itt = this->shop_cart.begin(); itt != this->shop_cart.end(); ++itt)
        /*
        for (auto itt: this->shop_cart)
            std::cout << (itt).transaction_id << " - " << getName((itt).product) << " - "
                      << (itt).count_product << std::endl;

        std::cout << "-------------------------------------------" << std::endl;
         */
        std::cout << std::setfill(' ') << std::setw(5) << std::left << "ID";
        std::cout << std::setfill(' ') << std::setw(15) << std::left << "Product";
        std::cout << std::setfill(' ') << std::setw(10) << std::right << "Quantity";
        std::cout << "   ";
        std::cout << std::setfill(' ') << std::setw(10) << std::left << "Price";
        std::cout << std::setfill(' ') << std::setw(10) << std::left << "Discount" << std::endl;
        std::cout << std::endl;

        for (auto itt: this->shop_cart) {
            std::cout << std::setfill(' ') << std::setw(5) << std::left << itt.transaction_id;
            std::cout << std::setfill(' ') << std::setw(15) << std::left << getName((itt).product);
            std::cout << " : ";
            std::cout << std::setfill(' ') << std::setw(7) << std::right << itt.count_product;
            std::cout << " x ";
            std::cout << std::setfill(' ') << std::setw(10) << std::left
                      << ShopCart::getPrice((itt).product);
            std::cout << "(";
            std::cout << 100 * (itt.product == max_discount_prod ? shca::ShopCart::max_discount : ShopCart::getDiscount(
                    itt.product));
            std::cout << "%)" << std::endl;
        }

        std::cout << std::endl;
    }

    std::vector<Products> ShopCart::getMaxDiscount() const {
        std::vector<Buy> shop_cart_clone = this->shop_cart;
        std::vector<Products> max_disc_prod;
        double max_price = 0;
        double sum_elem;
        double price_prod;
        Products prod;

        max_disc_prod.reserve(3);

        for (auto itt = shop_cart_clone.begin(); itt != shop_cart_clone.end(); ++itt) {

            prod = (*itt).product;
            price_prod = ShopCart::getPrice(prod);
            sum_elem = (*itt).count_product * price_prod;

            for (auto itt_sum = itt + 1; itt_sum != shop_cart_clone.end(); ++itt_sum) {
                if ((*itt_sum).product == prod) {
                    sum_elem += (*itt_sum).count_product * price_prod;
                    shop_cart_clone.erase(itt_sum);
                }
            }

            if (fabs(sum_elem - max_price) < 0.0001) {
                max_disc_prod.push_back(prod);
            } else if (sum_elem > max_price) {
                max_price = sum_elem;
                max_disc_prod.clear();
                max_disc_prod.push_back(prod);
            }
        }
        return max_disc_prod;
    }

    double ShopCart::getTotalBill(Products max_discount_prod) {
        double total_bill = 0;

        for (auto itt: this->shop_cart)
            total_bill += static_cast<double>((itt).count_product) * ShopCart::getPrice((itt).product) *
                          (1 - (itt.product == max_discount_prod ? shca::ShopCart::max_discount : ShopCart::getDiscount(
                                  itt.product)));

        return total_bill;
    }
}
