#include <iostream>
#include <fstream>
using namespace std;

#include "bst_classes.h"

// command line argument: name of command file
// see assignment for command file guidelines
int main(int argc, char *argv[])
{
    bstree t;
    bool r;

    // process a command file

 ifstream fin(argv[1]);
 int cmd, val;
 while (fin >> cmd)
 {
  if (cmd == 0)
    break;
  if (cmd == 1)
  {
    fin >> val;
    t.insert(val);
  }

  else if (cmd == -1)
  {
    fin >> val;
    printf("Removed %d\n", val);
    t.remove(val);
  }
  else if (cmd == 2)
  {
    fin >> val;
    if (t.search(val))
        cout << "Search " << val << ": Yes" << endl;
    else
        cout << "Search " << val << ": No" << endl;
  }
  else if (cmd == 3)
  {
    t.pre();
  }
  else if (cmd == 4)
  {
    t.in();
  }
  else if (cmd == 5)
  {
    t.post();
  }
  else if (cmd == 7)
  {
    printf("Number of nodes: %d\n", t.numnode());
    //print # of nodes in tree
  }
  else if (cmd == 8)
  {
    printf("Height of tree: %d\n", t.height());
    //print height of tree
  }
  else if (cmd == 9)
  {
    t.bigger();
    //print which side is taller, or if they're equal
  }
 }


    // below is just a small
    // bit of code for basic testing
    // not part of final solution
    // just like our array code!!

/*
    t.insert( 40 );
    t.insert( 20 );
    t.insert( 77 );
    t.insert( 85 );
    t.insert( 66 );
    t.insert( 75 );
    t.pre();
    t.in();
    t.post();


    int v;
    cout << "Value to search: ";
    cin >> v;
    r = t.search(v);
    cout << "Found " << r << endl;
*/
    return 0;
}
