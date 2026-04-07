#include <iostream>

//OTHER INCLUDES
#include "src/User.cpp"
#include "src/Driver.cpp"
#include "src/Client.cpp"
#include "src/Ride.cpp"

int main(void ) {
    //TEST 1
    std::cout << "Simulare cursa:\n\n";

    Driver drivers[] = {
        Driver("Silviu Candale", 5.0, "BMW", true)
    };

    drivers[0].afisare();

    Client clients[] = {
        Client("Nedelcu Andy", 5.0)
    };

    
    clients[0].afisare();


    std::cout << "\n";

    Ride* r1 = requestRide(&clients[0], drivers, "Centru", "Aeroport");

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

    drivers[0].afisare();
    clients[0].afisare();
    std::cout << "\n";

    r1 = requestRide(&clients[0], drivers, "Centru", "Aeroport");
    clients[0].cancelRide(&r1);

    r1 = nullptr;
    return 0;
}
