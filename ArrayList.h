#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "List.h"
#include "windows.h"

template<class T>
class ArrayList : public List<T>
{
public:
    ArrayList(int m);
    ArrayList(const ArrayList<T>& r);
    ~ArrayList();
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
    ArrayList<T>& operator=(const ArrayList<T>& r);
//private:
    int len;
    int size;
    T *elem;
    void copyFrom(const ArrayList<T>&);
    void increase(int n);
};

template<class T> ArrayList<T>::ArrayList(int m)
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

template<class T> ArrayList<T>::ArrayList(const ArrayList<T>& r)
{
    len = 0;
    size = 0;
    elem = NULL;
    copyFrom(r);
}

template<class T> ArrayList<T>::~ArrayList()
{
    len = 0;
    size = 0;
    elem = NULL;
    delete [] elem;
}

template<class T> bool ArrayList<T>::getElem(T& e, int i) const
{
    if (i < 1 || i > len)
    {
        return false;
    }
    e = elem[i - 1];
    return true;
}

template<class T> bool ArrayList<T>::setElem(const T& e, int i)
{
    if (i < 1 || i > len)
    {
        return false;
    }
    elem[i - 1] = e;
    return true;
}

template<class T> int ArrayList<T>::locateElem(const T& e) const
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

template<class T> int ArrayList<T>::locatePrior(const T& e) const
{
    return locateElem(e) - 1;
}

template<class T> int ArrayList<T>::locateNext(const T& e) const
{
    int i = locateElem(e);
    if (i >= 1 && i < len)
    {
        return i + 1;
    }
    return 0;
}

template<class T> bool ArrayList<T>::insertNode(const T& e, int i)
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

template<class T> bool ArrayList<T>::appendNode(const T& e)
{
    if (len == size)
    {
        increase(10);
    }
    elem[len] = e;
    ++len;
    return true;
}

template<class T> bool ArrayList<T>::deleteNode(T& e, int i)
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

template<class T> void ArrayList<T>::traverse(void (*visit)(const T& e)) const
{
    for (int i = 0; i < len; i++)
    {
        visit(elem[i]);
    }
}

template<class T> ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& r)
{
    clear();
    copyFrom(r);
}

template<class T> void ArrayList<T>::increase(int n)
{
    T *p = new T[size + n];
    for (int i = 0; i < size; i++)
    {
        p[i] = elem[i];
    }
    delete [] elem;
    elem = p;
    size += 10;
}

template<class T> void ArrayList<T>::copyFrom(const ArrayList<T>& r)
{
    T *p = r.elem;
    for (int i = 0; i < r.len; i++)
    {
        appendNode(*p++);
    }
}
#endif // ARRAYLIST_H