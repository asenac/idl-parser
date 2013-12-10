// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/WstringDef.cpp
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

#include "WstringDef.hpp"
#include <idlmm/IDLType.hpp>
#include <idlmm/Expression.hpp>





#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
WstringDef::WstringDef() :
    m_bound(0)
{

    /*PROTECTED REGION ID(WstringDefImpl__WstringDefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

WstringDef::~WstringDef()
{
    if (m_bound)
    {
        delete m_bound;
    }
}

/*PROTECTED REGION ID(WstringDef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::idlmm::Expression_ptr WstringDef::getBound()
{
    return m_bound;
}

void WstringDef::setBound(::idlmm::Expression_ptr _bound)
{
    ::idlmm::Expression_ptr _old_bound = m_bound;

    m_bound = _bound;

    delete _old_bound;
}

