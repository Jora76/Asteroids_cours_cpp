#pragma once
#include <SFML/Graphics.hpp>

#include "Coordonnees.h"

class ElementEspace
{
public:
	ElementEspace(std::string_view const&);
	virtual void mettreAJour(float temps);
	void afficher(sf::RenderWindow& window) const;
	void testerCollision(ElementEspace& autre);
	float getRayon() const;

protected:
	sf::Texture texture{};
	sf::Sprite sprite{};
	Coordonnees position{};
	Vecteur vitesse{ 0.f, 0.f };
	float vitesseAngulaire{};
};

