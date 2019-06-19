#include "BST.h"

BST::BST()
{
	this->root = NULL;
}


BST::~BST()
{
	RemoveSubTree(root);
}

Element *BST::CreateLeaf(int key)
{
	Element *newNode = new Element(key);

	return newNode;
}

void BST::addLeaf(int key)
{
	addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key, Element *node)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else
	{
		if (key < node->getKey())
		{
			if (node->left != NULL)
			{
				addLeafPrivate(key, node->left);
			}
			else
				node->left = CreateLeaf(key);
		}
		else if (key > node->getKey())
		{
			if (node->right != NULL)
			{
				addLeafPrivate(key, node->right);
			}
			else
				node->right = CreateLeaf(key);
		}
		else
			cout << "key " << key << " already added to the tree" << endl;
	}
}


void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(Element *node)
{
	if (root != NULL) {
		if (node->left != NULL)
		{
			PrintInOrderPrivate(node->left);
		}
		cout << node->getKey() << " ";
		if (node->right != NULL)
		{
			PrintInOrderPrivate(node->right);
		}
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

Element *BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

Element *BST::ReturnNodePrivate(int key, Element *node)
{
	if (node != NULL) {
		if (node->getKey() == key) {
			return node;
		}
		else {
			if (key < node->getKey()) {
				return ReturnNodePrivate(key, node->left);
			}
			else {
				return ReturnNodePrivate(key, node->right);
			}
		}
	}
	else {
		return NULL;
	}
}

void BST::PrintChildren(int key) {

	Element *temp = ReturnNode(key);
	if (temp != NULL) {
		cout << "Parent Node = " << temp->getKey() << endl;
		if (temp->left == NULL) {
			cout << "Left Child Is Null" << endl;
		}
		else {
			cout << "Left Child Is = " << temp->left->getKey() << endl;
		}
		if (temp->right == NULL) {
			cout << "Right Child Is Null" << endl;
		}
		else {
			cout << "Right Child Is = " << temp->right->getKey() << endl;
		}
	}
	else {
		cout << "Key " << key << " does not exist in tree" << endl;
	}
}

int BST::FindSmallest() {
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(Element *node) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
	}
	else {
		if (node->left != NULL) {
			return FindSmallestPrivate(node->left);
		}
		else {
			return node->getKey();
		}
	}
}

int BST::FindBiggest() {
	return FindBiggestPrivate(root);
}

int BST::FindBiggestPrivate(Element *node) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
	}
	else {
		if (node->right != NULL) {
			return FindBiggestPrivate(node->right);
		}
		else {
			return node->getKey();
		}
	}
}

void BST::RemoveNode(int key) {
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, Element *node) {
	if (root != NULL) {
		if (root->getKey() == key) {
			RemoveRootMatch();
		}
		else {
			if (key < node->getKey() && node->left != NULL) {
				if (node->left->getKey() == key) {
					RemoveMatch(node, node->left, true);
				}
				else {
					RemoveNodePrivate(key, node->left);
				}
			}
			else if (key > node->getKey() && node->right != NULL) {
				if (node->right->getKey() == key) {
					RemoveMatch(node, node->right, false);
				}
				else {
					RemoveNodePrivate(key, node->right);
				}
			}
			else {
				cout << "key = " << key << " was not found in tree" << endl;
			}
		}
	}
	else {
		cout << "tree is empty" << endl;
	}

}

void BST::RemoveRootMatch() {
	if (root != NULL) {
		Element *deltemp;
		deltemp = root;
		int rootKey = root->getKey();
		int SmallestinRightSubtree;

		// case 0, no Children

		if (root->left == NULL && root->right == NULL) {
			root = NULL;
			delete deltemp;
		}
		//case 1, root no one child
		else if (root->left == NULL && root->right != NULL) {
			root = root->right;
			deltemp->right = NULL;
			delete deltemp;
			cout << "root " << rootKey << " was deleted, new root contains key " << root->getKey() << endl;
		}
		else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			deltemp->left = NULL;
			delete deltemp;
			cout << "root " << rootKey << " was deleted, new root contains key " << root->getKey() << endl;
		}
		//case 2, root has 2 children
		else {
			SmallestinRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(SmallestinRightSubtree, root);
			root->setKey(SmallestinRightSubtree);
			cout << "The root key containing key " << rootKey << " was overwritten with key " << root->getKey() << endl;
		}
	}
	else {
		cout << "cannot remove root, tree is empty" << endl;
	}
}

void BST::RemoveMatch(Element *parent, Element *match, bool left) {
	if (root != NULL) {
		Element *deltemp;
		int matchKey = match->getKey();
		int Smallestinright;
		//case 0, no children
		if (match->left == NULL && match->right == NULL) {
			deltemp = match;
			left ? parent->left = NULL : parent->right = NULL;
			delete deltemp;
			cout << "The node containing key " << matchKey << " was removed " << endl;
		}
		//case 1, 1 child match
		else if (match->left == NULL && match->right != NULL) {
			left ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			deltemp = match;
			delete deltemp;
			cout << "The node containing key " << matchKey << " was removed " << endl;
		}
		else if (match->left != NULL && match->right == NULL) {
			left ? parent->left = match->left : parent->right = match->left;
			match->right = NULL;
			deltemp = match;
			delete deltemp;
			cout << "The node containing key " << matchKey << " was removed " << endl;
		}
		//case 2, 2 children
		else {
			Smallestinright = FindSmallestPrivate(match->right);
			RemoveNodePrivate(Smallestinright, match);
			match->setKey(Smallestinright);
		}
	}
	else {
		cout << "Cannot Remove Match, tree is empty" << endl;
	}
}

void BST::RemoveSubTree(Element *Ptr) {
	if (Ptr != NULL) {
		if (Ptr->left != NULL) {
			RemoveSubTree(Ptr->left);
		}
		if (Ptr->right != NULL) {
			RemoveSubTree(Ptr->right);
		}
		cout << "Deleting the node containing key " << Ptr->getKey() << endl;
		delete Ptr;
	}
}

void BST::PreOrder() {
	PreOrderPrivate(root);
}

void BST::PostOrder() {
	PostOrderPrivate(root);
}

void BST::PreOrderPrivate(Element *node) {
	if (root != NULL) {
		cout << node->getKey() << " ";

		if (node->left != NULL) {
			PreOrderPrivate(node->left);
		}
		if (node->right != NULL) {
			PreOrderPrivate(node->right);
		}
	}
	else {
		cout << "tree is empty" << endl;
	}
}

void BST::PostOrderPrivate(Element *node) {
	if (root != NULL) {

		if (node->left != NULL) {
			PostOrderPrivate(node->left);
		}
		if (node->right != NULL) {
			PostOrderPrivate(node->right);
		}
		cout << node->getKey() << " ";
	}
	else {
		cout << "tree is empty" << endl;
	}
}