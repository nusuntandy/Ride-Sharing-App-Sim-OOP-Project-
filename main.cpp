#include <iostream>

//OTHER INCLUDES
#include "src/User.cpp"
#include "src/Driver.cpp"
#include "src/Client.cpp"
#include "src/Ride.cpp"

int main(void ) {
    //TEST 1
    std::cout << "Simulare cursa:\n\n";

    Driver d1("Silviu Candale", 5.0, "BMW", true);
    d1.afisare();

    Client c1("Nedelcu Andy", 5.0);
    c1.afisare();

    std::cout << "\n";

    Ride* r1 = requestRide(&c1, &d1, "Centru", "Aeroport");

    if(r1 != nullptr) {
        r1->updateStatus(REQUESTED);
        r1->showStatus();
        std::cout << "\n";

        r1->updateStatus(ACCEPTED);
        r1->showStatus();
        std::cout << "\n";

        r1->updateStatus(ONGOING);
        r1->showStatus();
        std::cout << "\n";

        r1->updateStatus(COMPLETED);
        r1->showStatus();
        std::cout << "\n";

        delete r1;
    }
    else
        std::cout << "Nu au fost gasiti soferi disponibili!\n";

    std::cout << "Sfarsit simulare\n\n";

    //TEST 2
    std::cout << "Simulare cursa:\n\n";

    d1.afisare();
    c1.afisare();
    std::cout << "\n";

    r1 = requestRide(&c1, &d1, "Centru", "Aeroport");
    c1.cancelRide(&r1);

    r1 = nullptr;
    return 0;
}