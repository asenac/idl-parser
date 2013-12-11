// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ArrayDef.hpp
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

#ifndef IDLMM_ARRAYDEF_HPP
#define IDLMM_ARRAYDEF_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Typed.hpp>
#include <idlmm/IDLType.hpp>

/*PROTECTED REGION ID(ArrayDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class ArrayDef: public virtual ::idlmm::Typed,
            public virtual ::idlmm::IDLType
    {
    public:
        ArrayDef();

        virtual ~ArrayDef();

        // Operations
        // Attributes
        std::string const& getName() const;
        void setName(std::string const& _name);

        // References
        boost::ptr_vector< ::idlmm::Expression >& getBounds();

        /*PROTECTED REGION ID(ArrayDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(ArrayDefImpl) ENABLED START*/

        void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_name;

        // References

        boost::ptr_vector<
                ::idlmm::Expression > m_bounds;

    };

} // idlmm

#endif // IDLMM_ARRAYDEF_HPP
