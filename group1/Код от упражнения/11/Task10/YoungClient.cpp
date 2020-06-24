//
// Created by lyubo on 14.05.20 г..
//

#include "YoungClient.h"

YoungClient::YoungClient(): Client() {}

YoungClient::YoungClient(const std::string& name, const std::string& address,
            const std::string& last_name, const std::string& phone_number, const Credit& start_payment,
            const Client& parent): Client(name, address, last_name, phone_number, start_payment), parent(parent) {}

YoungClient::YoungClient(const std::string& name, const std::string& address,
            const std::string& last_name, const std::string& phone_number, const Deposit& start_payment,
            const Client& parent): Client(name, address, last_name, phone_number, start_payment), parent(parent) {}

YoungClient::YoungClient(const std::string& name, const std::string& address,
            const std::string& last_name, const std::string& phone_number, const Payment& start_payment,
            const Client& parent): Client(name, address, last_name, phone_number, start_payment), parent(parent) {}

Client YoungClient::get_parent() const
{
    return this->parent;
}

void YoungClient::set_parent(const Client& new_parent)
{
    this->parent = new_parent;
}