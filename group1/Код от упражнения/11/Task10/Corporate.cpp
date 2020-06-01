//
// Created by lyubo on 14.05.20 г..
//

#include "Corporate.h"

Corporate::Corporate();

Corporate::Corporate(const std::string& name, const std::string& address,
          const int& VAT_num, const Credit& start_payment);

Corporate::Corporate(const std::string& name, const std::string& address,
          const int& VAT_num, const Deposit& start_payment);

Corporate::Corporate(const std::string& name, const std::string& address,
          const int& VAT_num, const Payment& start_payment);

void Corporate::set_VAT(const int& new_VAT_number);

int Corporate::get_VAT() const;

BasePayment* Corporate::get_main_payment() const override;