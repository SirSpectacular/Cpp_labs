#ifndef POJAZD_H
#define POJAZD_H

#include <string>
#include <iostream>

#include "Osoba.h"

class Pojazd
{
protected:
	Osoba wlasciciel;
	int przebieg;
public:
	Pojazd(const Osoba& _wlasciciel, int _przebieg);
	~Pojazd();
	virtual std::string opis() const { return wlasciciel.pobierzImie() + "\t" + std::to_string(przebieg); }
	virtual float mocKW() const = 0;
	virtual bool zapisz(std::ostream & os) const;
	virtual bool wczytaj(std::istream & is);
};

#endif // POJAZD_H