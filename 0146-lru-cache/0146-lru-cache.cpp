#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    int cap;

    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void addNode(Node* node) {
        Node* n = head->next;
        head->next = node;
        node->prev = head;
        node->next = n;
        n->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        Node* node = m[key];
        deleteNode(node);
        addNode(node); 
        return node->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            deleteNode(node);
            m.erase(key);
        }

        if (m.size() == cap) {
            Node* lru = tail->prev;
            deleteNode(lru);
            m.erase(lru->key);
        }

        Node* node = new Node(key, value);
        addNode(node);
        m[key] = node;
    }
};
