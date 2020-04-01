class Wallet {
   private:
    int cash;
    int userId;

   public:
    Wallet(int initialCash);
    Wallet(const Wallet& rhs);
    Wallet& operator=(const Wallet& rhs);
    ~Wallet();

    int checkCurrentCash() const;
    int withdraw(int amount);

    void deposit(int amount);

    void deposit(Wallet& rhs);

    // Operator overloading inside class -> we must define only the right side
    // The left side is the implied THIS pointer as in any other method
    Wallet& operator+=(int amount);
    int operator-=(int amount); // You decide on the return type
    bool operator<(Wallet& rhs);
    bool operator>(Wallet& rhs);
};

// Operator overloading outside class -> we must define the right and left side
Wallet operator+(Wallet& lhs, Wallet& rhs);
