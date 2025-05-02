#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

#include "kolejka_lista.hpp"

using namespace std;

#define START_TIMER  begin = chrono::steady_clock::now();

#define STOP_TIMER   end = chrono::steady_clock::now();\
        myfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << ","; 

#define MEASURE_SOMETHING(function) START_TIMER;\
        function;\
        STOP_TIMER;

KolejkaLista<int> kolejkaLista;

void fillKolejkaRandom(int size) {

int priority = 0;

for(int i = 0; i < size; i++){
        priority = (rand()%size)+1;
        kolejkaLista.addQueque(i, priority);
}
}


int main() {
        srand(time(0));

        fillKolejkaRandom(100);
        cout << kolejkaLista.sizeQueque();

        kolejkaLista.addQueque(2137, 50);
        kolejkaLista.debugShowList();

        kolejkaLista.modifyPriority(50, 1, 2137);
        kolejkaLista.debugShowList();
}
