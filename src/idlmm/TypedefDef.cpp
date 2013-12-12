// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/TypedefDef.cpp
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

#include "TypedefDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/IDLType.hpp>
#include <idlmm/Contained.hpp>
#include <idlmm/Container.hpp>
using namespace ::idlmm;

// Default constructor
TypedefDef::TypedefDef()
{

    /*PROTECTED REGION ID(TypedefDefImpl__TypedefDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

}

TypedefDef::~TypedefDef()
{
}

/*PROTECTED REGION ID(TypedefDef.cpp) ENABLED START*/

void TypedefDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References

