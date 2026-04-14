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

    ~Ride();

    friend Ride* requestRide(Client* client, Driver* drivers, int dL, const std::string lS, const std::string lF);

    friend void cancelRide(const Client *client, Ride *ride);
    friend void cancelRide(const Driver *driver, Ride *ride);

    friend void acceptRide(const Driver *driver, Ride *ride);

    Driver* getDriver(void );
    Client* getClient(void );

    void updateStatus(enum status stat);
    void showStatus() const;
    int calculeazaPret() const;
};
#endif
