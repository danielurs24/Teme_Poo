#include <iostream>
class reparatie: public service{

private:

    std::string denumire;
    int durata;
    Masina m = Masina();
    std::vector<int> cost;
public:


    reparatie(const std::string &denumire, int durata, const Masina &m){

        this->denumire=denumire;
        this->durata=durata;
        this->m=m;


    }

    virtual ~reparatie() {


    }

    const std::string &getDenumire() const {

        return denumire;
    }

    void setDenumire(const std::string &denumire) {

        reparatie::denumire = denumire;
    }

    int getDurata() const {

        return durata;
    }

    void setDurata(int durata) {

        reparatie::durata = durata;
    }

    const Masina &getM() const {
        return m;
    }

    void setM(const Masina &m) {
        reparatie::m = m;
    }
    void cost_reparatie(int pret)
    {
        cost.push_back(pret);
    }

    void afisare_pret_total()
    {   int sum = 0;
        for(int i = 0; i < cost.size(); i++)
            sum = sum + cost[i];
        std::cout << "Pretul total pentru reparatii la masina " << m << " " << sum << " de lei\n";

    }

    void info()
    {
        std::cout << "Se repara " << m << "\n";
    }
    friend std::ostream &operator<<(std::ostream &m, const reparatie &rep) {
        m << "Se face operatiunea de "  << rep.getDenumire() << " la masina " << rep.getM()  << " care dureaza " << rep.getDurata() << " de minute \n";
        return m;
    }
};
