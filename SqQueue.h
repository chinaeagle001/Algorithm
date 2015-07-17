#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "windows.h"

template<class T>
class SqQueue
{
public:
    SqQueue(int);
    ~SqQueue();
    bool empty() const;
    int size() const;
    void clear();
    T& front() const;
    T& back() const;
    void push(const T&);
    void pop();
private:
    T *elem;
    int m_front; //point to the first element
    int m_rear; //point to the position after the last element
    int m_size; //length of array elem, not the count of elements in queue
};

template<class T> SqQueue<T>::SqQueue(int n)
{
    m_front = m_rear = 0;
    m_size = n;
    elem = new T[n];
}

template<class T> SqQueue<T>::~SqQueue()
{
    delete [] elem;
}

template<class T> bool SqQueue<T>::empty() const
{
    return m_front == m_rear;
}

template<class T> int SqQueue<T>::size() const
{
    return (m_rear - m_front + m_size) % m_size;
}

template<class T> void SqQueue<T>::clear()
{
    m_rear = m_front = 0;
}

template<class T> T& SqQueue<T>::front() const
{
    if (!empty())
    {
        return elem[m_front];
    }
}

template<class T> T& SqQueue<T>::back() const
{
    if (!empty())
    {
        return elem[(m_rear - 1 + m_size) % m_size];
    }
}

template<class T> void SqQueue<T>::push(const T& e)
{
    if ((m_rear + 1) % m_size == m_front) // Queue is full
    {
        T *p = new T[m_size + 10];
        int i, j;
        for (i = m_front, j = 0; i < m_rear; i = (i + 1) % m_size, j++)
        {
            p[j] = elem[i];
        }
        if (elem != NULL)
        {
            delete [] elem;
        }
        elem = p;
        m_front = 0;
        m_rear = j;
        m_size += 10;
    }
    elem[m_rear % m_size] = e;
    m_rear = (m_rear + 1) % m_size;
}

template<class T> void SqQueue<T>::pop()
{
    m_front = (m_front + 1) % m_size;
}
#endif // SQQUEUE_H

//#include <cstdio>
//#include <cstdlib>
//#include "SqQueue.h"
//
//int main()
//{
//    SqQueue<int> myque(5);
//    for (int i = 0; i < 20; i++)
//    {
//        myque.push(rand() % 100);
//        //myque.push(i);
//        printf("size:%d, front:%d, back:%d\n", myque.size(), myque.front(), myque.back());
//    }
//
//    while (!myque.empty())
//    {
//        printf("%d ", myque.front());
//        myque.pop();
//    }
//    return 0;
//}
