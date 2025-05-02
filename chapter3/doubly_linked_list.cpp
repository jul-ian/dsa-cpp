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
    void add_front(const T &e);
    void add_back(const T &e);
    void remove_front();
    void remove_back();
private:
    DNode<T> *header;
    DNode<T> *trailer;
protected:
    void add(DNode<T> v, const T &e);
    void remove(DNode<T> *v);
};

template <typename T>
DLinkedList<T>::DLinkedList() {
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
}

template <typename T>
DLinkedList<T>::~DLinkedList() {
    while(!empty()) {
        remove_front();
    }
    delete header;
    delete trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const {
    return (header->next == trailer);
}

template <typename T>
const T &DLinkedList<T>::front() const {
    return header->next->elem;
}

template <typename T>
const T &DLinkedList<T>::back() const {
    return trailer->prev->elem;
}

template <typename T>
void DLinkedList<T>::add(DNode<T> *v, const T &e) {
    DNode<T> *u = new DNode<T>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template <typename T>
void DLinkedList<T>::add_front(const T &e) {
    add(header->next, e);
}

template <typename T>
void DLinkedList<T>::add_back(const T &e) {
    add(trailer, e);
}

template <typename T>
void DLinkedList<T>::remove(DNode<T> *v) {
    DNode<T> *u = v->prev;
    DNode<T> *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <typename T>
void DLinkedList<T>::remove_front() {
    remove(header->next);
}

template <typename T>
void DLinkedList<T>::remove_back() {
    remove(trailer->prev);
}