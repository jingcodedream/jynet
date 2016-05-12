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
    virtual void OnRead() = 0;
    virtual void OnWrite() = 0;
    virtual void OnError() = 0;
};

class IOHandlerListen : public IOHandler //监听读写控制起
{
public:
    IOHandlerListen(){};
    ~IOHandlerListen(){};

    int OnRead();
    int OnWrite(){return OnError();};
    int OnError();
};

class IOHandlerCommon : public IOHandler //普通的读写控制器
{
public:
    IOHandlerCommon(){};
    ~IOHandlerCommon(){};

    int OnRead();
    int OnWrite(){return OnError();};
    int OnError();
};

#endif /* SRC_CORE_IOHANDLER_H_ */
