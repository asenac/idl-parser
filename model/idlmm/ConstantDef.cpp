// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ConstantDef.cpp
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

#include "ConstantDef.hpp"
#include <idlmm/Contained.hpp>
#include <idlmm/Typed.hpp>
#include <idlmm/Constant.hpp>
#include <idlmm/Container.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/TypedefDef.hpp>
#include <idlmm/Expression.hpp>





#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
ConstantDef::ConstantDef() :
    m_constValue(0)
{

    /*PROTECTED REGION ID(ConstantDefImpl__ConstantDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    
#endif
}

ConstantDef::~ConstantDef()
{
    if (m_constValue)
    {
        delete m_constValue;
    }
}

/*PROTECTED REGION ID(ConstantDef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::idlmm::Expression_ptr ConstantDef::getConstValue()
{
    return m_constValue;
}

void ConstantDef::setConstValue(::idlmm::Expression_ptr _constValue)
{
    ::idlmm::Expression_ptr _old_constValue = m_constValue;

    m_constValue = _constValue;

    delete _old_constValue;
}

