//
// Created by Janosch Baltensperger on 23.10.20.
//

#include "persistence_traits.h"

template<typename T>
static void persistence_traits<T>::read(ifstream &ifs, T &elem) {
        ifs >> elem;
}

template<typename T>
static void persistence_traits<T>::write(ofstream &ofs, const T &elem) {
        ofs << elem << endl;
}
