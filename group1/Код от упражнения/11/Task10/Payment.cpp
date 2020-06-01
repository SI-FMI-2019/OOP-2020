//
// Created by lyubo on 14.05.20 г..
//

#include "Payment.h"

void Payment::pay(const double &to_pay) {
    this->BasePayment::amount -= to_pay;
    this->BasePayment::amount += (to_pay * this->BasePayment::get_percentage());
}