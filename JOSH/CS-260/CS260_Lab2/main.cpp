/*
 * Joshua Jacob Mauricio
 * 2/1/2019 Lab2
 */
#include <iostream>
#include "DLINKEDLIST.h"
#include "QUEUE.h"

using namespace std;

void linkedListTest();
void queueTest();

template<typename T>
void printLinkedList(const DLinkedList<T>& theList);

template<typename T>
void printQueue(Queue<T>& theQueue);

int main()
{
    linkedListTest();
    queueTest();
}

void linkedListTest(){
    DLinkedList<int> list;

    cout << "--- DOUBLE LINKED LIST TEST ---" << endl;

    list.add(1);            //add(element)
    cout << "1: ";
    printLinkedList(list);

    list.add(2);
    cout << "2: ";
    printLinkedList(list);

    list.addFirst(3);       //addFirst
    cout << "3: ";
    printLinkedList(list);

    list.addFirst(4);
    cout << "4: ";
    printLinkedList(list);

    list.addLast(5);        //addLast
    cout << "5: ";
    printLinkedList(list);

    list.addLast(6);
    cout << "6: ";
    printLinkedList(list);

    list.add(2, 7);         //add(index, element)
    cout << "7: ";
    printLinkedList(list);

    list.add(5, 8);
    cout << "8: ";
    printLinkedList(list);

    list.remove(1);         //remove
    cout << "9: ";
    printLinkedList(list);

    auto temp = list.removeAt(5);   //removeAt
    cout << "10: ";
    printLinkedList(list);
    cout << "(Removed " << temp << ")" << endl;

    list.removeFirst();     //removeFirst
    cout << "11: ";
    printLinkedList(list);

    for(int i = 0; i < 10; i++){
        cout << "List contains " << i << "? " << list.contains(i) << endl;  //contains
    }

}

template<typename T>
void printLinkedList(const DLinkedList<T>& theList){
    for(int i = 0; i < theList.getSize(); i++){
        cout << theList.get(i) << " ";             //get(index)
    }
    cout << endl;

    cout << endl
         << "HEAD: " << theList.getFirst() << '\t'              //getFirst
         << "TAIL: " << theList.getLast() << '\t'               //getLast
         << "SIZE: " << theList.getSize() << endl << endl;      //getSize
}

void queueTest(){

    cout << "--- QUEUE TESTS ---" << endl;
    Queue<int> theQueue;
    theQueue.enqueue(5);
    theQueue.enqueue(6);
    theQueue.enqueue(7);
    theQueue.enqueue(8);
    theQueue.enqueue(9);
    theQueue.enqueue(10);

    cout << "Int queue: ";
    printQueue(theQueue);

    Queue<string> theQueueB;
    theQueueB.enqueue("The");
    theQueueB.enqueue("pie");
    theQueueB.enqueue("was");
    theQueueB.enqueue("very");
    theQueueB.enqueue("good");

    cout << "String queue: ";
    printQueue(theQueueB);

}

template<typename T>
void printQueue(Queue<T>& theQueue){
    while(theQueue.getSize() > 0){
        cout << theQueue.dequeue() << " ";
    }
    cout << endl << endl;
}

