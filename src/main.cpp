#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../include/Card.hpp"
#include "../include/AssetManager.hpp"
#include "../include/CardList.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1600, 900), "xolra");
    sf::Clock clock;
    AssetManager am;

    am.addTexture(CARD_ONE, "assets/card.png");

    std::vector<Card> hand;
    for (int i = 0; i < 4; i++)
    {
        Card card(am.getPointerToTexture(CARD_ONE), {300.f + i * 300.f, 900.f});
        hand.push_back(card);
    }

    // Card card3("assets/card.png", {600.f, 400.f});

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        // UPDATE
        float deltaTime = clock.restart().asSeconds();
        for (auto &card : hand)
            card.update(deltaTime, &window);

        //   card3.update(deltaTime, &window);

        // DRAW
        window.clear(sf::Color(75, 75, 75));
        for (auto &card : hand)
            window.draw(card.sprite);
        // window.draw(card3.sprite);
        window.display();
    }

    return 0;
}

// TODO:
// https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view