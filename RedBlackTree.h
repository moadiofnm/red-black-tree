#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#define COLOR_RED 0
#define COLOR_BLACK 1

#include <string>
using namespace std;

class RedBlackTree{



public: 

struct RBTNode{
    int data;
    unsigned short int color;
    RBTNode *left = nullptr; 
    RBTNode *right = nullptr;
    RBTNode *parent = nullptr; 
    RBTNode(int data): data(data), color(COLOR_RED), left(nullptr), right(nullptr) {} // RBT constructor 
};



~RedBlackTree();
void Remove(int data);
RBTNode* search(int a );
void deleteFixup(RBTNode* node);

RBTNode* InOrdersuccessor(RBTNode* node);
void transplant(RBTNode* a , RBTNode* b); 
RBTNode* BSTInsert(int value); //BST insert
void Insert(int value); //rbt insert
void RBTreeBalance(RBTNode* node);
bool RBTreeSetChild(RBTNode* parent, string whichChild, RBTNode* child); // left or right child of parent and sets it 
void RBTreeReplaceChild(RBTNode* parent,RBTNode* currentChild, RBTNode* newChild);//replaces a node's left or right child pointer with a new value.
void RBTreeRotateLeft(RBTNode* node);
void RBTreeRotateRight(RBTNode*  node);
RBTNode* GetRBTGrandparentNode(RBTNode* node);
RBTNode* GetUncleNode(RBTNode* node);
void DeleteNode(RBTNode* node);
void Fixup(RBTNode* node);
bool Contains(int value); 
int GetMin();
int GetMax(); 
int Size(){
    return numItems; 
}

string ToInfixString() const ;
string ToPrefixString() const;
string ToPostfixString() const ;



private: 


unsigned long long int numItems = 0; 
RBTNode *root; 
string ToInfixString(RBTNode* node) const;
string ToPrefixString(RBTNode* node) const;
string ToPostfixString(RBTNode* node) const;




};
#endif
