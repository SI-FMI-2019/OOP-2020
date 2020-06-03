//
// Created by lyubo on 14.05.20 г..
//

#include "Deposit.h"

void Deposit::pay(const double &to_pay) {
    this->BasePayment::amount -= amount;
}