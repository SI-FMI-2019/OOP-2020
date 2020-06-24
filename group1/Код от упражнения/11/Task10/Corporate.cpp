//
// Created by lyubo on 14.05.20 г..
//

#include "Corporate.h"

Corporate::Corporate(): BaseClient() {}

Corporate::Corporate(const std::string& name, const std::string& address,
          const int& VAT_num, const Credit& start_payment): BaseClient(name, address, start_payment), VAT_number(VAT_num) {}

Corporate::Corporate(const std::string& name, const std::string& address,
          const int& VAT_num, const Deposit& start_payment): BaseClient(name, address, start_payment), VAT_number(VAT_num) {}

Corporate::Corporate(const std::string& name, const std::string& address,
          const int& VAT_num, const Payment& start_payment): BaseClient(name, address, start_payment), VAT_number(VAT_num) {}

void Corporate::set_VAT(const int& new_VAT_number)
{
    this->VAT_number = new_VAT_number;
}

int Corporate::get_VAT() const
{
    return this->VAT_number;
}

BasePayment* Corporate::get_main_payment() const
{
    auto payments = this->BaseClient::get_payments();
    return payments[0];
}