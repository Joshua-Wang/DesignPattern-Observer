/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file main.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2015/06/04 09:40:10
 * @brief 
 *  
 **/

#include <iostream>
#include "blog.h"
#include "observer.h"

int main(int argc, char** args)
{
    Blog *my_blog = new ConcreteBlog();
    Observer *o1 = new RealObserver("ob1", my_blog);
    Observer *o2 = new RealObserver("ob2", my_blog);
    Observer *o3 = new RealObserver("ob3", my_blog);
    my_blog->set_blog_name("observer_model");
    my_blog->set_blog_name("factory_model");

    delete o1;
    delete o2;
    delete o3;
    delete my_blog;

    return 0;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
