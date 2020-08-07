/*
 * Joshua Jacob Mauricio
 * 2/1/2019 Lab2
 */
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
    T element; //element contained in the node
    Node<T>* next; //pointer to the next node
    Node<T>* previous; //pointer to the previous node

    Node() //no-arg constructor
    {
        next = NULL;
        previous = NULL;
    }

    Node(T element) //constructor
    {
        this->element = element;
        next = NULL;
        previous = NULL;
    }
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    Iterator(Node<T>* p)
    {
        current = p;                            //Creates new node starting from Pointer Node P
    }

    Iterator operator++() //prefix ++
    {
        current = current->next;                //Current will be changed to what its next
        return *this;                           //Returns this same Iterator
    }

    Iterator operator++(int dummy) //postfix ++
    {
        current = current->next;                //Current will be changed to what its next
        return *this;                           //Returns this same Iterator
    }

    T& operator*()
    {
        return current->element;                //Returns the element that Node current is holding
    }

    bool operator==(const Iterator<T>& iterator)
    {
        bool equal = 0;                         //Sets up a temporary bool named equal to 0
        if(current == iterator)                 //If the current node is the same as iterator
            equal = 1;                          //Equal will be set to 1
        else
            equal = 0;                          //Equal will be set to 0
        return equal;                           //Return if equal or not
    }

    bool operator!=(const Iterator<T>& iterator)
    {
        bool equal = 0;                         //Sets up a temporary bool named equal to 0
        if(current == iterator)                 //If the current node is same as iterator
            equal = 0;                          //Equal will be set to 0
        else
            equal = 1;                          //Equal will be set to 1
        return equal;                           //Return if not equal
    }

private:
    Node<T>* current;
};

template<typename T>
class DLinkedList
{
public:
    DLinkedList();
    DLinkedList(const DLinkedList<T>& list);
    //virtual DLinkedList();
    void addFirst(T element);
    void addLast(T element);
    T getFirst() const;
    T getLast() const;
    T removeFirst() throw (runtime_error);
    T removeLast() throw (runtime_error);
    void add(T element);
    void add(int index, T element);
    void clear();
    bool contains(T element) const;
    T get(int index) const;
    int indexOf(T element) const;
    bool isEmpty() const;
    int lastIndexOf(T element);
    void remove(T element);
    int getSize() const;
    T removeAt(int index);
    T set(int index, T element);
    ~DLinkedList();

    //Returns an iterator for the first element of the list
    Iterator<T> begin()
    {
        Iterator<T> myIterator(head);           //Creates an iterator starting from the head of linked list
        return myIterator;                      //Returns an iterator
    }

    //Returns an iterator that passes the last element in the list
    Iterator<T> end()
    {
        Iterator<T> myIterator(tail);           //Creates an iterator from the tail
        return myIterator;                      //Returns the iterator
    }

private:
    Node<T>* head; //the head of the list
    Node<T>* tail; //the tail of the list
    int size; //the size of the list
};

//(no-arg constructor) Creates a default double linked list
template<typename T>
DLinkedList<T>::DLinkedList()
{
    head = NULL;                                //Constructor sets head to NULL
    tail = NULL;                                //Constructor sets tail to NULL
    size = 0;                                   //Starting size is 0
}

//(destructor) Destructs a linked list
template<typename T>
DLinkedList<T>::~DLinkedList()
{

}

/**
  *@param element
  *@brief Adds the element to the head of the list
  **/
template<typename T>
void DLinkedList<T>::addFirst(T element)
{
    Node<T> *newNode = new Node<T>(element);    //Creates a new node for element being passed in
    if(head == NULL)                            //If the head is pointing to nothing
        head = newNode;                         //Then the head will be the new node
    else{
        head->previous = newNode;               //The head's previous will be the new node
        newNode->next = head;                   //The new node's next will be the head
        head = newNode;                         //Now sets the head to the new node
    }
    if(tail == NULL)                            //If the tail is pointing to nothing
        tail = newNode;                         //The tail will also point to the new node
    size++;                                     //Increase the size by 1
}

