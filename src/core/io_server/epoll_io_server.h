/*
 * epoll_io_server.h
 *
 *  Created on: 2016年6月7日
 *      Author: joe
 */

#ifndef SRC_CORE_IO_SERVER_EPOLL_IO_SERVER_H_
#define SRC_CORE_IO_SERVER_EPOLL_IO_SERVER_H_

#include "io_server/io_server_interface.h"

class IOServerEpoll : public IOServerInterface {
public:
    IOServerEpoll();
    IOServerEpoll(uint32_t flags, uint32_t maxevents, uint32_t timeout);
    ~IOServerEpoll();

    bool RunOnce();
    void RunForever();

    int AddEvent(uint32_t op, uint32_t fd, std::tr1::shared_ptr<Session> session);
    int DelEvent(uint32_t events, uint32_t fd);
    int WaitEvent();

private:
    int epfd;
    struct epoll_event *events;
    uint32_t maxevents;
    uint32_t timeout;
};



#endif /* SRC_CORE_IO_SERVER_EPOLL_IO_SERVER_H_ */
