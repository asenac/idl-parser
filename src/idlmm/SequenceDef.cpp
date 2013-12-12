// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/SequenceDef.cpp
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

#include "SequenceDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/Typed.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/TypedefDef.hpp>
#include <idlmm/Expression.hpp>
using namespace ::idlmm;

// Default constructor
SequenceDef::SequenceDef() :
    m_bound(0)
{

    /*PROTECTED REGION ID(SequenceDefImpl__SequenceDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

}

SequenceDef::~SequenceDef()
{
    if (m_bound)
    {
        delete m_bound;
    }
}

/*PROTECTED REGION ID(SequenceDef.cpp) ENABLED START*/

void SequenceDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::idlmm::Expression_ptr SequenceDef::getBound()
{
    return m_bound;
}

void SequenceDef::setBound(::idlmm::Expression_ptr _bound)
{
    ::idlmm::Expression_ptr _old_bound = m_bound;

    m_bound = _bound;

    delete _old_bound;
}

