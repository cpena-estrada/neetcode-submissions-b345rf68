#include <climits> 

struct Node{
    int value;
    Node * next;
};

class MinStack {
private:
    Node * head;

public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        //case: stack is empty
        if(head == nullptr){
            //create the node
            Node * new_node = new Node;
            new_node->value = val;
            head = new_node;

        //case: stack isn't empty
        }else{
            Node * new_node = new Node;
            new_node->value = val;
            new_node->next = head;
            head = new_node;
        }
    }
    
    void pop() {
        //case: stack is empty (nothing to pop)
        if(head==nullptr){
            //nothing
        //case: stack isn't empty
        }else{
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        
    }
    
    int top() {
        if(head != nullptr){
            return head->value;
        }
        return -1;
    }
    
    int getMin() {
        int min = INT_MAX;

        Node * temp = head;
        while(temp != nullptr){
            if(temp->value < min){
                min = temp->value;
                temp = temp->next;
            }else{
                temp = temp->next;
            }
        }
        return min;
    }
};
