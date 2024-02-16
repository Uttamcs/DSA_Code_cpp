/*
// Height of a binary tree

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;

	node(int data)
	{
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	}
};
int height(node *root)
{
	// base case
	if (root == NULL)
	{
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	int ans = max(left, right) + 1;
	return ans;
}
int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(7);
	root->left->right = new node(11);

	int treeHeight = height(root);
	cout << "Maximum height " << treeHeight << endl;
	return 0;
}

*/














/*
// MAXIMUM DIAMETER OF A BINARY TREE

// Approach - 1 (Less optimise solution of time complexity O(n))
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
int height(node *root)
{
	// base case
	if (root == NULL)
	{
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	int ans = max(left, right) + 1;
	return ans;
}
int diameter(node *root)
{
	// base case
	if (root == NULL)
	{
		return 0;
	}
	int op1 = diameter(root->left);
	int op2 = diameter(root->right);
	int op3 = height(root->left) + height(root->right) + 1;
	int ans = max(op1, max(op2, op3));
	return ans;
}
int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(7);
	root->left->right = new node(11);
	cout << "Diameter: " << diameter(root) << endl;
	return 0;
}











// Approach -2 (More optimise solution of time complexity O(n))
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
pair<int, int> diameterFast(node *root)
{
	// base case
	if (root == NULL)
	{
		return make_pair(0, 0);
	}
	pair<int, int> left = diameterFast(root->left);
	pair<int, int> right = diameterFast(root->right);

	int op1 = left.first;
	int op2 = right.first;
	int op3 = left.second + right.second + 1;
	pair<int, int> ans;
	ans.first = max(op1, max(op2, op3));
	ans.second = max(left.second, right.second) + 1;
	return ans;
}
int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(7);
	root->left->right = new node(11);
	pair<int, int> diameter = diameterFast(root);
	cout << "Diameter: " << diameter.first << endl;
	return 0;
}

*/










/* */
// check for balanced tree

// Approach - 1 (this solution is less optimise as it has complexity of O(n*n))

#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;

	node(int data)
	{
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};
int height(node *root)
{
	// base case
	if (root == NULL)
	{
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	int ans = max(left, right) + 1;
	return ans;
}
bool isbalanced(node *root)
{
	if (root == NULL)
	{
		return true;
	}
	bool left = isbalanced(root->left);
	bool right = isbalanced(root->right);
	bool diff = height(root->left) - height(root->right) <= 1;
}
int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(7);
	root->left->right = new node(11);
	cout << isbalanced(root) << endl;
	return 0;
}











/*

// Approach - 2 (this solution is more optimise as it has complexity of O(n))
#include<bits/stdc++.h>
using namespace std; 
class node
{
public:
	int data;
	node *left;
	node *right;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
pair<bool, int> isbalancedFast(node* root)
{
	// base case
	if(root == NULL)
	{
		return make_pair(true, 0);
	}
	pair<bool, int> left = isbalancedFast(root->left);
	pair<bool, int> right = isbalancedFast(root->right);

	bool leftAns = left.first;
	bool rightAns = right.first;

	bool diff = abs(left.second - right.second) <= 1;
	pair<bool, int> ans;
	ans.second = max(left.second , right.second)+1;
	if(leftAns && rightAns && diff){
		ans.first = true;
	}
	else{
		ans.first = false;
	}
	return ans;
}
int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(7);
	root->left->right = new node(11);
	cout << isbalancedFast(root).first << endl;
	return 0;
}
*/ 











/*
// Determine if two trees are identical

#include<bits/stdc++.h>
using namespace std; 
class node
{
	public:
		int data; 
		node* left;
		node* right;
	
	node(int data)
	{
		this->data = data;
		this-> left = NULL;
		this-> right =NULL;
	}
};
bool isIdentical(node* r1, node* r2)
{
	// base case
	if(r1 == NULL && r2 == NULL)
	{
		return true;
	}

	if(r1 ==NULL && r2 != NULL)
	{
		return false;
	}

	if(r1 != NULL && r2 == NULL)
	{
		return false;
	}
	bool left = isIdentical(r1->left, r2->left);
	bool right = isIdentical(r1->right, r2->right);

	bool value = r1->data == r2->data;

	if(left && right && value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	node *root1 = new node(1);
	root1->left = new node(2);
	root1->right = new node(5);
	root1->left->left = new node(7);
	root1->left->right = new node(11);
	node *root2 = new node(1);
	root2->left = new node(23);
	root2->right = new node(54);
	root2->left->left = new node(7);
	root2->left->right = new node(11);

	cout<<isIdentical(root1, root2)<<endl;
	return 0;
}
*/










/*
// Sum Tree

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data; 
	node* left;
	node* right;

	node(int data)
	{
		this->data =data;
		this->left = NULL;
		this->right = NULL;
	}
};
pair<bool,int> chkSumTree(node* root)
{
	// base case
	if(root == NULL)
	{
		return make_pair(true, 0);
	}

	if(root -> left == NULL && root->right == NULL)
	{
		return make_pair(true, root->data);
	}

	pair<bool, int> leftAns = chkSumTree(root -> left);
	pair<bool, int> rightAns = chkSumTree(root -> right);

	bool left = leftAns.first;
	bool second = rightAns.first;

	bool condn = root->data == leftAns.second + rightAns.second;
	pair<bool , int> ans;
	if(left && right && condn)
	{
		ans.first = true;
		ans.second = root->data + leftAns.second + rightAns.second;
	}
	else{
		ans.first = false;
	}
	return ans;
}
int main()
{
	node *root1 = new node(1);
	root1->left = new node(2);
	root1->right = new node(5);
	root1->left->left = new node(7);
	root1->left->right = new node(11);
	cout<<chkSumTree(root1).first<<endl;
	return 0;
}


*/