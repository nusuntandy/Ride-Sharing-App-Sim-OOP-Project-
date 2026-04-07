#ifndef Driver_h
#define Driver_h
class Driver : public User {
private:
    std::string masina;
    bool disponibil;

public:
    Driver(std::string nume, float rating, std::string masina, bool disponibil);

    std::string getMasina() const;
    bool getDisponibil() const;

    void acceptRide();

    void finishRide();

    void afisare() const override;
};
#endif