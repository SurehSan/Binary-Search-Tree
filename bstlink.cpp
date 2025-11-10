#include <iostream>
#include <fstream>
using namespace std;

#include "bstlink.h"


//THIS FILE DOES BINARY SEARCH TREE USING LINKED LISTS


// allocate a new node
//   not part of the class
treenode *makeatreenode( int x )
{

    treenode *node;
    node = new treenode;
    node->dat = x;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;
}

bstree::bstree()
{
    root = NULL; // set root pointer to NULL
}

void bstree::in(treenode *t)
{
    if (t == NULL)
        return; //pop back up
    in(t->lchild); //go left first
    cout << t->dat << " ";
    in(t->rchild); //go right first

}

void bstree::in()
{
    cout << "In: ";
    in(root);
    cout << endl;
}

void bstree::pre(treenode *t)
{
    if (t == NULL)
        return; //pop back up
    cout << t->dat << " ";
    pre(t->lchild);
    pre(t->rchild);
}

void bstree::pre()
{
    cout << "Pre: ";
    pre(root);
    cout << endl;
}

void bstree::post(treenode *t)
{
    if (t == NULL)
        return; //pop back up
    post(t->lchild);
    post(t->rchild);
    cout << t->dat << " ";
}

void bstree::post()
{
    cout << "Post: ";
    post(root);
    cout << endl;
}

void bstree::insertR( treenode *&t, int val)
{

    if (t == NULL) //if it is empty
    {
        t = makeatreenode(val);
        return;
    }

    if (t->dat == val)
        return;
    else if (val < t->dat)
        insertR(t->lchild, val);
    else
        insertR(t->rchild, val);

}

void bstree::insert( int val )
{
    insertR( root, val);
}


bool bstree::search( int val )
{

    return searchI(val);

}

bool bstree::searchR( treenode *t, int val)
{
    //needs header file
    if ( t->dat == val)
        return true;
    if ( t == NULL)
        return false;// ( no child)
    if ( val < t->dat)
        return searchR( t->lchild, val);
    else
        return searchR( t->rchild, val);
}

//private helper function
bool bstree::searchI(int val)
{
    //while loop
    treenode *t = root;

    while (t != NULL)
    {
        if (t->dat == val)
            return true;
        if (val < t->dat)
            t = t->lchild;
        else
            t = t->rchild;
    }

    return false;
}

int bstree::height()
{
    return height(root);
}

int bstree::height(treenode *t)
{
    if (t == NULL)
        return 0;

    int hL, hR;
    hL = height(t->lchild);
    hR = height(t->rchild);

    if (hL > hR)
        return 1 + hL;
    else
        return 1 + hR;

}

void bstree::bigger(treenode *t)
{
    if (t == NULL)
        printf("tree empty.\n");

    int hL, hR;
    hL = height(t->lchild);
    hR = height(t->rchild);

    if (hL > hR)
        printf("L bigger.\n");
    else if (hL < hR)
        printf("R bigger.\n");
    else
        printf("Equal.\n");

}

void bstree::bigger()
{
    return bigger(root);
}

int bstree::numnode()
{
    return numnode(root);
}

int bstree::numnode(treenode *t)
{
    if (t == NULL)
        return 0;

    if ( t->lchild == NULL && t->rchild == NULL)
        return 1;

    int hL, hR;
    hL = numnode(t->lchild);
    hR = numnode(t->rchild);
    int numnodes = hL + hR + 1;

    return numnodes;
}

void bstree::remove(treenode *&t, int val) // *&t so parent pointers can be updated
{
//search through to find the value to remove
    if (t->dat < val)
        remove(t->rchild, val);
    else if (t->dat > val)
        remove(t->lchild, val);

    else
    {
        if (t->rchild == NULL && t->lchild == NULL) //case 1: node has no children
        {
            delete t;
            t = NULL;
        }

        else if (t->lchild == NULL) //case 2: node has right child
        {
            treenode *tmp = t;
            t = t->rchild;
            delete tmp;
        }

        else if (t->rchild == NULL) //case 2: node has left child
        {
            treenode *tmp = t;
            t = t->lchild;
            delete tmp;
        }
        //case 3: 2 children

        else
        {
            treenode *rsmall = t->rchild;
            while (rsmall->lchild != NULL)
                rsmall = rsmall->lchild;

            t->dat = rsmall->dat;

            remove(t->rchild, rsmall->dat);
        }
    }
}

void bstree::remove(int val)
{
    return remove(root, val);
}

int bstree::getMin()
{
    treenode *walk;
    walk = root;

    if ( root == NULL)
        return 0;

    while ( walk->lchild != NULL )
        walk = walk->lchild;

    int save;
    save = walk->dat;
    remove(save);
    return save;
}
