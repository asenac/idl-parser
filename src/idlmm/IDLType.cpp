// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/IDLType.cpp
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

#include "IDLType.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/ModelElement.hpp>
using namespace ::idlmm;

// Default constructor
IDLType::IDLType()
{

    /*PROTECTED REGION ID(IDLTypeImpl__IDLTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

}

IDLType::~IDLType()
{
}

/*PROTECTED REGION ID(IDLType.cpp) ENABLED START*/

void IDLType::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::idlmm::ETypeCode IDLType::getTypeCode() const
{
    return m_typeCode;
}

void IDLType::setTypeCode(::idlmm::ETypeCode _typeCode)
{
    m_typeCode = _typeCode;
}

// References

