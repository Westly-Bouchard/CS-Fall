#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <iostream>

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
    void sort() override;
    int search(const T VALUE) const override;

private:
    struct Node {
        T value;
        Node* pNext;
        Node* pPrev;
    };

    Node* _pHead;
    Node* _pTail;
    int _size;

    void mergeSort(int begin, int end);
    void merge(const int left, const int middle, const int right);
};

//---------------------------------------------------------

template<typename T>
LinkedList<T>::LinkedList() {
    _size = 0;

    _pHead = nullptr;
    _pTail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
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

template<typename T>
void LinkedList<T>::mergeSort(const int begin, const int end) {
    if (begin < end) {
        const int middle = begin + (end - begin) / 2;

        mergeSort(begin, middle);
        mergeSort(middle + 1, end);

        merge(begin, middle, end);
    }
}

template<typename T>
void LinkedList<T>::merge(const int left, const int middle, const int right) {
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
void LinkedList<T>::sort() {
    cout << "Sorting a Linked List:" << endl;

    cout << "Initial list: ";

    for (int i = 0; i < _size; i++) { cout << this->get(i) << " "; }

    mergeSort(0, _size - 1);

    cout << endl << "Sorted list: ";

    for (int i = 0; i < _size; i++) { cout << this->get(i) << " "; }

    cout << endl;
}

template<typename T>
int LinkedList<T>::search(const T VALUE) const {
    Node* currNode = _pHead;
    int counter = 0;

    while (currNode) {
        if (currNode->value == VALUE) {
            return counter;
        }

        currNode = currNode->pNext;
        counter++;
    }

    return -1;
}

#endif //LINKED_LIST_HPP
