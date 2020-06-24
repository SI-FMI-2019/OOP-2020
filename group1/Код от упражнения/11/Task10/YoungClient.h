//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_YOUNGCLIENT_H
#define TASK10_YOUNGCLIENT_H

#include "Client.h"

class YoungClient: public Client {
public:
    YoungClient();

    YoungClient(const std::string& name, const std::string& address,
                const std::string& last_name, const std::string& phone_number, const Credit& start_payment,
                const Client& parent);

    YoungClient(const std::string& name, const std::string& address,
                const std::string& last_name, const std::string& phone_number, const Deposit& start_payment,
                const Client& parent);

    YoungClient(const std::string& name, const std::string& address,
                const std::string& last_name, const std::string& phone_number, const Payment& start_payment,
                const Client& parent);

    Client get_parent() const;

    void set_parent(const Client& new_parent);
private:
    Client parent;
};


#endif //TASK10_YOUNGCLIENT_H
