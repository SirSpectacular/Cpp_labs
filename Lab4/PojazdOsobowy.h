#ifndef POJAZDOSOBOWY_H
#define POJAZDOSOBOWY_H

#include "PojazdSilnikowy.h"

class PojazdOsobowy : PojazdSilnikowy
{
protected:
	std::string marka;

public:
	PojazdOsobowy(std::string marka, float pojemnosc, int mocKM, const Osoba &wlasciciel, int przebieg) : PojazdSilnikowy{ pojemnosc, mocKM, wlasciciel, przebieg }, marka{ marka } {}
	std::string opis() const override { return ((PojazdSilnikowy*)this)->opis() + "\t" + "\t" + marka; }
	bool zapisz(std::ostream& os) const override;
	bool wczytaj(std::istream& is) override;
};

#endif //POJAZDOSOBOWY_H

zapisz(std::ostream& os)
{
	os >> "kupa";
}