/**
  *@param element
  *@brief Adds the element to the tail of the list
  **/
template<typename T>
void DLinkedList<T>::addLast(T element)
{
    Node<T> *newNode = new Node<T>(element);    //Creates a new node for the element being passed in
    if(tail == NULL)                            //If the tail is pointing to nothing
        tail = newNode;                         //Then the head will be the new node
    else{
        tail->next = newNode;                   //The tail's next will be the new node
        newNode->previous = tail;               //The new node's previous will be the tail
        tail = newNode;                         //The tail will be set to the new node
    }
    if(head == NULL)                            //If the head is also pointing to nothing
        head = newNode;                         //The head will also point to the new node
    size++;                                     //Increase the size by 1
}

/**
  *@return the element of the head
  *@brief Returns the first element in the list
  **/
template<typename T>
T DLinkedList<T>::getFirst() const
{
    return head->element;                       //Returns the element inside of the head
}

/**
  *@return the tail's element
  *@brief Returns the last element in the list
  **/
template<typename T>
T DLinkedList<T>::getLast() const
{
    return tail->element;                       //Returns the element inside of the tail
}

/**
  *@return element
  *@brief Removes the first element from the list
  **/
template<typename T>
T DLinkedList<T>::removeFirst() throw (runtime_error)
{
    string error = "ERROR: Empty linked-list";  //Set a string called error as detailed warning message
    if(isEmpty() == 1)                          //If the linked list is empty
        throw runtime_error(error);             //Program will throw a run time error
    else if(head == tail){                      //Else if the head and tail are pointing to the same thing
        tail = NULL;                            //Make the tail point to nothing
    }
    Node<T>* temp = head;                       //Creates a temporary node and makes it point to the head
    T element = temp->element;                  //Creates a temporary element and gives it the value of the the temp's element
    if(head->next == NULL){                     //If the head's next is pointing to nothing
        head = NULL;                            //The head will be pointing to nothing
    }
    else {
        head = head->next;                      //The head will now be set as the current head's next
        head->previous = NULL;                  //The head's previous will now be pointing to nothing
    }
    size--;                                     //Decrease the size by 1
    delete temp;                                //Delete temp
    return element;                             //Returns the element of the node that has been removed(Temporary element)
}

/**
  *@return element
  *@brief Removes the last element from the list
  **/
template<typename T>
T DLinkedList<T>::removeLast() throw (runtime_error)
{
    string error = "ERROR: Empty linked-list";  //Set a string called error as detailed message warning
    if(isEmpty() == 1)                          //If the linked list is empty
        throw runtime_error(error);             //Program will throw a run time error
    else if (head == tail)                      //Else if the head and tail are pointing to the same thing
        head = NULL;                            //Make the head point to nothing
    Node<T>* temp = tail;                       //Creates a temporary node and gives it the value of the tail
    T element = temp->element;                  //Creates a temporary element and gives it the value of the same element as the temporary node
    tail = tail->previous;                      //Tail will now be the node before the tail
    tail->next = NULL;                          //New tail's next will now be nothing
    size--;                                     //Decrease the size by 1
    delete temp;                                //Delete the temporary node
    return element;                             //Return the temporary element
}

/**
  *@param element
  *@brief Appends a new element to the end of the list
  **/
template<typename T>
void DLinkedList<T>::add(T element)
{
    Node<T> *newNode = new Node<T>(element);    //Creates a new node for element being passed in
    if(tail == NULL)                            //If the tail is pointing to nothing
        tail = newNode;                         //Make the tail point to the new node
    else{
        tail->next = newNode;                   //Make the tail's next be the new node
        newNode->previous = tail;               //The new node's previous will now be the tail
        tail = newNode;                         //Tail will be updated as the new node
    }
    if(head == NULL)                            //If the head is pointing to nothing
        head = newNode;                         //Make the head point to the new node
    size++;                                     //Increase the size by 1
}

