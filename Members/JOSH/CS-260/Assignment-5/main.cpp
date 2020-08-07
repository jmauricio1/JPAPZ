#include <iostream>
#include "HASHSET.h"

using namespace std;

int main(){

    HashSet<string> newSet;

    cout << "Empty List: " << newSet.isEmpty() << endl;

    cout << "--- INSERTS ---" << endl;
    newSet.insert("Noah");
    newSet.insert("Levi");
    newSet.insert("Sam");
    newSet.insert("Jeff");

    cout << "--- FIND ---" << endl;
    newSet.find("Noah");
    newSet.find("Levi");
    newSet.find("Sam");
    newSet.find("Jeff");

    cout << "--- ERASE ---" << endl;
    newSet.erase("Levi");
    newSet.erase("Jeff");

    cout << "--- FINAL ---" << endl;
    cout << "Empty List: " << newSet.isEmpty() << endl;
    cout << "Size: " << newSet.getSize() << endl;

    //newSet.clear();

    cout << endl;
}
