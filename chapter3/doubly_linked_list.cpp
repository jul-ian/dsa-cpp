template <typename D>
class DNode {
private:
    D elem;
    DNode<D> *prev;
    DNode<D> *next;
    template <typename E>
    friend class DLinkedList;
};

template <typename T>
class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const T &front() const;
    const T &back() const;
    void add_front(const E &e);
    void add_back(const E &e);
    void remove_front();
    void remove_back();
private:
    DNode<T> *header;
    DNode<T> *trailer;
protected:
    void add(DNode<T> v, const E &e);
    void remove(DNode<T> *v);
};