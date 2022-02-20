#pragma once

#include <cmath>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <iostream>

namespace shca {

    const int price_length = 11;
    ///list of products
    enum class Products {
        BREAD,
        WHITE_BREAD,
        MILK,
        BUTTER,
        SOUR_CREAM,
        MEAT,
        ORANGE,
        APPLE,
        SUGAR,
        PASTA,
        UNKNOWN
    };
    ///list of type of products
    enum class ProductType {
        MILK_PRODUCT,
        FLOUR_PRODUCT,
        FRUIT,
        MEAT,
        SPICE,
        UNKNOWN
    };

    ///return description of product
    std::string getName(Products);

    class ShopCart {
    private:
        //static int array_price_length;
        static std::array<float, price_length> price;
        static std::array<float, 2> product_type_discount;
        static float max_discount;

        ///inner structure for list of items in our shop cart
        struct Buy {
        public:
            Products product;
            int count_product;
            unsigned transaction_id;

            Buy(Products, int, int);
        };

        std::vector<Buy> shop_cart;


    private:
        ///get product type of product
        static ProductType getProductType(Products);

        ///get price of product
        static float getPrice(Products);

        ///get discount of product
        static float getDiscount(Products);

    public:


        ///get list of available product
        static void printProducts();

        ///get maximum discount for products in our shop cart
        std::vector<Products> getMaxDiscount() const;

        ///add product in our shop cart
        int addProduct(Products, int);

        ///delete some one of product in our shop cart
        int cancelProduct(Products, int);

        ///print all products from our shop cart
        void printShopCart(Products max_discount_prod);

        ///get total score all products in our shop cart
        double getTotalBill(Products max_discount_prod);
    };
}