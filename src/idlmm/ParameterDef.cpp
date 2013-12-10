// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ParameterDef.cpp
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

#include "ParameterDef.hpp"
#include <idlmm/Typed.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/TypedefDef.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
ParameterDef::ParameterDef()
{

    /*PROTECTED REGION ID(ParameterDefImpl__ParameterDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

ParameterDef::~ParameterDef()
{
}

/*PROTECTED REGION ID(ParameterDef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& ParameterDef::getIdentifier() const
{
    return m_identifier;
}

void ParameterDef::setIdentifier(std::string const& _identifier)
{
    m_identifier = _identifier;
}

::idlmm::ParameterMode ParameterDef::getDirection() const
{
    return m_direction;
}

void ParameterDef::setDirection(::idlmm::ParameterMode _direction)
{
    m_direction = _direction;
}

// References

