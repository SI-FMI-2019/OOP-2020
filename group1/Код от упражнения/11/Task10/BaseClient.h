//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_BASECLIENT_H
#define TASK10_BASECLIENT_H

#include <string>
#include "BasePayment.h"
#include "Payment.h"
#include "Credit.h"
#include "Deposit.h"
#include <vector>

class BaseClient {
public:
    BaseClient();
    BaseClient(const std::string& name, const std::string& address, const Payment& start_payment);

    BaseClient(const std::string& name, const std::string& address, const Credit& start_payment);
    BaseClient(const std::string& name, const std::string& address, const Deposit& start_payment);

    BaseClient(const BaseClient& from);
    BaseClient& operator=(const BaseClient& from);


    void set_name(const std::string& new_name);
    void set_address(const std::string& new_address);
    void add_payment(const Payment& new_payment);
    void add_payment(const Credit& new_payment);
    void add_payment(const Deposit& new_payment);

    std::string get_name() const;
    std::string get_address() const;
    virtual BasePayment* get_main_payment() const = 0;
    const std::vector<BasePayment*> get_payments() const;

    virtual ~BaseClient();
private:
    static void copy_payments(const std::vector<BasePayment*>& source, std::vector<BasePayment*>& destination);
    static void clear_payments(std::vector<BasePayment*>& source);
    std::string name;
    std::string address;
    std::vector<BasePayment*> payments;

};


#endif //TASK10_BASECLIENT_H
