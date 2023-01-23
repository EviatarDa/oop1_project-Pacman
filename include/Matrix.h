#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>

class Matrix
{
public:
	Matrix();
	bool ReadLevel();
	const int GetRow()const;
	const int GetCol()const;
	const char GetChar(const int, const int);
	void ClearMatrix();
	void Reset();

private:
	std::ifstream m_file = std::ifstream("Board.txt"); // where is he locate?>
	std::vector< std::vector <char> > m_matrix;
	int m_row;
	int m_col;

};