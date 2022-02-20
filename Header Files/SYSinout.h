#pragma once
#include <iostream>

///interface menu operation for your shop cart
void showMenuItems();
///error message for incorrect input
void showErrorIn();
///quantity of input product for add to your shop cart
int getQuantityProduct();
///index of input product for add to your shop cart
int getIndexOfProduct();
///check Yes/No for continue/quit
bool isInputContinue();