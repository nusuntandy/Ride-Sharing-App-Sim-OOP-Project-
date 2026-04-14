#ifndef User_h
#define User_h
class User {
protected:
    int id;
    std::string nume;
    int age;
    int balance;
    float rating;

    static int nextID;
    int static genereazaID();

public:
    User(std::string nume, int age, float rating, int balance);

    ~User();

    int getID() const;
    std::string getNume() const;
    int getAge() const;
    int getBalance() const;
    float getRating() const;

    void setID(int ID);
    void setNume(std::string nume);
    void setAge(int a);
    void setBalance(int b);
    void setRating(float rating);

    virtual void afisare() const = 0;
};
#endif
