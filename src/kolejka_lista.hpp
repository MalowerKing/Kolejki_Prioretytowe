#include <iostream>

template<typename T>
class KolejkaLista {
        public:
                void addQueque(T data, int priority){
                       Node* newNode = new Node;
                        newNode->priority = priority;
                        newNode->data = data;

                        if(isEmptyQueque()){
                                newNode->next = NULL;
                                head = newNode;
                                return;
                        }
                       
                        if(priority < head->priority) {
                                newNode->next = head;
                                head = newNode;
                                return;
                        }

                        Node* temp = head;
                        while(temp->next && (priority > temp->next->priority)){
                                temp = temp->next;
                        }

                        newNode->next = temp->next;
                        temp->next = newNode;
                }

                void removeQueque() {
                        if (!head) return;
                        Node* toRemove = head;
                        head = head->next;
                        delete toRemove;
                }

                int sizeQueque() {
                        int size = 0;
                        Node* temp = head;
                        while(temp) {
                                size++;
                                temp = temp->next;
                        }
                        return size;
                }
 
                T peekQueque() {
                        return head->data;
                }

                bool isEmptyQueque() {if(!head) return true; else return false;}

                void modifyPriority(int from, int to, T data) {
                        if (!head) return;
                    
                        Node* prev = nullptr;
                        Node* current = head;
                    
                        // Find the node to modify
                        while (current && !(current->priority == from && current->data == data)) {
                            prev = current;
                            current = current->next;
                        }
                    
                        if (!current) return; // Node not found
                    
                        // Remove current node
                        if (prev) {
                            prev->next = current->next;
                        } else {
                            head = current->next;
                        }
                    
                        current->priority = to;
                    
                        // Reinsert with new priority
                        if (!head || to < head->priority) {
                            current->next = head;
                            head = current;
                            return;
                        }
                    
                        Node* temp = head;
                        while (temp->next && temp->next->priority <= to) {
                            temp = temp->next;
                        }
                    
                        current->next = temp->next;
                        temp->next = current;
                    }
                    
                    
                    void debugShowList(){
                        Node* temp = head;
                        int size = 0;
                        while (temp) {
                            std::cout << "[" << temp->data << "] Priority: " << temp->priority;
                            if (temp->next) std::cout << " --> ";
                            temp = temp->next;
                            size++;
                            if(size%5 == 0) std::cout << std::endl;
                        }
                        std::cout << std::endl;
                    }                    

        private:
                struct Node {
                        int priority;
                        T data;
                        Node* next;
                };

                Node* head = NULL;
};
