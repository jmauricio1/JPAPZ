/*
 * NAME: Joshua Jacob Mauricio
 * DATE: 2/24/2019
 * Lab 3 : Binary Search Trees
 */
#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T element; //Element contained in the node
    TreeNode<T>* left; //Pointer to the left child
    TreeNode<T>* right; //Pointer to the right child
    int height;

    TreeNode(T element) //Constructor
    {
        this->element = element;                        //Sets the element being passed in to TreeNode's element
        left = NULL;                                    //Sets left child to NULL
        right = NULL;                                   //Set right child to NULL
        height = 0;                                     //Set height of node to 0;
    }
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>

{
public:
    Iterator(TreeNode<T>* p)
    {
        current = 0;                                    //Sets the current index of the vector to 0
        treeToVector(p);                                //Calls the treeToVector function with the starting TreeNode p
    }

    Iterator operator++()
    {
        current++;                                      //Increments the current(index of the current position of the vector) by 1
    }

    T &operator*()
    {
        return v.at(current);                           //Returns the element at the current position in the vector
    }

    bool operator == (const Iterator<T> &iterator) const
    {
        if(current == iterator.current){                //If the current index is the same is another iterator's current
            return 1;                                   //Return true
        }
        else {
            return 0;                                   //Return false
        }
    }

    bool operator != (const Iterator<T> &iterator) const
    {
        if(current != iterator.current){                //If the current index is NOT the same as another iterator's current
            return 1;                                   //Return true
        }
        else {
            return 0;                                   //Return false
        }
    }

private:
    int current;
    vector<T> v;

    void treeToVector(TreeNode<T>* p)
    {
        v.push_back(p->element);                        //Adds element, from node being passed in, to the end of the vector
        //cout << p->element << " ";                    //This was a way to show the order of the elements being passed in
        if(p->left != NULL){                            //If the node p has a left child,
            treeToVector(p->left);                      //Call treeToVector starting from the left child
        }
        if(p->right != NULL){                           //If the node p has a right child,
            treeToVector(p->right);                     //Call treeToVector starting from the right child
        }
    }
};

template <typename T>
class BST
{
public:
    BST();
    BST(T elements[], int arraySize);
    BST(BST<T> &tree);
    ~BST();
    bool search(T element) const;
    virtual bool insert(T element);
    //virtual bool remove(T element);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    int getSize() const;
    void clear();
    int isEmpty();
    vector<TreeNode<T>*>* path(T element) const;

    Iterator<T> begin() const
    {
        Iterator<T> newIterator(root);                  //Creates an Iterator starting from the root of the BST
        return newIterator;                             //Returns the Iterator
    }

    Iterator<T> end() const                             //This is bast on a post-order traversal
    {
        Iterator<T> newIterator(root);                  //Creates an Iterator ending at the root of the BST
        return newIterator;                             //Returns the Iterator
    }

protected:
    TreeNode<T>* root;
    int size;
    virtual TreeNode<T>* createNewNode(T element);

private:
    void inorder(TreeNode<T>* root) const;
    void postorder(TreeNode<T>* root) const;
    void preorder(TreeNode<T>* root) const;
    void copy(TreeNode<T>* root);
    void clear(TreeNode<T>* node);
    void fixHeight(TreeNode<T>* node);
};

/**
  *@brief BST default constuctor
  **/
template <typename T>
BST<T>::BST()
{
    root = NULL;                                        //Sets the root of the BST to NULL
    size = 0;                                           //Sets the size of the BST to 0
}

/**
  *@param elements[]
  * @param arraySize
  *@brief BST constructor that takes in 2 arguments
  **/
template <typename T>
BST<T>::BST(T elements[], int arraySize)
{
    for(int i = 0; i < arraySize; i++){                 //Loop will run depending on the size of the array being passed in
        insert(elements[i]);                            //Will insert elements from array to BST from smallest index to largest index
    }
}

/**
  *@param &tree
  *@brief Copy constructor
  **/
template <typename T>
BST<T>::BST(BST<T> &tree)
{
    root = NULL;                                        //Root will be set to NULL
    size = 0;                                           //Size will be set to 0

    if(tree.root != NULL){                              //If the tree's root is NOT NULL
        Iterator<T> newIterator(tree.root);             //Create an Iterator starting at the tree's root
        for(int i = 0; i < tree.size; i++){             //Loop will run for how many elements are in the tree
            insert(*newIterator);                       //Inserts the element into BST from the vector in newIterator
            ++newIterator;                              //Current index in newIterator will increase by 1
        }
    }
}

/**
  *@param root
  *@brief Copies the element from the specified tree to this tree
  **/
template <typename T>
void BST<T>::copy(TreeNode<T>* root)
{
    insert(root->element);                              //Inserts a SINGLE element from another tree into the BST
}

/**
  *@brief Destructor for BST
  **/
