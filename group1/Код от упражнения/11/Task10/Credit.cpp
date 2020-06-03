//
// Created by lyubo on 14.05.20 г..
//

#include "Credit.h"

void Credit::pay(const double& to_pay)
{
    this->BasePayment::amount += to_pay + (to_pay * this->BasePayment::get_percentage());
}