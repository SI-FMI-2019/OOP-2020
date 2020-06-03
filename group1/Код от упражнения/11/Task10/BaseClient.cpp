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
    /*const Payment* start_payment_as_const_ptr = &start_payment;
    Payment* start_payment_as_ptr = const_cast<Payment*>(start_payment_as_const_ptr);
    BasePayment* start_payment_as_base_ptr = start_payment_as_ptr;
    this->payments.push_back(start_payment_as_base_ptr);*/

    this->payments.push_back(const_cast<Payment*>(&start_payment));
}
BaseClient::BaseClient(const std::string& name, const std::string& address, const Credit& start_payment)
    :name(name), address(address)
{
    this->payments.push_back(const_cast<Credit*>(&start_payment));
}
BaseClient::BaseClient(const std::string& name, const std::string& address, const Deposit& start_payment)
    :name(name), address(address)
{
    this->payments.push_back(const_cast<Deposit*>(&start_payment));
}

void BaseClient::set_name(const std::string& new_name)
{
    this->name = new_name;
}
void BaseClient::set_address(const std::string& new_address)
{
    this->address = new_address;
}
void BaseClient::add_payment(const Payment& new_payment)
{
    this->payments.push_back(const_cast<Payment*>(&new_payment));
}
void BaseClient::add_payment(const Credit& new_payment)
{
    this->payments.push_back(const_cast<Credit*>(&new_payment));
}
void BaseClient::add_payment(const Deposit& new_payment)
{
    this->payments.push_back(const_cast<Deposit*>(&new_payment));
}

std::string BaseClient::get_name() const
{
    return this->name;
}
std::string BaseClient::get_address() const
{
    return this->address;
}
const std::vector<BasePayment*> BaseClient::get_payments() const
{
    return this->payments;
}