// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/FixedDef.cpp
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

#include "FixedDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/IDLType.hpp>
#include <idlmm/Expression.hpp>
using namespace ::idlmm;

// Default constructor
FixedDef::FixedDef() :
    m_digits(0), m_scale(0)
{

    /*PROTECTED REGION ID(FixedDefImpl__FixedDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

}

FixedDef::~FixedDef()
{
    if (m_digits)
    {
        delete m_digits;
    }
    if (m_scale)
    {
        delete m_scale;
    }
}

/*PROTECTED REGION ID(FixedDef.cpp) ENABLED START*/

void FixedDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::idlmm::Expression_ptr FixedDef::getDigits()
{
    return m_digits;
}

void FixedDef::setDigits(::idlmm::Expression_ptr _digits)
{
    ::idlmm::Expression_ptr _old_digits = m_digits;

    m_digits = _digits;

    delete _old_digits;
}

::idlmm::Expression_ptr FixedDef::getScale()
{
    return m_scale;
}

void FixedDef::setScale(::idlmm::Expression_ptr _scale)
{
    ::idlmm::Expression_ptr _old_scale = m_scale;

    m_scale = _scale;

    delete _old_scale;
}

