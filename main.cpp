/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 15, 2018, 2:53 PM
 */

#include <iostream>
#include <array>

using namespace std;

template<typename T>
T square(T val) {
    return val*val;
}

template<typename T>
class Vect {
private:
    T m_array[1000];
    int m_size = 0;
public:

    Vect() : m_size{0}
    {
    }

    void pushBack(T var) {
        m_array[m_size] = var;
        ++m_size;
    }

    T get(int i) {
        return m_array[i];
    }

    int getSize() const {
        return m_size;
    }

    void printElements() {
        for (int i = 0; i < m_size; ++i) {
            cout << m_array[i] << '\n';
        }
    }

    T operator[](int i) {
        return get(i);
    }

};

template<typename T>
Vect<T> operator*(Vect<T>& fVec, Vect<T>& sVec) {
    Vect<T> resVec;
    for (int i = 0; i < fVec.getSize(); ++i) {
        resVec.pushBack(fVec[i] * sVec[i]);
    }

    return resVec;
}

int main(int argc, char** argv) {

    Vect<int> vect;
    vect.pushBack(10);
    vect.pushBack(20);
    vect.pushBack(30);
    vect.pushBack(40);
    vect.pushBack(50);
    vect.pushBack(60);

    vect.printElements();

    vect = square(vect);

    vect = vect*vect;

    vect.printElements();

    return 0;
}

