#ifndef SQSTACK_H
#define SQSTACK_H
#include "windows.h"

template<class T>
class SqStack
{
public:
    SqStack(int);
    ~SqStack();
    void clear();
    bool empty() const;
    int size() const;
    T& top() const;
    void pop();
    void push(const T&);
private:
    T *elem;
    int m_size; //length of array elem
    int m_top; //point to the position after the top element
};

template<class T> SqStack<T>::SqStack(int n)
{
    m_top = 0;
    m_size = n;
    elem = new T[n];
}

template<class T> SqStack<T>::~SqStack()
{
    if (elem != NULL)
    {
        delete [] elem;
    }
}

template<class T> void SqStack<T>::clear()
{
    m_top = 0;
}

template<class T> bool SqStack<T>::empty() const
{
    return m_top == 0;
}

template<class T> int SqStack<T>::size() const
{
    return m_top;
}

template<class T> T& SqStack<T>::top() const
{
    if (!empty())
    {
        return elem[m_top - 1];
    }
}

template<class T> void SqStack<T>::pop()
{
    --m_top;
}

template<class T> void SqStack<T>::push(const T& e)
{
    if (m_top == m_size)
    {
        T *p = new T[m_size + 10];
        for (int i = 0; i < m_top; i++)
        {
            p[i] = elem[i];
        }
        if (elem != NULL)
        {
            delete [] elem;
        }

        elem = p;
        m_size += 10;
    }
    elem[m_top] = e;
    ++m_top;
}
#endif // SQSTACK_H

//#include <iostream>
//#include "SqStack.h"
//using namespace std;
//
//void print(SqStack<int>& r)
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
//    SqStack<int> mystack(5);
//    for (int i = 0; i < 10; i++)
//    {
//        mystack.push(i);
//    }
//
//    SqStack<int> mystack2(3);
//    for (int i = 100; i < 110; i++)
//    {
//        mystack2.push(i);
//    }
//    print(mystack);
//    print(mystack2);
//
//    return 0;
//}
