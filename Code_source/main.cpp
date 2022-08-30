#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include "Asteroide.h"

#include <array>
using namespace std;

constexpr int LONGUEUR_FENETRE{ 1920 };
constexpr int HAUTEUR_FENETRE{ 1080 };

int main()
{
    sf::RenderWindow window(sf::VideoMode(LONGUEUR_FENETRE, HAUTEUR_FENETRE), "Asteroids"); 
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
    auto vaisseau = Vaisseau();
    auto asteroide = Asteroide{};
    auto asteroide2 = Asteroide{};
    auto asteroide3 = Asteroide{};
    auto elements = array <ElementEspace*, 4> {&asteroide, &asteroide2, &asteroide3, &vaisseau};
    auto chrono = sf::Clock{};
    while (window.isOpen()) //boucle ouverture fenetre
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        vaisseau.actualiserEtat();
        auto tempsBoucle = chrono.restart().asSeconds();

        for (auto* element : elements)
        {
            element -> mettreAJour(tempsBoucle);
        }

        for (auto* element : elements)
        {
            if (element != &vaisseau)
            {
                element->testerCollision(vaisseau);
            }
        }

        window.clear();
        for (auto* element : elements)
        {
            element -> afficher(window);
        }
        window.display();
    }

    return 0;
}