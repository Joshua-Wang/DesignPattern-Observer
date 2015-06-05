/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file blog.h
 * @author wangzhengkang(com@baidu.com)
 * @date 2015/06/04 09:32:11
 * @brief 
 *  
 **/




#ifndef  __BLOG_H_
#define  __BLOG_H_

#include <vector>
#include "observer.h"


class Blog
{

public:
    Blog() {}
    virtual ~Blog() {}
    void add_observer(Observer* o);
    void del_observer(Observer* o);
    void notify_all();
    void set_blog_name(const std::string& str);
    std::string get_blog_name();

private:
    std::vector<Observer*> observers;
    std::string blog_name;

};

class ConcreteBlog : public Blog
{
public:
    

};












#endif  //__BLOG_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
