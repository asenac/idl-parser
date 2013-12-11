// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/AttributeDef.cpp
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

#include "AttributeDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/Contained.hpp>
#include <idlmm/Typed.hpp>
#include <idlmm/Container.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/TypedefDef.hpp>
#include <idlmm/ExceptionDef.hpp>
using namespace ::idlmm;

// Default constructor
AttributeDef::AttributeDef()
{
}

AttributeDef::~AttributeDef()
{
}

/*PROTECTED REGION ID(AttributeDef.cpp) ENABLED START*/

void AttributeDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

bool AttributeDef::isIsReadonly() const
{
    return m_isReadonly;
}

void AttributeDef::setIsReadonly(bool _isReadonly)
{
    m_isReadonly = _isReadonly;
}

// References
boost::ptr_vector< ::idlmm::ExceptionDef >& AttributeDef::getGetRaises()
{
    return m_getRaises;
}

boost::ptr_vector< ::idlmm::ExceptionDef >& AttributeDef::getSetRaises()
{
    return m_setRaises;
}

