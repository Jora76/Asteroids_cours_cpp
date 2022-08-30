#include "Asteroide.h"

#include <random>

using namespace std;

Asteroide::Asteroide() : ElementEspace{"ressources/asteroide.png"}
{
	auto generateur = random_device{};
	auto distributionPosition = uniform_real_distribution<float>{ -150, 150 };
	auto distributionVitesse = uniform_real_distribution<float>{ 80, 120 };
	auto distributionAngle = uniform_real_distribution<float>{ 10, 30 };
	auto distributionVitesseAngulaire = uniform_real_distribution<float>{ 0, 360 };
	position = { distributionPosition(generateur), distributionPosition(generateur) };
	vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur), distributionAngle(generateur));
	vitesseAngulaire = distributionVitesseAngulaire(generateur);
}
