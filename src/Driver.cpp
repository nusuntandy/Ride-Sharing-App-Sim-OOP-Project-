#include "../includes/Driver.h"

Driver::Driver(std::string nume, float rating, std::string masina, bool disponibil) : User(nume, rating), masina(masina), disponibil(disponibil) {}

std::string Driver::getMasina() const { return masina; }
bool Driver::getDisponibil() const { return disponibil; }

void Driver::acceptRide() {
    std::cout << nume << " a acceptat o cursa\n";
    disponibil = false;
}

void Driver::finishRide() {
    disponibil = true;
}

void Driver::afisare() const {
    std::cout << "Driver " << id << " -> " << nume << ", Rating: " << rating << ", Masina: " << masina << ", Disponibil: " << (disponibil ? "DA" : "NU") << ".\n";
}