//
// Created by lyubo on 14.05.20 г..
//

#include "BasePayment.h"
BasePayment::BasePayment(): amount(0), percentage(0) {}
BasePayment::BasePayment(const double& amount, const double& percentage): amount(amount), percentage(percentage) {}

double BasePayment::get_amount() const
{
    return this->amount;
}
double BasePayment::get_percentage() const
{
    return this->percentage;
}