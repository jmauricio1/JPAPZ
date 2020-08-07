#ifndef BSTree_H
#define BSTree_H
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T element; //Element contained in the node
    TreeNode<T>* left; //Pointer to the left child
    TreeNode<T>* right; //Pointer to the right child

    TreeNode(T element) //Constructor
    {
        this->element = element;
        left = NULL;
        right = NULL;
    }
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>

{
public:
    Iterator(TreeNode<T>* p)
    {
        if(p == NULL){
            current = -1; // The end
        }
            else{

            // Get all the elements in inorder
            treeToVector(p);
            current = 0;
            }

    }

    Iterator operator++()
    {
        current++;
        if (current == v.size())
        current = -1; // The end
        return *this;

    }

    T &operator*()
    {

        return v[current];
    }

    bool operator == (const Iterator<T> &iterator) const
    {
        return current == iterator.current;

    }

    bool operator != (const Iterator<T> &iterator) const
    {
        return current != iterator.current;

    }

private:
    int current;
    vector<T> v;

    void treeToVector(TreeNode<T>* p)
    {
        if (p != NULL)

        {

        treeToVector(p -> left);

        v.push_back(p -> element);

        treeToVector(p -> right);

        }

    }
};

template <typename T>
class BST
{
public:
    BST();
    BST(T elements[], int arraySize); //Done
    BST(BST<T> &tree);//Done
    ~BST(); //Done
    bool search(T element) const;// Done.
    virtual bool insert(T element); // Done
    virtual bool remove(T element); // (optional).
    void inorder() const; //Done
    void preorder() const; //Done
    void postorder() const; //Done
    int getSize() const; //Done
    void clear();
    vector<TreeNode<T>* >* path(T element) const;//Done

    Iterator<T> begin() const
    {

        return Iterator<T>(root);
    }

    Iterator<T> end() const
    {
        return Iterator<T>(NULL);

    }

protected:
    TreeNode<T>* root;
    int size;
    virtual TreeNode<T>* createNewNode(T element);

private:
    void inorderP(TreeNode<T>* root)const; // Done
    void postorderP(TreeNode<T>* root) const; //Done
    void preorderP(TreeNode<T>* root) const; //Done
    void copyP(TreeNode<T>* root);
    void clearP(TreeNode<T>* root);
};

template <typename T>
BST<T>::BST()
{
    root = NULL;


    size = 0;


}


template <typename T>
BST<T>::BST(T elements[], int arraySize)
{
    root = NULL;
    size = 0;

    for(int i = 0; i < arraySize; i++){

        cout << insert(elements[i]) <<" ";
        cout << endl;
    }



}

/* Copy constructor */
template <typename T>
BST<T>::BST(BST<T> &tree)
{

    root = NULL;
    size = 0;
    copyP(tree.root);
}

/* Copies the element from the specified tree to this tree */
template <typename T>
void BST<T>::copyP(TreeNode<T>* root)
{
    // if root is empty, print tree is empty
    if(root == NULL){
        cout << "Original tree is empty" << endl;
    }

    else{// otherwise, do the following instructions.

            // insert element in this node to new node in the new tree.
            insert(root -> element);
            // go to the left side of the tree.
            copyP(root -> left);
            // go to the right side of the tree.
            copyP(root -> right);

    }




}


/* Destructor */
template <typename T>
BST<T>::~BST()
{

    // use clear function to delete all elements in the tree.
    clear();

}

/* Return true if the element is in the tree */
template <typename T>
bool BST<T>::search(T element) const
{

    // make a new node. point it to root.
    TreeNode<T>* temp /*= new TreeNode<T>(element)*/;
    temp = root;
    // while the value looking is not found, do the following instructions.
    while(temp -> element != element){
        // if the element is > than the value in this node, look only at the right side of the tree.
        if(element > temp -> element){

            temp = temp -> right;

            // if the right node is empty, return false. and break the loop.
            if(temp == NULL){

                return 0;
                break;
            }
        }
        else if(element < temp -> element){ // otherwise, look at the left side of the tree.

            temp = temp -> left;
            //// if the left node is empty, return false. and break the loop.
            if(temp == NULL){
                return 0;
                break;
            }

        }
    }
    // if argument in the loop is satisfied (element is found), return true.
    return 1;




    
}

template <typename T>
TreeNode<T>* BST<T>::createNewNode(T element)
{

    TreeNode<T>* newNode = new TreeNode<T>(element);

    return newNode;


}