/**
  *@param index
  *@param element
  *@brief Adds a new element at the specified index in the list
  **/
template<typename T>
void DLinkedList<T>::add(int index, T element)
{
    if(index == 0){                             //If The index is 0
        addFirst(element);                      //Call the addFirst function to add to beginning of the linked list
    }
    else if(index == size){                     //If the index is the same as the size
        addLast(element);                       //Call addLast function to add to the ending of the linked list
    }
    else if((index < 0) || (index > size)){     //If the index given does not exist in the list
        cout << "Please use valid index." << endl; // Print out reason
    }
    else{                                       //This is if the index is other than 0 or the size
        Node<T>* temp = head;                   //Make a new temp node and give it point to the same as the head
        Node<T> *newNode = new Node<T>(element);//Creates a new node with the given element
        for(int i = 1; i < index; i++){         //For loop to iterate through list for where the new node is going to be added
            temp = temp->next;                  //Our temporary node will be assigned to its next
        }
        newNode->next = temp->next;             //The new node's next will point to the temp's next
        newNode->previous = temp;               //The new node's previous will now point to the temporary node
        temp->next = newNode;                   //The temporary's next will point to the new node
        newNode->next->previous = newNode;      //The new node's next will have its previous point to new node
        size++;                                 //Increase the size by 1
    }
}

/**
  *@brief Removes all elements from the list
  **/
template<typename T>
void DLinkedList<T>::clear()
{
    for(int i = 0; i < size; i++){              //For loop to delete everything in the list
        delete head->previous;                  //Delete head's previous in order to keep working with the head
        head = head->next;                      //Make the head to the head's next
    }
    delete tail;                                //Delete the tail
    head = NULL;                                //Makes the head point to nothing to make sure everything has been reset
    tail = NULL;                                //Makes the tail point to nothing to make sure everything has been reset
    size = 0;                                   //Set the size to 0
}

/**
  *@param element
  *@return found
  *@brief Returns true if the list contains the specified element
  **/
template<typename T>
bool DLinkedList<T>::contains(T element) const
{
    Iterator<T> counter(head);                  //Creates an iterator starting from the head
    int found = 0;                              //Creates a bool called found and sets it to 0
    for(int i = 0; i < size; i++){              //Iterates through the the whole linked list
        if(*counter == element){                //If the element in the counter is the same as the wanted element
            found = 1;                          //Make found to 1
        }
        else{                                   //If not the same
            counter++;                          //Make the counter be the current node's next
        }
    }
    return found;                               //Return if the element has been found
}

/**
  *@param index
  *@return element
  *@brief Returns the element from the list at the specified index
  **/
template<typename T>
T DLinkedList<T>::get(int index) const
{
    if((index < 0) || (index >= size)){             //If the index does not exist in the list
        cout << "Please use a valid index." << endl;//Print out the problem
    }
    else{
        Iterator<T> counter(head);                  //Creates a new iterator starting from the head
        T element = head->element;                  //Ceates a new temporary element
        for(int i = 0; i < index + 1; i++){         //Iterates through the list until it reaches the desired index
            element = *counter;                     //Element will be given the value of the counter's element
            counter++;                              //Make the counter be the next node in the list
        }
        return element;                             //Returns the temporary element
    }
}

/**
  *@param element
  *@return index
  *@brief Returns the index of the first matching element in the list
  **/
template<typename T>
int DLinkedList<T>::indexOf(T element) const
{
    if(contains(element) == 1){
        Iterator<T> counter(head);              //Creates a new iterator starting from the beginning of the linked list
        int index = 0;                          //Creates a starting index
        for(int i = 0; i < size; i++){          //For loop to go through the linked list
            if(*counter == element){            //If the counter's element is the same as the wanted element
                index = i;                      //Give the index the same value as i
                break;                          //Exit out of loop
            }
            counter++;                          //Counter will now point to the next node in the list
        }
        return index;                           //Returns the index of the wanted element
    }
    else
        return -1;                              //Return -1 for does not exist
}

