#include <iostream>
#include "BSTREE.h"
#include <random>

using namespace std;

int main()
{
    BST<int> treeA;

    for(int i = 0; i < 25; i++){
        treeA.insert(rand() % 25);
    }
    cout << "--- TREE ---" << endl;
    cout << "PRE-ORDER: ";
    treeA.preorder();
    cout << endl;

    cout << "IN-ORDER: ";
    treeA.inorder();
    cout << endl;

    cout << "POST-ORDER: ";
    treeA.postorder();
    cout << endl;


    for(int i = 0; i < 25; i++){
        cout << "Found " << i << ": " << treeA.search(i) << endl;
    }

    vector<TreeNode<int>*>* vectorA = treeA.path(5);
    cout << "\nPath to 5: ";
    for(unsigned i = 0; i < (*vectorA).size(); i++){
        cout << (*vectorA).at(i)->element << " ";
    }
    cout << endl;

    vector<TreeNode<int>*>* vectorB = treeA.path(14);
    cout << "\nPath to 14: ";
    for(unsigned i = 0; i < (*vectorB).size(); i++){
        cout << (*vectorB).at(i)->element << " ";
    }
    cout << endl;

    vector<TreeNode<int>*>* vectorC = treeA.path(20);
    cout << "\nPath to 20: ";
    for(unsigned i = 0; i < (*vectorC).size(); i++){
        cout << (*vectorC).at(i)->element << " ";
    }
    cout << endl;

    BST<int> treeB(treeA);

    cout << "\n--- TREE B ---" << endl;
    cout << "PRE-ORDER: ";
    treeB.preorder();
    cout << endl;

    cout << "IN-ORDER: ";
    treeB.inorder();
    cout << endl;

    cout << "POST-ORDER: ";
    treeB.postorder();
    cout << endl;

    treeA.clear();
    cout << "--- TREE A (After clear())---" << endl;

    if(treeA.isEmpty() == 1){
        cout << "PRE-ORDER: ";
        treeA.preorder();
        cout << endl;

        cout << "IN-ORDER: ";
        treeA.inorder();
        cout << endl;

        cout << "POST-ORDER: ";
        treeA.postorder();
        cout << endl;
    }

}
