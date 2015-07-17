#ifndef LINKLIST_H
#define LINKLIST_H
#include "List.h"
#include "windows.h"
template<class T>
struct LinkNode
{
    int val;
    LinkNode<T> *next;
};

template<class T>
class LinkList : public List<T>
{
public:
    LinkList();
    LinkList(const LinkList<T>&);
    ~LinkList();
    bool isEmpty() const { return len == 0; }
    int length() const { return len; }
    void clear();
    bool getElem(T&, int) const;
    bool setElem(const T&, int);
    int locateElem(const T&) const;
    int locatePrior(const T&) const;
    int locateNext(const T&) const;
    bool insertNode(const T&, int);
    bool appendNode(const T&);
    bool deleteNode(T&, int);
    void traverse(void (*visit)(const T&));
    LinkList<T>& operator=(const LinkList<T>&);
private:
    void copyFrom(const LinkList<T>&);
    LinkNode<T> *head; //point to the position before the first element
    LinkNode<T> *tail; //point to the last element
    int len;
};

template<class T> LinkList<T>::LinkList()
{
    len = 0;
    head = tail = new LinkNode<T>;
    head->next = NULL;
}

template<class T> LinkList<T>::LinkList(const LinkList<T>& r)
{
    copyFrom(r);
}

template<class T> LinkList<T>::~LinkList()
{
    clear();
    delete head;
}

template<class T> void LinkList<T>::clear()
{
    LinkNode<T> *p = head->next;
    while (p != NULL)
    {
        LinkNode<T> *q = p->next;
        delete p;
        p = q;
    }
}

template<class T> bool LinkList<T>::getElem(T& e, int i) const
{
    if (i < 1 || i > len)
    {
        return false;
    }

    LinkNode<T> *p = head;
    for (int m = 1; m <= i; m++)
    {
        p = p->next;
    }
    e = p->val;
    return true;
}

template<class T> bool LinkList<T>::setElem(const T& e, int i)
{
    if (i < 1 || i > len + 1)
    {
        return false;
    }

    LinkNode<T> *p = head;
    for (int m = 1; m <= i; m++)
    {
        p = p->next;
    }

    p->val = e;
    return true;
}

template<class T> int LinkList<T>::locateElem(const T& e) const
{
    int i = 1;
    LinkNode<T> *p = head->next;
    while (p != NULL && p->val != e)
    {
        p = p->next;
        i++;
    }

    if (p != NULL)
    {
        return i;
    }
    return 0;
}

template<class T> int LinkList<T>::locatePrior(const T& e) const
{
    int i = locateElem(e);
    if (i == 0)
    {
        return 0;
    }
    return i - 1;
}

template<class T> int LinkList<T>::locateNext(const T& e) const
{
    int i = locateElem(e);
    if (i == 0 || i == len)
    {
        return 0;
    }
    return i + 1;
}

template<class T> bool LinkList<T>::insertNode(const T& e, int i)
{
    LinkNode<T> *p = head;
    for (int m = 1; m < i; m++)
    {
        p = p->next;
    }

    LinkNode<T> *newnode = new LinkNode<T>;
    newnode->val = e;
    newnode->next = p->next;
    p->next = newnode;

    if (i == len + 1)
    {
        tail = newnode;
    }
    ++len;
    return true;
}

template<class T> bool LinkList<T>::appendNode(const T& e)
{
    LinkNode<T> *newnode = new LinkNode<T>;
    newnode->val = e;
    newnode->next = NULL;
    tail->next = newnode;
    tail = newnode;
    ++len;
    return true;
}

template<class T> bool LinkList<T>::deleteNode(T& e, int i)
{
    if (i < 1 || i > len)
    {
        return false;
    }

    LinkNode<T> *p = head;
    for (int m = 1; m < i; m++)
    {
        p = p->next;
    }
    LinkNode<T> *q = p->next;
    p->next = p->next->next;
    e = q->val;
    if (q == tail)
    {
        tail = p;
    }
    delete q;
    --len;
    return true;
}

template<class T> LinkList<T>& LinkList<T>::operator=(const LinkList<T>& r)
{
    clear();
    copyFrom(r);
    return *this;
}

template<class T> void LinkList<T>::traverse(void (*visit)(const T& e))
{
    LinkNode<T> *p = head->next;
    while (p != NULL)
    {
        visit(p->val);
        p = p->next;
    }
}

template<class T> void LinkList<T>::copyFrom(const LinkList<T>& r)
{
    len = 0;
    head = tail = new LinkNode<T>;
    head->next = NULL;
    LinkNode<T> *p = r.head->next;
    while (p != NULL)
    {
        appendNode(p->val);
        p = p->next;
    }
}

#endif // LINKLIST_H

//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include "ArrayList.h"
//#include "LinkList.h"
//using namespace std;
//
//void print(const int& n)
//{
//    cout<<n<<" ";
//}
//
//int main()
//{
//    LinkNode<int> *node = new LinkNode<int>;
//    if (node->next == NULL)
//    {
//        cout<<" fdsf";
//    }
//    LinkList<int> mylist;
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
//    LinkList<int> mylist2;
//    mylist2 = mylist; //"=" operator
//    //LinkList<int> mylist2 = mylist; //copy constructor
//    printf("len = %d\n", mylist.length());
//    mylist2.traverse(print); cout<<endl;
//
//    return 0;
//}
