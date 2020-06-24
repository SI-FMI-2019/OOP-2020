//
// Created by lyubo on 24.06.20 г..
//

#include <stdexcept>
#include <iostream>
#include "Bank.h"
Bank::Bank(const Bank& from)
{
    Bank::copy_memory(from.clients, this->clients);
}
Bank& Bank::operator= (const Bank& from)
{
    if(this != &from)
    {
        Bank::clear_memory(this->clients);
        Bank::copy_memory(from.clients, this->clients);
    }
    return *this;
}
Bank::~Bank()
{
    Bank::clear_memory(this->clients);
}

//Client-Credit
void Bank::create_client(const std::string& name, const std::string& address,
                   const std::string& last_name, const std::string& phone_number, const Credit& start_payment)
{
    this->clients.push_back(new Client(name, address, last_name, phone_number, start_payment));
}

//Client-Deposit
void Bank::create_client(const std::string& name, const std::string& address,
                   const std::string& last_name, const std::string& phone_number, const Deposit& start_payment)
{
    this->clients.push_back(new Client(name, address, last_name, phone_number, start_payment));
}

//Client-Payment
void Bank::create_client(const std::string& name, const std::string& address,
                   const std::string& last_name, const std::string& phone_number, const Payment& start_payment)
{
    this->clients.push_back(new Client(name, address, last_name, phone_number, start_payment));
}

//YoungClient-Credit
void Bank::create_client(const std::string& name, const std::string& address,
                   const std::string& last_name, const std::string& phone_number, const Credit& start_payment,
                   const Client& parent)
{
    this->clients.push_back(new YoungClient(name, address, last_name, phone_number, start_payment, parent));
}

//YoungClient-Deposit
void Bank::create_client(const std::string& name, const std::string& address,
                         const std::string& last_name, const std::string& phone_number, const Deposit& start_payment,
                         const Client& parent)
{
    this->clients.push_back(new YoungClient(name, address, last_name, phone_number, start_payment, parent));
}

//YoungClient-Payment
void Bank::create_client(const std::string& name, const std::string& address,
                         const std::string& last_name, const std::string& phone_number, const Payment& start_payment,
                         const Client& parent)
{
    this->clients.push_back(new YoungClient(name, address, last_name, phone_number, start_payment, parent));
}

//Corporate-Credit
void Bank::create_client(const std::string& name, const std::string& address,
                   const int& VAT_num, const Credit& start_payment)
{
    this->clients.push_back(new Corporate(name, address, VAT_num, start_payment));
}

//Corporate-Deposit
void Bank::create_client(const std::string& name, const std::string& address,
                   const int& VAT_num, const Deposit& start_payment)
{
    this->clients.push_back(new Corporate(name, address, VAT_num, start_payment));
}

//Corporate-Payment
void Bank::create_client(const std::string& name, const std::string& address,
                   const int& VAT_num, const Payment& start_payment)
{
    this->clients.push_back(new Corporate(name, address, VAT_num, start_payment));
}


void Bank::add_payment_to_client(const std::string& name, const Payment& start_payment)
{
    BaseClient* client;
    try{
        client = this->search_by_name(name);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cout << "Client not found";
    }

    client->add_payment(start_payment);
}
void Bank::add_payment_to_client(const std::string& name, const Deposit& start_payment)
{
    BaseClient* client;
    try{
        client = this->search_by_name(name);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cout << "Client not found";
    }

    client->add_payment(start_payment);
}
void Bank::add_payment_to_client(const std::string& name, const Credit& start_payment)
{
    BaseClient* client;
    try{
        client = this->search_by_name(name);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cout << "Client not found";
    }

    client->add_payment(start_payment);
}

BaseClient* Bank::search_by_name(const std::string& name)
{
    for(auto* client: this->clients)
    {
        if(client->get_name() == name)
        {
            return client;
        }
    }
    throw std::invalid_argument("Client not found");
}

void Bank::copy_memory(const std::vector<BaseClient*>& source, std::vector<BaseClient*>& destination)
{
    for(auto* client: source)
    {
        if(dynamic_cast<Client*>(client) != nullptr)
        {
            destination.push_back(new Client(*dynamic_cast<Client*>(client)));
        }
        else if(dynamic_cast<YoungClient*>(client) != nullptr)
        {
            destination.push_back(new YoungClient(*dynamic_cast<YoungClient*>(client)));
        }
        else if(dynamic_cast<Corporate*>(client) != nullptr)
        {
            destination.push_back(new Corporate(*dynamic_cast<Corporate*>(client)));
        }
        else
        {
            throw std::bad_cast();
        }
    }
}
void Bank::clear_memory(std::vector<BaseClient*>& source)
{
    for(auto* client: source)
    {
        delete client;
    }
}