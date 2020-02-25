class Factorial {
 private:
    int fact;
    int calculated;
    int factorial(int p);

 public:
    void calc(int fact);
    int getCalculated() const;
    int getFact() const;

    Factorial();
    Factorial(int fact);
};
