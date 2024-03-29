#pragma once
#include <iostream>
#include "GameControll.h"

GameControll::GameControll()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pacman"),
     m_menu(WINDOW_WIDTH, WINDOW_HEIGHT),
     m_board()
{
    m_window.setFramerateLimit(60);
    m_Sound[0].setBuffer(m_resource.GetSound(SONG));
    m_Sound[1].setBuffer(m_resource.GetSound(GAME_OVER));
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
                handleMouseMoved(location, PLAY, EXIT);
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
    //reset variabels
    m_MoveClock.restart();
    m_GameClock.restart();
    m_board.ResetMatrix();

    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::Color(0, 102, 102)); // blue
        DrawGame();
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
        m_board.UpdateDirection(); //update moving directions
        m_board.UpdateMoving(m_AddedTime); // update moving objects below the situation
        auto delta = m_MoveClock.restart(); 
        m_board.MoveObjects(delta); // move all moving objects
        UpdateData();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }

        if (m_board.ReturnPacmanLife() == 0) //lose
        {
            m_Sound[1].play(); 
            m_level = 0;
            break;
        }

        else if (m_board.GetCookies() - m_board.GetEattenCookies() == 0) // next level
        {
            if (m_board.ReadNewLevel())
            {
                m_board.SetPacmanData(m_toolbar.GetLife(),m_toolbar.GetScore());
                m_level++;
                m_GameClock.restart();
            }
            else // end of the game
            {
                m_level = 0;
                break;
            }
        }
        else if (m_GameClock.getElapsedTime().asSeconds() > 120 + m_AddedTime) // time over
        {
            m_board.InitLevel();
            m_GameClock.restart();
        }

    }
}

void GameControll::DrawGame()
{
    DrawToolBar();
    for (int row = 0; row < m_board.GetRow(); row++)
    {
        for (int col = 0; col < m_board.GetCol(); col++)
        {
            m_window.draw(m_board.GetRectangle(row, col));
        }
    }

    for (int index = 0; index < m_board.GetStaticSize(); index++)
    {
        m_window.draw(m_board.GetGameObjectStatic(index));
    }

    for (int index = 0; index < m_board.GetMoveSize(); index++)
    {
        m_window.draw(m_board.GetGameObjectMoving(index));
    }
}

void GameControll::handleClick(const sf::Vector2f& location)
{
    if (m_menu.GetButton(PLAY).getGlobalBounds().contains(location))
    {
        m_menu.PlaySound(CLICK);
        m_Sound[0].play();
        PlayVideo();
        StartGame();
    }
    else if (m_menu.GetButton(HELP).getGlobalBounds().contains(location))
    {
        m_menu.PlaySound(CLICK);
        InstructionsLoop();
    }
    else if (m_menu.GetButton(EXIT).getGlobalBounds().contains(location))
    {
        m_menu.PlaySound(CLICK);
        m_window.close();
    }
}

void GameControll::handleNextClick(const sf::Vector2f& location, bool& exit)
{
    static int display = EVIATAR1;
    if (m_menu.GetButton(BACK).getGlobalBounds().contains(location))
    {
        m_menu.PlaySound(CLICK);
        m_menu.ResetRules();
        display = EVIATAR1;
        exit = true;
    }
    else if (m_menu.GetButton(VIDEO_PLAY).getGlobalBounds().contains(location))
    {
        m_menu.PlaySound(CLICK);
        switch (display)
        {
        case EVIATAR1:
        {
            m_menu.DisplayRules();
            display = SHIR;
            break;
        }
        case SHIR:
        {
            m_menu.DropTheMic();
            break;
        }

        default:
            break;
        }
    }
}

void GameControll::handleMouseMoved(const sf::Vector2f location, const Button first, const Button last)
{
    for (int button = first; button <= last; button++)
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
    for (int object = TITLE; object <= TITLE_DEAMONS; ++object)
    {
        m_window.draw(m_menu.GetTitle((Title)object));
    }

    for (int button = PLAY; button <= EXIT; ++button)
    {
        m_window.draw(m_menu.GetButton((Button)button));
    }
}

