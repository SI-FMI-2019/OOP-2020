//
// Created by lyubo on 24.06.20 г..
//

#ifndef TASK10_BANK_H
#define TASK10_BANK_H

#include "BaseClient.h"
#include "Client.h"
#include "Corporate.h"
#include "YoungClient.h"
class Bank {
public:
    Bank() = default;
    Bank(const Bank& from);
    Bank& operator= (const Bank& from);
    ~Bank();

    //Client-Credit
    void create_client(const std::string& name, const std::string& address,
                       const std::string& last_name, const std::string& phone_number, const Credit& start_payment);

    //Client-Deposit
    void create_client(const std::string& name, const std::string& address,
                       const std::string& last_name, const std::string& phone_number, const Deposit& start_payment);

    //Client-Payment
    void create_client(const std::string& name, const std::string& address,
                       const std::string& last_name, const std::string& phone_number, const Payment& start_payment);

    //YoungClient-Credit
    void create_client(const std::string& name, const std::string& address,
                       const std::string& last_name, const std::string& phone_number, const Credit& start_payment,
                       const Client& parent);

    //YoungClient-Deposit
    void create_client(const std::string& name, const std::string& address,
                       const std::string& last_name, const std::string& phone_number, const Deposit& start_payment,
                       const Client& parent);

    //YoungClient-Payment
    void create_client(const std::string& name, const std::string& address,
                       const std::string& last_name, const std::string& phone_number, const Payment& start_payment,
                       const Client& parent);

    //Corporate-Credit
    void create_client(const std::string& name, const std::string& address,
                       const int& VAT_num, const Credit& start_payment);

    //Corporate-Deposit
    void create_client(const std::string& name, const std::string& address,
                       const int& VAT_num, const Deposit& start_payment);

    //Corporate-Payment
    void create_client(const std::string& name, const std::string& address,
                       const int& VAT_num, const Payment& start_payment);


    void add_payment_to_client(const std::string& name, const Payment& start_payment);
    void add_payment_to_client(const std::string& name, const Deposit& start_payment);
    void add_payment_to_client(const std::string& name, const Credit& start_payment);

private:
    BaseClient* search_by_name(const std::string& name);

    static void copy_memory(const std::vector<BaseClient*>& source, std::vector<BaseClient*>& destination);
    static void clear_memory(std::vector<BaseClient*>& source);
    std::vector<BaseClient*> clients;
};


#endif //TASK10_BANK_H
