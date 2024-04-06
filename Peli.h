#include "Noppa.h"
#include <iostream>
#include <fstream>
#include <limits>

class Peli {
private:
    Noppa noppa;

public:
    void pelaa() {
        std::cout << "Tervetuloa pelaamaan mahtavaa noppapeliä!" << std::endl;
        std::ofstream tulostiedosto("pistetiedosto.txt", std::ios::app); 
        for (int i = 0; i < 3; ++i) {
            std::cout << "Paina Enter heittääksesi noppaa";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            int heitto = noppa.heita();
            pisteet += heitto;
            std::cout << "Heitit: " << heitto << std::endl;
            
            if (tulostiedosto.is_open()) {
                tulostiedosto << "Heitto " << i + 1 << ": " << heitto << std::endl;
            }
        }
        std::cout << "Kolmen heiton yhteissumma: " << pisteet << std::endl;
        
        if (tulostiedosto.is_open()) {
            tulostiedosto << "Kolmen heiton yhteissumma: " << pisteet << "\n\n";
            tulostiedosto.close();
        }
    }
};
