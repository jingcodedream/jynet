/*
 * IOServer.h
 *
 *  Created on: 2016年5月11日
 *      Author: joe
 */

#ifndef SRC_CORE_IO_SERVER_INTERFACE_H_
#define SRC_CORE_IO_SERVER_INTERFACE_H_

#include <stdint.h>
#include <memory>

const uint32_t io_empty = 0x0000;
const uint32_t io_read  = 0x0001;
const uint32_t io_write = 0x0002;
const uint32_t io_rdwt  = 0x0003;
const uint32_t io_error = 0x0004;

class Session;

//typedef struct EventInfo {
//    int fd;
//    Session *session;
//}eventinfo;

class IOServerInterface {
public:
    virtual ~IOServerInterface(){}

    virtual bool RunOnce() = 0;
    virtual void RunForever() = 0;

    virtual int AddEvent(uint32_t op, uint32_t fd, std::tr1::shared_ptr<Session> session) = 0;
    virtual int DelEvent(uint32_t events, uint32_t fd) = 0;
    virtual int WaitEvent() = 0;
};

#endif /* SRC_CORE_IOSERVER_H_ */
