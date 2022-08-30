#include "ElementEspace.h"

#include <iostream>
#include <array>

using namespace std;

ElementEspace::ElementEspace(string_view const& cheminImage)
{
	if (!texture.loadFromFile(cheminImage.data()))
	{
		cerr << "L'image" << cheminImage << "n'a pas été correctement chargée." << endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2); //détermination du centre de rotation du sprite
	sprite.setPosition(position.getX(), position.getY());
}

void ElementEspace::afficher(sf::RenderWindow& window) const
{
	auto affichages = array <Vecteur, 9> 
	{
		Vecteur{ -1, -1 }, Vecteur{ 0, -1 }, Vecteur{ 1, -1 },
		Vecteur{ -1, 0 }, Vecteur{ 0, 0 }, Vecteur{ 1, 0 },
		Vecteur{ -1, 1 }, Vecteur{ 0, 1 }, Vecteur{ 1, 1 }
	};
	for (auto& affichage : affichages)
	{
		auto transformation = sf::Transform{};
		transformation.translate(affichage.x * Coordonnees::getspaceX(), affichage.y * Coordonnees::getspaceY());
		window.draw(sprite, transformation);
	}
}

void ElementEspace::mettreAJour(float temps) //methode qui calcule les déplacements du vaisseau en fonction de la touche pressée
{
	auto deplacement = vitesse * temps;
	position += deplacement;
	sprite.setPosition(position.getX(), position.getY());
	sprite.rotate(vitesseAngulaire * temps);
}

float ElementEspace::getRayon() const
{
	return sprite.getLocalBounds().height / 2.f;
}

void ElementEspace::testerCollision(ElementEspace& autre)
{
	auto distance = position.calculerDistance(autre.position);
	if (distance < getRayon() + autre.getRayon())
	{
		sprite.setColor(sf::Color::Red);
		autre.sprite.setColor(sf::Color::Red);
	}
}