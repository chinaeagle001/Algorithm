具有父亲结点的Binary Search Tree实现代码：
```C++
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* minNode(TreeNode *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

TreeNode* maxNode(TreeNode *root)
{
    if (root != NULL && root->right != NULL)
    {
        return maxNode(root->right);
    }

    return root;
}

TreeNode* search(TreeNode *root, int value)
{
    if (root == NULL || root->val == value)
    {
        return root;
    }
    else if (root->val > value)
    {
        return search(root->left, value);
    }
    else if (root->val < value)
    {
        return search(root->right, value);
    }
}

void insertNode(TreeNode*& root, int value)
{
    if (search(root, value) != NULL)
    {
        return;
    }

    TreeNode *newnode = new TreeNode(value);
    TreeNode *temp = root;
    TreeNode *parentNode = NULL;
    if (root == NULL)
    {
        root = newnode; //新插入结点成为根结点
        return;
    }

    while (temp != NULL)
    {
        parentNode = temp;
        if (temp->val > value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (value < parentNode->val)
    {
        parentNode->left = newnode;
    }
    else
    {
        parentNode->right = newnode;
    }
    newnode->parent = parentNode;
}

bool deleteNode(TreeNode*& root, int value)
{
    TreeNode *cur = search(root, value);
    TreeNode *temp;
    if (cur == NULL)
    {
        return false; //未找到结点
    }
    if (cur->left != NULL && cur->right != NULL)
    {
        TreeNode *max_node = maxNode(cur->left);
        cur->val = max_node->val;
        deleteNode(max_node, max_node->val);
    }
    else
    {
        if (cur->left == NULL && cur->right == NULL) //删除叶子结点
        {
            temp = NULL;
        }
        else if (cur->left == NULL) //要删除结点的左结点为空
        {
            temp = cur->right;
        }
        else if (cur->right == NULL) //要删除结点的右结点为空
        {
            temp = cur->left;
        }

        if (cur->parent == NULL)
        {
            root = temp;
            if (temp != NULL) temp->parent = NULL;
        }
        else
        {
            if (cur->parent->left == cur)
            {
                cur->parent->left = temp;
            }
            else
            {
                cur->parent->right = temp;
            }

            if (temp != NULL)
            {
                temp->parent = cur->parent;
            }

        }

        delete cur;
    }

    return true;
}

void preTraverse(TreeNode *root)
{
    if (root != NULL)
    {
        cout<<root->val<<" ";
        preTraverse(root->left);
        preTraverse(root->right);
    }
}

void inTraverse(TreeNode *root)
{
    if (root != NULL)
    {
        inTraverse(root->left);
        cout<<root->val<<" ";
        inTraverse(root->right);
    }
}

void postTraverse(TreeNode *root)
{
    if (root != NULL)
    {
        postTraverse(root->left);
        postTraverse(root->right);
        cout<<root->val<<" ";
    }
}

int main()
{
    TreeNode *root = NULL;
    for (int i = 0; i < 20; i++)
    {
        insertNode(root, rand() % 100);
    }

    cout<<"先序遍历：";preTraverse(root);cout<<" END"<<endl;
    cout<<"中序遍历：";inTraverse(root);cout<<" END"<<endl;
    cout<<"后序遍历：";postTraverse(root);cout<<" END"<<endl;

    for (int  i = 0; i < 20; i++)
    {
        deleteNode(root, i);
    }
    cout<<"先序遍历：";preTraverse(root);cout<<" END"<<endl;

    TreeNode *temp = minNode(root);
    temp != NULL ? cout<<temp->val<<endl : cout<<"null"<<endl;
    temp = maxNode(root);
    temp != NULL ? cout<<temp->val<<endl : cout<<"null"<<endl;

    return 0;
}
```
