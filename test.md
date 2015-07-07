#Title




fsadf
**STRONG**

[fadf](http://www.baidu.com)
```c++
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