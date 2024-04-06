#include <cstdlib>
#include <ctime>   

class Noppa {
public:
    Noppa() { srand(static_cast<unsigned int>(time(0))); }
    int heita() { return rand() % 6 + 1; } 
};
