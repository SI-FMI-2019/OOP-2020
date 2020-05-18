//
// Created by lyubo on 14.05.20 г..
//

#include "BaseClient.h"
BaseClient::BaseClient(): name(""), address("")
{
    this->payments = std::vector<BasePayment*>();
}
BaseClient::BaseClient(const std::string& name, const std::string& address, const Payment& start_payment):
    name(name), address(address)
{
    this->payments.push_back();
}
BaseClient::BaseClient(const std::string& name, const std::string& address, const Credit& start_payment);
BaseClient::BaseClient(const std::string& name, const std::string& address, const Deposit& start_payment);

void BaseClient::set_name(const std::string& new_name);
void BaseClient::set_address(const std::string& new_address);
void BaseClient::add_payment(const Payment& new_payment);
void BaseClient::add_payment(const Credit& new_payment);
void BaseClient::add_payment(const Deposit& new_payment);

std::string get_name() const;
std::string get_address() const;
const std::vector<BasePayment*> get_payments() const;