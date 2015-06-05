/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file observer.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2015/06/04 09:29:44
 * @brief 
 *  
 **/

#include <iostream>
#include "observer.h"
#include "blog.h" // ���include�������cpp�ļ��У�����observer.h�ļ��оͱ���

RealObserver::RealObserver(const std::string& name, Blog* bb) : observer_name(name), blog(bb)
{
    blog->add_observer(this);
}

void RealObserver::update()
{
    std::cout << "Observer name :" << observer_name << "get notice " << blog->get_blog_name() << std::endl;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
