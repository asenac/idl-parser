// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/TranslationUnit.hpp
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

#ifndef IDLMM_TRANSLATIONUNIT_HPP
#define IDLMM_TRANSLATIONUNIT_HPP

#include <idlmm_forward.hpp>



#include <idlmm/ModelElement.hpp>

/*PROTECTED REGION ID(TranslationUnit_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class TranslationUnit: public virtual ::idlmm::ModelElement
    {
    public:
        TranslationUnit();

        virtual ~TranslationUnit();



        // Operations


        // Attributes
        std::string const& getIdentifier() const;
        void setIdentifier(std::string const& _identifier);

        // References
        boost::ptr_vector< ::idlmm::Contained >& getContains();

        boost::ptr_vector< ::idlmm::Include >& getIncludes();

        /*PROTECTED REGION ID(TranslationUnit) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl








        /*PROTECTED REGION ID(TranslationUnitImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_identifier;

        // References

        boost::ptr_vector<
                ::idlmm::Contained > m_contains;

        boost::ptr_vector<
                ::idlmm::Include > m_includes;

    };

} // idlmm

#endif // IDLMM_TRANSLATIONUNIT_HPP
