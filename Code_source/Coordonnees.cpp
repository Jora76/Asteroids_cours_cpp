#include<SFML/Graphics.hpp>
#include<iostream>

#include "Coordonnees.h"

int Coordonnees::spaceX = 0;
int Coordonnees::spaceY = 0;

Coordonnees::Coordonnees()
{
	if (spaceX == 0 || spaceY == 0)
	{
		std::cerr << "une coordonnee a ete creee avant l'initialisation de l'espace" << std::endl;
	}
}

Coordonnees::Coordonnees(float px, float py) : x(px), y(py)
{
	leDroitChemin();
}

void Coordonnees::initialiserEspace(int lx, int ly)
{
	if (spaceX != 0 || spaceY != 0)
	{
		std::cerr << "espace deja initialise" << std::endl;
	}
	spaceX = lx;
	spaceY = ly;
}


void Coordonnees::operator+=(Vecteur const& pos) 
{
	x += pos.x;
	y += pos.y;
	leDroitChemin();
}

void Coordonnees::leDroitChemin()
{
	while (x > spaceX)
	{
		x -= spaceX;
	}

	while (y > spaceY)
	{
		y -= spaceY;
	}

	while (x < 0)
	{
		x += spaceX;
	}

	while (y < 0)
	{
		y += spaceY;
	}
}

float Coordonnees::calculerDistance(Coordonnees const& autre) const
{
	auto delta = Vecteur
	{
		std::min({abs(x - autre.x), abs(x - autre.x - spaceX), abs(autre.x + spaceX)}), std::min({abs(y - autre.y), abs(y - autre.y - spaceY), abs(autre.y + spaceY)})
	};
	return sqrt(delta.x * delta.x + delta.y * delta.y);
};