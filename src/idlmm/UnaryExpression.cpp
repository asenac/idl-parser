// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/UnaryExpression.cpp
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

#include "UnaryExpression.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/Expression.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
UnaryExpression::UnaryExpression() :
    m_expression(0)
{

    /*PROTECTED REGION ID(UnaryExpressionImpl__UnaryExpressionImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

UnaryExpression::~UnaryExpression()
{
    if (m_expression)
    {
        delete m_expression;
    }
}

/*PROTECTED REGION ID(UnaryExpression.cpp) ENABLED START*/

void UnaryExpression::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& UnaryExpression::getOperator() const
{
    return m_operator;
}

void UnaryExpression::setOperator(std::string const& _operator)
{
    m_operator = _operator;
}

// References
::idlmm::Expression_ptr UnaryExpression::getExpression()
{
    return m_expression;
}

void UnaryExpression::setExpression(::idlmm::Expression_ptr _expression)
{
    ::idlmm::Expression_ptr _old_expression = m_expression;

    m_expression = _expression;

    delete _old_expression;
}

