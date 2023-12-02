#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

#include "List.hpp"

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
    void sort() override;
    int search(const T VALUE) const override;

private:
    int _size;
    T* _pArray;

    void mergeSort(int begin, int end);
    void merge(const int left, const int middle, const int right);

    int binarySearch(const int begin, const int end, const T VALUE) const;
};

//---------------------------------------------------------

template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    // set array to be a nullptr
    _pArray = nullptr;
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

template<typename T>
void Array<T>::mergeSort(const int begin, const int end) {
    if (begin < end) {
        const int middle = begin + (end - begin) / 2;

        mergeSort(begin, middle);
        mergeSort(middle + 1, end);

        merge(begin, middle, end);
    }
}

template<typename T>
void Array<T>::merge(const int left, const int middle, const int right) {
    const int subLen1 = middle - left + 1;
    const int subLen2 = right - middle;

    T* sub1 = new T[subLen1];
    T* sub2 = new T[subLen2];

    for (int i = 0; i < subLen1; i++) {
        sub1[i] = this->get(left + i);
    }

    for (int i = 0; i < subLen2; i++) {
        sub2[i] = this->get(middle + 1 + i);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < subLen1 && j < subLen2) {
        if (sub1[i] <= sub2[j]) {
            this->set(k, sub1[i]);
            i++;
        } else {
            this->set(k, sub2[j]);
            j++;
        }
        k++;
    }

    while (i < subLen1) {
        this->set(k, sub1[i]);
        i++;
        k++;
    }

    while (j < subLen2) {
        this->set(k, sub2[j]);
        j++;
        k++;
    }

    delete[] sub1;
    delete[] sub2;
}

template<typename T>
void Array<T>::sort() {
    cout << "Sorting an array:" << endl;

    cout << "Initial array: ";

    for (int i = 0; i < _size; i++) { cout << this->get(i) << " "; }

    mergeSort(0, _size - 1);

    cout << endl << "Sorted array: ";

    for (int i = 0; i < _size; i++) { cout << this->get(i) << " "; }

    cout << endl;
}

template<typename T>
int Array<T>::binarySearch(const int begin, const int end, const T VALUE) const {
    if (begin < end) {
        const int middle = begin + (end - begin) / 2;

        T val = this->get(middle);

        if (val == VALUE) return middle;

        if (val > VALUE) return binarySearch(begin, middle, VALUE);

        if (val < VALUE) return binarySearch(middle + 1, end, VALUE);
    }

    return -1;
}

template<typename T>
int Array<T>::search(const T VALUE) const {
    return binarySearch(0, _size, VALUE);
}

#endif //ARRAY_HPP