#define _USE_MATH_DEFINES

#include "Vecteur.h"
#include <cmath>

// modification des op?rateurs pour qu'il puissent prendre en param?tres des ?l?ments de la classe vecteur

void Vecteur::operator+=(Vecteur const& autre)
{
	x += autre.x;
	y += autre.y;
}

void Vecteur::operator-=(Vecteur const& autre)
{
	x -= autre.x;
	y -= autre.y;
}

Vecteur Vecteur::operator*(float coefficient) const
{
	return Vecteur{ x * coefficient, y * coefficient };
}

Vecteur Vecteur::creerDepuisAngle(float taille, float angleEnDegre) //vecteur qui va faire avancer le vaisseau en fonction de son angle de rotation
{
	return { taille * cos(angleEnDegre / 180.f * static_cast<float>(M_PI)), taille * sin(angleEnDegre / 180.f * static_cast<float>(M_PI)) };
}