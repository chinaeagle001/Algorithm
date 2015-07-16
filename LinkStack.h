#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "windows.h"

template<class T>
struct LinkNode
{
    int val;
    LinkNode<T> *next;
};

template<class T>
class LinkStack
{
public:
    LinkStack();
    ~LinkStack();
    bool empty() const;
    int size() const;
    void clear();
    void pop();
    T& top() const;
    void push(const T&);
private:
    LinkNode<T> *m_top;
};

template<class T> LinkStack<T>::LinkStack()
{
    m_top = NULL;
}

template<class T> LinkStack<T>::~LinkStack()
{
    clear();
}

template<class T> bool LinkStack<T>::empty() const
{
    return m_top == NULL;
}

template<class T> int LinkStack<T>::size() const
{
    LinkNode<T> *p = m_top;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        ++len;
    }

    return len;
}

template<class T> void LinkStack<T>::clear()
{
    LinkNode<T> *p;
    while (m_top != NULL)
    {
        p = m_top->next;
        delete m_top;
        m_top = p;
    }
}

template<class T> void LinkStack<T>::pop()
{
    if (!empty())
    {
        LinkNode<T> *p = m_top->next;
        delete m_top;
        m_top = p;
    }
}

template<class T> T& LinkStack<T>::top() const
{
    if (!empty())
    {
        return m_top->val;
    }
}

template<class T> void LinkStack<T>::push(const T& e)
{
    LinkNode<T> *newnode = new LinkNode<T>;
    newnode->val = e;
    newnode->next = m_top;
    m_top = newnode;
}

#endif // LINKSTACK_H

//#include <iostream>
//#include <cstdlib>
//#include "LinkStack.h"
//using namespace std;
//
//void print(LinkStack<int>& r)
//{
//    while (!r.empty())
//    {
//        cout<<r.top()<<" ";
//        r.pop();
//    }
//    cout<<endl;
//}
//
//int main()
//{
//    LinkStack<int> mystack;
//    for (int i = 0; i < 10; i++)
//    {
//        mystack.push(i);
//    }
//
//    LinkStack<int> mystack2;
//    for (int i = 100; i < 110; i++)
//    {
//        mystack2.push(i);
//    }
//    cout<<mystack.size()<<" "<<mystack.top()<<endl;
//    cout<<mystack2.size()<<" "<<mystack2.top()<<endl;
//    print(mystack);
//    print(mystack2);
//
//    for (int i = 100; i < 120; i++)
//    {
//        mystack.push(i);
//        mystack2.push(rand() % 100);
//    }
//    print(mystack);
//    print(mystack2);
//
//    return 0;
//}