/* Insert element into the binary tree
* Return true if the element the element is inserted successfully
* Return false if the element is already in the list
*/
template <typename T>
bool BST<T>::insert(T element)
{
    bool checker = 0;
    // make a new node. assign root to it.
    TreeNode<T>* newNode = createNewNode(element);

    // if the root is empty, assign it to root.
    if(root == NULL){
        root = newNode;
        checker = 1;
         size++; //increment size by one.
    }
    else{

        TreeNode<T>* temp = root;  /*= new TreeNode<T>(element)*/
        // while the condition is not satisfied, do the following instructions.
        while(checker != 1){
            // if the element inserted is greater than the element in the root, look only at the right side of the tree.
            if(element > temp->element){
                // if the right node is NULL, insert the element in it, it should be a leaf node.
                if(temp->right == NULL){
                    temp->right  = newNode;
                    checker = 1;
                     size++; //increment size by one.
                    // break the loop and return true.
                    //break;
                }
                else{
                    // make the temp node points to the node on the right.
                    temp = temp->right;
                }


            }

            else if(element < temp->element){
                // if the left node is NULL, insert the element in it, it should be a leaf node.
                if(temp->left == NULL){

                    temp->left  = newNode;
                    checker = 1;
                     size++; //increment size by one.
                    // break the loop and return true.
                    //break;
                }

                else{
                    // otherwise, make temp node points to the left side of the node,
                    temp = temp -> left;
                }

            }
        }
    }


    return  checker;




}

template <typename T>
bool BST<T>::remove(T element){
  // case 1: if node is a leaf.
  // case 2: if node has one child.
  // case 3: if node has 2 children.





}

/* Inorder traversal */
template <typename T>
void BST<T>::inorder() const
{
    // use the private inorder function and pass root in it's argument.
    inorderP(root);

}

/* Inorder traversal from a subtree */
template <typename T>
void BST<T>::inorderP(TreeNode<T>* root) const
{
    // TreeNode<T>* temp = root;
    // if root is not empty, do the foloowing instructions
    if(root != NULL){
        // if left node is not empty
        if(root -> left != NULL){
            // call a recursive function and make temp goes to the most left.
            inorderP(root -> left);
        }
        // then, print value.
        cout << root -> element << " ";
        // if right node is not empty
        if(root -> right != NULL){

            // call a recursive function and make temp goes to the right.
            inorderP(root -> right);
        }
    }

    if(root == NULL){
        cout << "EMPTY" << endl;
    }

}

/* Postorder traversal */
template <typename T>
void BST<T>::postorder() const
{

    postorderP(root);


}

/* Postorder traversal from a subtree */
template <typename T>
void BST<T>::postorderP(TreeNode<T>* root) const
{
    // LRP
    // TreeNode<T>* temp = root;
    // if root is not empty, do the foloowing instructions
    if(root != NULL){
        // if left node is not empty.
        if(root -> left != NULL){
            // call a recursive function and make temp goes to the most left.
            postorderP(root -> left);
        }
        // if right node is not empty
        if(root -> right != NULL){
            // call a recursive function and make temp goes to the right.
            postorderP(root -> right);
        }
        // finally, print the value
        cout << root -> element << " ";
    }

    if(root == NULL){
        cout << "EMPTY" << endl;
    }


}

/* Preorder traversal */
template <typename T>
void BST<T>::preorder() const
{
    preorderP(root);


}

/* Preorder traversal from a subtree */
template <typename T>
void BST<T>::preorderP(TreeNode<T>* root) const
{
    // if root empty, stop doing function.
    if (root == NULL){
       return;
    }
    cout << root->element << " ";
    preorderP(root->left);
    preorderP(root->right);
    }

/* Get the number of nodes in the tree */
template <typename T>
int BST<T>::getSize() const
{
    return size;

}

/* Remove all nodes from the tree */
template <typename T>
void BST<T>::clear()
{


}

/* Return a path from the root leading to the specified element */
template <typename T>vector<TreeNode<T>*>*
BST<T>::path(T element) const
{
    vector<TreeNode<T>* >* v = new vector<TreeNode<T>*>();
    //let current node starts from the root
    TreeNode<T>* current = root;

    while (current != NULL)
    {
     // print element.
     v->push_back(current);
     // if element inserted less than the element in the tree, shift to the left subtree.
    if (element < current->element){
    current = current->left;
    }
    // if element inserted less than the element in the tree, shift to the left subtree.
    else if (element > current->element){
    current = current->right;
    }
    //otherwise, break the loop.
          else;
          break;

    }
    // return elements.
    return v;

}

#endif
