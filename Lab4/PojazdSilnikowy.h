#ifndef POJAZDSILNIKOWY_H
#define POJAZDSILNIKOWY_H

#include "Pojazd.h"

class PojazdSilnikowy : public Pojazd
{
protected:
	float pojemnosc;
	int mocKM;
public:
	PojazdSilnikowy(float pojemnosc, int mocKM, const Osoba &wlasciciel, int przebieg) : Pojazd{ wlasciciel, przebieg }, pojemnosc{ pojemnosc }, mocKM{ mocKM } {};
	float pobierzPojemnosc();
	std::string opis() const override { return ((Pojazd*)this)->opis() + "\t" + std::to_string(pojemnosc) + "\t" + std::to_string(mocKM); }
	float mocKW() const override;
	bool zapisz(std::ostream& os) const override;
	bool wczytaj(std::istream& is) override;
};

#endif //POJAZDSILNIKOWY_H
