#ifndef Client_h
#define Client_h
class Client : public User {
public:
    Client(std::string nume, int age, float rating, int balance);

    ~Client();

    void afisare() const override;    
};
#endif
