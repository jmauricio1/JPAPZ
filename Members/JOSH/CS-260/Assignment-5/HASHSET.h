/*
 * NAME: Joshua Jacob Mauricio
 * DATE: 3/14/2019
 * LAB 5: Unordered Sets
 */
#ifndef HASHSET_H
#define HASHSET_H
#include <string>
#include "DLINKEDLIST.h"
#include <unordered_set>
#include <cmath>

typedef std::unordered_set<std::string> stringset;
template<typename T>
class HashSet
{
public:
    HashSet();
    double hashFunction(T data);
    bool insert(T data);
    void clear();
    bool find(T data);
    bool isEmpty();
    bool erase(T data);
    int getSize();
private:
    int size;
    const static int tableSize = 101;
    DLinkedList<T>* hashTable [tableSize];
};
template<typename T>
HashSet<T>::HashSet()
{
    size = 0;
    for(int i = 0; i < 101; i++){
        hashTable[i] = nullptr;
    }
}
template<typename T>
double HashSet<T>::hashFunction(T data)
{
    stringset myset;
    stringset::hasher fn = myset.hash_function();
    double hash = (abs(fn(data)));
    return fmod(hash, tableSize);
}


/**
 * @param data
 * @return successful
 * @brief Inserts the data into a Doubly Linked List at a certain location in array
 **/
template<typename T>
bool HashSet<T>::insert(T data)
{
    int location = static_cast<int>(floor(hashFunction(data))); //Sets the lcoation of where the data should go in array
    bool successful = 0;                                        //Sets new bool called successful
    if(hashTable[location] == nullptr){                         //If location in array is a nullptr
        DLinkedList<T>* newList = new DLinkedList<T>();         //Create a new DlinkedList
        hashTable[location] = newList;                          //Put new DLinkedList into location in array
        newList->addFirst(data);                                //Add data to the DLinkedList
        successful = 1;
    }
    else{
        hashTable[location]->addFirst(data);                    //Add data to the DLinkedList
        successful = 1;
    }
    cout << location << ": " << data << endl;                   //Print out of the index where data goes
    size += 1;                                                  //Increase size by 1

    return successful;                                          //Returns whether or not insert was successful
}


/**
 * @brief Resets the hashSet
 **/
template<typename T>
void HashSet<T>::clear()
{
    for(int i = 0; i < tableSize; i++){                         //Loop will run same times as tableSize
        if(hashTable[i] != nullptr){                            //If location in hashTable is NOT nullptr
            hashTable[i]->clear();                              //Clear the linked list in that location
            hashTable[i] = nullptr;                             //Reset the location  in hashTable as a nullptr
        }
    }
    size = 0;                                                   //Set size to 0;
}


/**
 * @param data
 * @return 0 or 1
 * @brief Returns true or false if data has been found
 **/
template<typename T>
bool HashSet<T>::find(T data)
{
    int location = static_cast<int>(floor(hashFunction(data))); //Sets the index of where the data should go in array
    if(hashTable[location]->contains(data) == 1){               //If the DLinkedList in location of hashTable contains the data
        cout << data << ": FOUND" << endl;                      //Print out of which data has been found
        return 1;                                               //Returns 1
    }
    else{
        cout << data << ": NOT FOUND" << endl;                  //Print out of the data NOT found
        return 0;                                               //Returns 0
    }
}


/**
 * @return 0 or 1
 * @brief Returns true or false if the hashTable is empty
 **/
template<typename T>
bool HashSet<T>::isEmpty()
{
    if(size == 0){                                              //If size is 0
        return 1;                                               //Return 1
    }
    else
        return 0;                                               //Return 0
}


/**
 * @param data
 * @return 0 or 1
 * @brief Returns 0 or 1 if the data has been erased successfully
 **/
template<typename T>
bool HashSet<T>::erase(T data)
{
    int location = static_cast<int>(floor(hashFunction(data))); //Sets the index of where the data should go in array
    if(hashTable[location]->contains(data) == 1){               //If the DLinkedList in lcoation of hashTable contains the data
        find(data);                                             //Used only for print out statement
        cout << data << ": ";
        hashTable[location]->remove(data);                      //Remove the data in DLinkedList at location in hashTable
        cout << "REMOVED" << endl;
        size -= 1;                                              //Decrement size by 1

        if(hashTable[location]->getSize() == 0){                //If the size of the DlinkedList at location in hashTable is 0
            hashTable[location] = nullptr;                      //Set the location of the hashTable to nullptr
        }
        return 1;                                               //Return 1
    }
    else
        return 0;                                               //Return 0
}

/**
 * @return size
 * @brief Returns the size of the hashSet
 **/
template<typename T>
int HashSet<T>::getSize()
{
    return size;                                                //Returns size
}
#endif // HASHSET_H
