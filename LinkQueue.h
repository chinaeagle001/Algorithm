#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "windows.h"

template<class T>
struct LinkNode
{
    int val;
    LinkNode<T> *next;
};

template<class T>
class LinkQueue
{
public:
    LinkQueue();
    ~LinkQueue();
    bool empty() const;
    int size() const;
    void clear();
    void push(const T&);
    T& front() const;
    T& back() const;
    void pop();
private:
    LinkNode<T> *m_front; //point to the position before the first element
    LinkNode<T> *m_rear; //point to the last element
};

template<class T> LinkQueue<T>::LinkQueue()
{
    m_front = m_rear = new LinkNode<T>;
    m_front->next = NULL;
}

template<class T> LinkQueue<T>::~LinkQueue()
{
    clear();
    delete m_front;
}

template<class T> bool LinkQueue<T>::empty() const
{
    return m_front == m_rear;
}

template<class T> int LinkQueue<T>::size() const
{
    int len = 0;
    LinkNode<T> *p = m_front->next;
    while (p != NULL)
    {
        ++len;
        p = p->next;
    }
    return len;
}

template<class T> void LinkQueue<T>::clear()
{
    LinkNode<T>* p;
    while (m_front->next != NULL)
    {
        p = m_front->next;
        m_front->next = p->next;
        delete p;
    }
    m_rear = m_front;
}

template<class T> void LinkQueue<T>::push(const T& e)
{
    LinkNode<T>* p = new LinkNode<T>;
    p->val = e;
    p->next = NULL;
    m_rear->next = p;
    m_rear = p;
}

template<class T> T& LinkQueue<T>::front() const
{
    if (!empty())
    {
        return m_front->next->val;
    }
}

template<class T> T& LinkQueue<T>::back() const
{
    if (!empty())
    {
        return m_rear->val;
    }
}

template<class T> void LinkQueue<T>::pop()
{
    if (!empty())
    {
        LinkNode<T> *p = m_front->next;
        m_front->next = m_front->next->next;
        if (p == m_rear)
        {
            m_rear = m_front;
        }
        delete p;
    }
}
#endif // LINKQUEUE_H

//#include <cstdio>
//#include <cstdlib>
//#include "LinkQueue.h"
//
//int main()
//{
//    LinkQueue<int> myque;
//    for (int i = 0; i < 20; i++)
//    {
//        myque.push(rand() % 100);
//        //myque.push(i);
//        printf("size:%d, front:%d, back:%d\n", myque.size(), myque.front(), myque.back());
//        if (i == 10)
//        {
//            myque.clear();
//        }
//    }
//
//    while (!myque.empty())
//    {
//        printf("%d ", myque.front());
//        myque.pop();
//    }
//    return 0;
//}
