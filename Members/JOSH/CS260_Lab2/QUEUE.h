/*
 * Joshua Jacob Mauricio
 * 2/1/2019 Lab2
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "DLINKEDLIST.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Queue
{
public:
    Queue();
    void enqueue(T element);
    T dequeue() throw (runtime_error);
    int getSize() const;

private:
    DLinkedList<T> list; //Stores the elements in the queue
};

template<typename T>
Queue<T>::Queue()
{

}
/**
  *@param element
  *@brief Adds an element to the queue
  **/
template<typename T>
void Queue<T>::enqueue(T element)
{
    list.addLast(element);                      //Adds the element to the end of the linked lis
}

/**
  *@return element
  *@brief Removes an element from the queue
  **/
template<typename T>
T Queue<T>::dequeue() throw (runtime_error)
{
    string problem = "ERROR: Empty List";       //Creates a string called problem for a detailed warning message
    if(list.isEmpty() == 1)                     //If the list is empty
        throw runtime_error(problem);           //Throw the run time error
    else
        return list.removeFirst();              //Return the first element in the queue
}

/**
  *@return size
  *@brief Returns the number of elements in the queue
  **/
template<typename T>
int Queue<T>::getSize() const
{
    return list.getSize();                      //Returns the size of the queue
}

#endif
