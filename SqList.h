#ifndef SQLIST_H
#define SQLIST_H
#include "List.h"
#include "windows.h"

template<class T>
class SqList : public List<T>
{
public:
    SqList(int m);
    SqList(const SqList<T>& r);
    ~SqList();
    bool isEmpty() const { return len == 0; }
    int length() const { return len; }
    void clear() {len = 0; }
    bool getElem(T&, int) const;
    bool setElem(const T&, int);
    int locateElem(const T&) const;
    int locatePrior(const T&) const;
    int locateNext(const T&) const;
    bool insertNode(const T&, int);
    bool appendNode(const T&);
    bool deleteNode(T&, int);
    void traverse(void (*visit)(const T&)) const;
    SqList<T>& operator=(const SqList<T>& r);
private:
    int len;
    int size;
    T *elem;
    void copyFrom(const SqList<T>&);
    void increase(int n);
};

template<class T> SqList<T>::SqList(int m)
{
    len = 0;
    if (m = 0)
    {
        elem = NULL;
    }
    else
    {
        elem = new T[m];
    }
    size = m;
}

template<class T> SqList<T>::SqList(const SqList<T>& r)
{
    len = 0;
    size = 0;
    elem = NULL;
    copyFrom(r);
}

template<class T> SqList<T>::~SqList()
{
    delete [] elem;
}

template<class T> bool SqList<T>::getElem(T& e, int i) const
{
    if (i < 1 || i > len)
    {
        return false;
    }
    e = elem[i - 1];
    return true;
}

template<class T> bool SqList<T>::setElem(const T& e, int i)
{
    if (i < 1 || i > len)
    {
        return false;
    }
    elem[i - 1] = e;
    return true;
}

template<class T> int SqList<T>::locateElem(const T& e) const
{
    for (int i = 1; i <= len; i++)
    {
        if (elem[i-1] == e)
        {
            return i;
        }
    }
    return 0;
}

template<class T> int SqList<T>::locatePrior(const T& e) const
{
    int i = locateElem(e);
    if (i > 0)
    {
        return i - 1;
    }
    return 0;
}

template<class T> int SqList<T>::locateNext(const T& e) const
{
    int i = locateElem(e);
    if (i >= 1 && i < len)
    {
        return i + 1;
    }
    return 0;
}

template<class T> bool SqList<T>::insertNode(const T& e, int i)
{
    if (i < 1 || i > len + 1)
    {
        return false;
    }
    if (len == size)
    {
        increase(10);
    }
    for (int m = size; m >= i; m--)
    {
        elem[m] = elem[m - 1];
    }
    elem[i - 1] = e;
    ++len;
    return true;
}

template<class T> bool SqList<T>::appendNode(const T& e)
{
    if (len == size)
    {
        increase(10);
    }
    elem[len] = e;
    ++len;
    return true;
}

template<class T> bool SqList<T>::deleteNode(T& e, int i)
{
    if (i < 1 || i > len)
    {
        return false;
    }
    e = elem[i - 1];
    for (int m = i - 1; m < len - 1; m++)
    {
        elem[m] = elem[m + 1];
    }
    --len;
    return true;
}

template<class T> void SqList<T>::traverse(void (*visit)(const T& e)) const
{
    for (int i = 0; i < len; i++)
    {
        visit(elem[i]);
    }
}

template<class T> SqList<T>& SqList<T>::operator=(const SqList<T>& r)
{
    clear();
    copyFrom(r);
    return *this;
}

template<class T> void SqList<T>::increase(int n)
{
    T *p = new T[size + n];
    for (int i = 0; i < size; i++)
    {
        p[i] = elem[i];
    }
    if (elem != NULL)
    {
        delete [] elem;
    }

    elem = p;
    size += 10;
}

template<class T> void SqList<T>::copyFrom(const SqList<T>& r)
{
    T *p = r.elem;
    for (int i = 0; i < r.len; i++)
    {
        appendNode(*p++);
    }
}
#endif // SQLIST_H

//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include "SqList.h"
//using namespace std;
//
//void print(const int& n)
//{
//    cout<<n<<" ";
//}
//
//int main()
//{
//    SqList<int> mylist(10);
//    for (int i = 0; i < 10; i++)
//    {
//        mylist.appendNode(i);
//    }
//    mylist.traverse(print); cout<<endl;
//    printf("len = %d\n", mylist.length());
//
//    mylist.insertNode(100, 11);
//    mylist.insertNode(111,10);
//    mylist.traverse(print); cout<<endl;
//    printf("len = %d\n", mylist.length());
//
//    int a;
//    mylist.deleteNode(a, 1);
//    mylist.traverse(print); cout<<endl;
//    printf("len = %d\n", mylist.length());
//
//    int i = mylist.locateElem(5);
//    int j = mylist.locatePrior(5);
//    int k = mylist.locateNext(5);
//    cout<<i<<" "<<j<<" "<<k<<" "<<endl;
//
//    SqList<int> mylist2(10);
//    mylist2 = mylist;  //"=" operator
//    SqList<int> mylist2 = mylist;  //copy constructor
//    cout<<mylist2.length()<<endl;
//    mylist2.traverse(print); cout<<endl;
//
//    return 0;
//}
