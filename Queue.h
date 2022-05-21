template <class T>
class Queue
{
    public:
    Queue();
    Queue(const T& queue);
    ~Queue();
    Queue& operator=(const Queue&);

    void pushBack(const T node);
    T& front();
    void popFront();
    int size();

    class EmptyQueue{};
    class InvalidOperation{};

    private:
    T m_node;
    static int m_size;
    T* m_nextNode;
    T* m_prevNode;
};

template <class T>
Queue<T>::Queue() : m_node = NULL, m_size = 0, m_nextNode = NULL, 
    m_prevNode = NULL {}

//template <class T>
//Queue<T>::Queue(const Queue<T>& queue){}
