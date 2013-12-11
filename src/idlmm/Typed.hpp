// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Typed.hpp
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

#ifndef IDLMM_TYPED_HPP
#define IDLMM_TYPED_HPP

#include <idlmm_forward.hpp>
#include <idlmm/ModelElement.hpp>

/*PROTECTED REGION ID(Typed_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class Typed: public virtual ::idlmm::ModelElement
    {
    public:
        Typed();

        virtual ~Typed();

        // Operations
        // Attributes

        // References
        ::idlmm::IDLType_ptr getContainedType();
        void setContainedType(::idlmm::IDLType_ptr _containedType);

        ::idlmm::TypedefDef_ptr getSharedType();
        void setSharedType(::idlmm::TypedefDef_ptr _sharedType);

        /*PROTECTED REGION ID(Typed) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(TypedImpl) ENABLED START*/

        virtual void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes
        // References

        ::idlmm::IDLType_ptr m_containedType;

        ::idlmm::TypedefDef_ptr m_sharedType;

    };

} // idlmm

#endif // IDLMM_TYPED_HPP
