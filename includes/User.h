#ifndef User_h
#define User_h
class User {
protected:
    int id;
    std::string nume;
    float rating;

    static int nextID;
    int static genereazaID();

public:
    User();
    User(std::string nume, float rating);

    int getID() const;
    std::string getNume() const;
    float getRating() const;

    void setID(int ID);
    void setNume(std::string nume);
    void setRating(float rating);

    virtual void afisare() const;
};
#endif