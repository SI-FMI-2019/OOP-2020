//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_BASEPAYMENT_H
#define TASK10_BASEPAYMENT_H


class BasePayment {
public:
    BasePayment();
    BasePayment(const double& amount, const double& percentage);

    double get_amount() const;
    double get_percentage() const;

    virtual void pay(const double& to_pay) = 0;

    virtual ~BasePayment() = default;
protected:
    double amount;
private:
    double percentage;
};


#endif //TASK10_BASEPAYMENT_H
