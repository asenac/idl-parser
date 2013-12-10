// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Include.hpp
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

#ifndef IDLMM_INCLUDE_HPP
#define IDLMM_INCLUDE_HPP

#include <idlmm_forward.hpp>

#include <idlmm/ModelElement.hpp>

/*PROTECTED REGION ID(Include_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class Include: public virtual ::idlmm::ModelElement
    {
    public:
        Include();

        virtual ~Include();

        // Operations
        // Attributes
        std::string const& getImportURI() const;
        void setImportURI(std::string const& _importURI);

        // References
        ::idlmm::TranslationUnit_ptr getTranslationUnit();
        void setTranslationUnit(::idlmm::TranslationUnit_ptr _translationUnit);

        /*PROTECTED REGION ID(Include) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(IncludeImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_importURI;

        // References

        ::idlmm::TranslationUnit_ptr m_translationUnit;

    };

} // idlmm

#endif // IDLMM_INCLUDE_HPP
