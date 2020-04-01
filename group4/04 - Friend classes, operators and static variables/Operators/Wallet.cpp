#include <iostream>
#include "Wallet.h"
Wallet::Wallet(int initialCash) : cash(initialCash) {
    userId = 1;
    // ^ You can generate it with the Static id generation example
}

Wallet::Wallet(const Wallet& rhs) : cash(0), userId(rhs.userId) {
    // Copy only the ID, without the cash
}

Wallet& Wallet::operator=(const Wallet& rhs) {
    if (this != &rhs) {
        // Custom logic for copying, that's why define an operator=
        userId = rhs.userId;
        cash = 0;
    }
    return *this;
}

Wallet::~Wallet() {
    // Free dynamic memory, but we don't have such
}

int Wallet::checkCurrentCash() const {  // Getter
    return cash;
}

int Wallet::withdraw(int amount) {  // Setter
    if (amount > cash) {
        amount = cash;
    }
    cash -= amount;
    return amount;
}

void Wallet::deposit(int amount) {  // Setter again
    cash += amount;
}

void Wallet::deposit(Wallet& rhs) {  // Seter AGAIN
    cash += rhs.cash;
    rhs.cash = 0;
}

// Operator overloading inside class -> we must define only the right side
// The left side is the implied THIS pointer as in any other method
Wallet& Wallet::operator+=(int amount) {
    deposit(amount);
    return *this;
}

int Wallet::operator-=(int amount) {
    return withdraw(amount);
}

bool Wallet::operator<(Wallet& rhs) {
    return cash < rhs.cash;
}

bool Wallet::operator>(Wallet& rhs) {
    return rhs < *this;
}

// Operator overloading outside class -> we must define the right and left side
Wallet operator+(Wallet& lhs, Wallet& rhs) {
    Wallet newWallet(0);
    newWallet.deposit(lhs);
    newWallet.deposit(rhs);
    return newWallet;
}
