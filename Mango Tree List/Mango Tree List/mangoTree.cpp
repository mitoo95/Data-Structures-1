#include "pch.h"
#include "mangoTree.h"



mangoTree::mangoTree()
{
	head = NULL;
	tail = NULL;
	counter = 0;
}


mangoTree::~mangoTree()
{
}


int mangoTree::addMango(mangoFruit *mango)
{
	if (head == 0)
	{
		head = mango;
		tail = mango;
	}
	else
	{
		tail->next = mango;
		mango->prev = this->tail;
		tail = mango;
	}

	increaseCounter();
	return 5;


}

int mangoTree::insertMango(mangoFruit *mango, int pos)
{


	if (pos > getCounter() + 1)
	{
		return -1;
	}
	else if (pos < 0)
	{
		return -2;
	}

	else if (pos == getCounter() + 1)
	{
		addMango(mango);
		return 0;
	}
	else if (pos <= getCounter())
	{
		mangoFruit *temp = head;
		int actualPos = 1;
		while (actualPos < pos)
		{
			actualPos++;
			temp = temp->next;
		}

		if (actualPos == pos)
		{

			mango->prev = NULL;
			mango->next = temp;
			temp->prev = mango;
			head = mango;
		}
		else
		{
			mango->prev = temp->prev;
			mango->next = temp;
			mango->prev->next = mango;
			temp->prev = mango;
		}



		increaseCounter();
		return 0;
	}
	return -3;
}

int mangoTree::deleteMango(int pos)
{
	if (pos > this->getCounter())
	{
		return -1;
	}

	else if (pos < 0)
	{
		return -2;
	}

	else if (pos <= this->getCounter())
	{
		mangoFruit *temp = this->head;
		int actualPos = 1;

		while (actualPos < pos)
		{
			actualPos++;
			temp = temp->next;
		}

		if (temp == this->head)
		{
			if (temp->next)
			{
				temp->next->prev = nullptr;
			}

			head = head->next;
		}
		else if (temp == this->tail)
		{
			temp->prev->next = NULL;
			tail = tail->prev;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}

		delete temp;
		decreaseCounter();
		return 0;

	}
}

void mangoTree::printMangoTree()
{
	mangoFruit *temp = new mangoFruit;
	temp = this->head;

	while (temp != NULL)
	{
		cout << temp->getWeight() << endl;
		temp = temp->next;
	}
}

int mangoTree::getCounter()
{
	return this->counter;
}

void mangoTree::increaseCounter()
{
	this->counter++;
}

void mangoTree::decreaseCounter()
{
	this->counter--;
}

double mangoTree::getTotalWeight()
{
	double totalWeight = 0.0;

	mangoFruit *mango = new mangoFruit;
	mango = this->head;

	while (mango != NULL)
	{
		totalWeight += mango->getWeight();
		mango = mango->next;
	}

	cout << totalWeight << endl;

	return totalWeight;

}

int mangoTree::getFruitQuantity()
{
	return getCounter();
}


bool mangoTree::fruitMaxCapacityExceeded()
{
	int maxCapacity = 50;

	if (this->getCounter() > maxCapacity)
	{
		return true;
	}
	else
		return false;

}

bool mangoTree::treeMaxWeightExceeded()
{
	double maxWeight = 500.00;

	if (this->getTotalWeight() > maxWeight)
	{
		return true;
	}
	else
		return false;

}

void mangoTree::mergeTrees(mangoTree list1, mangoTree list2) {

	list1.tail->next = list2.head;
	list2.head->prev = list1.tail;

	printMangoTree();

}