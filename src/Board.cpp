#pragma once

#include "Board.h"

Board::Board()
	:m_matrix(), m_row(m_matrix.GetRow()), m_col(m_matrix.GetCol())
{
	CreateReactangles();
	InitVector();
}

int Board::GetRow() const
{
	return m_row;
}

int Board::GetCol() const
{
	return m_col;
}

int Board::GetCookies() const
{
	 return m_Cookies;
}

int Board::GetEattenCookies() const
{
	return m_MovingObject[m_PacmanIndex]->GetEatten();
}

bool Board::ReadNewLevel()
{
	m_matrix.ClearMatrix();
	ClearReactangles();
	if (m_matrix.ReadLevel())
	{
		InitLevel();
		CreateReactangles();
		return true;
	}
	return false;
}

void Board::ResetMatrix()
{
	m_matrix.Reset();
	if (m_matrix.ReadLevel())
	{
		InitLevel();
		CreateReactangles();
	}
}

void Board::UpdateDirection()
{
	for (int index = 0; index < m_MovingObject.size(); ++index)
	{
		m_MovingObject[index]->UpdateDirection(GetGameObjectMoving(m_PacmanIndex).getPosition());
	}
}


const sf::RectangleShape Board::CreateRectangle(const int row, const int col) const
{
	sf::RectangleShape rec;

	//Position
	rec.setSize(sf::Vector2f(50.f, 50.f));
	rec.setPosition((float)((1400 - m_col * 50.f) / 2 + (col * 50.f)),
					(float)((800 - m_row * 50.f) / 2 + (row * 50.f)));

	//Style
	rec.setOutlineColor(sf::Color::Color(102, 102, 102));
	rec.setOutlineThickness(0.f);
	rec.setFillColor(sf::Color::Color(224,224,224));

	return rec;
}

sf::RectangleShape Board::GetRectangle(const int row, const int col) const
{
	return m_RectangleMatrix[row][col];

}

void Board::InitVector()
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			char type = m_matrix.GetChar(row, col);
			if (type == 'a' || type == '&')
			{
				m_MovingObject.push_back(Getptrmove(type, row, col));
				if (type == 'a')
				{
					m_PacmanIndex =(int)m_MovingObject.size()-1;
				}
			}
			else if (type != ' ')
			{
				m_StaticObject.push_back(Getptrstatic(type, row, col));
			}
		}

	}
}

sf::Sprite Board::GetGameObjectMoving(const int index)
{
	return m_MovingObject[index]->GetSprite();
}

sf::Sprite Board::GetGameObjectStatic(const int index)
{
	return m_StaticObject[index]->GetSprite();
}

int Board::GetStaticSize() const
{
	return (int)m_StaticObject.size();
}

int Board::GetMoveSize() const
{
	return m_MovingObject.size();
}

void Board::MoveObjects(sf::Time delta)
{
	for (int index = 0; index < m_MovingObject.size(); index++)
	{
		m_MovingObject[index]->Move(delta);
		HandleCollisions(*m_MovingObject[index]);
	}
}

void Board::HandleCollisions(GameObject& game_object)
{
	for (int index = 0; index < m_StaticObject.size(); index++)
	{
		if (game_object.CheckCollision(*m_StaticObject[index]))
		{
			game_object.HandleCollision(*m_StaticObject[index]);
		}
	}
	std::erase_if(m_StaticObject, [](const auto& game_object) {return game_object->GetIsCollide(); });

	for (int index = 0; index < m_MovingObject.size(); index++)
	{
		if (game_object.CheckCollision(*m_MovingObject[index]))
		{
			game_object.HandleCollision(*m_MovingObject[index]);
		}
	}
}

int Board::ReturnPacmanLife() const
{
	return m_MovingObject[m_PacmanIndex]->GetLife();
}

int Board::ReturnPacmanScore() const
{
	return m_MovingObject[m_PacmanIndex]->GetScore();
}

int Board::ReturnPacmanKeys() const
{
	return m_MovingObject[m_PacmanIndex]->GetKeys();
}

void Board::UpdateMoving(int& added_time)
{
	for (int index = 0; index < m_MovingObject.size(); ++index)
	{
		m_MovingObject[index]->UpdateState(m_MovingObject[m_PacmanIndex]->GetFreeze(), added_time);
	}
	if (m_MovingObject[m_PacmanIndex]->GetResetLocation())
	{
		for (int index = 0; index < m_MovingObject.size(); ++index)
		{
			m_MovingObject[index]->ResetLocation();
		}
		m_MovingObject[m_PacmanIndex]->SetResetLocation();
	}
}

void Board::InitLevel()
{
	
	m_MovingObject.clear();
	m_StaticObject.clear();
	m_PacmanIndex = 0;
	m_Cookies = 0;
	m_col = m_matrix.GetCol();
	m_row = m_matrix.GetRow();
	InitVector();
	initData();
}

void Board::SetPacmanData(int life, int score)
{
	m_MovingObject[m_PacmanIndex]->SetLife(life);
	m_MovingObject[m_PacmanIndex]->SetScore(score);

}

std::unique_ptr<StaticObjects> Board::Getptrstatic(const char type, const int row, const int col)
{
	switch (type)
	{
	case 'D':
		return std::make_unique <Door>(row, col, m_row, m_col, DOOR);

	case '%':
		return std::make_unique<Key>(row, col, m_row, m_col, KEY);

	case '$': // superpacman
		return std::make_unique<SuperPresent>(row, col, m_row, m_col, SUPER_PRESENT);

	case 'F': //freeze
		return std::make_unique<Freeze>(row, col, m_row, m_col, FREEZE);

	case 'T'://addtime
		return std::make_unique<AddTime>(row, col, m_row, m_col, ADD_TIME);

	case 'L': // addlife
		return std::make_unique<AddLife>(row, col, m_row, m_col, ADD_LIFE);

	case '*':
		m_Cookies++;
		return std::make_unique<Cookie>(row, col, m_row, m_col, COOKIE);

	case '#':
		return std::make_unique<Wall>(row, col, m_row, m_col, WALL);

	}
}

std::unique_ptr<MovingObject> Board::Getptrmove(const char type, const int row, const int col) const
{
	switch (type)
	{

	case 'a':
		return std::make_unique<Pacman>(row, col, m_row, m_col, PACMAN);

	case '&':
	{
		static int add = 0;
		add++;
		add %= 4;
		return std::make_unique<Deamon>(row, col, m_row, m_col, (Object)(DEAMON_ORANGE + add), (Object)(DEAMON_ORANGE + add));///todo fix
	}
	}
}

void Board::CreateReactangles()
{
	for (int row = 0; row < m_row; ++row)
	{
		std::vector < sf::RectangleShape > vector_row;
		for (int col = 0; col < m_col; ++col)
		{
			vector_row.push_back(CreateRectangle(row, col)); // create the corrent row
		}
		m_RectangleMatrix.push_back(vector_row); // push the vector to the vector
	}
}

void Board::ClearReactangles()
{
	for (int row = 0; row < m_row; ++row)
	{

		m_RectangleMatrix[row].clear();
	}
	m_RectangleMatrix.clear();
}

void Board::initData()
{
	m_MovingObject[m_PacmanIndex]->SetCookies();
}


