#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

const int INITIAL_SIZE = 1;

//===============INTERFACE===============//
template <class T>
class Queue
{
    public:
    Queue(int size = 0); //C'tor of Queue
    Queue(const Queue& queue); // Copy c'tor of Queue
    ~Queue(); //D'tor of Queue
    Queue& operator=(const Queue& queue); //Assignment operator of Queue

    /*
     * Adds a new node to the end of the queue.
     *
     * @param node - the node that is added.
     * @return 
     *      void
     */
    void pushBack(const T& node);

    /*
     * Returns the first node in the queue.
     *
     * @return 
     *      The first node in the queue
     */
    T& front();

    /*
     * Releases the first node in the queue.
     *
     * @return 
     *      void
     */
    void popFront();

    /*
     * Returns the size of the queue.
     *
     * @return 
     *      The size of the queue
     */
    const int size() const;

    /*
     * Iterator of queue.
     */
    class Iterator;
    class ConstIterator;

    Iterator begin();
    Iterator end();

    ConstIterator begin() const;
    ConstIterator end() const;

    class EmptyQueue //exceptions
    {
        EmptyQueue() = default;
    };

    private:
    T* m_data; //The array that contains the data of the queue
    int m_size; //The size of the queue
    int m_max_size; //The max size of the curret queue
    int m_front; //The index of the first node in the queue

    const int getFront() const; //returns the index of the first node
    const int getEnd() const; //returns the amount of nodes in data array
    const int getMaxSize() const; //return the max size
    T& getData(int index); //returns a reference to a node

};

/*
    * Filters a queue using a specific condition.
    *
    * @param queue - The queue to be filtered.
    * @param c - The condition to filter the queue with.  
    * @return 
    *      The filtered queue
    */
    template<class T, class Condition>
    Queue<T> filter(Queue<T> queue, Condition c);

    /*
    * Changed the nodes in the queue using a specific condition.
    *
    * @param queue - The queue to be filtered.
    * @param c - The condition to change the nodes with.  
    * @return 
    *      void
    */
    template<class T, class Condition>
    void transform(Queue<T> queue, Condition c);

//===============INTERFACE===============//

//=============IMPLEMENTATION=============//
template <class T>
Queue<T>::Queue(int size) : m_data(new T[size >= INITIAL_SIZE ? size : INITIAL_SIZE]), 
    m_size(size),
    m_max_size(size >= INITIAL_SIZE ? size : INITIAL_SIZE), 
    m_front(0) {}

template <class T>
Queue<T>::Queue(const Queue<T>& queue) : m_data(new T[queue.size()]),
    m_size(queue.size()), m_max_size(queue.size()),
    m_front(queue.getFront())
{
    for (int i = queue.getFront(); i < queue.getEnd(); i++)
    {
        m_data[i - queue.getFront()] = queue.m_data[i];
    }
}

template <class T>
Queue<T>::~Queue()
{
    delete[] m_data;
}

template <class T>
Queue<T>& Queue<T>:: operator=(const Queue<T>& queue) {
    if (this == &queue)
    {
        return *this;
    }

    delete[] m_data;
    m_data = new T[queue.size()];
    m_size = queue.size();
    m_max_size = queue.size();
    m_front = queue.getFront();

    for (int i = queue.getFront(); i < queue.getEnd(); i++)
    {
        m_data[i - queue.getFront()] = queue.m_data[i];
    }
}

template <class T>
void Queue<T>::pushBack(const T& node)
{
    if (this->getEnd() == this->getMaxSize())
    {
        T* temp = (new T[(this->size())*2]);
        for (int i = this->getFront(); i < this->getEnd(); i++)
        {
            temp[i - this->getFront()] = m_data[i];
        }
        delete[] m_data;
        m_max_size = (this->size())*2;
        try{
            m_data = new T[this->getMaxSize()];
        } catch (const std::bad_alloc&) {
            delete[] temp;
            throw;
        }
        for (int i = 0; i < this->size(); i++)
        {
            m_data[i] = temp[i];
        }
        delete[] temp;
    }
    m_data[this->size()] = node;
    m_size++;
}

template <class T>
T& Queue<T>::front()
{
    if (this->size() == 0)
    {
        throw EmptyQueue();
    }
    return m_data[this->getFront()];
}

template <class T>
void Queue<T>::popFront()
{
    if (this->size() == 0)
    {
        throw EmptyQueue();
    }
    m_front++;
}
template <class T>
const int Queue<T>::size() const
{
    return m_size - m_front;
}

template <class T>
const int Queue<T>::getFront() const
{
    return m_front;
} 

template <class T>
const int Queue<T>::getEnd() const
{
    return m_size;
}

template <class T>
const int Queue<T>::getMaxSize() const
{
    return m_max_size;
}

template <class T>
T& Queue<T>::getData(int index)
{
    return m_data[index];
}

//===============ITERATOR===============//

template <class T>
class Queue<T>::Iterator
{
    Queue<T>* m_queue;
    int m_index;
    Iterator(Queue<T>* queue, int index);
    friend class Queue<T>;

    public:
    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation //exceptions
    {
        InvalidOperation() = default;
    };
};

template<class T>
Queue<T>::Iterator::Iterator(Queue<T>* queue, int index) :
    m_queue(queue), m_index(index){}

template<class T>
const T& Queue<T>::Iterator::operator*() const
{
    return m_queue->m_data[m_index];
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if (m_index++ >= m_queue->getEnd())
    {
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
    if (m_index++ >= m_queue->getEnd())
    {
        throw InvalidOperation();
    }
    Iterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator& it) const
{
    return m_index == it.m_index;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    return !(*this == it);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Iterator(this, this->getFront());
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(this, this->getEnd());
}

//===============ITERATOR===============//

//===============CONST_ITERATOR===============//

template <class T>
class Queue<T>::ConstIterator
{
    const Queue<T>* m_queue;
    int m_index;
    ConstIterator(const Queue<T>* queue, int index);
    friend class Queue<T>;

    public:
    const T& operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    bool operator==(const ConstIterator& it) const;
    bool operator!=(const ConstIterator& it) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation //exceptions
    {
        InvalidOperation() = default;
    };
};

template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, int index) :
    m_queue(queue), m_index(index){}

template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return m_queue->m_data[m_index];
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if (m_index++ >= m_queue->getEnd())
    {
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{
    if (m_index++ >= m_queue->getEnd())
    {
        throw InvalidOperation();
    }
    Iterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& it) const
{
    return m_index == it.m_index;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const
{
    return !(*this == it);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(this, this->getFront());
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(this, this->getEnd());
}

//===============CONST_ITERATOR===============//
template<class T, class Condition>
Queue<T> filter(Queue<T> queue, Condition c)
{
    Queue<T> temp = queue;
    Queue<T> result = Queue<T>(queue.size());
    for (int i = 0; i < queue.size(); i++)
    {
        if (c(temp.front()))
        {
            result.pushBack(temp.front());
            temp.popFront();
        }
    }
    return result;
}

template<class T, class Condition>
void transform(Queue<T> queue, Condition c)
{
    Queue<T> temp = queue;
    for (int i = 0; i < queue.size(); i++)
    {
       queue.popFront();
    }
    for (int i = 0; i < queue.size(); i++)
    {
        c(temp.front());
       queue.pushBack(temp.front());
       temp.popFront();
    }
}
//=============IMPLEMENTATION=============//

#endif /* QUEUE_H */