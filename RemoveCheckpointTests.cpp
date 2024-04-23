#include <iostream>
#include <cassert>

#include "RedBlackTree.h"


void TestRemoveLeaf(){
	cout << "Testing Remove Leaf..." << endl;
	
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(40);

	// removing root
	rbt.Remove(40);
	//cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == "");
	//assert(rbt.root == nullptr);



	rbt.Insert(40);
	rbt.Insert(23);
	rbt.Remove(23);
	//cout << "rbt after: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B40 ");
	
	rbt.Insert(23);
	rbt.Insert(52);
	rbt.Remove(52);
	assert(rbt.ToPrefixString() == " B40  R23 ");


	rbt.Insert(52);
	rbt.Insert(15);
	rbt.Remove(15);
	//cout << "rbt after: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B40  B23  B52 ");
	
	cout << "PASSED!" << endl << endl;
}


int main(){
	
	TestRemoveLeaf();
	
	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
