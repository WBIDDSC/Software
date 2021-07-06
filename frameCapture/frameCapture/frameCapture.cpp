// WebcamPhoto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "windows.h"
#include "vfw.h"
#include <cstdio>
#pragma comment(lib, "Vfw32.lib")

#include <iostream>
#include <string>
#include <stdio.h>
#include "frameFunctions.h"

using namespace std;

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


int main()
{
    string photo; // will hold decision to take a photo or not

    //prompt user for decision on taking photo
    cout << "Please enter pic or stop: " << endl;
    cin >> photo;

    //check for promper input
    while (photo != "pic" && photo != "stop")
    {
        cout << "Please enter pic or stop: " << endl;
        cin >> photo;
    }

    while (photo == "pic")
    {
        // create the preview window 
        HWND hCam = capCreateCaptureWindow(
            L"hoven",
            WS_CHILD,
            0, 0, 0, 0,
            ::GetDesktopWindow(), 0);

        // connect to the first camera 
        // for other cameras try index 
        // 1, 2, in place of the 0 below 
        if (capDriverConnect(hCam, 0))
        {
            string pName; //name of photo being captured

            //prompt for photo name
            cout << "Please enter photo name (with photo type extension at the end such as .bmp): " << endl;
            cin >> pName;

            //check for a valid photo file extension
            while (!validPhotoName(pName))
            {
                cout << "Please enter photo name (with photo type extension at the end such as .bmp): " << endl;
                cin >> pName;
            }


            //create bmp photo file and rename it to whatever use enters
            capFileSaveDIB(hCam, L"pic.bmp");
            if (rename("pic.bmp", pName.c_str()) != 0)
                cout << "Error naming file";
            else
                cout << "File named successfully";

            // the screenshot is in the current 
            // directory, usually the same 
            // where the exe is created by 
            // your compiler 
            cout << "Saved as " << pName << endl;

        }

        else
        {

            printf("Check camera?");

        }

        DestroyWindow(hCam);

        //reprompt for decision on photo taking
        cout << "Please enter pic or stop: " << endl;
        cin >> photo;

        while (photo != "pic" && photo != "stop")
        {
            cout << "Please enter pic or stop: " << endl;
            cin >> photo;
        }

    }

    return 0;
}