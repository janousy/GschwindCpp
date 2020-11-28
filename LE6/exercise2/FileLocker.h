//
// Created by Janosch Baltensperger on 28.11.20.
//

#ifndef EXERCISE2_FILELOCKER_H
#define EXERCISE2_FILELOCKER_H


#include <iostream>

using namespace std;

struct FileLocker {
    string res;
    FileLocker(string file) : res(file) {
        cout << "file locked" << endl;
    }

    ~FileLocker() {
        cout << "file unlocked" << endl;
    }
};

/*
void foo() {
    try {
        FileLocker lock("whatever we want to lock"); // problematic code
        } catch (  ) {
When this block is left, the destructor will be executed
 // exception handler and our external resource will }
be unlocked.
}
*/


#endif //EXERCISE2_FILELOCKER_H
