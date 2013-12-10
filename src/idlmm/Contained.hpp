// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Contained.hpp
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

#ifndef IDLMM_CONTAINED_HPP
#define IDLMM_CONTAINED_HPP

#include <idlmm_forward.hpp>

#include <idlmm/NamedElement.hpp>

/*PROTECTED REGION ID(Contained_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class Contained: public virtual ::idlmm::NamedElement
    {
    public:
        Contained();

        virtual ~Contained();

        // Operations
        // Attributes
        std::string const& getRepositoryId() const;
        void setRepositoryId(std::string const& _repositoryId);

        std::string const& getVersion() const;
        void setVersion(std::string const& _version);

        std::string const& getAbsoluteName() const;
        void setAbsoluteName(std::string const& _absoluteName);

        // References
        ::idlmm::Container_ptr getDefinedIn();
        void setDefinedIn(::idlmm::Container_ptr _definedIn);

        /*PROTECTED REGION ID(Contained) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(ContainedImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_repositoryId;

        std::string m_version;

        std::string m_absoluteName;

        // References

        ::idlmm::Container_ptr m_definedIn;

    };

} // idlmm

#endif // IDLMM_CONTAINED_HPP
