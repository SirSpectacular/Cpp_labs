#ifndef ROWER_H
#define ROWER_H

#include "Pojazd.h"

class Rower : public Pojazd
{
protected:
	bool amatorski;
public:
	Rower(const Osoba &wlasciciel, int przebieg, int amatorski) : Pojazd{ wlasciciel, przebieg }, amatorski{ amatorski } {}
	float mocKW();
	std::string opis() const override;
	float mocKW() const override;
	bool zapisz(std::ostream& os) const override;
	bool wczytaj(std::istream& is) override;
};

#endif //ROWER_H
