约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。通常解决这类问题时我们把编号从0~n-1，最后结果+1即为原问题的解。

#数组方式
假设下标从0开始，0，1，2 .. m-1共m个人，从1开始报数，报到k则此人从环出退出，问最后剩下的一个人的编号是多少？

现在假设m=10
0 1 2 3  4 5 6 7 8 9    k=3
第一个人出列后的序列为：
0 1 3 4 5 6 7 8 9
即:
3 4 5 6 7 8 9 0 1（\*）
我们把该式转化为:
0 1 2 3 4 5 6 7 8 (\*\*)
则你会发现: （(\*\*)+3）%10则转化为(\*)式了

也就是说，我们求出9个人中第9次出环的编号，最后进行上面的转换就能得到10个人第10次出环的编号了 
设f(m,k,i)为m个人的环，报数为k，第i个人出环的编号，则f(10,3,10)是我们要的结果
当i=1时，  f(m, k ,i) = (m+k-1) % m
当i!=1时，  f(m, k, i)= ( f(m-1, k, i-1)+k ) % m

Java实现：
```java
public class Test {
	public static void main(String[] args) {
		for (int i = 1; i <= 10; i++){
			System.out.print(fun(10,3,i) + " ");
		}
	}
	
	public static int fun(int m, int k, int i){
		if (i == 1){
			return (m + k - 1) % m;
		}else{
			return (fun(m - 1, k, i - 1) + k) % m;
		}
	}
}
```
上述实现将结点的值设为0~n-1，若要变为1~n-1，则打印fun(m, k, i) + 1即可。

Python实现：
```python
def fun(m, k, i):
    if i == 1:
        return (m + k - 1) % m
    else:
        return (fun(m - 1, k, i - 1) + k) % m
                

for i in range(1, 11):
    print(fun(10, 3, i), end=' ')
```

C++实现：
```C++
#include <iostream>
using namespace std;

int fun(int m, int k, int i);

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout<<fun(10, 3, i)<<" "; // 输出数值为[0,9]
        //cout<<fun(10, 3, i) + 1<<" "; // 输出数值为[1,10]
    }
}

int fun(int m, int k, int i)
{
    if (i == 1)
    {
        return (m + k - 1) % m;
    }
    else
    {
        return (fun(m - 1, k, i - 1) + k) % m;
    }
}
```

#链表方式
使用一个循环链表来实现，每次将一个结点移出链表。
Java实现：
```java
class ListNode{
	int val;
	ListNode next;
	ListNode(int x) {val = x;}
}

public class Josephus {
	ListNode head;
	int n;
	Josephus(int x){
		n = x;
		head = new ListNode(1);
		ListNode pre = head;
		ListNode cur = null;
		for (int i = 2; i <= n; i++){
			cur = new ListNode(i);
			pre.next = cur;
			pre = cur;
		}
		cur.next = head;
	}
	
	public void PerformKilling(int d){
		d = d % n;
		ListNode pre = null;
		ListNode cur = head;
		int count = 1;
		while (count++ <= n){ // while (cur.next != cur)
			int i = 1;
			while (i++ < d){
				pre = cur;
				cur = cur.next;
			}
			System.out.println("Killing: " + cur.val);
			pre.next = cur.next;
			cur = cur.next;
			i = 1;
		}
		//System.out.println("Killing: " + cur.val);
	}
}
```
Python实现：
```python
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Josephus:
    def __init__(self, x):
        self.n = x
        self.head = ListNode(1)
        pre = self.head
        for i in range(2, x + 1):
            cur = ListNode(i)
            pre.next = cur
            pre = cur
        cur.next = self.head
    
    def performKilling(self, d):
        cur = self.head
        while cur.next != cur:
            for i in range(1, d):
                pre = cur
                cur = cur.next
            print(cur.val, end=' ')
            pre.next = cur.next
            cur = cur.next
        print(cur.val, end=' ')

J = Josephus(10)
J.performKilling(3)
```
C++实现：
```c++
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Josephus
{
public:
    Josephus(int x)
    {
        n = x;
        head = new ListNode(1);
        ListNode *pre = head;
        ListNode *cur;
        for (int i = 2; i <= x; i++)
        {
            cur = new ListNode(i);
            pre->next = cur;
            pre = cur;
        }
        cur->next = head;
    }

    void performKilling(int d)
    {
        d %= n;
        int count = 1;
        ListNode *pre;
        ListNode *cur = head;
        while (count++ <= n)  //while (cur->next != cur)
        {
            for (int i = 1; i < d; i++)
            {
                pre = cur;
                cur = cur->next;
            }
            cout<<cur->val<<" ";
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        }
        //cout<<cur->val;
        //delete cur;
    }

private:
    ListNode *head;
    int n; //size of the linked list
};

int main()
{
    Josephus *J = new Josephus(10);
    J->performKilling(3);
}
```
（使用C++时，特别注意的是<font color="red">释放内存</font>）
结束条件可以设置为已经打印了n个结点，或者链表中仅有一个结点（继续打印该唯一结点）。
