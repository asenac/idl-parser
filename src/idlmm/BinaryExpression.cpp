// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/BinaryExpression.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "BinaryExpression.hpp"
#include <idlmm/Expression.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
BinaryExpression::BinaryExpression() :
    m_left(0), m_right(0)
{

    /*PROTECTED REGION ID(BinaryExpressionImpl__BinaryExpressionImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

BinaryExpression::~BinaryExpression()
{
    if (m_left)
    {
        delete m_left;
    }
    if (m_right)
    {
        delete m_right;
    }
}

/*PROTECTED REGION ID(BinaryExpression.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& BinaryExpression::getOperator() const
{
    return m_operator;
}

void BinaryExpression::setOperator(std::string const& _operator)
{
    m_operator = _operator;
}

// References
::idlmm::Expression_ptr BinaryExpression::getLeft()
{
    return m_left;
}

void BinaryExpression::setLeft(::idlmm::Expression_ptr _left)
{
    ::idlmm::Expression_ptr _old_left = m_left;

    m_left = _left;

    delete _old_left;
}

::idlmm::Expression_ptr BinaryExpression::getRight()
{
    return m_right;
}

void BinaryExpression::setRight(::idlmm::Expression_ptr _right)
{
    ::idlmm::Expression_ptr _old_right = m_right;

    m_right = _right;

    delete _old_right;
}

