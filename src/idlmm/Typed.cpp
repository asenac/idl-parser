// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Typed.cpp
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

#include "Typed.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/ModelElement.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/TypedefDef.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
Typed::Typed() :
    m_containedType(0), m_sharedType(0)
{

    /*PROTECTED REGION ID(TypedImpl__TypedImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

Typed::~Typed()
{
    if (m_containedType)
    {
        delete m_containedType;
    }
}

/*PROTECTED REGION ID(Typed.cpp) ENABLED START*/

void Typed::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::idlmm::IDLType_ptr Typed::getContainedType()
{
    return m_containedType;
}

void Typed::setContainedType(::idlmm::IDLType_ptr _containedType)
{
    ::idlmm::IDLType_ptr _old_containedType = m_containedType;

    m_containedType = _containedType;

    delete _old_containedType;
}

::idlmm::TypedefDef_ptr Typed::getSharedType()
{
    return m_sharedType;
}

void Typed::setSharedType(::idlmm::TypedefDef_ptr _sharedType)
{
    m_sharedType = _sharedType;
}

