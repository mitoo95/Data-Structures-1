#include <iostream>

#include "Element.h"
using namespace std;

#include <iostream>
#include "Element.h"

class BST
{
	public:
		void addLeaf(int key);
		void PrintInOrder();
		void PreOrder();
		void PostOrder();
		void PrintChildren(int key);
		int FindSmallest();
		int FindBiggest();
		void RemoveNode(int key);
		void RemoveRootMatch();
		BST();
		~BST();

	private:
		Element *root;
		void addLeafPrivate(int key, Element *node);
		void PostOrderPrivate(Element *node);
		void PrintInOrderPrivate(Element *node);
		void PreOrderPrivate(Element *node);
		Element *ReturnNodePrivate(int key, Element* node);
		int FindSmallestPrivate(Element *node);
		int FindBiggestPrivate(Element *node);
		void RemoveNodePrivate(int key, Element *node);
		void RemoveMatch(Element *parent, Element *match, bool left);
		Element *CreateLeaf(int key);
		Element *ReturnNode(int key);
		void RemoveSubTree(Element *Ptr);
};