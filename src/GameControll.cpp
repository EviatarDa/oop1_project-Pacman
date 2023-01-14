#pragma once
#include <iostream>
#include "GameControll.h"

GameControll::GameControll()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pacman"),
     m_menu(WINDOW_WIDTH, WINDOW_HEIGHT),
     m_board()
{
    m_window.setFramerateLimit(60);
    //PlayMusic();
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
    for (int row = 0; row < m_board.GetRow(); row++)
    {
        for (int col = 0; col < m_board.GetCol(); col++)
        {
            m_window.draw(m_board.GetRectangle(row, col));//get_object(row,col)
            
        }
    }
    for (int row = 0; row < m_board.GetRowVec(); row++)
    {
        for (int col = 0; col < m_board.GetColVec(row); col++)
        {
            m_window.draw(m_board.GetStaticObject(row, col));
        }
    }
    m_window.draw(m_pacman.GetPacman());
    //for loop:
    //m_window.draw(m_deamons.GetDeamon());
}

void GameControll::handleClick(const sf::Vector2f& location)
{
    if (m_menu.GetButton(PLAY).getGlobalBounds().contains(location))
    {
        PlayVideo();
        StartGame();
    }
    else if (m_menu.GetButton(HELP).getGlobalBounds().contains(location))
    {
        InstructionsLoop();
    }
    else if (m_menu.GetButton(EXIT).getGlobalBounds().contains(location))
    {
        m_window.close();
    }
}

void GameControll::handleNextClick(const sf::Vector2f& location, bool& exit)
{
    static int display = EVIATAR1;
    if (m_menu.GetButton(BACK).getGlobalBounds().contains(location))
    {
        m_menu.ResetRules();
        display = EVIATAR1;
        exit = true;
    }
    else if (m_menu.GetButton(VIDEO_PLAY).getGlobalBounds().contains(location))
    {
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
    for (int object = TITLE; object <= DEMONS; ++object)
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
            //handle every case of event
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

    //m_window.draw(m_menu.GetInstructions(SHIR));
    //m_window.draw(m_menu.GetInstructions(EVIATAR1));
    //m_window.draw(m_menu.GetInstructions(EVIATAR2));
    //m_window.draw(m_menu.GetInstructions(SHIR_DROP));
    //m_window.draw(m_menu.GetInstructions(EVIATAR_DROP));
    //m_window.draw(m_menu.GetInstructions(OH_NO));
    //m_window.draw(m_menu.GetInstructions(GAME_RULES));
    //m_window.draw(m_menu.GetButton(VIDEO_PLAY));
    //m_window.draw(m_menu.GetButton(BACK));
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

        m_menu.UpdateVisible(PACMAN, pacman, 255, 255);

        m_menu.UpdateVisible(DEMONS, deamons, 255, 255);

        BrighteningSprite(TITLE, title, -5, 0);

        m_menu.GetTitle(PACMAN).setOrigin(m_menu.GetTitle(PACMAN).getGlobalBounds().width / 2,
                                          m_menu.GetTitle(PACMAN).getGlobalBounds().height / 2);
        m_menu.Mirror(PACMAN);
        m_menu.GetTitle(PACMAN).setOrigin(m_menu.GetTitle(PACMAN).getGlobalBounds().width, 0);

        while (m_menu.GetTitle(DEMONS).getPosition().x > -m_menu.GetTitle(DEMONS).getGlobalBounds().width)
        {
            m_window.clear(sf::Color::Color(0, 0, 0));
            DrawMenu();
            m_window.display();
            m_menu.MoveObject(PACMAN, -5, 0);
            m_menu.MoveObject(DEMONS, -5, 0);
        }

        //ends
        m_menu.Mirror(PACMAN);
        m_menu.GetTitle(PACMAN).setOrigin(0, 0);
        m_menu.ResetLocation();
        m_menu.UpdateVisible(PACMAN, pacman, -255, 0);
        m_menu.UpdateVisible(DEMONS, deamons, -255, 0);
        m_menu.UpdateVisible(TITLE, title, 255, 255);

        break;
    }
}

void GameControll::PlayMusic()
{
    m_song.loadFromFile("Song.ogg");
    m_Sound.setBuffer(m_song);
    m_Sound.play();
    m_Sound.setLoop(true);
}


