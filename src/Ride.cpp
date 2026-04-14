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

    std::cout << "[Constructor] Class Ride called\n";
}

Ride::~Ride() {
    nextID--;
    driver->setDisponibil(true);
    std::cout << "[Destructor] Class Ride called\n";
}

Client* Ride::getClient(void ) {
    return this->client;
}

Driver* Ride::getDriver(void ) {
    return this->driver;
}

void Ride::updateStatus(enum status stat) {
    currentStatus = stat;

    if(currentStatus == COMPLETED) {
        if(client->getBalance() < calculeazaPret())
            throw std::runtime_error("Payment error: Balanta insuficienta pentru a completa tranzactia.");
    
        client->setBalance(client->getBalance() - calculeazaPret());
        driver->setBalance(driver->getBalance() + calculeazaPret());
        driver->finishRide();
    }
    if(currentStatus == CANCELED && !driver->getDisponibil())
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
        case REQUESTED: 
            std::cout << "REQUESTED"; 
            break;

        case ACCEPTED: 
            std::cout << "ACCEPTED"; 
            break;

        case ONGOING: 
            std::cout << "ONGOING"; 
            break;

        case COMPLETED: 
            std::cout << "COMPLETED"; 
            break;

        case CANCELED: 
            std::cout << "CANCELED"; 
            break;
    }

    std::cout << "\n";
    if(currentStatus == COMPLETED) 
        std::cout << "Pret Final: " << this->calculeazaPret() << " LEI\n";
}

int Ride::calculeazaPret() const {
    return 10 * (locatieStart.length() + locatieFinal.length());
}

Ride* requestRide(Client* client, Driver* drivers, int dL, const std::string lS, const std::string lF) {
    std::cout << client->getNume() << " a solicitat o cursa\n";
    std::cout << "Se cauta soferi..." << "\n";

    for(int i = 0; i < dL; i++) {
        int dRand = rand() % dL;

        if(drivers[dRand].getDisponibil())
            return new Ride(client, &drivers[dRand], lS, lF);
    }

    throw std::runtime_error("Nu au fost gasiti soferi disponibili!");
    return nullptr;
}

void cancelRide(const Client *c, Ride **ride) {
    std::cout << c->getNume() << " a anulat cursa.\n";

    Ride *currentRide = *ride;
    currentRide->updateStatus(CANCELED);
    delete currentRide;

    *ride = nullptr;
}

void cancelRide(const Driver *d, Ride **ride) {
    std::cout << d->getNume() << " a anulat cursa.\n";

    Ride *currentRide = *ride;
    currentRide->updateStatus(CANCELED);
    delete currentRide;

    *ride = nullptr;
}

void acceptRide(Driver *d, Ride *ride) {
    std::cout << d->getNume() << " a acceptat cursa.\n";
    d->setDisponibil(false);

    ride->updateStatus(ACCEPTED);
}
