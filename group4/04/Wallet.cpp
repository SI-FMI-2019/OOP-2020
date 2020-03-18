#include <iostream>

class Wallet {
   private:
    int cash;
    int userId;

   public:
    Wallet(int initialCash) : cash(initialCash) {
        userId = 1;
        // ^ You can generate it with the Static id generation example
    }

    Wallet(const Wallet& rhs) : cash(0), userId(rhs.userId) {
        // Copy only the ID, without the cash
    }

    Wallet& operator=(const Wallet& rhs) {
        if (this != &rhs) {
            // Custom logic for copying, that's why define an operator=
            userId = rhs.userId;
            cash = 0;
        }
        return *this;
    }

    ~Wallet() {
        // Free dynamic memory, but we don't have such
    }

    int checkCurrentCash() const {  // Getter
        return cash;
    }

    int withdraw(int amount) {  // Setter
        if (amount > cash) {
            amount = cash;
        }
        cash -= amount;
        return amount;
    }

    void deposit(int amount) {  // Setter again
        cash += amount;
    }

    void deposit(Wallet& rhs) {  // Seter AGAIN
        cash += rhs.cash;
        rhs.cash = 0;
    }

    // Operator overloading inside class -> we must define only the right side
    // The left side is the implied THIS pointer as in any other method
    Wallet& operator+=(int amount) {
        deposit(amount);
        return *this;
    }

    int operator-=(int amount) {
        return withdraw(amount);
    }

    bool operator<(Wallet& rhs) {
        return cash < rhs.cash;
    }

    bool operator>(Wallet& rhs) {
        return rhs < *this;
    }
};

// Operator overloading outside class -> we must define the right and left side
Wallet operator+(Wallet& lhs, Wallet& rhs) {
    Wallet newWallet(0);
    newWallet.deposit(lhs);
    newWallet.deposit(rhs);
    return newWallet;
}

int main() {
    Wallet myWallet(20);
    Wallet myWallet2(40);

    Wallet myWallet3 = myWallet + myWallet2;  // myWallet3.cash = 60

    myWallet += 40;  // === myWallet.operator+=(40);
}