void GameControll::InstructionsLoop()
{
    bool exit = false;
    while (!exit)
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        DrawInstructions();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                exit = true;
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleNextClick(location, exit);
                break;
            }

            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                handleMouseMoved(location, VIDEO_PLAY, BACK);
            }

            }
        }
    }
}

void GameControll::DrawInstructions()
{
    for (int object = SHIR; object <= GAME_RULES; ++object)
    {
        m_window.draw(m_menu.GetInstructions((Instructions)object));
    }
    for (int object = VIDEO_PLAY; object <= BACK; ++object)
    {
        m_window.draw(m_menu.GetButton((Button)object));
    }
}

void GameControll::BrighteningSprite(Title object, int& curr_brightness, int add, int brightness)
{
    while (curr_brightness != brightness)
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        DrawMenu();
        m_window.display();
        m_menu.UpdateVisible(object, curr_brightness, add, brightness);
    }
}

void GameControll::PlayVideo()
{
    int pacman_chat_box = 0;
    int demons_chat_box = 0;
    int title = 255;
    int pacman = 0;
    int deamons = 0;

    while (m_window.isOpen())
    {
        BrighteningSprite(HELLO, pacman_chat_box, 5, 255);

        BrighteningSprite(WANNA_PLAY, demons_chat_box, 5, 255);

        BrighteningSprite(HELLO, pacman_chat_box, -5, 0);

        BrighteningSprite(LETS_GO, pacman_chat_box, 5, 255);

        BrighteningSprite(WANNA_PLAY, demons_chat_box, -5, 0);

        BrighteningSprite(LETS_GO, pacman_chat_box, -5, 0);

        m_menu.UpdateVisible(TITLE_PACMAN, pacman, 255, 255);

        m_menu.UpdateVisible(TITLE_DEAMONS, deamons, 255, 255);

        BrighteningSprite(TITLE, title, -5, 0);

        m_menu.GetTitle(TITLE_PACMAN).setOrigin(m_menu.GetTitle(TITLE_PACMAN).getGlobalBounds().width / 2,
                                          m_menu.GetTitle(TITLE_PACMAN).getGlobalBounds().height / 2);
        m_menu.Mirror(TITLE_PACMAN);
        m_menu.GetTitle(TITLE_PACMAN).setOrigin(m_menu.GetTitle(TITLE_PACMAN).getGlobalBounds().width, 0);

        while (m_menu.GetTitle(TITLE_DEAMONS).getPosition().x > -m_menu.GetTitle(TITLE_DEAMONS).getGlobalBounds().width)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.MoveObject(TITLE_PACMAN, -10, 0);
            m_menu.MoveObject(TITLE_DEAMONS, -10, 0);
        }

        //ends
        m_menu.Mirror(TITLE_PACMAN);
        m_menu.GetTitle(TITLE_PACMAN).setOrigin(0, 0);
        m_menu.ResetLocation();
        m_menu.UpdateVisible(TITLE_PACMAN, pacman, -255, 0);
        m_menu.UpdateVisible(TITLE_DEAMONS, deamons, -255, 0);
        m_menu.UpdateVisible(TITLE, title, 255, 255);

        break;
    }
}


void GameControll::DrawToolBar()
{
    for (int word = LIFE; word <= KEYCOUNTER; word++)
    {
        m_window.draw(m_toolbar.GetText(word));
        m_window.draw(m_toolbar.GetNum(word));
    }
}

void GameControll::UpdateData()
{
    //update the toolbar data
    m_toolbar.SetLife(m_board.ReturnPacmanLife());
    m_toolbar.SetScore(m_board.ReturnPacmanScore());
    m_toolbar.SetLevel(m_level);
    m_toolbar.SetKeys(m_board.ReturnPacmanKeys());
    m_toolbar.SetTime(m_GameClock.getElapsedTime().asSeconds() - m_AddedTime);
}


