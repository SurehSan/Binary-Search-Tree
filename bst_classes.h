// Base Code - linked binary search tree

#include <iostream>
#include <fstream>
using namespace std;


// tree node for linked BST
struct treenode
{
    int dat;
    treenode *lchild;
    treenode *rchild;
};


// Class for binary search tree
// Private will be treenode * to the root

class bstree
{
 public:
    bstree();
    void in( );
    void pre( );
    void post( );
    void insert( int x );
    bool search( int x );
    int numnode(); // must compute, not a variable in class
    int height();   // must compute, not a variable in class
    void bigger();
    int getMin();
    void remove(int x);
 private:
    bool searchI(int x);
    bool searchR(treenode *t, int x);
    void in(treenode *t);
    int height(treenode *t);
    treenode *root;
    void pre(treenode *t );
    void post(treenode *t );
    void insertR(treenode *&t, int x);
    int numnode(treenode *t); // must compute, not a variable in class
    void remove(treenode *&t, int x );
    void bigger(treenode *t);
};
