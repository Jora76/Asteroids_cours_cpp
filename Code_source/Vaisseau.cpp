#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include <iostream>

using namespace std;

Vaisseau::Vaisseau() : ElementEspace{ "ressources/Vaisseau.png" } //constructeur de Vaisseau
{
}

void Vaisseau::actualiserEtat() //détection de touches pour diriger le vaisseau
{
	accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Vaisseau::mettreAJour(float temps) //methode qui calcule les déplacements du vaisseau en fonction de la touche pressée
{
	if(accelerationEnCours)
	{
		vitesse += Vecteur::creerDepuisAngle(ACCELERATION * temps, sprite.getRotation());

	}
	vitesse -= vitesse * COEF_FROTTEMENTS * temps;
	if (tourneAGauche)
	{
		vitesseAngulaire = -VITESSE_ANGULAIRE;
	}
	else if (tourneADroite)
	{
		vitesseAngulaire = VITESSE_ANGULAIRE;
	}
	else
	{
		vitesseAngulaire = 0;
	}

	ElementEspace::mettreAJour(temps);
}