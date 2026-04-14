#include <iostream>

#include "src/User.cpp"
#include "src/Driver.cpp"
#include "src/Client.cpp"
#include "src/Ride.cpp"

int main(void ) {
    srand(time(NULL));

    int n = 1, m = 1;
    Driver drivers[1] = {
        Driver("Silviu Candale", 18, 5.0, 100, "BMW", true)
    };

    Client clients[m] = {
        Client("Nedelcu Andy", 18, 5.0, 130)
    };

    //TEST 1
    Ride *r1;

    std::cout << "Simulare cursa:\n\n";
    try {
        r1 = requestRide(&clients[0], drivers, n, "Centru", "Aeroport");

        r1->showStatus();
        std::cout << "\n";

        acceptRide(r1->getDriver(), r1);
        r1->showStatus();
        std::cout << "\n";

        r1->updateStatus(ONGOING);
        r1->showStatus();
        std::cout << "\n";

        r1->updateStatus(COMPLETED);
        r1->showStatus();
        std::cout << "\n";

        delete r1;        
    } catch(const std::runtime_error &e) {
        std::cout << e.what() << "\n";
        
        if(r1 != nullptr)
            delete r1;
    }
    
    std::cout << "Sfarsit simulare\n\n";

    //TEST 2
    std::cout << "Simulare cursa:\n\n";
    try {
        r1 = requestRide(&clients[0], drivers, n, "Centru", "Aeroport");
        cancelRide(r1->getDriver(), &r1);
    } catch(const std::runtime_error &e) {
        std::cout << e.what() << "\n";

        if(r1 != nullptr)
            delete r1;
    }

    return 0;
}
