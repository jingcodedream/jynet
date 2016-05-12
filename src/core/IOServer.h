/*
 * IOServer.h
 *
 *  Created on: 2016年5月11日
 *      Author: joe
 */

#ifndef SRC_CORE_IOSERVER_H_
#define SRC_CORE_IOSERVER_H_

class IOServer
{
public:
    virtual ~IOServer(){}

    virtual bool RunOnce() = 0;
    virtual void RunForever() = 0;

    virtual void AddEvent() = 0;
    virtual void DelEvent() = 0;
    virtual void WaitEvent() = 0;
};

class IOServerEpoll : public IOServer
{
public:
    IOServerEpoll();
    IOServerEpoll(uint32_t flags, uint32_t maxevents, uint32_t timeout);
    ~IOServerEpoll();

    bool RunOnce();
    void RunForever();

    int AddEvent(uint32_t op, uint32_t fd);
    int DelEvent(uint32_t events, uint32_t fd);
    int WaitEvent();

private:
    int epfd;
    struct epoll_event *events;
    uint32_t maxevents;
    uint32_t timeout;
};


#endif /* SRC_CORE_IOSERVER_H_ */
