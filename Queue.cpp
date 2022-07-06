#include "Queue.h"


template<class T>
Queue<T>::Queue(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    size = 0;
    max_size = max;
    front = 0;
    rear = front - 1;
    items = new T[max];
}

template<class T>
Queue<T>::Queue()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    size = 0;
    max_size = 500;
    front = 0;
    rear = front - 1;
    items = new T[max_size];
}

template<class T>
Queue<T>::~Queue()         // Class destructor
{
    delete[] items;
}

template<class T>
void Queue<T>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = 0;
    rear = front + 1;
    size = 0;
}

template<class T>
bool Queue<T>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return size == 0;
}

template<class T>
bool Queue<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return false;
}

template<class T>
void Queue<T>::Enqueue(T newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.

    if (isFull()){
        throw FullQueue;
    }
{
    items[rear] = newItem;
    rear == (rear + 1) % max_size; //wraps to the front

    size++;
}

template<class T>
T Queue<T>::Dequeue()
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       otherwise a EmptyQueue exception has been thrown.
{
    T itemToReturn = items[front]; //whatever is at the front
    front = (front + 1) % max_size; //wrap around
    return itemToReturn;
    size--;
}
