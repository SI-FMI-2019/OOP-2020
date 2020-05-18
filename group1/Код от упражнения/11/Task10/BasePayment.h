//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_BASEPAYMENT_H
#define TASK10_BASEPAYMENT_H


class BasePayment {
public:
    BasePayment();
    BasePayment(const double& amount, const double& percentage);

    void get_amount();
    void get_percentage();

    virtual void pay(const double& to_pay) = 0;
private:
    double amount;
    double percentage;
};


#endif //TASK10_BASEPAYMENT_H
