#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <list>

using namespace std;

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

private:
    int _size;
    T* _pArray;
};

//---------------------------------------------------------

template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    // set array to be a nullptr
    _pArray = nullptr;
    std::list<int> arr;
}

template<typename T>
Array<T>::~Array() {
    // deallocate current array
    delete[] _pArray;
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if (POS >= _size || POS < 0) throw std::out_of_range("Index out of range"); 
    // return value at POS within array
    return _pArray[POS];
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if (POS >= _size || POS < 0) throw std::out_of_range("Index out of range");
    // set VALUE at POS within array    
    _pArray[POS] = VALUE;
}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    int posActual = POS;
    if (posActual > _size) posActual = _size;
    if (posActual < 0) posActual = 0;

    T* temp = new T[++_size];

    for (int i = 0; i < posActual; i++) temp[i] = _pArray[i];

    temp[posActual] = VALUE;

    for (int i = posActual + 1; i < _size; i++) temp[i] = _pArray[i - 1];

    delete[] _pArray;
    _pArray = temp;
}

template<typename T>
void Array<T>::remove(const int POS) {
    if (_size == 0) throw std::out_of_range("Array is empty");

    int posActual = POS;
    if (POS < 0) posActual = 0;
    if (POS >= _size) posActual = _size - 1;

    T* temp = new T[--_size];

    for (int i = 0; i < posActual; i++) temp[i] = _pArray[i];
    for (int i = posActual + 1; i < _size + 1; i++) temp[i - 1] = _pArray[i];

    delete[] _pArray;
    _pArray = temp;
}

template<typename T>
T Array<T>::min() const {
    if (_size == 0) throw std::out_of_range("Array is empty");

    T min = _pArray[0];

    for (int i = 0; i < _size; i++) if (_pArray[i] < min) min = _pArray[i];

    return min;
}

template<typename T>
T Array<T>::max() const {
    if (_size == 0) throw std::out_of_range("Array is empty");

    T max = _pArray[0];

    for (int i = 0; i < _size; i++) if (_pArray[i] > max) max = _pArray[i];

    return max;
}

template<typename T>
int Array<T>::find(const T VALUE) const {
    for (int i = 0; i < _size; i++) if (_pArray[i] == VALUE) return i;

    return -1;
}

#endif//ARRAY_HPP