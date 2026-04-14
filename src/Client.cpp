#include "../includes/Client.h"

Client::Client(std::string nume = "necunoscut", int age = 18, float rating = 0.0, int balance = 100.0) : User(nume, age, rating, balance) {
    std::cout << "[Constructor] Class Client called\n";
}

Client::~Client() {
    std::cout << "[Destructor] Class Client called\n";
}

void Client::afisare() const {
    std::cout << "Client " << id << " -> " << nume << ", Rating: " << rating << ".\n";
}
