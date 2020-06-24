//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_CLIENT_H
#define TASK10_CLIENT_H

#include "BaseClient.h"

class Client: public BaseClient {
public:
    Client();
    Client(const std::string& name, const std::string& address,
            const std::string& last_name, const std::string& phone_number, const Credit& start_payment);

    Client(const std::string& name, const std::string& address,
           const std::string& last_name, const std::string& phone_number, const Deposit& start_payment);

    Client(const std::string& name, const std::string& address,
           const std::string& last_name, const std::string& phone_number, const Payment& start_payment);



    void set_last_name(const std::string& new_last_name);
    void set_phone_number(const std::string& new_phone_number);

    std::string get_last_name() const;
    std::string get_phone_number() const;

    BasePayment* get_main_payment() const override;

    virtual ~Client() = default;
private:
    std::string last_name;
    std::string phone_number;
};


#endif //TASK10_CLIENT_H
