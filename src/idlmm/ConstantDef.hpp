// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ConstantDef.hpp
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

#ifndef IDLMM_CONSTANTDEF_HPP
#define IDLMM_CONSTANTDEF_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Contained.hpp>
#include <idlmm/Typed.hpp>
#include <idlmm/Constant.hpp>

/*PROTECTED REGION ID(ConstantDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class ConstantDef: public virtual ::idlmm::Contained,
            public virtual ::idlmm::Typed,
            public virtual ::idlmm::Constant
    {
    public:
        ConstantDef();

        virtual ~ConstantDef();

        // Operations
        // Attributes

        // References
        ::idlmm::Expression_ptr getConstValue();
        void setConstValue(::idlmm::Expression_ptr _constValue);

        /*PROTECTED REGION ID(ConstantDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(ConstantDefImpl) ENABLED START*/

        virtual void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes
        // References

        ::idlmm::Expression_ptr m_constValue;

    };

} // idlmm

#endif // IDLMM_CONSTANTDEF_HPP
