// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ExceptionDef.cpp
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

#include "ExceptionDef.hpp"
#include <idlmm/Contained.hpp>
#include <idlmm/Container.hpp>
#include <idlmm/Field.hpp>





#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
ExceptionDef::ExceptionDef()
{
}

ExceptionDef::~ExceptionDef()
{
}

/*PROTECTED REGION ID(ExceptionDef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::idlmm::ETypeCode ExceptionDef::getTypeCode() const
{
    return m_typeCode;
}

void ExceptionDef::setTypeCode(::idlmm::ETypeCode _typeCode)
{
    m_typeCode = _typeCode;
}

// References
boost::ptr_vector< ::idlmm::Field >& ExceptionDef::getMembers()
{
    return m_members;
}

