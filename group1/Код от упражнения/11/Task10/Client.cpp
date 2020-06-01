//
// Created by lyubo on 14.05.20 г..
//

#include "Client.h"

Client::Client(): BaseClient(), last_name(""), phone_number("") {}

Client::Client(const std::string& name, const std::string& address,
       const std::string& last_name, const std::string& phone_number, const Credit& start_payment)
       :BaseClient(name, address, start_payment), last_name(last_name), phone_number(phone_number) {}

Client::Client(const std::string& name, const std::string& address,
       const std::string& last_name, const std::string& phone_number, const Deposit& start_payment)
        :BaseClient(name, address, start_payment), last_name(last_name), phone_number(phone_number) {}

Client::Client(const std::string& name, const std::string& address,
       const std::string& last_name, const std::string& phone_number, const Payment& start_payment)
        :BaseClient(name, address, start_payment), last_name(last_name), phone_number(phone_number) {}

void Client::set_last_name(const std::string& new_last_name)
{
    this->last_name = new_last_name;
}
void Client::set_phone_number(const std::string& new_phone_number)
{
    this->phone_number = new_phone_number;
}

std::string Client::get_last_name() const
{
    return this->last_name;
}
std::string Client::get_phone_number() const
{
    return this->phone_number;
}

BasePayment* Client::get_main_payment() const
{
    auto payments = this->BaseClient::get_payments();
    return payments[0];

    //return this->BaseClient::get_payments()[0];
}