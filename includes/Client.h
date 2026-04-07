#ifndef Client_h
#define Client_h
class Ride;

class Client : public User {
public:
    Client(std::string nume, float rating);

    void cancelRide(Ride **ride);

    void afisare() const override;

    friend Ride *requestRide(Driver* d, std::string lS, std::string lF);
};
#endif