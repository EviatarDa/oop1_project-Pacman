#pragma once

#include "GameControll.h"

GameControll::GameControll()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pacman"),
     m_menu(WINDOW_WIDTH, WINDOW_HEIGHT),
     m_board(m_matrix.GetRow(), m_matrix.GetCol())
{
    m_window.setFramerateLimit(60);
}

void GameControll::run()
{
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::Color(0,0,0));
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

            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                hendleMouseMoved(location);
            }


            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}

void GameControll::handleClick(const sf::Vector2f& location)
{
    if (m_menu.GetSprite(PLAY).getGlobalBounds().contains(location))
    {
        //StartGame();
    }
    else if (m_menu.GetSprite(HELP).getGlobalBounds().contains(location))
    {
        //Instructions
    }
    else if (m_menu.GetSprite(EXIT).getGlobalBounds().contains(location))
    {
        m_window.close();
    }
}

void GameControll::hendleMouseMoved(const sf::Vector2f location)
{
    for (int button = PLAY ; button <= EXIT ; button++)
    {
        if ((m_menu.GetSprite((Button)button).getGlobalBounds().contains(location)))
        {
            m_menu.ButtonPress((Button)button);
        }
        else
        {
            m_menu.ButtonRelease((Button)button);
        }
    }
}

void GameControll::DrawMenu()
{
    m_window.draw(m_menu.GetSprite(TITLE));
    m_window.draw(m_menu.GetSprite(PLAY));
    m_window.draw(m_menu.GetSprite(HELP));
    m_window.draw(m_menu.GetSprite(EXIT));
    m_window.draw(m_menu.GetSprite(HELLO));
    m_window.draw(m_menu.GetSprite(WANNA_PLAY));

}


