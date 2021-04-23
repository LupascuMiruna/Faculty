#include <iostream>
#include "Masca.h"
#include "MascaChirurgicala.h"
#include "MascaPolicarbonat.h"
#include "Dezinfectant.h"
#include "DezinfectantBacterii.h"
#include "DezinfectantVirusuri.h"
using namespace std;
int main() {
    MascaChirugicala m1, m2("ch", "rosie", 3), m3(m2);
    m1 = m2;
    std::cout << m1;
//    DezinfectantBacterii d1;
//    std::cin >> d1;
//    std::cout << d1;

}
