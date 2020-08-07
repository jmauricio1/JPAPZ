//Joshua Jacob Mauricio and Magalay
//Assign5/Lab 5
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    ifstream inFile;
    inFile.open("Images.txt");

    if(inFile.fail()){
        cout << "Sorry Buddy" << endl;
    }
    cout<< left << setw(35) << "Name" << left << setw(10)<< "Type" << left << setw(10)
        << "Width" << left << setw(10) << "Height" << "File Size" << endl;

    string website = "";
    string hash = "";
    double inFileSize = 0.0;
    double totalSize = inFileSize;
    while (!inFile.eof())
    {
        inFile >> website >> hash >> inFileSize;
        if(inFile.fail())
            break;
        website = website.substr(website.rfind('/') + 1); //substring is going to be everything from the last slash to the end
        string name = website.substr(0, (website.find('?')));
        string type = name.substr(name.find('.') + 1);
        string width = website.substr((website.rfind('?') + 1), 3);
        string height = website.substr((website.find('x') + 1), website.find(' '));
        cout<< left << setw(35) << name << left << setw(10)<< type << left << setw(10)
            << width << left << setw(10) << height << (inFileSize/1024) << endl;
        totalSize = totalSize + inFileSize;
    }
    cout << endl;
    cout << right << setw(65) << "Total Size: " << (totalSize/1024) << endl;
}
