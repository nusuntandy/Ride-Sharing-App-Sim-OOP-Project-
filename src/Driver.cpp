#include "../includes/Driver.h"

Driver::Driver(std::string nume = "necunoscut", int age = 18, float rating = 0.0, int balance = 100, std::string masina = "necunoscuta", bool disponibil = false) : User(nume, age, rating, balance), masina(masina), disponibil(disponibil) {
    std::cout << "[Constructor] Class Driver called\n";
}

Driver::~Driver() {
    std::cout << "[Destructor] Class Driver called\n";
}

void Driver::setDisponibil(bool val) {
    disponibil = val;
}

void Driver::setMasina(std::string m) {
    masina = m;
}

std::string Driver::getMasina() const { return masina; }
bool Driver::getDisponibil() const { return disponibil; }

void Driver::finishRide() {
    disponibil = true;
}

void Driver::afisare() const {
    std::cout << "Driver " << id << " -> " << nume << ", Rating: " << rating << ", Masina: " << masina << ", Disponibil: " << (disponibil ? "DA" : "NU") << ".\n";
}
