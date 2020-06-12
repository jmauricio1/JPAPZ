#include <iostream>
#include <vector>
#include <stdexcept>

#include "BST.h"


using namespace std;

int main()
{

    BST<int> tree;

   cout << "inserting elements in the tree: " << endl;
   cout << "size before inserting is: " << tree.getSize() << endl;
   cout << "insertion good, return 1, or return 0 if its false: " << tree.insert(3) << endl;
   cout << "insertion good, return 1, or return 0 if its false: " << tree.insert(2) << endl;
   cout << "insertion good, return 1, or return 0 if its false: " << tree.insert(1) << endl;
   cout << "insertion good, return 1, or return 0 if its false: " << tree.insert(5) << endl;
   cout << "insertion good, return 1, or return 0 if its false: " << tree.insert(4) << endl;
   cout << "insertion good, return 1, or return 0 if its false: " << tree.insert(6) << endl;
   cout << "size after instertion is: " << tree.getSize() << endl;

   cout << endl;

   cout << "Fidning the path of a certain element" << endl;

   cout << " find the path for number 3: " <<tree.path(3) << endl;
   cout << " find the path for number 1: " <<tree.path(1) << endl;
   cout << " find the path for number 4: " <<tree.path(4) << endl;
   cout << " find the path for number 5: " <<tree.path(5) << endl;

   cout << endl;

   cout << "_________________ NOW SEARCHING ELEMENTS IN THE TREE _________________" << endl;
   cout << "searching good, return 1, or return 0 if its false: " << tree.search(1) << endl;
   cout << "searching good, return 1, or return 0 if its false: " << tree.search(2) << endl;
   cout << "searching good, return 1, or return 0 if its false: " << tree.search(3) << endl;
   cout << "searching good, return 1, or return 0 if its false: " << tree.search(7) << endl;
   cout << "searching good, return 1, or return 0 if its false: " << tree.search(8) << endl;

   cout << "_________________ NOW TRAVERSALS_________________" << endl;

   cout << "Inorder: ";
   tree.inorder();
   cout << endl;
   cout << "Postorder: ";
   tree.postorder();
   cout <<endl;
   cout << "preorder: ";
   tree.preorder();
   cout << endl;


   cout << "__________ Iterator ___________" << endl;
   tree.insert(8);

   Iterator<int> iterator = tree.begin();

   cout << "elements in the tree are: ";
   while (iterator != tree.end())
   {
   cout << *iterator << " ";
   iterator.operator++();
   }

   system("pause");
   cout << endl;

   // test to see if number 8 in the tree or not.
   cout << " Is number 8 in the tree?  " << tree.search(8) << endl;













}
