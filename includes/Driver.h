#ifndef Driver_h
#define Driver_h
class Driver : public User {
private:
    std::string masina;
    bool disponibil;

public:
    Driver(std::string nume, int age, float rating, int balance, std::string masina, bool disponibil);

    ~Driver();

    void setDisponibil(bool val);
    void setMasina(std::string m);

    std::string getMasina() const;
    bool getDisponibil() const;

    void acceptRide();
    void finishRide();
    void afisare() const override;
};
#endif
