/*
 * IOServer.h
 *
 *  Created on: 2016年5月11日
 *      Author: joe
 */

#ifndef SRC_CORE_IOSERVER_H_
#define SRC_CORE_IOSERVER_H_

#include <stdint.h>

const uint32_t io_empty = 0x0000;
const uint32_t io_read  = 0x0001;
const uint32_t io_write = 0x0002;
const uint32_t io_rdwt  = 0x0004;
const uint32_t io_error = 0x0008;

class IOHandler;

typedef struct EventInfo
{
    int fd;
    IOHandler *iOHandler;
}eventinfo;

class IOServer
{
public:
    virtual ~IOServer(){}

    virtual bool RunOnce() = 0;
    virtual void RunForever() = 0;

    virtual int AddEvent(uint32_t op, uint32_t fd, IOHandler *iOHandler) = 0;
    virtual int DelEvent(uint32_t events, uint32_t fd) = 0;
    virtual int WaitEvent() = 0;
};

class IOServerEpoll : public IOServer
{
public:
    IOServerEpoll();
    IOServerEpoll(uint32_t flags, uint32_t maxevents, uint32_t timeout);
    ~IOServerEpoll();

    bool RunOnce();
    void RunForever();

    int AddEvent(uint32_t op, uint32_t fd, IOHandler *iOHandler);
    int DelEvent(uint32_t events, uint32_t fd);
    int WaitEvent();

private:
    int epfd;
    struct epoll_event *events;
    uint32_t maxevents;
    uint32_t timeout;
};


#endif /* SRC_CORE_IOSERVER_H_ */
