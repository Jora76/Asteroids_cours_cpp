#pragma once
#include<SFML/Graphics.hpp>

#include "Coordonnees.h" 
#include "ElementEspace.h"

using namespace std;

class Vaisseau : public ElementEspace
{
public:
	Vaisseau();
	void actualiserEtat();
	void mettreAJour(float temps);

private:
	bool accelerationEnCours{ false };
	bool tourneAGauche{ false };
	bool tourneADroite{ false };

	static constexpr float ACCELERATION{ 2500.f };
	static constexpr float COEF_FROTTEMENTS{ 2.f };
	static constexpr float VITESSE_ANGULAIRE{ 300.f };
};