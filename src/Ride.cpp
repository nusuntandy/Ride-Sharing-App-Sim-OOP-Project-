#include "../includes/Ride.h"

int Ride::nextID = 0;

Ride::Ride(Client* c, Driver* d, std::string lS, std::string lF) {
    nextID++;

    this->id = id;
    client = c;
    driver = d;

    locatieStart = lS;
    locatieFinal = lF;

    currentStatus = REQUESTED;
}

void Ride::updateStatus(enum status stat) {
    currentStatus = stat;

    if(currentStatus == ACCEPTED)
        driver->acceptRide();
    else if(currentStatus == COMPLETED)
        driver->finishRide();
    else if(currentStatus == CANCELED && !driver->getDisponibil())
        driver->finishRide();
}

void Ride::showStatus() const {
    std::cout << "Ride Status:\n";
    std::cout << "Client: " << client->getNume() << "\n";
    std::cout << "Driver: " << driver->getNume() << "\n";

    std::cout << "Locatie Start: " << locatieStart << "\n";
    std::cout << "Locatie Final: " << locatieFinal << "\n";

    std::cout << "Status: ";
    switch(currentStatus) {
        case REQUESTED: std::cout << "REQUESTED"; break;

        case ACCEPTED: std::cout << "ACCEPTED"; break;

        case ONGOING: std::cout << "ONGOING"; break;

        case COMPLETED: std::cout << "COMPLETED"; break;

        case CANCELED: std::cout << "CANCELED"; break;
    }

    std::cout << "\n";

    if(currentStatus == COMPLETED) 
        std::cout << "Pret Final: " << this->calculeazaPret() << " LEI\n";
}

int Ride::calculeazaPret() const {
    return 10 * (locatieStart.length() + locatieFinal.length());
}

Ride* requestRide(Client* client, Driver* drivers, const std::string lS, const std::string lF) {
    std::cout << client->getNume() << " a solicitat o cursa\n";
    std::cout << "Se cauta soferi..." << "\n";

    return new Ride(client, drivers, lS, lF);
}