template <typename T>
BST<T>::~BST()
{

}

/**
  *@param element
  *@return found
  *@brief Return true if the element is in the tree
  **/
template <typename T>
bool BST<T>::search(T element) const
{
    bool found = 0;                                     //Creates a bool named found and sets it to 0
    TreeNode<T>* temp = root;                           //Creates a temporary TreeNode that starts at the root of the BST
    while(found == 0){                                  //While the element is NOT found
        if(element == temp->element){                   //If my temporary TreeNode's element is the same as wanted element
            found = 1;                                  //Set my found to true
        }
        else if(element < temp->element){               //Else if element being passed in is less than the temporary element,
            if(temp->left != NULL){                     //If the temporary TreeNode's left is NOT NULL
                temp = temp->left;                      //Set my temporary TreeNode to its left child
            }
            else if(temp->left == NULL){                //Else if the temporary TreeNode's left is NULL,
                break;                                  //Break the loop with found as false
            }
        }
        else if(element > temp->element){               //Else if element being passed in is greater than the temporary TreeNode's element
            if(temp->right != NULL){                    //If the temporary TreeNode's right is NOT NULL
                temp = temp->right;                     //Set the tmporary TreeNode as its right child
            }
            else if(temp->right == NULL){               //Else if the tmporary TreeNode's right is NULL
                break;                                  //Break the loop with found as false
            }
        }
    }
    return found;                                       //Return the value of found;
}

/**
  *@param element
  *@return newTreeNode
  *@brief Created a TreeNode for a new element
  **/
template <typename T>
TreeNode<T>* BST<T>::createNewNode(T element)
{
    TreeNode<T>* newTreeNode = new TreeNode<T>(element);//Creates a TreeNode that POINTS to a TreeNode on the heap(created with an element)
    return newTreeNode;                                 //Returns the newly created TreeNode
}

/**
  *@param node
  *@brief Fixes height of the nodes that are on the path to newly inserted TreeNode
  **/
template <typename T>
void BST<T>::fixHeight(TreeNode<T>* node){
    vector<TreeNode<T>*>* treeVector = path(node->element);//This sets up a new vector full of addresses of the path to the node
    unsigned int j = (*treeVector).size() - 1;          //Creates an unigned int j and sets it to the size of the vector minus 1
    for(unsigned int i = 0; i < (*treeVector).size(); i++){//Loop will run for how many elements are in treeVector
        (*treeVector).at(i)->height = j;                //Sets height of current node in the vector to j
        j--;                                            //Decrement j by 1
    }
}

/**
  *@param element
  *@return successful : returns 0 for inserted or 1 for not inserted
  *@brief Insert element into the binary tree
  **/
template <typename T>
bool BST<T>::insert(T element)
{
    bool successful = 0;                                //Creates a bool called successful and sets it to 0
    TreeNode<T>* newNode = createNewNode(element);      //Creates a new TreeNode for the element that is being passed in
    if(root == NULL){                                   //If the current root in the BST is NULL
        root = newNode;                                 //Set the newNode as the root
        successful = 1;                                 //Successful is set to true
    }
    else{                                               //If the root of the current BST is NOT NULL
        TreeNode<T>* temp = root;                       //Create a temporary TreeNode called temp
        while(successful != 1){                         //While the insertion is not successful
            if(element > temp->element){                //If the element being passed in is greater than the temp's element
                if(temp->right == NULL){                //Also, If temp's right child is NULL
                    temp->right = newNode;              //Insert the newNode as temp's right child
                    successful = 1;                     //Set successful to true
                }
                else                                    //If the right child is NOT NULL
                    temp = temp->right;                 //Update the temp as its right child
            }
            else if(element < temp->element){           //Else if the element being passed in is less than temp's element
                if(temp->left == NULL){                 //Also, if the temp's element is NULL
                    temp->left = newNode;               //Set the newNode as temp's left child
                    successful = 1;                     //Set successful to 1
                }
                else{                                   //If the left child is NOT NULL
                    temp = temp->left;                  //Update the temp as its left child
                }
            }
            else if(element == temp->element){          //Else if the element is the same as temp's element
                break;                                  //Break the loop and does not insert the element
            }
        }
    }
    if(successful == 1){                                //If the insertion is successful
        fixHeight(newNode);
        size++;                                         //Increase the size by 1
    }
    return successful;                                  //Return the value of successful
}

/**
  *@brief Inorder traversal
  **/
template <typename T>
void BST<T>::inorder() const
{
    if(root != NULL){
        inorder(root);                                  //Calls the inorder function (with 1 argument) starting at the root
        cout << endl;
    }
    else {
        cout << "Empty Binary Search Tree ";
    }
}

/**
  *@param root
  *@brief Inorder traversal from a subtree
  **/
