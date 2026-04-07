#ifndef Ride_h
#define Ride_h
enum status {
    REQUESTED,
    ACCEPTED,
    ONGOING,
    COMPLETED,
    CANCELED
};

class Ride {
private:
    int id;
    Client *client;
    Driver *driver;
    std::string locatieStart;
    std::string locatieFinal;

    enum status currentStatus;

    static int nextID;

public:
    Ride(Client* c, Driver* d, std::string lS, std::string lF);

    void updateStatus(enum status stat);

    void showStatus() const;

    int calculeazaPret() const;
};
#endif