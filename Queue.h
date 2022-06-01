#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <iostream>

template <class T>
class Queue
{
<<<<<<< HEAD
    template <class S>
    class Node
    {
        S* m_firstNode;
        Node<S>* m_nextNode;

    public:
        Node() {m_firstNode = new S(); m_nextNode = nullptr;};
        Node(const S& first) {m_firstNode = new S(first); m_nextNode = nullptr;};
        Node(const Node& node) {m_firstNode = new S(node.m_firstNode); m_nextNode = node.m_nextNode;};
        ~Node() {delete m_firstNode;};
        Node& operator=(const Node& node)
        {
            if (this == &node)
            {
                return *this;
            }
            S* temp = m_firstNode;
            Node<S>* tempNext = m_nextNode;
            m_firstNode = node.m_firstNode;
            m_nextNode = node.m_nextNode;
            delete temp;
            delete tempNext;
            return *this;
        };
        S& getS() {return *m_firstNode;};

        void setNext(Node<S>* node)
        {
            m_nextNode = node;
        };

        Node<T>* next() {return m_nextNode;};

        void add(const S& next)
        {
            Node<S>* temp = new Node<S>(next);
            m_nextNode = temp;
        };
    };
    int m_size;
    Node<T>* m_PointerToFirstNode;
    Node<T>* m_PointerToLastNode;

public:
    Queue();
    Queue(const Queue& queue);
    ~Queue();
    Queue& operator=(const Queue& queue);

    void pushBack(const T& val);
    T& front() const;
    void popFront();
    int size() const;

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    class EmptyQueue{};

};
//------------------------Iterator class--------------------//
template <class T>
class Queue<T>::Iterator
{
    const Queue<T>* m_queue;
    int index;
    Iterator(const Queue<T>* queue, int otherIndex);
    friend class Queue<T>;
public:
    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation{};
};

template <class T>
typename Queue<T>::Iterator Queue<T>::begin()
=======
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

    T& front() const;

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
    void transform(Queue<T>& queue, Condition c);

//===============INTERFACE===============//

//=============IMPLEMENTATION=============//
template <class T>
Queue<T>::Queue(int size) : m_data(new T[size >= INITIAL_SIZE ? size : INITIAL_SIZE]), 
    m_size(0),
    m_max_size(size >= INITIAL_SIZE ? size : INITIAL_SIZE), 
    m_front(0) {}

template <class T>
Queue<T>::Queue(const Queue<T>& queue) : m_data(new T[queue.size()]),
    m_size(queue.size()), m_max_size(queue.size()),
    m_front(queue.getFront())
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
{
    return Iterator(this, 0);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(this, m_size);
}

template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, int otherIndex) : m_queue(queue), index(otherIndex) {}

template <class T>
T &Queue<T>::Iterator::operator*() const
{
    if (index == m_queue->m_size)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    Node<T>* temp = m_queue->m_PointerToFirstNode;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next();
    }
<<<<<<< HEAD
    return temp->getS();
=======
    return *this;
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
<<<<<<< HEAD
    if (index == m_queue->m_size)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    index++;
    return *this;
=======
    if (this->getEnd() == this->getMaxSize())
    {
        T* temp = (new T[(this->size())*2]);
        for (int i = this->getFront(); i < this->getEnd(); i++)
        {
            temp[i - this->getFront()] = m_data[i];
        }
        delete[] m_data;
        m_max_size = (this->size())*2;
        m_size -= m_front;
        m_data = temp;
        m_front = 0;
    }
    m_data[(this->size()) + this->getFront()] = node;
    m_size++;
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator &it) const
{
<<<<<<< HEAD
    return index != it.index;
=======
    if (this->size() == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_data[this->getFront()];
}

template <class T>
T& Queue<T>::front() const
{
    if (this->size() == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_data[this->getFront()];
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
}
//----------------------End of Iterator class---------------------//

//----------------------Const Iterator class----------------------//
template <class T>
class Queue<T>::ConstIterator
{
<<<<<<< HEAD
    const Queue<T>* m_queue;
    int index;
    ConstIterator(const Queue<T>* queue, int otherIndex);
    friend class Queue<T>;
public:
    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator& it) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation{};
};

=======
    if (this->size() == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    m_front++;
}
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(this, 0);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(this, m_size);
}

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, int otherIndex) : m_queue(queue), index(otherIndex) {}

template <class T>
const T &Queue<T>::ConstIterator::operator*() const
{
    if (index == m_queue->m_size)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    Node<T>* temp = m_queue->m_PointerToFirstNode;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next();
    }
    return temp->getS();
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if (index == m_queue->m_size)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    index++;
    return *this;
}

<<<<<<< HEAD
=======
//===============ITERATOR===============//
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &it) const
{
<<<<<<< HEAD
    return index != it.index;
}
//---------------------End of ConstIterator----------------------//

//----------------------Implementation of Queue------------------//
template <class T>
Queue<T>::Queue() :  m_size(0), m_PointerToFirstNode(nullptr),
                     m_PointerToLastNode(nullptr) {}

