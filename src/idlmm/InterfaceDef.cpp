// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/InterfaceDef.cpp
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

#include "InterfaceDef.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/Container.hpp>
#include <idlmm/TypedefDef.hpp>
#include <idlmm/Contained.hpp>
#include <idlmm/InterfaceDef.hpp>
#include <idlmm/ForwardDef.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
InterfaceDef::InterfaceDef() :
    m_forward(0)
{
}

InterfaceDef::~InterfaceDef()
{
}

/*PROTECTED REGION ID(InterfaceDef.cpp) ENABLED START*/

void InterfaceDef::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

bool InterfaceDef::isIsAbstract() const
{
    return m_isAbstract;
}

void InterfaceDef::setIsAbstract(bool _isAbstract)
{
    m_isAbstract = _isAbstract;
}

bool InterfaceDef::isIsCustom() const
{
    return m_isCustom;
}

void InterfaceDef::setIsCustom(bool _isCustom)
{
    m_isCustom = _isCustom;
}

bool InterfaceDef::isIsTruncatable() const
{
    return m_isTruncatable;
}

void InterfaceDef::setIsTruncatable(bool _isTruncatable)
{
    m_isTruncatable = _isTruncatable;
}

// References
boost::ptr_vector< ::idlmm::InterfaceDef >& InterfaceDef::getDerivesFrom()
{
    return m_derivesFrom;
}

::idlmm::ForwardDef_ptr InterfaceDef::getForward()
{
    return m_forward;
}

void InterfaceDef::setForward(::idlmm::ForwardDef_ptr _forward)
{
    m_forward = _forward;
}

