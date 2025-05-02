#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

#include "kolejka_lista.hpp"
#include "kolejka_heap.hpp"

using namespace std;

fstream myfile;

#define START_TIMER  begin = chrono::steady_clock::now();

#define STOP_TIMER   end = chrono::steady_clock::now();\
        myfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << ","; 

#define MEASURE_SOMETHING(function) START_TIMER;\
        function;\
        STOP_TIMER;

#define MEASURE_PACKET(className, size, minus_size) \
    std::cout << "\nNow doing " << #className << " size " << size << std::endl; \
    className##Fill(size - minus_size); \
    cout << endl;       \
    for (int i = 0; i < 100; i++) { \
        myfile << size << ","; \
        MEASURE_SOMETHING(className.addQueque(2137, size)); \
        MEASURE_SOMETHING(className.peekQueque()); \
        MEASURE_SOMETHING(className.modifyPriority(size, size / 4, 2137)); \
        MEASURE_SOMETHING(className.removeQueque()); \
        MEASURE_SOMETHING(className.sizeQueque()); \
        myfile << "\n";         \
        cout << i << " | ";     \
        if(i%20 == 19) cout << endl;     \
    } \

KolejkaLista<int> kolejkaLista;
KolejkaHeap<int> kolejkaHeap;

void kolejkaListaFill(int size) {
cout << "\nFilling up List\n";
int priority = 0;

for(int i = 0; i < size; i++){
        priority = (rand()%size)+1;
        kolejkaLista.addQueque(i, priority);
        if(i%(size/100) == 0) cout << "\r" << i << "/" << size << flush;     
}
}

void kolejkaHeapFill(int size) {
cout << "\nFilling up Heap\n";
int priority = 0;

for(int i = 0; i < size; i++){
        priority = (rand()%size)+1;
        kolejkaHeap.addQueque(i, priority);
        if(i%(size/100) == 0) cout << "\r" << i << "/" << size << flush;     
}
}


int main() {
        srand(time(0));

        auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        myfile.open("KolejkaPrioretytowaHeap.csv", ios::app);
        myfile << "SIZE,ADD,PEEK,MODIFY,REMOVE,SIZE\n";

        MEASURE_PACKET(kolejkaHeap, 100, 0);

        kolejkaHeap.debugShowList();

        MEASURE_PACKET(kolejkaHeap, 500, 100);
        MEASURE_PACKET(kolejkaHeap, 1000, 500);
        MEASURE_PACKET(kolejkaHeap, 5000, 1000);
        MEASURE_PACKET(kolejkaHeap, 10000, 5000);
        MEASURE_PACKET(kolejkaHeap, 50000, 10000);
        MEASURE_PACKET(kolejkaHeap, 100000, 50000);
        MEASURE_PACKET(kolejkaHeap, 500000, 100000);
        MEASURE_PACKET(kolejkaHeap, 1000000, 500000);

        myfile.close();

        myfile.open("KolejkaPrioretytowaLista.csv", ios::app);
        myfile << "SIZE,ADD,PEEK,MODIFY,REMOVE,SIZE\n";
        
        MEASURE_PACKET(kolejkaLista, 100, 0);
        MEASURE_PACKET(kolejkaLista, 500, 100);
        MEASURE_PACKET(kolejkaLista, 1000, 500);
        MEASURE_PACKET(kolejkaLista, 5000, 1000);
        MEASURE_PACKET(kolejkaLista, 10000, 5000);
        MEASURE_PACKET(kolejkaLista, 50000, 10000);
        MEASURE_PACKET(kolejkaLista, 100000, 50000);
        MEASURE_PACKET(kolejkaLista, 500000, 100000);
        MEASURE_PACKET(kolejkaLista, 1000000, 500000);

        myfile.close();
}
