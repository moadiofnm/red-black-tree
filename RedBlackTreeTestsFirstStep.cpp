
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

/**
 * 
 * This "First Step" tests file is useful to get your project started
 * 
 * To run this code you only need to implement
 * 	+ The Constructor
 * 	+ The Insert() function to insert only one node
 * 	+ The ToInfixString() function to print a tree containing only one node
 * 
**/

using namespace std;

void TestSimpleConstructor(){
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	//cout << "empty r-b-tree: " << rbt.ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");
	
	cout << "PASSED!"<< endl << endl;
}


void TestInsertFirstNode(){
	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToInfixString() == " B30 ");

	cout << "PASSED!" << endl << endl;
}

void TestInsertMultipleNodes() {
    cout << "Testing Insert Multiple Nodes..." << endl;
    RedBlackTree rbt;
    rbt.Insert(30);
    rbt.Insert(20);
    // rbt.Insert(40);
    // rbt.Insert(10);
    // rbt.Insert(25);
    // rbt.Insert(35);
    // rbt.Insert(50);
    cout << "rbt: " << rbt.ToPrefixString() <<endl;
    assert(rbt.ToInfixString() == " B20 R30 ");
    std::cout << "PASSED!" << endl << endl;
}


int main(){	
	TestSimpleConstructor();
	TestInsertFirstNode();
	TestInsertMultipleNodes();

	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}