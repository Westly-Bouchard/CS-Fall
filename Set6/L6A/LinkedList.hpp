#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class LinkedList final : public IList<T> {
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

private: 
    struct Node {
        T value;
        Node* pNext;
        Node* pPrev;
    };

    Node* _pHead;
    Node* _pTail;
    int _size;
};

//---------------------------------------------------------

template<typename T>
LinkedList<T>::LinkedList() {
  // set size to zero
    _size = 0;

    _pHead = nullptr;
    _pTail = nullptr;

  // set head to be a nullptr
  
  // set tail to be a nullptr
  
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // remove each node in the list
    while (_size > 0) {
        remove(_size);
    }
}

template<typename T>
int LinkedList<T>::size() const {
    return _size;
}

template<typename T>
T LinkedList<T>::get(const int POS) const {
    if (POS >= _size || POS < 0) throw std::out_of_range("Index out of range");

    Node* temp = _pHead;
    int counter = 0;
    while (counter < POS) {
        temp = temp->pNext;
        counter++;
    }

    return (*temp).value;
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
    if (POS >= _size || POS < 0) throw std::out_of_range("Index out of range");

    Node* temp = _pHead;
    int counter = 0;
    while (counter < POS) {
        temp = temp->pNext;
        counter++;
    }

    temp->value = VALUE;
  
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    int posActual = POS;
    if (posActual > _size) posActual = _size;
    if (posActual < 0) posActual = 0;

    Node* node = new Node();
    node->value = VALUE;

    node->pNext = nullptr;
    node->pPrev =  nullptr;

    if (_size == 0) {
        _pHead = node;
        _pTail = node;
    } else {
        if (posActual == 0) {
            node->pNext = _pHead;
            _pHead->pPrev = node;
            _pHead = node;
        } else if (posActual == _size) {
            node->pPrev = _pTail;
            _pTail->pNext = node;
            _pTail = node;
        } else {
            Node* temp = _pHead;
            int counter = 0;
            while (counter < posActual - 1) {
                temp = temp->pNext;
                counter++;
            }

            temp->pNext->pPrev = node;
            node->pNext = temp->pNext;

            node->pPrev = temp;
            temp->pNext = node;
        }
    }

    _size++;
}

template<typename T>
void LinkedList<T>::remove(const int POS) {
    if (_size == 0) throw std::out_of_range("List is empty");

    int posActual = POS;
    if (posActual < 0) posActual = 0;
    if (posActual >= _size) posActual = _size - 1;

    Node* toDelete = nullptr;

    if (_size == 1) {
        toDelete = _pHead;
    } else {
        if (posActual == 0) {
            toDelete = _pHead;
            _pHead = _pHead->pNext;
            _pHead->pPrev = nullptr;
        } else if (posActual == _size - 1) {
            toDelete = _pTail;
            _pTail = _pTail->pPrev;
            _pTail->pNext = nullptr;
        } else {
            Node* temp = _pHead;
            int counter = 0;
            while (counter < posActual - 1) {
                temp = temp->pNext;
                counter++;
            }

            toDelete = temp->pNext;
            temp->pNext = toDelete->pNext;
            toDelete->pNext->pPrev = temp;
        }
    }

    delete toDelete;
    _size--;
}

template<typename T>
T LinkedList<T>::min() const {
    // if list is empty, throw std::out_of_range exception
    
    // find minimum value within list
    
    // return min value

    if (_size == 0) throw std::out_of_range("List is empty");

    T min = _pHead->value;

    Node* currNode = _pHead;

    while (currNode->pNext != nullptr) {
        currNode = currNode->pNext;
        if (currNode->value < min) min = currNode->value;
    }

    return min;

}

template<typename T>
T LinkedList<T>::max() const {
    // if list is empty, throw std::out_of_range exception
    
    // find maxiumum value within list
    
    // return max value

    if (_size == 0) throw std::out_of_range("List is empty");

    T max = _pHead->value;

    Node* currNode = _pHead;

    while (currNode->pNext != nullptr) {
        currNode = currNode->pNext;
        if (currNode->value > max) max = currNode->value;
    }

    return max;
}

template<typename T>
int LinkedList<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    
    // return index of first occurrence if found
    
    // otherwise return -1

    if (_size == 0) return -1;

    Node* currNode = _pHead;
    int counter = 0;

    while (currNode) {
        if (currNode->value == VALUE) return counter;
        currNode = currNode->pNext;
        counter++;
    }

    return -1;
}

#endif //LINKED_LIST_HPP
