// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ValueExpression.cpp
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

#include "ValueExpression.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/LiteralExpression.hpp>
using namespace ::idlmm;

// Default constructor
ValueExpression::ValueExpression()
{

    /*PROTECTED REGION ID(ValueExpressionImpl__ValueExpressionImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

}

ValueExpression::~ValueExpression()
{
}

/*PROTECTED REGION ID(ValueExpression.cpp) ENABLED START*/

void ValueExpression::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& ValueExpression::getValue() const
{
    return m_value;
}

void ValueExpression::setValue(std::string const& _value)
{
    m_value = _value;
}

// References

