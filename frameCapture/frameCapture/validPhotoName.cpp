#include <iostream>
#include <string>
#include "frameFunctions.h"

using namespace std;

bool validPhotoName(string& pName)
{
    if (pName.find(".bmp") != string::npos)
    {
        cout << "Valid name" << endl;
        return true;
    }
    else if (pName.find(".png") != string::npos)
    {
        cout << "Valid name" << endl;
        return true;
    }
    else if (pName.find(".jpg") != string::npos)
    {
        cout << "Valid name" << endl;
        return true;
    }
    else if (pName.find(".jpeg") != string::npos)
    {
        cout << "Valid name" << endl;
        return true;
    }
    else
    {
        cout << "Invalid name" << endl;
        return false;
    }
}