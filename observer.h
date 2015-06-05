/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file observer.h
 * @author wangzhengkang(com@baidu.com)
 * @date 2015/06/04 09:26:24
 * @brief 
 *  
 **/




#ifndef  __OBSERVER_H_
#define  __OBSERVER_H_

#include <string>

class Blog;

class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void update() {}
};

class RealObserver : public Observer
{
public:
    RealObserver(const std::string& name, Blog* bb); 
    virtual void update();

private:
    Blog* blog;
    const std::string observer_name;
};














#endif  //__OBSERVER_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
