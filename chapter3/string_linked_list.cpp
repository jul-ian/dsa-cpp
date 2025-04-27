class StringNode {
private:
    string elem;
    StringNode *next;

friend class StringLinkedList;
}

class StringLinkedList {
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const string &front() const;
    void add_front(const string &e);
    void remove_front();
private:
    StringNode *head;
}

StringLinkedList::StringLinkedList(): head(NULL) {}

StringLinkedList::~StringLinkedList() {
    while(!empty()) {
        remove_front();
    }
}

bool StringLinkedList::empty() const {
    return head == NULL;
}

const string &StringLinkedList::front() const {
    return head->elem;
}

void StringLinkedList::add_front(const string &e) {
    StringNode *add_node = new StringNode;
    add_node->elem = e;
    add_node->next = head;
    head = add_node;
}

void remove_front() {
    if(empty()) {
        return;
    }
    StringNode *current_head = head;
    head = current_head->next;
    delete current_head;
}