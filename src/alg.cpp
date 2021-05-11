// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template <typename T>
class TPQueue {
private:
    T* arr;
    int size;
    int begin, end;
    int count;

public:
    TPQueue();
    ~TPQueue();
    void push(const T&);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};

// конструктор по умолчанию
template <typename T>
TPQueue<T>::TPQueue()
    : size(100)
    , begin(0)
    , end(0)
    , count(0)
{
    arr = new T[size + 1];
}

// деструктор класса Queue
template <typename T>
TQueue<T>::~TQueue()
{
    delete[] arr;
}

// функция добавления элемента в очередь
template <typename T>
void TPQueue<T>::push(const T& item)
{
    assert(count < size);
    if (end != 0) {
        for (int i = end - 1; i > -1; --i) {
            if (arr[i].prior >= item.prior) {
                arr[i + 1] = item;
                continue;
            }
            if (arr[i].prior < item.prior) {
                arr[i + 1] = arr[i];
                if (i == 0)
                    arr[i] = item;
                continue;
            }
        }
    }
    else {
        arr[begin] = item;
    }
    count++;
    end++;
}

// функция удаления элемента из очереди
template <typename T>
T TQueue<T>::pop()
{
    // проверяем, есть ли в очереди элементы
    assert(count > 0);
    T item = arr[begin++];
    count--;
    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем begin на начало очереди
    return item;
}

// функция чтения элемента на первой позиции
template <typename T>
T TQueue<T>::get() const
{
    // проверяем, есть ли в очереди элементы
    assert(count > 0);
    return arr[begin];
}

// функция проверки очереди на пустоту
template <typename T>
bool TQueue<T>::isEmpty() const
{
    return count == 0;
}

// функция проверки очереди на заполненность
template <typename T>
bool TQueue<T>::isFull() const
{
    return count == size;
}

struct SYM {
    char ch;
    int prior;
};

#endif // INCLUDE_TPQUEUE_H_
