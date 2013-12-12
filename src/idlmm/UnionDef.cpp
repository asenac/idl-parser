// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/UnionDef.cpp
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

#include "UnionDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/TypedefDef.hpp>
#include <idlmm/Container.hpp>
#include <idlmm/UnionField.hpp>
#include <idlmm/IDLType.hpp>
using namespace ::idlmm;

// Default constructor
UnionDef::UnionDef() :
    m_containedDiscrim(0), m_sharedDiscrim(0)
{
}

UnionDef::~UnionDef()
{
    if (m_containedDiscrim)
    {
        delete m_containedDiscrim;
    }
}

/*PROTECTED REGION ID(UnionDef.cpp) ENABLED START*/

void UnionDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
UnionDef::UnionMembers_t& UnionDef::getUnionMembers()
{
    return m_unionMembers;
}

::idlmm::IDLType_ptr UnionDef::getContainedDiscrim()
{
    return m_containedDiscrim;
}

void UnionDef::setContainedDiscrim(::idlmm::IDLType_ptr _containedDiscrim)
{
    ::idlmm::IDLType_ptr _old_containedDiscrim = m_containedDiscrim;

    m_containedDiscrim = _containedDiscrim;

    delete _old_containedDiscrim;
}

::idlmm::TypedefDef_ptr UnionDef::getSharedDiscrim()
{
    return m_sharedDiscrim;
}

void UnionDef::setSharedDiscrim(::idlmm::TypedefDef_ptr _sharedDiscrim)
{
    m_sharedDiscrim = _sharedDiscrim;
}

