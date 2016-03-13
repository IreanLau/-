#include<iostream>
using namespace std;

template<class T>
class BST;
template<class T>
class TreeNode
{
	friend class BST<T>;
	public:
		TreeNode() 
			:data(0),freq(1), lson(NULL), rson(NULL) {}
		TreeNode(T x)
			:data(x), freq(1), lson(NULL), rson(NULL) {}
		T data;
		unsigned int freq;
		TreeNode* lson;
		TreeNode* rson;
};

template<class T>
class BST
{
public:
	BST():root(NULL)
	{}
	void insert(T x)
	{
		insertpri(root, x);
	}
	TreeNode<T>* find(T x)
	{
		return findpri(root, x);
	}
	void Delete(T x)
	{
		Deletepri(root, x);
	}
	void traversal()
	{
		inorder(root);
		cout << endl;
	}
private:
	void insertpri(TreeNode<T>*&root, T x);
	TreeNode<T>* findpri(TreeNode<T>*&root, T x);
	void Deletepri(TreeNode<T>*&root, T x);
	void inorder(TreeNode<T>*&root);
private:
	TreeNode<T>* root;
};

template<class T>
void BST<T>::insertpri(TreeNode<T>*&root, T x)
{
	if (NULL == root)
	{
		root = new TreeNode<T>(x);
		return;
	}

	if (root->data > x)
		insertpri(root->lson, x);
	else if (root->data < x)
		insertpri(root->rson, x);
	else
		++(root->freq);
}

template<class T>
TreeNode<T>* BST<T>::findpri(TreeNode<T>*&root, T x)
{
	if (root == NULL)
	{
		cout << "NULL! error" << endl;
		exit(1);
	}
	if (x < root->data)
		return findpri(root->lson, x);
	else if (x>root->data)
		return findpri(root->rson, x);
	else
		return root;
}

template<class T>
void BST<T>::Deletepri(TreeNode<T>*&root, T x)
{
	if (root == NULL)
		return;
	if (x < root->data)
		return Deletepri(root->lson, x);
	else if (x>root->data)
		return Deletepri(root->rson, x);
	else//is this node
	{
		if (--(root->freq) == 0)
		{
			if (root->lson && root->rson)//have two son
			{
				TreeNode<T>*tmp = root->rson;
				while (tmp->lson)
					tmp = tmp->rson;

				root->data = tmp->data;
				root->freq = tmp->data;
				delete tmp;
				//Deletepri(root->rson, tmp->data);
			}

			else//have only one son or no son
			{
				TreeNode<T>*tmp = root;
				if (root->lson == NULL)
					root = root->rson;
				else if (root->rson == NULL)
					root = root->lson;

				delete tmp;
			}
		}
	}
}

template<class T>
void BST<T>::inorder(TreeNode<T>*&root)
{
	if (root == NULL)
		return;
	inorder(root->lson);
	cout << root->data << " ";
	inorder(root->rson);
}

void test()
{
	class BST<int> bstint;
	bstint.insert(6);
	bstint.insert(7);
	bstint.insert(2);
	bstint.insert(1);
	bstint.insert(4);
	bstint.insert(3);

	bstint.traversal();
	bstint.Delete(4);
	bstint.traversal();
}


void main()
{
	test();
}
