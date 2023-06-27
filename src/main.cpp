#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../include/Game.hpp"
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

    // create goofy ass vector of pairs {Card card, int z-index}.
    std::vector<cardPair> hand;
    for (int i = 0; i < 4; i++)
    {
        Card card(am.getPointerToTexture(CARD_ONE), {300.f + i * 300.f, 900.f});
        hand.push_back({i, card});
    }

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
            if (card.card.update(deltaTime, &window))
            {
                for (auto &card2 : hand)
                    if (card2.zIndex > card.zIndex)
                        card2.zIndex -= 1;
                card.zIndex = hand.size() - 1;
            }

        // DRAW
        window.clear(sf::Color(75, 75, 75));
        for (int i = 0; i < hand.size(); i++)
            for (auto &card : hand)
                if (card.zIndex == i)
                    window.draw(card.card.sprite);

        window.display();
    }

    return 0;
}

// TODO:
// https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view