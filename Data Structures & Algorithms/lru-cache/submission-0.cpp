struct Node {
    int key;
    int val;
    Node * next;
    Node * prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {  
private:
    int cap;
    int size; 
    Node* head;
    Node* tail;
    unordered_map<int, Node*> table;

    // insert at the front
    void insert_front(Node * node_to_insert) {
        node_to_insert->next = head->next;
        node_to_insert->next->prev = node_to_insert;
        node_to_insert->prev = head;
        head->next = node_to_insert;
    }

    // helper function for pop_back and for moving stuff to front in general
    void detach(Node * node_to_detach) {
        node_to_detach->prev->next = node_to_detach->next;
        node_to_detach->next->prev = node_to_detach->prev;
    }

    // remove and return LRU node (node before tail) (O(1))
    Node* pop_back() {
        Node* lru = tail->prev;
        if (lru == head) {
            return nullptr; // no real nodes
        }
        detach(lru);
        return lru;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (table.count(key)) {
            detach(table[key]); // mark it as used/ move it to the front
            insert_front(table[key]);
            return table[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // CASE 1: key already exists — update value and move to front
        if (table.count(key)) {
            table[key]->val = value;         // update value
            detach(table[key]);              // remove from current position
            insert_front(table[key]);        // move to front (mark as MRU)
            return;
        }

        // CASE 2: inserting a new key
        // if cache is full, evict the least recently used node (at the back)
        if (size == cap) {
            Node* victim = pop_back();     // get LRU node (just before tail)
            if (victim) {
                table.erase(victim->key);  // remove from hash table
                delete victim;             // free memory
                --size;                   // update count
            }
        }

        // insert the new node at the front (MRU position)
        Node* node_to_insert = new Node(key, value);
        insert_front(node_to_insert);      // attach to DLL
        table[key] = node_to_insert;       // map key to node
        ++size;                           // increase size
    }
};


// jp morgan assesment haha

// vector<string> result
// for (const auto& line : text) {
//     stringstream iss(sent[i])
//     vector<string> words
//     string word = ""
//     while (iss >> word) {
//         words.push_back(word)
//     }

//     // so now you have all of the seperate words in a vector
//     if (words[0] = '#') {
//         chapter++
//         section = 0
//         rest = ""
//         for (int i=1, i < words.size(); i++) {
//             rest += " " + words[i]
//         }
//         result.push_back(stoi(chapter) + "." + rest)        
//     }

//         if (words[0] = '##') {
//         section++
//         rest = ""
//         for (int i=1, i < words.size(); i++) {
//             rest += " " + words[i]
//         }
//         result.push_back(stoi(chapter) + "." + stoi(section) + "." + rest)        
//     }
// }
// return result