/*********************************************
> File  : ThreadPool.cpp
> Author: NewYork
> Mail  : 2287794993@qq.com 
> Time  : Fri 03 Jul 2015 10:13:17 AM CST
 ********************************************/

#include<iostream>
#include<vector>
#include "MyPoolThread.h"
using namespace std;

namespace wd
{
    void ThreadPool::start()
    {
        for(std::size_t index=0; index!=numThreads_; index++)
        {
            Thread* pThread = new MyPoolThread(*this);
            vecThreads_.push_back(pThread);
            pThread->start();
        }
    }
    ThreadPool::~ThreadPool()
    {
        if(!isExit_)
        {
            isExit_ = true;
        for(auto it: vecThreads_)
        {
            (*it)->join();
            delete *it;
        }
        }
        vecThreads_.clear();
    }
    void ThreadPool::addTask(Task task)
    {
        buffer_.push(task);
    }
    Task ThreadPool::getTask()
    {
        return buffer_.pop();
    }
    void ThreadPool::runInThread()
    {
        while(!isExit_)
        {
            Task task =getTask()
            if(task!=NULL)
            {
                task->process();
            }
        }
    }
}
