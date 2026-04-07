#include "../includes/Client.h"
#include "../includes/Ride.h"

Client::Client(std::string nume, float rating) : User(nume, rating) {}

void Client::cancelRide(Ride **ride) {
    std::cout << nume << " a anulat cursa.";

    Ride *currentRide = *ride;
    currentRide->updateStatus(CANCELED);
    delete currentRide;

    *ride = nullptr;
}

void Client::afisare() const {
    std::cout << "Client " << id << " -> " << nume << ", Rating: " << rating << ".\n";
}