#include "../includes/User.h"

int User::nextID = 0;

int User::genereazaID() {
    nextID++;
    return nextID;
}

User::User() : id(genereazaID()), nume("Necunoscut"), rating(0.0) {}
User::User(std::string nume, float rating) : id(genereazaID()), nume(nume), rating(rating) {}

int User::getID() const { return id; }
std::string User::getNume() const { return nume; }
float User::getRating() const { return rating; }

void User::setID(int ID) {
    this->id = ID;
}

void User::setNume(std::string nume) {
    this->nume = nume;
}

void User::setRating(float rating) {
    this->rating = rating;
}

void User::afisare() const {
    std::cout << id << ". " << nume << ", Rating: " << rating << "\n";
}