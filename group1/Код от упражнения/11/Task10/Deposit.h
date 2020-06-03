//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_DEPOSIT_H
#define TASK10_DEPOSIT_H

#include "BasePayment.h"

class Deposit: public BasePayment {
public:
    void pay(const double& to_pay) override;
};


#endif //TASK10_DEPOSIT_H
