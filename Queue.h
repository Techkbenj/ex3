#include <iostream>

const int INITIAL_SIZE = 1;

template <class T>
class Queue
{
    public:
    Queue();
    Queue(const T& queue);
    ~Queue();
    Queue& operator=(const Queue& queue);

    void pushBack(const T& node);
    T& front();
    void popFront();
    const int size() const;

    class Iterator;

    Iterator begin();
    Iterator end();

    class EmptyQueue{};
    class InvalidOperation{};

    private:
    T* m_data; //The array that contains the data of the queue
    int m_size; //The size of the queue
    int m_max_size; //The max size of the curret queue
    static int m_front; //The index of the first node in the queue

    const int getFront() const; 
    const int getMaxSize() const;

};

template <class T>
Queue<T>::Queue() : m_data(new T[INITIAL_SIZE]), m_size = 0, 
    m_max_size = INITIAL_SIZE, m_front = 0 {}
    
template <class T>
Queue<T>::Queue(const T& queue) : m_data(new T[queue.size()]),
    m_size(queue.size()), m_max_size(queue.size(),
    m_front = queue.getFront())
{
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = queue.m_data[i];
    }
}

template <class T>
Queue<T>::~Queue()
{
    delete[] m_data;
}

template <class T>
Queue<T>& Queue<T>:: operator=(const Queue<T>&)
{
    if(this == &queue)
    {
        return *this;
    }

delete[] m_data;
m_data = new T[queue.size()];
m_size = queue.size();
m_max_size = queue.size();
m_front = queue.getFront();

for (int i = 0; i < m_size; i++)
    {
        m_data[i] = queue.m_data[i];
    }
}

template <class T>
void Queue<T>::pushBack(const T& node)
{
    if (this.size == this.getMaxSize)
    {
        T* temp = (new T[(this.size)*2]);
        for (int i = this.getFront; i < this.size; i++)
        {
            temp[i - this.getFront] = m_data[i]
        }
        delete[] m_data;
        m_max_size = (this.size)*2;
        m_data = new T(this.getMaxSize);
        for (int i = 0; i < this.size; i++)
        {
            m_data[i] = temp[i]
        }
        delete[] temp;
        m_data[this.size] = node;
    }
    else
    {
        m_data[this.size] = node;
        size++;
    }
}

template <class T>
T& Queue<T>::front()
{
    return &m_data[this.getFront];
}

template <class T>
void Queue<T>::popFront()
{
    m_front++;
}
template <class T>
const int Queue<T>::size() const
{
    return m_size;
}

template <class T>
const int Queue<T>::getFront() const
{
    return m_front;
} 

template <class T>
const int Queue<T>::getMaxSize() const
{
    return m_max_size;
}

template <class T>
Queue<T>::Iterator Queue<T>::begin() const
{
    return Iterator(this, 0);
}

template <class T>
Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(this, m_size);
}

template <class T>
class Queue<T>::Iterator
{
    const Queue<T>* m_queue;
    int m_index;
    Iterator(const Queue<T>* queue, int index);
    friend class Queue<T>;

    public:
    const int& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
};

template<T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, int index) :
    m_queue(queue), m_index(index){}

template<T>
const int& Queue<T>::Iterator::operator*() const
{
    m_queue->m_data[m_index];
}

template<T>
Iterator& Queue<T>::Iterator::operator++()
{
    ++m_index;
    return *this;
}

template<T>
Iterator Queue<T>::Iterator::operator++(int)
{
    Iterator result = *this;
    ++*this;
    return result;
}

template<T>
bool Queue<T>::Iterator::operator==(const Iterator& it) const
{
    return m_index == it.m_index;
}

template<T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    return !(*this == it)
}