/**
  *@param
  *@return bool
  *@brief Returns true if the list constains no elements
  **/
template<typename T>
bool DLinkedList<T>::isEmpty() const
{
    if(size == 0)                               //If the size is 0
        return 1;                               //Return 1 for empty
    else
        return 0;                               //Return 0 for not empty
}

/**
  *@param element
  *@brief Removes the specified element from the list
  **/
template<typename T>
void DLinkedList<T>::remove(T element)
{
    Node<T>* temp = head;                       //Creates a new temporary node and has it point to same node as the head
    bool found = 0;                             //Creates a bool called found and is given the value 0
    if(temp->element == element){               //If the temporary node's element is the same as the given element
        head->next->previous = NULL;            //Make the head's next have the previous be nothing
        head = head->next;                      //The head will now be the head's next
        found = 1;                              //Give found the value of 1
    }
    else if(tail->element == element){          //Else if the tail's element is the same as the wanted element
        temp = tail;                            //The temporary node will first be given the value of tail
        tail->previous->next = NULL;            //The tail's previous will have it's next point to nothing
        tail = tail->previous;                  //The tail will now be updated to the tail's previous
        found = 1;                              //Give found the vlaue of 1
    }
    else{
        while(found == 0){                      //While found is still 0
            if(temp->element == element){       //If the temporary element is the same as the wanted element
                temp->previous->next = temp->next;  //Make the temp's previous have its next point to the same thing as the temp's next
                temp->next->previous = temp->previous;  //Make the temp's next have its previous point to the temo's previous
                found = 1;                      //Give found the value of 1
            }
            else{
                temp = temp->next;              //Temp will be updated as the temp's next
            }
        }
    }
    if(found == 1){                             //If found is 1
        size--;                                 //Decrease the size by 1
        delete temp;                            //Delete's the temp node
    }
}

/**
  *@return size
  *@brief Returns the number of elements in the list
  **/
template<typename T>
int DLinkedList<T>::getSize() const
{
    return size;                                //Returns the size of the linked list
}

/**
  *@param index
  *@return element
  *@brief Removes the element at the specified index and returns the removed element
  **/
template<typename T>
T DLinkedList<T>::removeAt(int index)
{
    Node<T>* temp = head;                       //Make a new node called temp and have it point to the same thing as the head
    T element = temp->element;                  //Makes a new temporary element and gives it the value of the temp's element
    if(index == 0){                             //If the index is 0
        head->next->previous = NULL;            //Make the hea'ds next have its previous point to nothing
        head = head->next;                      //Update the head to be the current head's next
    }
    else if (index == (size - 1)){              //Else if the index is the very last thing in the index
        temp = tail;                            //Makes the temp point to the same node as the tail
        tail->previous->next = NULL;            //Make the tail's previous have its next point to nothing
        tail = tail->previous;                  //Have the tail now be the the current tail's previous
        element = temp->element;                //Have the temporary element be the temporary node's element
    }
    else{
        for(int i = 0; i < size; i++){          //Iterates through the loop until it finds the correct index
            if(i == index){                     //If variable i has the same value as the index being passed in
                break;                          //Exit the loop
            }
            else{
                temp = temp->next;              //Have the temp node be updated to the next node in the list
            }
        }
        temp->previous->next = temp->next;      //Make the temp's previous have its next point to the temp's next
        temp->next->previous = temp->previous;  //Make the temp's next have its previous point to the temp's previous
        element = temp->element;                //Have the element now be updated to be the temp's element
    }
    size--;                                     //Decrease the size by 1
    delete temp;                                //Delete the temp
    return element;                             //Return the element
}

#endif
