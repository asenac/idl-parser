// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/OperationDef.cpp
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

#include "OperationDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/Contained.hpp>
#include <idlmm/Typed.hpp>
#include <idlmm/Container.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/TypedefDef.hpp>
#include <idlmm/ParameterDef.hpp>
#include <idlmm/ExceptionDef.hpp>
using namespace ::idlmm;

// Default constructor
OperationDef::OperationDef()
{
}

OperationDef::~OperationDef()
{
}

/*PROTECTED REGION ID(OperationDef.cpp) ENABLED START*/

void OperationDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

bool OperationDef::isIsOneway() const
{
    return m_isOneway;
}

void OperationDef::setIsOneway(bool _isOneway)
{
    m_isOneway = _isOneway;
}

// References
OperationDef::Parameters_t& OperationDef::getParameters()
{
    return m_parameters;
}

OperationDef::CanRaise_t& OperationDef::getCanRaise()
{
    return m_canRaise;
}

