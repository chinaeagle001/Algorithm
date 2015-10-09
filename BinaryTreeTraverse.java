package test;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {
		val = x;
	}
}

class BinarySearchTree {
	protected TreeNode root;
	public TreeNode searchNode (int key) {
		TreeNode p = root;
		while (p != null) {
			if (p.val > key) {
				p = p.left;
			}
			else if (p.val < key) {
				p = p.right;
			}
			else {
				break;
			}
		}
		
		return p;
	}
	
	public void insertNode (int key) {
		TreeNode newnode = new TreeNode(key);
		TreeNode p = root;
		TreeNode q = null;
		while (p != null) {
			if (p.val > key) {
				q = p;
				p = p.left;
			}
			else if (p.val < key) {
				q = p;
				p = p.right;
			}
			else {
				return;
			}
		}
		
		if (q == null) {
			root = newnode;
		}
		else if (q.val > key) {
			q.left = newnode;
		}
		else {
			q.right = newnode;
		}
	}
	
	public void deleteNode (int key) {
		TreeNode p = root;
		TreeNode q = null;
		while (p != null) {
			if (p.val > key) {
				q = p;
				p = p.left;
			}
			else if (p.val < key) {
				q = p;
				p = p.right;
			}
			else {
				break;
			}
		}
		
		if (p == null) return;
		
		if (p.left != null && p.right != null) {
			TreeNode s = p.left;
			TreeNode t = null;
			while (s.right != null) {
				t = s;
				s = s.right;
			}
			p.val = s.val;
			if (s == p.left) {
				p.left = s.left;
			}
			else {
				t.right = s.left;
			}
		}
		else {
			TreeNode temp = null;
			if (p.left == null) {
				temp = p.right;
			}
			else if (p.right == null) {
				temp = p.left;
			}
			
			if (p == root) {
				root = temp;
			}
			else if (q.val > p.val) {
				q.left = temp;
			}
			else {
				q.right = temp;
			}
		}
	}
}

public class BinaryTreeTraverse {
	public static void main(String args[]) {
		BinarySearchTree bst = new BinarySearchTree();
		for (int i = 0; i < 100; i++) {
			bst.insertNode((int)(Math.random() * 0x7fffffff) % 100);
		}
		
		for (int i = 0; i < 50; i++) {
			bst.deleteNode(i);
		}
		
		TreeNode target = bst.searchNode(56);
		if (target != null) {
			System.out.println(target.val);
		}
		else{
			System.out.println("The node with value 56 does not exists!");
		}
		
		//preorder traverse
		BinaryTreeTraverse.preorder(bst.root); 
		System.out.println();
		BinaryTreeTraverse.preorderTraverse(bst.root);
		System.out.println();
		
		//inorder traverse
		BinaryTreeTraverse.inorder(bst.root); 
		System.out.println();
		BinaryTreeTraverse.inorderTraverse(bst.root);
		System.out.println();
		
		//postorder traverse
		BinaryTreeTraverse.postorder(bst.root); 
		System.out.println();
		BinaryTreeTraverse.postorderTraverse(bst.root);
		System.out.println();
		
		//level traverse
		BinaryTreeTraverse.levelTraverse(bst.root);
	}
	
	public static void preorder(TreeNode root) {
		if (root != null) {
			System.out.print(root.val + " ");
			preorder(root.left);
			preorder(root.right);
		}
	}
	
	public static void inorder(TreeNode root) {
		if (root != null) {
			inorder(root.left);
			System.out.print(root.val + " ");
			inorder(root.right);
		}
	}
	
	public static void postorder(TreeNode root) {
		if (root != null) {
			postorder(root.left);
			postorder(root.right);
			System.out.print(root.val + " ");
		}
	}
	
	public static void preorderTraverse(TreeNode root) {
		Stack<TreeNode> nodes = new Stack<TreeNode>();
		TreeNode p = root;
		while (!nodes.empty() || p != null) {
			while (p != null) {
				nodes.push(p);
				System.out.print(p.val + " ");
				p = p.left;
			}
			if (!nodes.empty()) {
				p = nodes.pop();
				p = p.right;
			}
		}
	}
	
	public static void inorderTraverse(TreeNode root) {
		Stack<TreeNode> nodes = new Stack<TreeNode>();
		TreeNode p = root;
		while (!nodes.empty() || p != null) {
			while (p != null) {
				nodes.push(p);
				p = p.left;
			}
			if (!nodes.empty()) {
				p = nodes.pop();
				System.out.print(p.val + " ");
				p = p.right;
			}
		}
	}
	
	public static void postorderTraverse(TreeNode root) {
		if (root == null) return;
		Stack<TreeNode> nodes = new Stack<TreeNode>();
		nodes.push(root);
		TreeNode cur = null;
		TreeNode pre = null;
		while (!nodes.empty()) {
			cur = nodes.peek();
			if ((cur.left == null && cur.right == null) ||
					pre != null && (pre == cur.left || pre == cur.right)) {
				System.out.print(cur.val + " ");
				pre = cur;
				nodes.pop();
			}
			else {
				if (cur.right != null) {
					nodes.push(cur.right);
				}
				if (cur.left != null) {
					nodes.push(cur.left);
				}
			}
		}
	}
	
	public static void levelTraverse(TreeNode root) {
		if (root == null) return;
		Queue<TreeNode> nodes = new LinkedList<TreeNode>();
		nodes.offer(root);
		TreeNode p;
		while (nodes.size() > 0) {
			p = nodes.poll();
			System.out.print(p.val + " ");
			if (p.left != null) {
				nodes.offer(p.left);
			}
			if (p.right != null) {
				nodes.offer(p.right);
			}
		}
	}
}
