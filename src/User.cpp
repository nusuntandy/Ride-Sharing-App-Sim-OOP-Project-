#include "../includes/User.h"

int User::nextID = 0;

User::User(std::string nume = "Necunoscut", int age = 18, float rating = 0.0, int balance = 100) : id(genereazaID()), nume(nume), rating(rating), balance(balance) {
    std::cout << "[Constructor] Class User called\n";
}

User::~User() {
    nextID--;
    std::cout << "[Destructor] Class User called\n";
}

int User::getID() const { return id; }
std::string User::getNume() const { return nume; }
int User::getAge() const { return age; }
int User::getBalance() const { return balance; }
float User::getRating() const { return rating; }

void User::setID(int ID) {
    this->id = ID;
}

void User::setNume(std::string nume) {
    this->nume = nume;
}

void User::setAge(int a) {
    this->age = a;
}

void User::setBalance(int b) {
    this->balance = b;
}

void User::setRating(float rating) {
    this->rating = rating;
}

int User::genereazaID() {
    nextID++;
    return nextID;
}
