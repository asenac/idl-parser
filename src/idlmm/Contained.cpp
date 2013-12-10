// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Contained.cpp
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

#include "Contained.hpp"
#include <idlmm/NamedElement.hpp>
#include <idlmm/Container.hpp>

#ifdef ECORECPP_NOTIFICATION_API

#endif

using namespace ::idlmm;

// Default constructor
Contained::Contained() :
    m_definedIn(0)
{

    /*PROTECTED REGION ID(ContainedImpl__ContainedImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API

#endif
}

Contained::~Contained()
{
}

/*PROTECTED REGION ID(Contained.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

std::string const& Contained::getRepositoryId() const
{
    return m_repositoryId;
}

void Contained::setRepositoryId(std::string const& _repositoryId)
{
    m_repositoryId = _repositoryId;
}

std::string const& Contained::getVersion() const
{
    return m_version;
}

void Contained::setVersion(std::string const& _version)
{
    m_version = _version;
}

std::string const& Contained::getAbsoluteName() const
{
    return m_absoluteName;
}

void Contained::setAbsoluteName(std::string const& _absoluteName)
{
    m_absoluteName = _absoluteName;
}

// References
::idlmm::Container_ptr Contained::getDefinedIn()
{
    return m_definedIn;
}

void Contained::setDefinedIn(::idlmm::Container_ptr _definedIn)
{
    m_definedIn = _definedIn;
}

