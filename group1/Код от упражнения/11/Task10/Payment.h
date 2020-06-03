//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_PAYMENT_H
#define TASK10_PAYMENT_H

#include "BasePayment.h"

class Payment: public BasePayment {
public:
    void pay(const double& to_pay) override;
};


#endif //TASK10_PAYMENT_H
