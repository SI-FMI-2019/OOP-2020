//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_CORPORATE_H
#define TASK10_CORPORATE_H

#include "BaseClient.h"
#include "BasePayment.h"
#include "Payment.h"
#include "Credit.h"
#include "Deposit.h"


class Corporate: public BaseClient {
public:
    Corporate();

    Corporate(const std::string& name, const std::string& address,
           const int& VAT_num, const Credit& start_payment);

    Corporate(const std::string& name, const std::string& address,
              const int& VAT_num, const Deposit& start_payment);

    Corporate(const std::string& name, const std::string& address,
              const int& VAT_num, const Payment& start_payment);

    void set_VAT(const int& new_VAT_number);

    int get_VAT() const;

    BasePayment* get_main_payment() const override;
private:
    int VAT_number;
};


#endif //TASK10_CORPORATE_H
