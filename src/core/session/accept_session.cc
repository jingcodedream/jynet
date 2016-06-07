/*
 * accept_session.cc
 *
 *  Created on: 2016年6月7日
 *      Author: joe
 */

#include "session/accept_session.h"

int32_t AcceptSession::Init(){
    return 0;
}

IOStatus AcceptSession::OnRead() {
    return IOContinue;
}


