/*
 * test.cpp
 *
 *  Created on: 2016年5月12日
 *      Author: joe
 */

#include "IOServer.h"

int main()
{
    IOServer *test = new IOServerEpoll();
    delete test;
    return 0;
}


