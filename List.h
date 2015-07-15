#ifndef LIST_H
#define LIST_H

template<class T>
class List
{
public:
    virtual bool isEmpty() const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;
    virtual bool getElem(T&, int) const = 0;
    virtual bool setElem(const T&, int) = 0;
    virtual int locateElem(const T&) const = 0;
    virtual int locatePrior(const T&) const = 0;
    virtual int locateNext(const T&) const = 0;
    virtual bool insertNode(const T&, int) = 0;
    virtual bool appendNode(const T&) = 0;
    virtual bool deleteNode(T&, int) = 0;
};

#endif // LIST_H
