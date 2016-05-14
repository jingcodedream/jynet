/*
 * IOHandler.h
 *
 *  Created on: 2016年5月12日
 *      Author: joe
 */

#ifndef SRC_CORE_IOHANDLER_H_
#define SRC_CORE_IOHANDLER_H_

class IOHandler
{
public:
    IOHandler(){};
    virtual ~IOHandler(){};
    virtual int OnRead(int fd) = 0;
    virtual int OnWrite(int fd) = 0;
    virtual int OnError(int fd) = 0;
};

class IOHandlerListen : public IOHandler //监听读写控制起
{
public:
    IOHandlerListen(){};
    ~IOHandlerListen(){};

    int OnRead(int fd);
    int OnWrite(int fd){return OnError(fd);};
    int OnError(int fd);
};

class IOHandlerCommon : public IOHandler //普通的读写控制器
{
public:
    IOHandlerCommon(){};
    ~IOHandlerCommon(){};

    int OnRead(int fd);
    int OnWrite(int fd);
    int OnError(int fd);
};

#endif /* SRC_CORE_IOHANDLER_H_ */
