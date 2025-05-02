#include <iostream>

template<typename T>
class KolejkaHeap {
public:
        void addQueque(T data, int priority) {
                size++;

                if(size > arraySize) { increaseArraySize();}

                int i = size -1;
                array[i].data = data;
                array[i].priority = priority;

                while(i != 0 && array[parent(i)].priority > array[i].priority) {
                        swap(&array[i], &array[parent(i)]);
                        i = parent(i);
                }
        }

        T removeQueque(){
                if( size <= 0) return INT_MAX;
                if (size == 1) {
                        size--;
                        return array[0].data;
                }

                T root = array[0].data;
                array[0] = array[size-1];
                size--;
                MinHeapify(0);

                return root;
        }

        int sizeQueque(){ return size;}

        T peekQueque(){return array[0].data;}

        bool isEmptyQueque() { if(size == 0) return true; else return false;}

        void modifyPriority(int from, int to, T data) {
                // Find the index of the node with matching data and priority
                int index = -1;
                for (int i = 0; i < size; i++) {
                        if (array[i].data == data && array[i].priority == from) {
                                index = i;
                                break;
                        }
                }

                if (index == -1) {
                        return;
                }

                array[index].priority = to;

                // If the new priority is lower, bubble up
                if (to < from) {
                        while (index != 0 && array[parent(index)].priority > array[index].priority) {
                                swap(&array[index], &array[parent(index)]);
                                index = parent(index);
                        }
                }
                // If the new priority is higher, heapify down
                else if (to > from) {
                        MinHeapify(index);
                }
        }

        void debugShowList() {
                for(int i = 0; i < size; i++) {
                        std::cout << "[" << array[i].data << " | " << array[i].priority << "]";
                        if(i%20 == 19) std::cout << std::endl;
                }
        }

        void MinHeapify(int i){
                int l = leftChild(i);
                int r = rightChild(i);
                int smallest = i;

                if(l < size && array[l].priority < array[i].priority) smallest = l;
                if(r < size && array[r].priority < array[smallest].priority) smallest = r;
                if(smallest != i) {
                        swap(&array[i], &array[smallest]);
                        MinHeapify(smallest);
                }
        }


private:
        struct Node {
                T data;
                int priority;
        };

        int size = 0;
        int arraySize = 8;
        Node* array = new Node[arraySize];

        void swap(Node* x, Node* y){
                Node temp = *x;
                *x = *y;
                *y = temp;
        }


        int parent(int i) { return (i-1) / 2;}
        int leftChild(int i) { return ((2*i)+1);}
        int rightChild(int i) {return (2*i)+2 ;}

        void increaseArraySize() {
                arraySize *= 2;
                Node* newArray = new Node[arraySize];
                Node* oldArray = array;

                for(int i = 0; i < arraySize/2; i++) {
                        newArray[i].data = oldArray[i].data;
                        newArray[i].priority = oldArray[i].data;
                }

                array = newArray;
                delete[] oldArray;
        }

};
