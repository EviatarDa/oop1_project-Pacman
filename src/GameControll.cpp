#pragma once

#include "GameControll.h"

GameControll::GameControll()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pacman"),
    m_menu(WINDOW_WIDTH, WINDOW_HEIGHT)
{
    m_window.setFramerateLimit(60);
}

void GameControll::run()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        DrawMenu();
        m_window.display();
        
        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            //handle every case of event
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleClick(location);
                break;
            }
            }
        }
    }
}

void GameControll::handleClick(const sf::Vector2f&)
{

}

void GameControll::DrawMenu()
{
    m_window.draw(m_menu.GetSprite(BACKGROUND));
    m_window.draw(m_menu.GetSprite(PLAY));
    m_window.draw(m_menu.GetSprite(HELP));
    m_window.draw(m_menu.GetSprite(EXIT));
}


