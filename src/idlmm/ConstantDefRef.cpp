// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ConstantDefRef.cpp
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

#include "ConstantDefRef.hpp"
#include <idlmm/LiteralExpression.hpp>
#include <idlmm/Constant.hpp>





#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
ConstantDefRef::ConstantDefRef() :
    m_constant(0)
{

    /*PROTECTED REGION ID(ConstantDefRefImpl__ConstantDefRefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

ConstantDefRef::~ConstantDefRef()
{
}

/*PROTECTED REGION ID(ConstantDefRef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::idlmm::Constant_ptr ConstantDefRef::getConstant()
{
    return m_constant;
}

void ConstantDefRef::setConstant(::idlmm::Constant_ptr _constant)
{
    m_constant = _constant;
}

