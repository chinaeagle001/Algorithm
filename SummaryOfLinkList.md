链表的插入、删除、排序、反转等操作的总结：
```
#include <iostream>
#include <cstdlib>
using namespace std;

// definition of Node
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL){}
};

// create a linklist with n nodes
Node* create(int n)
{
    Node *head = new Node(rand() % 100);
    Node *pre = head;
    for (int i = 1; i < n; i++)
    {
        Node *newnode = new Node(rand() % 100);
        pre->next = newnode;
        pre = newnode;
    }

    return head;
}

// insert node with value num
Node* insert(Node *head, int num)
{
    Node *p = head;
    Node *q;
    while (p != NULL && p->val < num)
    {
        q = p;
        p = p->next;
    }

    Node *newnode = new Node(num);
    if (p == head)
    {
        newnode->next = head;
        head = newnode;
    }
    else if (p == NULL)
    {
        q->next = newnode;
    }
    else
    {
        newnode->next = q->next;
        q->next = newnode;
    }

    return head;
}

// delete node with value num
Node* del(Node *head, int num)
{
    Node *p = head;
    Node *q;
    while (p != NULL && p->val != num)
    {
        q = p;
        p = p->next;
    }

    if (p == head)
    {
        head = head->next;
        delete p;
    }
    else if (p == NULL)
    {
        cout<<"Node could not found!"<<endl;
    }
    else
    {
        q->next = q->next->next;
        delete p;
    }

    return head;
}

int length(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        ++len;
        head = head->next;
    }

    return len;
}

// sort the linklist
Node* sort(Node *head)
{
    int n = length(head);
    for (int i = 0; i < n - 1; i++)
    {
        Node *p = head;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p->val > p->next->val)
            {
                int temp = p->val;
                p->val = p->next->val;
                p->next->val = temp;
            }
            p = p->next;
        }
    }

    return head;
}

// reverse the linklist non-recursive
Node *reverse(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *pre = head;
    Node *cur = head->next;
    while (cur != NULL)
    {
        pre->next = cur->next;
        cur->next = head;
        head = cur;
        cur = pre->next;
    }

    return head;
}

// reverse the linklist recursively
Node* reverse2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void droplist(Node *head)
{
    Node *p;
    while (head != NULL)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

int main()
{
    Node *head = create(10); print(head);
    sort(head); print(head);
    head = insert(head, 101); print(head);
    head = insert(head, -1); print(head);
    head = insert(head, 50); print(head);
    head = del(head, -1); print(head);
    head = del(head, 101); print(head);
    head = del(head, 50); print(head);
    head = reverse(head); print(head);
    head = reverse2(head); print(head);
    droplist(head);
}

```
