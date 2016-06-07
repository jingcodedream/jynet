/*
 * listen_session.h
 *
 *  Created on: 2016年6月7日
 *      Author: joe
 */

#ifndef SRC_CORE_SESSION_LISTEN_SESSION_H_
#define SRC_CORE_SESSION_LISTEN_SESSION_H_

#include "session_interface.h"

#include <string>

class ListenSession : public SessionInterface {
public:
    ListenSession(const std::string &listen_ipv4, uint32_t listen_port)
        : fd_(-1), listen_ipv4_(listen_ipv4), listen_port_(listen_port) {}
    ~ListenSession(){}

    int32_t Init();
    IOStatus OnRead();
    IOStatus OnWrite() {return IOError;}
    IOStatus OnError() {return IOError;}
private:
    int fd_;
    std::string listen_ipv4_;
    uint32_t listen_port_;
};

#endif /* SRC_CORE_SESSION_LISTEN_SESSION_H_ */