template <class T>
Queue<T>::Queue(const Queue<T>& queue)
{
    m_PointerToFirstNode = new Node<T>(queue.m_PointerToFirstNode->getS());
    Node<T>* runsOnThis = m_PointerToFirstNode;
    Node<T>* runsOnQueue;
    Node<T>* temp;
    runsOnQueue = queue.m_PointerToFirstNode->next();
    while (runsOnQueue != nullptr)
    {
        try
        {
            temp = new Node<T>(runsOnQueue->getS());
        }
        catch (const std::bad_alloc&)
        {
            Node<T>* tempDelete = m_PointerToFirstNode;
            Node<T>* tempNext;
            while (tempDelete != nullptr)
            {
                tempNext = tempDelete->next();
                delete tempDelete;
                tempDelete = tempNext;
            }
            throw;
        }
        runsOnThis->setNext(temp);
        runsOnThis = runsOnThis->next();
        runsOnQueue = runsOnQueue->next();
    }
    m_PointerToLastNode = runsOnThis;
    m_size = queue.m_size;
=======
    Queue<T>* m_queue;
    int m_index;
    Iterator(Queue<T>* queue, int index);
    friend class Queue<T>;

    public:
    T& operator*() const;
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
T& Queue<T>::Iterator::operator*() const
{
    if (m_index >= m_queue->getEnd())
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    return m_queue->m_data[m_index];
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &queue)
{
<<<<<<< HEAD
    if (this == &queue)
    {
        return *this;
    }
    Node<T>* tempDel = m_PointerToFirstNode;
    Node<T>* temp = tempDel;
    m_PointerToFirstNode = new Node<T>(queue.m_PointerToFirstNode->getS());
    Node<T> *runsOnThis = m_PointerToFirstNode;
    Node<T> *runsOnQueue;
    try
    {
        runsOnQueue = queue.m_PointerToFirstNode->next();
        while (runsOnQueue != nullptr)
        {
            temp = new Node<T>(runsOnQueue->getS());
            runsOnThis->setNext(temp);
            runsOnThis = runsOnThis->next();
            runsOnQueue = runsOnQueue->next();
        }
        m_PointerToLastNode = runsOnThis;
        temp = tempDel;
        while (tempDel != nullptr) {
            temp = tempDel->next();
            delete tempDel;
            tempDel = temp;
        }
    }
    catch (const std::bad_alloc&)
    {
        runsOnThis = m_PointerToFirstNode;
        while (runsOnThis != nullptr)
        {
            temp = runsOnThis->next();
            delete runsOnThis;
            runsOnThis = temp;
        }
        m_PointerToFirstNode = tempDel;
        throw;
    }
    m_size = queue.m_size;
=======
    if (m_index >= m_queue->getEnd())
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    ++m_index;
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
    return *this;
}

template <class T>
Queue<T>::~Queue()
{
    Node<T>* temp = m_PointerToFirstNode;
    Node<T>* tempNext = temp;
    while (temp != nullptr)
    {
        tempNext = temp->next();
        delete temp;
        temp = tempNext;
    }
    m_PointerToFirstNode = nullptr;
    m_PointerToLastNode = nullptr;
}

template <class T>
void Queue<T>::pushBack(const T& val)
{
    if (m_PointerToLastNode == nullptr)
    {
        Node<T> *temp = new Node<T>(val);
        m_PointerToFirstNode = temp;
        m_PointerToLastNode = temp;
    }
    else
    {
        m_PointerToLastNode->add(val);
        m_PointerToLastNode = m_PointerToLastNode->next();
    }
    m_size++;
}

template <class T>
T& Queue<T>::front() const
{
    if (m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_PointerToFirstNode->getS();
}

template <class T>
<<<<<<< HEAD
void Queue<T>::popFront()
{
    if (m_size == 0)
    {
        throw Queue<T>::EmptyQueue();
    }
    if (m_size == 1)
    {
        delete m_PointerToFirstNode;
        m_PointerToFirstNode = nullptr;
        m_PointerToLastNode = nullptr;
    }
    else
    {
        Node<T> *temp = m_PointerToFirstNode;
        m_PointerToFirstNode = m_PointerToFirstNode->next();
        delete temp;
    }
    m_size--;
}

template <class T>
int Queue<T>::size() const
{
    return m_size;
}

template <class T, class Condition>
Queue<T> filter(const Queue<T>& queue, Condition c)
{
    Queue<T> temp;
    for (const T& org : queue)
    {
        if (c(org))
        {
            temp.pushBack(org);
=======
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
    if (m_index >= m_queue->getEnd())
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    return m_queue->m_data[m_index];
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if (m_index >= m_queue->getEnd())
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    ++m_index;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{
    ConstIterator result = *this;
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
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
        }
        temp.popFront();
    }
<<<<<<< HEAD
    return temp;
}

template <class T, class Changing>
void transform(Queue<T>& queue, Changing c)
{
    for (T& org : queue)
    {
        c(org);
=======
    return result;
}

template<class T, class Condition>
void transform(Queue<T>& queue, Condition c)
{
    Queue<T> temp = queue;
    int sizeOfQueue = queue.size();
    for (int i = 0; i < sizeOfQueue; i++)
    {
       queue.popFront();
    }
    for (int i = 0; i < sizeOfQueue; i++)
    {
       c(temp.front());
       queue.pushBack(temp.front());
       temp.popFront();
>>>>>>> 0d8afb62e5648218437469511f7260631d8f9a47
    }
    
}

#endif // MY_QUEUE_H
