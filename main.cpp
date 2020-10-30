#include <iostream>

using namespace std ;

class Masina{

private:

    string marca;
    string model;
    string culoare;
    int pret;

public:

    Masina(const string &marca, const string &model, const string &culoare, const int &pret) {
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

    const string &getMarca() const {
        return marca;
    }

    void setMarca(const string &marca) {
        Masina::marca = marca;
    }

    const string &getModel() const {
        return model;
    }

    void setModel(const string &model) {
        Masina::model = model;
    }

    const string &getCuloare() const {
        return culoare;
    }

    void setCuloare(const string &culoare) {
        Masina::culoare = culoare;
    }

    int getPret() const {
        return pret;
    }

    void setPret(int pret) {
        Masina::pret = pret;
    }

    virtual ~Masina() {
        cout << "Masina " << this->marca << " " << this->model << " a fost reparata" << "\n";

    }

    void inService();

};

void Masina::inService(){
    cout << "Masina " << marca << " " << model << " de culoare " << culoare << " cu pretul de " << pret << "$ a intrat in service " << "\n";
};

class service{

private:

    string locatie;
    string manager;
    int locuri_masini;

public:

    service(const string &locatie = "Focsani",const string &manager = "Manager", const int &locuriMasini = 2)  {
    this->locatie=locatie;
    this->locuri_masini=locuriMasini;
    this->manager=manager;

}
    service(const service &srv) {
        manager = srv.manager;

    }

    const string &getLocatie() const {
        return locatie;
    }
    void setLocatie(const string &locatie) {
        service::locatie = locatie;
    }

    const string &getManager() const {
        return manager;
    }

    void setManager(const string &manager) {
        service::manager = manager;
    }

    int getLocuriMasini() const {
        return locuri_masini;
    }

    void setLocuriMasini(int locuriMasini) {
        locuri_masini = locuriMasini;
    }

    virtual ~service() {
        cout << "Service-ul din " << locatie << " s-a inchis" << "\n";
    }
    int seRepara();
};

    int service::seRepara()
    {
        return locuri_masini--;
    }
class reparatie
{
private:
    string denumire;
    int durata;
    int cost;
public:
    reparatie(const string &denumire, int durata, int cost) {
        this->denumire=denumire;
        this->durata=durata;
        this->cost=cost;
    }

    virtual ~reparatie() {

    }

    const string &getDenumire() const {
        return denumire;
    }

    void setDenumire(const string &denumire) {
        reparatie::denumire = denumire;
    }

    int getDurata() const {
        return durata;
    }

    void setDurata(int durata) {
        reparatie::durata = durata;
    }

    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        reparatie::cost = cost;
    }
};



int main() {
    service service1("Bucuresti","Alex",5);
    service service2("Cluj","Marius");

    service service3 = service1;

    cout << "Service-ul din " << service1.getLocatie() << " unde manager este " << service1.getManager() << " are " << service1.getLocuriMasini()<< " locuri libere pentru reparatii \n";
    cout << "Service-ul din " << service2.getLocatie() << " unde manager este " << service2.getManager() << " are " << service2.getLocuriMasini()<< " locuri libere pentru reparatii \n";
    cout << "Service-ul din " << service3.getLocatie() << " unde manager este " << service3.getManager() << " are " << service3.getLocuriMasini()<< " locuri libere pentru reparatii \n";

    service3 = service2;

    cout << "Service-ul din " << service3.getLocatie() << " unde manager este " << service3.getManager() << " are " << service3.getLocuriMasini()<< " locuri libere pentru reparatii \n\n\n";

    Masina masina1("BMW","X5","Negru",5000);
    Masina masina2("Audi","A3","Verde",4000);

    masina1.inService();
    masina2.inService();
    service1.seRepara();
    service1.seRepara();

    cout << "\nIn service-ul din " << service1.getLocatie() << " mai sunt " << service1.getLocuriMasini() << " locuri\n\n";

    return 0;
}
