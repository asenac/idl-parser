// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Include.cpp
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

#include "Include.hpp"
#include "IdlmmVisitor.hpp"
#include <idlmm/ModelElement.hpp>
#include <idlmm/TranslationUnit.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
Include::Include() :
    m_translationUnit(0)
{

    /*PROTECTED REGION ID(IncludeImpl__IncludeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

Include::~Include()
{
}

/*PROTECTED REGION ID(Include.cpp) ENABLED START*/

void Include::accept(IdlmmVisitor& visitor)
{
    visitor.visit(this);
}

// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& Include::getImportURI() const
{
    return m_importURI;
}

void Include::setImportURI(std::string const& _importURI)
{
    m_importURI = _importURI;
}

// References
::idlmm::TranslationUnit_ptr Include::getTranslationUnit()
{
    return m_translationUnit;
}

void Include::setTranslationUnit(::idlmm::TranslationUnit_ptr _translationUnit)
{
    m_translationUnit = _translationUnit;
}

