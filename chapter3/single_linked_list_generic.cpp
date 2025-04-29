template <typename E>
class SNode {
private:
    E elem;
    SNode<E> *next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E &front() const;
    void add_front(const E &e);
    void remove_front();
private:
    SNode<E> *head;
};

template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E &SLinkedList<E>::front() const {
    return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while(!empty()) {
        remove_front();
    }
}

template <typename E>
void SLinkedList<E>::add_front(const E &e) {
    SNode<E> *add_node = new SNode<E>;
    add_node->elem = e;
    add_node->next = head;
    head = add_node;
}

template <typename E>
void SLinkedList<E>::remove_front() {
    SNode<E> *current_head = head;
    head = current_head->next;
    delete current_head;
}