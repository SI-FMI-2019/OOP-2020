#include <iostream>
#include "Wallet.h"

int main() {
    Wallet myWallet(20);
    Wallet myWallet2(40);

    Wallet myWallet3 = myWallet + myWallet2;  // myWallet3.cash = 60

    myWallet += 40;  // === myWallet.operator+=(40);
}
