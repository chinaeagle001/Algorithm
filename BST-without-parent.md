没有父亲结点的Binary Search Tree实现代码：
```C++
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* search(TreeNode *root, int key)
{
    while (root != NULL)
    {
        if (root->val > key)
        {
            root = root->left;
        }
        else if (root->val < key)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }

    return root;
}

void insertNode(TreeNode*& root, int key)
{
    TreeNode *p = root;
    TreeNode *q;
    while (p != NULL)
    {
        if (p->val > key)
        {
            q = p;
            p = p->left;
        }
        else if (p->val < key)
        {
            q = p;
            p = p->right;
        }
        else
        {
            break;
        }
    }

    if (p != NULL)
    {
        return;
    }

    TreeNode *newnode = new TreeNode(key);
    if (root == NULL)
    {
        root = newnode;
        return;
    }

    if (q->val > key)
    {
        q->left = newnode;
    }
    else
    {
        q->right = newnode;
    }
}

void deleteNode(TreeNode*& root, int key)
{
    TreeNode *p = root;
    TreeNode *q;
    while (p != NULL)
    {
        if (p->val > key)
        {
            q = p;
            p = p->left;
        }
        else if (p->val < key)
        {
            q = p;
            p = p->right;
        }
        else
        {
            break;
        }
    }

    if (p == NULL)
    {
        return;
    }

    if (p->left != NULL && p->right != NULL)
    {
        TreeNode *s = p->left;
        TreeNode *t = p;
        while (s->right != NULL)
        {
            t = s;
            s = s->right;
        }

        p->val = s->val;
        if (t == p)
        {
            p->left = s->left;
        }
        else
        {
            t->right = s->left;
        }

        delete s;
    }
    else
    {
        TreeNode *temp;
        if (p->left == NULL && p->right == NULL)
        {
            temp = NULL;
        }
        else if (p->left == NULL)
        {
            temp = p->right;
        }
        else
        {
            temp = p->left;
        }

        if (p == root)
        {
            root = temp;
        }
        else
        {
            if (q->left == p)
            {
                q->left = temp;
            }
            else
            {
                q->right = temp;
            }
        }

        delete p;
    }
}

void preorderTraverse(TreeNode *root)
{
    if (root != NULL)
    {
        cout<<root->val<<" ";
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

int main()
{
    TreeNode *root = NULL;
    for (int i = 0; i < 20; i++)
    {
        insertNode(root, rand() % 50);
    }
    preorderTraverse(root); cout<<endl;

    for (int i = 0; i < 20; i++)
    {
        deleteNode(root, i);
    }
    preorderTraverse(root); cout<<endl;
}
```