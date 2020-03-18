class Static {
   private:
    int secretNumber = 5;

   public:
    static char letter;

    Static();
    int generateId() const;
};
