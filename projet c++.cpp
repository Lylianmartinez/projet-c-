#include <iostream>
#include <string>

class ServiceMaintenance {
public:
    virtual void effectuerMaintenance() = 0;
};
struct Coordonnees {
    double latitude;
    double longitude;

    Coordonnees(double lat, double lon) : latitude(lat), longitude(lon) {}
};

class Vehicule {
public:
    virtual void demarrer() = 0;
    virtual void arreter() {
        std::cout << "Le vehicule est arrete." << std::endl;
    }
};

class Voiture : public Vehicule, public ServiceMaintenance {
private:
    std::string marque;
    std::string modele;
    Coordonnees position;  

public:
    Voiture(std::string m, std::string mod, double lat, double lon) : marque(m), modele(mod), position(lat, lon) {}

    void demarrer() override {
        std::cout << "La voiture de marque " << marque << " et de modele " << modele << " demarre." << std::endl;
    }

    void effectuerMaintenance() override {
        std::cout << "Maintenance de la voiture effectuee." << std::endl;
    }

    void afficherPosition() {
        std::cout << "Position de la voiture : Latitude " << position.latitude << ", Longitude " << position.longitude << std::endl;
    }
};

class Moto : public Vehicule {
private:
    std::string marque;
    std::string modele;

public:
    Moto(std::string m, std::string mod) : marque(m), modele(mod) {}

    void demarrer() override {
        std::cout << "La moto de marque " << marque << " et de modele " << modele << " demarre." << std::endl;
    }
};

void effectuerOperation(Vehicule& vehicule) {
    vehicule.demarrer();
    vehicule.arreter();
}

int main() {
    Voiture maVoiture("Toyota", "Yaris", 48.8566, 2.3522);
    maVoiture.demarrer();
    maVoiture.arreter();
    maVoiture.effectuerMaintenance();
    maVoiture.afficherPosition();

    Moto maMoto("Honda", "CBR");
    effectuerOperation(maMoto);

    return 0;
}
