#include "RedBlackTree.h"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

RedBlackTree :: RBTNode* RedBlackTree::BSTInsert (int value){ // regular bst insert
    RBTNode* newNode = new RBTNode(value); 
    if(root == nullptr){
        root = newNode; 
        newNode->parent = nullptr; 
        return newNode;
    }
    
    RBTNode *curr = root; 
    RBTNode *parent = nullptr;

    while(curr != nullptr){
        parent = curr; 
        if(newNode->data < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }   
    newNode->parent = parent;
    if(newNode->data < parent->data){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }          
    newNode->color = 0;// set new node to red
    Fixup(newNode);
    numItems++;
    return newNode;
}

bool RedBlackTree ::Contains(int value){
    RBTNode* curr = root; 
    while(curr != nullptr){
        if (value == curr->data){ // value is found 
            return true; 
        }
        if(value < curr->data){ // if value is less than go left 
            curr = curr->left; 

        }else{
            curr = curr->right; // greater go right 
        }

    }
    return false; // not found 
}




int RedBlackTree :: GetMin() {

    RBTNode* curr = root; 
    // RBTNode* next = curr->left;

    if(root == nullptr){
        throw runtime_error("tree is empty");

    }
    while(curr->left != nullptr){
        curr = curr->left; // keep going left
    }
    return curr->data; 
}

int RedBlackTree :: GetMax() {

    RBTNode* curr = root; 
    // RBTNode* next = curr->right;

    if(root == nullptr){
        throw runtime_error("tree is empty");

    }
    while(curr->right != nullptr){
        curr = curr->right; // keep going right 
    }
    return curr->data; 
}

//https://learn.zybooks.com/zybook/FANDMCPS222NovakSpring2024/chapter/16/section/2?content_resource_id=61871801
//16.2.1
bool RedBlackTree:: RBTreeSetChild(RBTNode* parent, string whichChild, RBTNode* child){
    if (whichChild != "left" && whichChild != "right"){ // if whichchild is neither the left ot right child of the parent return false
        return false;
    }
    if(whichChild == "left"){ //if node is equal to the parent left set child 
        parent->left = child;
    }else{ // else set right to child 
        parent->right = child; 
    }
    if(child != nullptr){
        child->parent = parent;

    }
    return true;

}

//https://learn.zybooks.com/zybook/FANDMCPS222NovakSpring2024/chapter/16/section/2?content_resource_id=61871801
//16.2.2
void RedBlackTree ::  RBTreeReplaceChild(RBTNode* parent,RBTNode* currentChild, RBTNode* newChild){
    if(parent->left == currentChild){// is a child of parent it updates the pointers 
        RBTreeSetChild(parent,"left",newChild );
    }
    if(parent->right == currentChild){
        RBTreeSetChild(parent,"right",newChild);
    }
    // return false;
}

//16.2.4 zybook
void RedBlackTree:: RBTreeRotateRight(RBTNode*  node){
    if (node == nullptr || node->left == nullptr) { // if rotation is possible 
        throw logic_error("trying to right rotate there is no left child"); 
    }

    RBTNode* leftRightChild = node->left->right;
    if(node->parent != nullptr){// node isnt root
        RBTreeReplaceChild(node->parent,node,node->left);
    }else{
        root = node->left; // if node is root
        if (root != nullptr) {
            root->parent = nullptr;
        }
    }
    RBTreeSetChild(node->left,"right",node);
    RBTreeSetChild(node,"left",leftRightChild);

}

///16.2.3 zybook 
void RedBlackTree:: RBTreeRotateLeft(RBTNode* node){
    if (node == nullptr || node->right == nullptr) { // if rotation is possible 
        throw  logic_error("trying to left rotate there is no right child"); 
    }

    RBTNode* rightLeftChild = node->right->left;
    if(node->parent != nullptr){ // if node isnt a root
        RBTreeReplaceChild(node->parent, node ,node->right);
    }else{ // if node is root
        root= node->right; 
        if (root != nullptr) {
            root->parent = nullptr; 
        }
    }
    RBTreeSetChild(node->right,"left", node);
    RBTreeSetChild(node, "right", rightLeftChild);
}

RedBlackTree:: RBTNode* RedBlackTree:: GetRBTGrandparentNode(RBTNode* node){
    if(node->parent!=nullptr){
        return node->parent->parent; 
    }
    return nullptr;
}

RedBlackTree :: RBTNode* RedBlackTree:: GetUncleNode(RBTNode* node){
    RBTNode* gramps = nullptr;
    if (node->parent!= nullptr){
        gramps = node->parent->parent;
    }
    if(gramps == nullptr){ // no grandparent
        return nullptr;
    }
    if (gramps->left == node->parent){
        return gramps->right;
    }else{
        return gramps->left;
    }
    
}
//https://learn.zybooks.com/zybook/FANDMCPS222NovakSpring2024/chapter/16/section/3
//16.3.1 
// used RebBlack tree balancing algorithm
void RedBlackTree:: RBTreeBalance(RBTNode* node){
    if(node->parent == nullptr){
        node->color = 1; // black
        return;
    }
    if(node->parent->color == 1){
        return;
    }
    RBTNode* parent = node->parent; 
    RBTNode* grandparent = GetRBTGrandparentNode(node); 
    RBTNode* unc = GetUncleNode(node); 
    if (unc != nullptr && unc->color == 0 ){//red 
        parent->color = unc->color = 1; // change parent to black 
        grandparent->color = 0; // to red 
        RBTreeBalance(grandparent);// recurse
        return;
    }
    if(node == parent->right && parent == grandparent->left){
        RBTreeRotateLeft(parent);
        // node = parent->left;
        node = parent;
        parent = node->parent;
    }
    else if (node == parent->right && parent == grandparent->right){
        RBTreeRotateRight(parent); 
        // node = parent->right;
        node = parent; 
        parent = node->parent; 
    }
    parent->color = 1; 
    grandparent->color = 0; 
    if(node == parent->left){
        RBTreeRotateRight(grandparent);
    }else{
        RBTreeRotateLeft(grandparent);
    }

}

void RedBlackTree :: Fixup(RBTNode* node){
    while(node!=root && node->parent->color == 0){ // if parent is red
        RBTNode* grandparent = GetRBTGrandparentNode(node);
        if (grandparent == nullptr) break; // if it doesnt exist 
        if(node->parent == grandparent->left){
            RBTNode* unc = GetUncleNode(node); 
            //recolor the nodes since all node added will be red 
            if(unc!= nullptr && unc->color == 0){ // if unc is red
                unc->color = 1; // change to black
                node->parent->color = 1; // parent should be black
                grandparent->color = 0; // to red
                node = grandparent; 
            }else{// if its black
                if(node == node->parent->right){
                    node = node->parent;
                    RBTreeRotateLeft(node);
                }
                node->parent->color = 1;
                grandparent->color = 0;// grandparent is red
                RBTreeRotateRight(grandparent); // rotate grandparent
            }

        }else{
            RBTNode* uncle = GetUncleNode(node);
            if(uncle!= nullptr && uncle->color == 0){
                uncle->color = 1; 
                node->parent->color = 1; 
                grandparent->color = 0;
                node = grandparent;  // 
            }else{
                if(node == node->parent->left){
                    node = node->parent;
                    RBTreeRotateRight(node);
                }
                node->parent->color = 1;
                grandparent->color = 0;
                RBTreeRotateLeft(grandparent);
            }
        }
    }
    root->color = 1;// make sure root is black
}

// 16.3.1 zybook
void RedBlackTree :: Insert(int value){ // rbt insert
     if (this->Contains(value)) {
        throw invalid_argument("Value already exists");
    }
    RBTNode* newNode = BSTInsert(value); 
    // newNode->color = 0; // color is red
    RBTreeBalance(newNode);
}


RedBlackTree:: RBTNode* RedBlackTree  ::  InOrdersuccessor(RBTNode* node){
    if(node == nullptr){// check if node is nullptr
        return nullptr; 
    }
    if(node->right!=nullptr){
        RBTNode* curr = node;
        curr = curr->right; // traverse right one time 
        while(curr->left!= nullptr){
            curr = curr->left; // then go all the way left 
        }
        return curr;
    }   

    //geeksforgeeks.org/inorder-successor--binary-search-tree/#
    // used the part of this code for if the node does not have a right child.

    RBTNode* curr = node->parent; 
    while(curr!=nullptr && node == curr->right){ // use parent pointer to find a left child 
        node = curr; 
        curr = node->parent;// move up
    }
    return curr; 
}

//https://youtu.be/lU99loSvD8s?si=BrdZWzb0SulOxox6
// move subtrees within the treee
void RedBlackTree :: transplant(RBTNode* a, RBTNode* b){ // moving the b subtree
    if(a->parent == nullptr){
        root= b; 
    }
    else if(a == a->parent->left){
        a->parent->left = b; 
    }else{
        a->parent->right = b; 
    }
    if(b!= nullptr){ // change b to a 
        b->parent = a->parent; 
    }

}
RedBlackTree:: RBTNode* RedBlackTree:: search(int a ){ // searching the tree for node 
    RBTNode* curr = root; 

    while(curr != nullptr && a != curr->data ){
        if(curr->data > a){
            curr = curr->left; 
        }
        else{
            curr = curr->right; 
        }
    }
    return curr; 
 }


void RedBlackTree:: Remove(int data){
    RBTNode* node = search(data); //removed node
    if (node == nullptr){
        cout<< "node not found"<< endl; 
        return; 
    }
    RBTNode* nodeCopy = node; // point to the orginal node memory 
    RBTNode* x = nullptr; // pointer to a child of removed node
    bool nodeOriginalColor = node->color; // keep track of orginal node color
    //case 1 
    // no left child
    if(node->left == nullptr){
        x = node->right; // x becomes right node 
        transplant(node,node->right); // removed node replaced with right node because node left node is null
     //case 2 
    //no right child 
    }else if (node->right == nullptr){
        x = node->left; //x become left node 
        transplant(node,node->left);  //removed node replaced with left node because node right node is null
    }else{
        //case 3 
        // 2 child case
        nodeCopy = InOrdersuccessor(node); 
        nodeOriginalColor = nodeCopy->color; 
        x = nodeCopy->right; 
        if(nodeCopy->parent!= node){
            transplant(nodeCopy,nodeCopy->right); 
            nodeCopy->right = node->right; 
            nodeCopy->right->parent = nodeCopy;

        }else{
            x->parent= nodeCopy; // nodecopy right is null
        }
        transplant(node,nodeCopy); 
        nodeCopy->left = node->left; 
        nodeCopy->left->parent = nodeCopy; 
        nodeCopy->color= node->color;
    }
    if(nodeOriginalColor == 1 && x != nullptr){
        deleteFixup(x);
    }
}

void RedBlackTree:: deleteFixup(RBTNode* node){
    while(node != root && node->color == 1  ){
        if(node == node->parent->left){
            RBTNode* sibling = node->parent->right;
            if(sibling->color == 0){
                sibling->color = 1;
                node->parent->color = 0;
                RBTreeRotateLeft(node->parent); 
                sibling = node->parent->right;
            }
            if(sibling->left->color == 1 && sibling->right->color == 1){
                sibling->color = 0;
                node= node->parent; 
            }else{
                if(sibling->right->color == 1 ){
                    sibling->left->color = 1; 
                    node->color = 0;
                    RBTreeRotateRight(node);
                    sibling = node->parent->right; 
                }
                sibling->color = node->parent->color;
                node->parent->color = 1; 
                sibling->right->color = 1;
                RBTreeRotateLeft(node->parent);
                node = root; 
            }
        }else{
            RBTNode* sibling = node->parent->left;
            if(sibling->color == 0){
                sibling->color = 1; 
                node->parent->color = 0; 
                RBTreeRotateRight(node->parent);
                sibling = node->parent->left; 
            }
            if(sibling->right->color == 1 && sibling->left->color == 1){
                sibling->color = 0;
                node = node->parent; 
            }else{
                if(sibling->left->color == 1 ){
                    sibling->right->color = 1;
                    sibling->color = 0;
                    RBTreeRotateLeft(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = 1;
                sibling->left->color = 1;
                RBTreeRotateRight(node->parent);
                node = root;
            }
        }

    }
    node->color = 1;
}


string RedBlackTree :: ToInfixString() const{
    return ToInfixString(root);
}

string RedBlackTree :: ToPrefixString() const{
    return ToPrefixString(root);
}

string RedBlackTree::ToPrefixString(RBTNode* node) const {
    if (node == nullptr) {
        return "";
    }
    //https://chat.openai.com/share/4c6dc826-f20a-4f94-8b42-ba64555abdc4
    //used how to get root color of node 
    string root = (node->color == 1? " B" : " R") + to_string(node->data) + " ";
    string left= ToPrefixString(node->left);
    string right = ToPrefixString(node->right);
    return root + left + right;
}


string RedBlackTree :: ToInfixString(RBTNode* node) const{
    if(node == nullptr){
        return "";
    }
    string left = ToInfixString(node->left); 
    string root = (node->color == 1? " B" : " R") + to_string(node->data)+ " ";
    string right = ToInfixString(node->right); 
    return left + root + right; 
}

string RedBlackTree::ToPostfixString() const {
    return ToPostfixString(root);
}

string RedBlackTree::ToPostfixString(RBTNode* node) const {
    if (node == nullptr) {
        return "";
    }
    
    string left = ToPostfixString(node->left);
    string right = ToPostfixString(node->right);
    string root = (node->color == 1 ? " B" : " R") + to_string(node->data) + " ";
    
    return left + right + root;
}

void RedBlackTree::DeleteNode(RBTNode* node) {
    if (node != nullptr) {
        DeleteNode(node->left); 
        DeleteNode(node->right); 
        delete node; // Delete the current node
    }
}

RedBlackTree :: ~RedBlackTree(){ 
    DeleteNode(root);
}

