#pragma once

#include "Matrix.h"

Matrix::Matrix() 
{
    ReadLevel();
}

bool Matrix::ReadLevel()
{
    if(!m_file.eof())
    {
        m_file >> m_row >> m_col;
        m_file.get(); //for /n

        for (int row = 0; row < m_row; ++row)
        {
            std::string row_string;
            std::getline(m_file, row_string);
            std::vector <char> row_vector;
            for (int col = 0; col < m_col; ++col)
            {
                row_vector.push_back(row_string[col]);
            }
            m_matrix.push_back(row_vector);
        }
        return true;
    }
    return false;
}

const int Matrix::GetRow() const
{
    return m_row;
}

const int Matrix::GetCol() const
{
    return m_col;
}

const char Matrix::GetChar(const int row, const int col)
{
    return m_matrix[row][col];
}

void Matrix::ClearMatrix()
{
    for (int row = 0; row < m_row; ++row)
    {
         m_matrix[row].clear();
	}
    m_matrix.clear();
}

void Matrix::Reset()
{
    m_file.seekg(0);
}