template <typename T>
void BST<T>::inorder(TreeNode<T>* root) const
{
    if(root->left == NULL){                             //If the root does not have left child
        cout << root->element << " ";                   //Print out the root's element to the console
    }
    else {                                              //If the root does have a left child
        inorder(root->left);                            //Call inorder function starting at the root's left child
        cout << root->element << " ";                   //Prints out the root's element to the console
    }
    if(root->right == NULL){                            //If the root does not have right child
        //Do nothing
    }
    else{                                               //If the root does have a right child
        inorder(root->right);                           //Call inorder function starting at the root's right child
    }
}

/**
  *@brief Postorder traversal
  **/
template <typename T>
void BST<T>::postorder() const
{
    if(root != NULL){
        postorder(root);                                //Calls thepost order function (with 1 argument) starting at the root
        cout << endl;
    }
    else {
        cout << "Empty Binary Search Tree ";
    }
}

/**
  *@param root
  *@brief Postorder traversal from a subtree
  **/
template <typename T>
void BST<T>::postorder(TreeNode<T>* root) const
{
    if(root->left != NULL){                             //If the root does have a left child
        postorder(root->left);                          //Calls postorder function starting at the left child
    }
    if(root->right != NULL){                            //If the root deos have a right child
        postorder(root->right);                         //Calls the postorder function starting at the right child
    }
    cout << root->element << " ";                       //Prints out the root's element to the console
}

/**
  *@brief Preorder traversal
  **/
template <typename T>
void BST<T>::preorder() const
{
    if(root != NULL){
        preorder(root);                                 //Calls the preorder function (with 1 argument) starting at the root
        cout << endl;
    }
    else {
        cout << "Empty Binary Search Tree ";
    }
}

/**
  *@param root
  *@brief Preorder traversal from a subtree
  **/
template <typename T>
void BST<T>::preorder(TreeNode<T>* root) const
{
    cout << root->element << " ";                       //Prints out the element of the root to the console
    if(root->left != NULL){                             //If the root does have a left child,
        preorder(root->left);                           //Call preorder function starting at the root's left child
    }
    if(root->right != NULL){                            //If the root does have a right child,
        preorder(root->right);                          //Call preorder function starting from the root's right child
    }
}

/**
  *@return size
  *@brief Get the number of nodes in the tree
  **/
template <typename T>
int BST<T>::getSize() const
{
    return size;                                        //Returns the size of the BST
}

/**
  *@param
  *@return
  *@brief
  **/
template <typename T>
void BST<T>::clear(){
    clear(root);                                        //Calls the clear function (with 1 argument) starting at the root
}

/**
  *@param node
  *@brief Remove all nodes from the tree
  **/
template <typename T>
void BST<T>::clear(TreeNode<T>* node)
{
    if(node->left != NULL){                             //If the node being passed in has a left child
        clear(node->left);                              //Call clear function starting from the node's left child
    }
    if(node->right != NULL){                            //If the node has a right child,
        clear(node->right);                             //Call clear function starting from the node's right child
    }
    node->left = NULL;                                  //Make the node's left child to NULL
    node->right = NULL;                                 //Make the node's right child to NULL
    root = NULL;                                        //Make the root of the BST to NULL
    size--;                                             //Decrement the size of the BST by 1
}

/**
  *@param element
  *@return treeVector
  *@brief Return a path from the root leading to the specified element
  **/
template <typename T>
vector<TreeNode<T>*>* BST<T>::path(T element) const
{
    vector<TreeNode<T>*>* treeVector = new vector<TreeNode<T>*>;//Creates a new vector called treeVector(the path to the desired element)
    if(search(element) == 1){                           //If the element exists in the BST
        TreeNode<T>* temp = root;                       //Create a temporary TreeNode called temp and give it the value same as the root
        bool found = 0;                                 //Create a bool called found and set it to 0
        while(found == 0){                              //While the element is NOT found in BST
            if(element == temp->element){               //If the element is the same as the temp's element.
                treeVector->push_back(temp);            //Add the address of the temp to treeVector
                found = 1;                              //Sets found to true
            }
            else if(element < temp->element){           //Else if the element is less than the temp's element
                treeVector->push_back(temp);            //Add the address of the temp to treeVector
                if(temp->left != NULL){                 //Also if the temp's left child is NOT NULL
                    temp = temp->left;                  //Set the temp as its left child
                }
            }
            else if(element > temp->element){           //Else if the element is greater than the temp's element
                treeVector->push_back(temp);            //Add the address of the temp to treeVector
                if(temp->right != NULL){                //Also if the temp's right child is NOT NULL
                    temp = temp->right;                 //Set the temp as its right child
                }
            }
        }
    }
    return treeVector;                                  //Returns the vector that holds the addresses(path) that leads to desired element
}

template<typename T>
int BST<T>::isEmpty(){
    if(size == 0){
        return 1;
    }
    else {
        return 0;
    }
}

#endif
