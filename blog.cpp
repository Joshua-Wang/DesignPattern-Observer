/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file blog.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2015/06/04 09:36:59
 * @brief 
 *  
 **/

#include "blog.h"
#include <algorithm>

void Blog::set_blog_name(const std::string& str)
{
    blog_name = str; 
    notify_all();
}

std::string Blog::get_blog_name()
{
    return blog_name;
}

void Blog::add_observer(Observer* o)
{
    observers.push_back(o);

}

void Blog::del_observer(Observer* o)
{
    std::vector< Observer*>::iterator iter = find(observers.begin(), observers.end(), o);
    if (iter != observers.end())
    {
        observers.erase(iter);
    }
}

void Blog::notify_all()
{
    int len = observers.size();
    for (int i = 0; i < len; i++)
    {
        Observer *obj = observers[i];
        obj->update();
    }
}















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
