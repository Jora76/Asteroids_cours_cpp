#pragma once
#include<SFML/Graphics.hpp>

#include"Vecteur.h"

class Coordonnees
{
public:
	void operator+= (Vecteur const& pos);
	inline float getX() const { return x; };
	inline float getY() const { return y; };
	static inline int getspaceX() { return spaceX; };
	static inline int getspaceY() { return spaceY; };
	static void initialiserEspace(int lx, int ly);
	Coordonnees();
	Coordonnees(float px, float py);
	float calculerDistance(Coordonnees const& autre) const;
private:
	float x{ spaceX / 2.f };
	float y{ spaceY / 2.f };

	static int spaceX;
	static int spaceY;

	void leDroitChemin();
};

