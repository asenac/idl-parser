// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ModuleDef.cpp
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

#include "ModuleDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/Container.hpp>
#include <idlmm/Contained.hpp>
using namespace ::idlmm;

// Default constructor
ModuleDef::ModuleDef()
{

    /*PROTECTED REGION ID(ModuleDefImpl__ModuleDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

}

ModuleDef::~ModuleDef()
{
}

/*PROTECTED REGION ID(ModuleDef.cpp) ENABLED START*/

void ModuleDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& ModuleDef::getPrefix() const
{
    return m_prefix;
}

void ModuleDef::setPrefix(std::string const& _prefix)
{
    m_prefix = _prefix;
}

// References

