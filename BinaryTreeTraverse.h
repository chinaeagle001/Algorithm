#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
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
    TreeNode *parent = NULL;
    TreeNode *p = root;
    while (p != NULL)
    {
        if (p->val > key)
        {
            parent = p;
            p = p->left;
        }
        else if(p->val < key)
        {
            parent = p;
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
    }
    else if(parent->val > key)
    {
        parent->left = newnode;
    }
    else
    {
        parent->right = newnode;
    }
}

void deleteNode(TreeNode*& root, int key)
{
    TreeNode *parent = NULL;
    TreeNode *p = root;
    while (p != NULL)
    {
        if (p->val > key)
        {
            parent = p;
            p = p->left;
        }
        else if (p->val < key)
        {
            parent = p;
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
        TreeNode *t = p;
        TreeNode *q = p->left;
        while (q->right != NULL)
        {
            t = q;
            q = q->right;
        }

        p->val = q->val;
        if (t == p)
        {
            p->left = q->left;
        }
        else
        {
            t->right = q->left;
        }
        delete q;
    }
    else
    {
        TreeNode *temp;
        if (p->left == NULL && p->right == NULL)
        {
            temp = NULL;
        }
        else if(p->left == NULL)
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
        else if (parent->left == p)
        {
            parent->left = temp;
        }
        else
        {
            parent->right = temp;
        }
        delete p;
    }
}

void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void preorder2(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            cout<<p->val<<" ";
            s.push(p);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void inorder2(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top();
            cout<<p->val<<" ";
            s.pop();
            p = p->right;
        }
    }
}

void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

void postorder2(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<TreeNode*> s;
    s.push(root);
    TreeNode *pre = NULL;
    TreeNode *cur;
    while (!s.empty())
    {
        cur = s.top();
        if (cur->left == NULL && cur->right == NULL ||
            pre != NULL && (pre == cur->left || pre == cur->right))
        {
            cout<<cur->val<<" ";
            s.pop();
            pre = cur;
        }
        else
        {
            if (cur->right != NULL)
            {
                s.push(cur->right);
            }
            if (cur->left != NULL)
            {
                s.push(cur->left);
            }
        }
    }
}

void levelTraverse(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout<<p->val<<" ";
        if (p->left != NULL)
        {
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
        }
    }
}

int main()
{
    TreeNode *root = NULL;
    for (int i = 0; i < 20; i++)
    {
        insertNode(root, rand() % 100);
    }
    preorder(root); cout<<endl;
    preorder2(root); cout<<endl;
    inorder(root); cout<<endl;
    inorder2(root); cout<<endl;
    postorder(root); cout<<endl;
    postorder2(root); cout<<endl;
    levelTraverse(root); cout<<endl;
}
