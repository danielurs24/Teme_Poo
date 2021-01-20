#include <iostream>
class Masina{

private:

    std::string marca;
    std::string model;
    std::string culoare;
    int pret;

public:

    Masina(const std::string &marca, const std::string &model, const std::string &culoare, const int &pret) {

        this->marca=marca;
        this->model=model;
        this->culoare=culoare;
        this->pret=pret;

    }

    Masina(){

        this->marca="FaraMarca";
        this->model="FaraModel";
        this->culoare="FaraCuloare";
        this->pret=0;
    }

    Masina(const Masina &mas) {

        this->marca=mas.marca;
        this->model=mas.model;
        this->culoare=mas.culoare;
        this->pret=mas.pret;

    }

    const std::string &getMarca() const {

        return marca;
    }

    void setMarca(const std::string &marca) {

        Masina::marca = marca;
    }

    const std::string &getModel() const {

        return model;
    }

    void setModel(const std::string &model) {

        Masina::model = model;
    }

    const std::string &getCuloare() const {

        return culoare;
    }

    void setCuloare(const std::string &culoare) {

        Masina::culoare = culoare;
    }

    int getPret() const {

        return pret;
    }

    void setPret(int pret) {

        Masina::pret = pret;
    }

    virtual ~Masina() {

        std::cout << "Masina " << this->marca << " " << this->model << " a fost distrusa" << "\n";

    }

    friend std::ostream &operator<<(std::ostream &m, const Masina &masina1) {
        m << masina1.getMarca() << " " << masina1.getModel();
        return m;
    }

    void inService();
    void outService();

};

void Masina::inService(){

    std::cout << "Masina " << marca << " " << model << " de culoare " << culoare << " cu pretul de " << pret << "$ a intrat in service " << "\n";
};

void Masina::outService(){

    std::cout << "Masina " << this->marca << " " << this->model << " a fost reparata" << "\n";
};

class masina_factory{
public:
    static Masina  BMW_X5() { return Masina ("BMW","X5","Negru",5000);}
    static Masina Audi_A3() { return Masina ("Audi","A3","Verde",4000);}
};