// Here are the tests that your code failed.

#include "RedBlackTree.h"
#include <cassert>
#include <iostream>
#include <random>

void TestInsertThirdNode() {
  cout << "Testing Insert Third Node..." << endl;
  RedBlackTree *rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(10); // Left Left
  cout << "rbt: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B15  R10  R30 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(25); // Right Left
  cout << "rbt: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B25  R15  R30 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45); // Easy case
  cout << "rbt: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B30  R15  R45 ");
  delete rbt;

  // symmetry!
  cout << "symmtry"<< endl; 
  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(45);
  rbt->Insert(15); // Easy case
  cout << "rbt: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B30  R15  R45 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(45);
  rbt->Insert(35); // Left Right
  // cout << "rbt: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B35  R30  R45 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(45);
  rbt->Insert(55); // Right Right
  // cout << "rbt: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B45  R30  R55 ");
  delete rbt;

  cout << "PASSED!" << endl << endl;
}

void TestInsertFifthNode() {
  cout << "Testing Insert Fifth Node..." << endl;
  RedBlackTree *rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(10);
  rbt->Insert(25);
  cout << "result: "  << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B30  B15  R10  R25  B45 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(10);
  rbt->Insert(35);
  assert(rbt->ToPrefixString() == " B30  B15  R10  B45  R35 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(10);
  rbt->Insert(55);
  assert(rbt->ToPrefixString() == " B30  B15  R10  B45  R55 ");
  delete rbt;

  // There are other tests like the above three.
  // Simply keep 25 in instead of keeping 10 in
  // But, NONE of these result in an unbalanced tree
  // The only way to get an unbalanced tree is to add
  // a node below the fourth node (on left and on right)
  // I think this is the point of redundancy with previous tests

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(10);
  rbt->Insert(5);
  assert(rbt->ToPrefixString() == " B30  B10  R5  R15  B45 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(10);
  rbt->Insert(12);
  // cout<<"rbt: " << rbt->ToPrefixString();
  assert(rbt->ToPrefixString() == " B30  B12  R10  R15  B45 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(10);
  rbt->Insert(12);
  assert(rbt->ToPrefixString() == " B30  B12  R10  R15  B45 ");
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(30);
  rbt->Insert(15);
  rbt->Insert(45);
  rbt->Insert(20);
  rbt->Insert(17);
  assert(rbt->ToPrefixString() == " B30  B17  R15  R20  B45 ");
  delete rbt;

  // The rest of these should be symmetric / identical on the right side
  cout << "PASSED!" << endl << endl;
}


void TestInsertDuplicates() {
  cout << "Testing Insert Duplicates..." << endl;
  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(35);

  try {
    rbt.Insert(35);
    assert(false);
  } catch (const invalid_argument &e) {
  }

  cout << "PASSED!" << endl << endl;
}


void TestToStrings2() {
  cout << "Testing ToString Methods..." << endl;

  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(12);
  rbt.Insert(11);
  rbt.Insert(15);
  rbt.Insert(5);
  rbt.Insert(13);
  rbt.Insert(7);
  cout <<  "pre: " << rbt.ToPrefixString()<<endl;
  cout <<  "inf: "<< rbt.ToInfixString()<<endl; 
  cout << "post: " << rbt.ToPostfixString()<< endl; 

  assert(rbt.ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");
  assert(rbt.ToInfixString() == " R5  B7  R11  B12  R13  B15 ");
  assert(rbt.ToPostfixString() == " R5  R11  B7  R13  B15  B12 ");

  cout << "PASSED!" << endl << endl;
}


void TestInsertWithRecursiveFixUp() {
  cout << "Testing Recursive FixUp..." << endl;
  // Red uncle, and we "move the blackness up"
  // the makes the grandparent red and that might cause issues
  // at the grand-parent level.
  // This may repeat until the root node (which must be black)
  RedBlackTree *rbt = new RedBlackTree();
  rbt->Insert(400);
  rbt->Insert(800);
  rbt->Insert(200);
  rbt->Insert(600);
  rbt->Insert(150);
  rbt->Insert(900);
  rbt->Insert(300);
  rbt->Insert(100);
  rbt->Insert(175);
  rbt->Insert(160); // does some weird stuff!
  assert(rbt->ToPrefixString() ==
         " B200  R150  B100  B175  R160  R400  B300  B800  R600  R900 ");
  rbt->Insert(185);
  rbt->Insert(180); // does a recursive fix-up
  assert(rbt->ToPrefixString() == " B200  B150  B100  R175  B160  B185  R180  "
                                  "B400  B300  B800  R600  R900 ");
  // cout << rbt->ToPrefixString() << endl;
  delete rbt;

  cout << "PASSED!" << endl << endl;
}


void TestToStrings() {
  cout << "Testing ToString Methods..." << endl;

  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(12);
  rbt.Insert(11);
  rbt.Insert(15);
  rbt.Insert(5);
  rbt.Insert(13);
  rbt.Insert(7);
  cout<< "rbt: " << rbt.ToPrefixString();
  assert(rbt.ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");
  assert(rbt.ToInfixString() == " R5  B7  R11  B12  R13  B15 ");
  assert(rbt.ToPostfixString() == " R5  R11  B7  R13  B15  B12 ");

  cout << "PASSED!" << endl << endl;
}


void TestInsertRandomTests() {
  cout << "Testing Random Insert Stuff..." << endl;
  cout << "\t This test passes if it doesn't crash and valgrind reports no "
          "issues"
       << endl;
  RedBlackTree *rbt = new RedBlackTree();
  rbt->Insert(15);
  rbt->Insert(13);
  rbt->Insert(20);
  rbt->Insert(12);
  cout << endl;
  // cout << "tree: " << rbt->ToInfixString() << endl;
  delete rbt;

  // probably should have a delete or something here
  rbt = new RedBlackTree();
  // cout << endl << "NEW TREE" << endl;
  rbt->Insert(12);
  // cout << "tree: "  << rbt->ToInfixString() << endl;
  rbt->Insert(11);
  // cout << "tree: "  << rbt->ToInfixString() << endl;
  rbt->Insert(15);
  // cout << "tree: "  << rbt->ToInfixString() << endl;
  rbt->Insert(5);
  // cout << "tree: "  << rbt->ToInfixString() << endl;
  rbt->Insert(13);
  // cout << "tree: "  << rbt->ToInfixString() << endl;
  rbt->Insert(7);
  // cout << "tree: "  << rbt->ToInfixString() << endl;
  delete rbt;

  rbt = new RedBlackTree();
  // cout << endl << "NEW TREE" << endl;
  rbt->Insert(12);
  // cout << "tree: "  << rbt->ToPrefixString() << endl;
  rbt->Insert(10);
  // cout << "tree: "  << rbt->ToPrefixString() << endl;
  rbt->Insert(8);
  // cout << "tree: "  << rbt->ToPrefixString() << endl;
  delete rbt;

  rbt = new RedBlackTree();
  rbt->Insert(11);
  rbt->Insert(9);
  rbt->Insert(4);
  rbt->Insert(31);
  rbt->Insert(23);
  rbt->Insert(52);
  // cout << rbt->ToPrefixString() << endl;
  assert(rbt->ToPrefixString() == " B9  B4  R23  B11  B31  R52 ");
  delete rbt;

  cout << "PASSED!" << endl << endl;
}

void BigTreeTest() {
  cout << "Testing Construction of Big Tree..." << endl;
  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(12);
  rbt.Insert(10);
  rbt.Insert(0);
  rbt.Insert(11);
  rbt.Insert(3);
  rbt.Insert(9);
  rbt.Insert(2);
  rbt.Insert(7);
  rbt.Insert(1);
  rbt.Insert(4);
  rbt.Insert(6);
  rbt.Insert(8);
  rbt.Insert(37);
  rbt.Insert(5);
  rbt.Insert(72);
  rbt.Insert(55);
  rbt.Insert(90);
  rbt.Insert(92);
  rbt.Insert(20);
  rbt.Insert(13);
  rbt.Insert(57);
  rbt.Insert(30);
  rbt.Insert(64);
  rbt.Insert(69);
  rbt.Insert(50);
  rbt.Insert(67);
  rbt.Insert(99);
  rbt.Insert(89);
  rbt.Insert(33);

  assert(
      rbt.ToPrefixString() ==
      " B12  R7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  R55  B20  B13  "
      "R37  B30  R33  B50  B69  R64  B57  B67  R90  B72  R89  B92  R99 ");

  cout << "PASSED!" << endl << endl;
}


void TestCopyConstructor() {
  cout << "Testing Copy Constructor..." << endl;

  RedBlackTree rbt1 = RedBlackTree();
  rbt1.Insert(11);
  rbt1.Insert(23);
  rbt1.Insert(9);
  rbt1.Insert(52);
  rbt1.Insert(31);
  rbt1.Insert(4);

  assert(rbt1.ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

  RedBlackTree rbt2 = RedBlackTree(rbt1);

  assert(rbt1.Size() == rbt2.Size());
  assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());

  rbt1.Insert(200);
  assert(rbt2.ToPrefixString() != rbt1.ToPrefixString());

  RedBlackTree rbt3 = RedBlackTree();
  rbt3.Insert(12);
  rbt3.Insert(10);
  rbt3.Insert(0);
  rbt3.Insert(11);
  rbt3.Insert(3);
  rbt3.Insert(9);
  rbt3.Insert(2);
  rbt3.Insert(7);
  rbt3.Insert(1);
  rbt3.Insert(4);
  rbt3.Insert(6);
  rbt3.Insert(8);
  rbt3.Insert(37);
  rbt3.Insert(5);
  rbt3.Insert(72);
  rbt3.Insert(55);
  rbt3.Insert(90);
  rbt3.Insert(92);
  rbt3.Insert(20);
  rbt3.Insert(13);
  rbt3.Insert(57);
  rbt3.Insert(30);
  rbt3.Insert(64);
  rbt3.Insert(69);
  rbt3.Insert(50);
  rbt3.Insert(67);
  rbt3.Insert(99);
  rbt3.Insert(89);
  rbt3.Insert(33);

  assert(
      rbt3.ToPrefixString() ==
      " B12  R7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  R55  B20  B13  "
      "R37  B30  R33  B50  B69  R64  B57  B67  R90  B72  R89  B92  R99 ");

  RedBlackTree rbt4 = RedBlackTree(rbt3);

  string s3 = rbt3.ToPrefixString();
  // cout << "s3: " << s3 << endl;
  string s4 = rbt4.ToPrefixString();
  // cout << "s4: " << s4 << endl;
  assert(rbt3.Size() == rbt4.Size());
  assert(s3 == s4);

  rbt3.Insert(200);
  assert(rbt3.ToPrefixString() != rbt4.ToPrefixString());

  // copy of empty tree
  RedBlackTree rbt5 = RedBlackTree();
  RedBlackTree rbt6 = RedBlackTree(rbt5);
  assert(rbt5.ToPrefixString() == "");
  assert(rbt6.ToPrefixString() == "");

  rbt5.Insert(65);
  assert(rbt5.ToPrefixString() == " B65 ");

  rbt6.Insert(32);
  assert(rbt6.ToPrefixString() == " B32 ");

  cout << "PASSED!" << endl << endl;
}


void TestGetMinimumMaximum() {
  cout << "Testing Get Minimum and Get Maximum..." << endl;

  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(30);
  rbt.Insert(20);
  rbt.Insert(60);
  rbt.Insert(33);
  rbt.Insert(23);
  rbt.Insert(85);
  rbt.Insert(61);
  // cout << rbt.GetMax();

  assert(rbt.GetMin() == 20);
  assert(rbt.GetMax() == 85);

  cout << "PASSED!" << endl << endl;
}

void TestRemoveRootWithTwoChildren() {
  cout << "Testing Remove Root with Two Children..." << endl;
  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(40);
  rbt.Insert(20);
  rbt.Insert(60);
  rbt.Remove(40);
  cout << "rbt: " << rbt.ToPrefixString() << endl;
  assert(rbt.ToPrefixString() == " B60  R20 "); 

  cout << "PASSED!" << endl << endl;
}

void TestRemoveRootWithOneChild() {
  cout << "Testing Remove Root with One Child..." << endl;
  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(40);
  rbt.Insert(20);
  rbt.Remove(40);
  cout << "rbt: " << rbt.ToPrefixString() << endl;
  assert(rbt.ToPrefixString() == " B20 "); 

  cout << "PASSED!" << endl << endl;
}

void TestRemoveNodeWithOneChild() {
  cout << "Testing Remove Node with One Child..." << endl;
  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(50);
  rbt.Insert(30);
  rbt.Insert(70);
  rbt.Insert(20);
  rbt.Insert(40);
  rbt.Remove(30);
  cout << "rbt: " << rbt.ToPrefixString() << endl;
  assert(rbt.ToPrefixString() == " B50  B40  R20  B70 "); 

  cout << "PASSED!" << endl << endl;
}

void TestRemoveNodeWithTwoChildren() {
  cout << "Testing Remove Node with Two Children..." << endl;
  RedBlackTree rbt = RedBlackTree();
  rbt.Insert(50);
  rbt.Insert(30);
  rbt.Insert(70);
  rbt.Insert(20);
  rbt.Insert(40);
  rbt.Insert(60);
  rbt.Insert(80);
  rbt.Remove(30);
  cout << "rbt: " << rbt.ToPrefixString() << endl;
  assert(rbt.ToPrefixString() == " B50  B40  R20  B70  R60  R80  ");

  cout << "PASSED!" << endl << endl;
}

int main(){
  TestInsertThirdNode();//works
  TestInsertFifthNode();//works 
  TestGetMinimumMaximum();//works 
  // TestCopyConstructor();
TestInsertWithRecursiveFixUp(); // works 
TestInsertDuplicates();// works
TestToStrings2(); //works 
TestToStrings();//works 
TestInsertRandomTests();  
TestRemoveRootWithOneChild();//works
TestRemoveRootWithTwoChildren();//works
TestRemoveNodeWithOneChild();// works
TestRemoveNodeWithTwoChildren();// works

}