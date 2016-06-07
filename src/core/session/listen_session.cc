/*
 * listen_session.cc
 *
 *  Created on: 2016年6月7日
 *      Author: joe
 */

#include "listen_session.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int32_t ListenSession::Init(){
    int fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if(fd < 0) {
        return -1;
    }
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htonl(listen_port_);
    listen_addr.sin_addr.s_addr = inet_addr(listen_ipv4_.c_str());
    if(bind(fd, (sockaddr *)&listen_addr, sizeof(sockaddr)) != 0){
        return -2;
    }
    fd_ = fd;
    return 0;
}

IOStatus ListenSession::OnRead() {
    struct sockaddr_in peer_addr;
    uint32_t peer_addr_addr;
    int accept_fd = accept(fd_, (sockaddr *)&peer_addr, &peer_addr_addr);
    if(accept_fd < 0)
    {
        return IOError;
    }
    return IOContinue;
}


