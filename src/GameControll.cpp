#pragma once
#include <iostream>
#include "GameControll.h"

GameControll::GameControll()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pacman"),
     m_menu(WINDOW_WIDTH, WINDOW_HEIGHT),
     m_matrix(),
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

void GameControll::StartGame()
{
    //init();
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        DrawGame();
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::KeyPressed:
            {
                m_pacman.UpdateDirection(event.key.code);
                break;
            }
            case sf::Event::KeyReleased:
            {
                m_pacman.UpdateDirection(sf::Keyboard::Space);
                break;
            }
            
            }
        }
        auto delta = m_game_clock.restart();
        m_pacman.Move(delta);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}

void GameControll::DrawGame()
{
    for (int row = 0; row < m_matrix.GetRow(); row++)
    {
        for (int col = 0; col < m_matrix.GetCol(); col++)
        {
            m_window.draw(m_board.GetRectangle(row, col));
        }
    }
    m_window.draw(m_pacman.GetPacman());
    //todo : draw pac
}

void GameControll::handleClick(const sf::Vector2f& location)
{
    if (m_menu.GetButton(VIDEO_PLAY).getGlobalBounds().contains(location))
    {
       PlayVideo();
    }
    else if (m_menu.GetButton(PLAY).getGlobalBounds().contains(location))
    {
        StartGame();
    }
    else if (m_menu.GetButton(HELP).getGlobalBounds().contains(location))
    {
        //Instructions
        DrawInstructions();
    }
    else if (m_menu.GetButton(EXIT).getGlobalBounds().contains(location))
    {
        m_window.close();
    }
}

void GameControll::hendleMouseMoved(const sf::Vector2f location)
{
    for (int button = VIDEO_PLAY ; button <= EXIT ; button++)
    {
        if ((m_menu.GetButton((Button)button).getGlobalBounds().contains(location)))
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
    for (int button = VIDEO_PLAY; button <= EXIT; ++button)
    {
        m_window.draw(m_menu.GetButton((Button)button));
    }

    for (int object = TITLE; object <= DEMONS; ++object)
    {
        m_window.draw(m_menu.GetTitle((Title)object));
    }
}

void GameControll::DrawInstructions()
{
    bool exit = false;
    while (!exit)
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_window.draw(m_menu.GetInstructions(INSTRUCTION));
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            //handle every case of event
            switch (event.type)
            {
            case sf::Event::Closed:
                exit = true;
                break;

            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                break;
            }

            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            }

            }
        }
    }
}

void GameControll::PlayVideo()
{
    int pacman_chat_box = 0;
    int demons_chat_box = 0;
    int title = 255;

    while (m_window.isOpen())
    {
        while (pacman_chat_box != 255)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(HELLO, pacman_chat_box, 5);
        }

        while (demons_chat_box != 255)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(WANNA_PLAY, demons_chat_box, 5);
        }

        while (pacman_chat_box != 0)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(HELLO, pacman_chat_box, -5);
        }

        while (pacman_chat_box != 255)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(LETS_GO, pacman_chat_box, 5);
        }

        while (demons_chat_box != 0)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(WANNA_PLAY, demons_chat_box, -5);
        }

        while (pacman_chat_box != 0)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(LETS_GO, pacman_chat_box, -5);
        }

        m_menu.UpdateVisible(PACMAN, title, 255);
        m_menu.UpdateVisible(DEMONS, title, 255);

        while (title != 0)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(TITLE, title, -5);
        }
        
        m_menu.Mirror(PACMAN);
        m_menu.GetTitle(PACMAN).setOrigin(m_menu.GetTitle(PACMAN).getGlobalBounds().width, 0);
        while (m_menu.GetTitle(DEMONS).getPosition().x > -m_menu.GetTitle(DEMONS).getGlobalBounds().width)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateLocation(PACMAN, -5);
            m_menu.UpdateLocation(DEMONS, -5);
        }

        //ends
        m_menu.Mirror(PACMAN);
        m_menu.GetTitle(PACMAN).setOrigin(0, 0);
        m_menu.ResetLocation();
        m_menu.UpdateVisible(PACMAN, title, 0);
        m_menu.UpdateVisible(DEMONS, title, 0);

        while( title != 255)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.UpdateVisible(TITLE, title, 5);
        }
        break;
    }
}


