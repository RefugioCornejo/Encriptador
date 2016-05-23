//
//  MatrixManager.h
//  Encryption
//
//  Created by Refugio Cornejo on 4/9/16.
//  Copyright © 2016 Refugio Cornejo. All rights reserved.
//

#ifndef MatrixManager_h
#define MatrixManager_h
#include <iostream>
#include <cstdlib>

using namespace std;

class CMatrix
{
private:
    int m_rows;
    int m_cols;
    string m_name;
    
public:
    
    float **m_pData;
    CMatrix();
    float Determinant();
    CMatrix Inverse();
    CMatrix Adjoint();
    CMatrix Transpose();
    CMatrix CoFactor();
    string GetName();
    void GetInput();
    void SetName(string);

    CMatrix(string name, int rows, int cols) :
    m_rows(rows), m_cols(cols)
    {
        m_name=name;
        m_pData = new float*[m_rows];
        for (int i = 0; i < m_rows; i++)
            m_pData[i] = new float[m_cols];
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                m_pData[i][j] = 0.0;
            }
        }
    }
    CMatrix(const CMatrix &other)
    {
        m_name=other.m_name;
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_pData = new float*[m_rows];
        for (int i = 0; i < m_rows; i++)
            m_pData[i] = new float[m_cols];
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                m_pData[i][j] = other.m_pData[i][j];
            }
        }
    }
    CMatrix(int ** matrix, int n)
    {
        m_name="";
        m_rows=n;
        m_cols=n;
        m_pData = new float*[m_rows];
        for (int i = 0; i < m_rows; i++)
            m_pData[i] = new float[m_cols];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                m_pData[i][j]=matrix[i][j];
            }
        }
    }

    ~CMatrix()
    {
        for (int i = 0; i < m_rows; i++)
            delete[] m_pData[i];
        delete[] m_pData;
        m_rows = m_cols = 0;
    }
    
    CMatrix& operator =(const CMatrix &other)
    {
        if (this->m_rows != other.m_rows || this->m_cols != other.m_cols)
        {
            std::cout
            << "WARNING: Assignment is taking place with by changing the number of rows and columns of the matrix";
        }
        for (int i = 0; i < m_rows; i++)
            delete[] m_pData[i];
        delete[] m_pData;
        m_rows = m_cols = 0;
        m_name=other.m_name;
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_pData = new float*[m_rows];
        for (int i = 0; i < m_rows; i++)
            m_pData[i] = new float[m_cols];
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                m_pData[i][j] = other.m_pData[i][j];
            }
        }
        return *this;
    }
    CMatrix operator +(const CMatrix &other)
    {
        if (this->m_rows != other.m_rows || this->m_cols != other.m_cols)
        {
            std::cout
            << "Addition could not take place because number of rows and columns are different between the two matrices";
            return *this;
        }
        CMatrix result("", m_rows, m_cols);
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                result.m_pData[i][j] = this->m_pData[i][j]
                + other.m_pData[i][j];
            }
        }
        return result;
    }
    CMatrix operator -(const CMatrix &other)
    {
        if (this->m_rows != other.m_rows || this->m_cols != other.m_cols)
        {
            std::cout
            << "Subtraction could not take place because number of rows and columns are different between the two matrices";
            return *this;
        }
        CMatrix result("", m_rows, m_cols);
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                result.m_pData[i][j] = this->m_pData[i][j]
                - other.m_pData[i][j];
            }
        }
        return result;
    }
    CMatrix operator *(const CMatrix &other)
    {
        if (this->m_cols != other.m_rows)
        {
            std::cout
            << "Multiplication could not take place because number of columns of 1st Matrix and number of rows in 2nd Matrix are different";
            return *this;
        }
        CMatrix result("", this->m_rows, other.m_cols);
        for (int i = 0; i < this->m_rows; i++)
        {
            for (int j = 0; j < other.m_cols; j++)
            {
                for (int k = 0; k < this->m_cols; k++)
                {
                    result.m_pData[i][j] += this->m_pData[i][k]
                    * other.m_pData[k][j];
                }
            }
        }
        return result;
    }
    bool operator ==(const CMatrix &other)
    {
        if (this->m_rows != other.m_rows || this->m_cols != other.m_cols)
        {
            std::cout
            << "Comparision could not take place because number of rows and columns are different between the two matrices";
            return false;
        }
        CMatrix result("", m_rows, m_cols);
        bool bEqual = true;
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                if (this->m_pData[i][j] != other.m_pData[i][j])
                    bEqual = false;
            }
        }
        return bEqual;
    }
    friend std::istream& operator >>(std::istream &is, CMatrix &m);
    friend std::ostream& operator <<(std::ostream &os, const CMatrix &m);
};




#endif /* MatrixManager_h */
