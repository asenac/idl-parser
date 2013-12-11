// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/UnionField.hpp
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

#ifndef IDLMM_UNIONFIELD_HPP
#define IDLMM_UNIONFIELD_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Typed.hpp>

/*PROTECTED REGION ID(UnionField_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class UnionField: public virtual ::idlmm::Typed
    {
    public:
        UnionField();

        virtual ~UnionField();

        // Operations
        // Attributes
        std::string const& getIdentifier() const;
        void setIdentifier(std::string const& _identifier);

        // References
        boost::ptr_vector< ::idlmm::Expression >& getLabel();

        /*PROTECTED REGION ID(UnionField) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(UnionFieldImpl) ENABLED START*/

        void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_identifier;

        // References

        boost::ptr_vector<
                ::idlmm::Expression > m_label;

    };

} // idlmm

#endif // IDLMM_UNIONFIELD_HPP
