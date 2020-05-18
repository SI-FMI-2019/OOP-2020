//
// Created by lyubo on 14.05.20 г..
//

#ifndef TASK10_YOUNGCLIENT_H
#define TASK10_YOUNGCLIENT_H

#include "Client.h"

class YoungClient: public Client {
public:
    YoungClient();
private:
    Client parent;
};


#endif //TASK10_YOUNGCLIENT_H
