// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ForwardDef.hpp
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

#ifndef IDLMM_FORWARDDEF_HPP
#define IDLMM_FORWARDDEF_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Contained.hpp>

/*PROTECTED REGION ID(ForwardDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class ForwardDef: public virtual ::idlmm::Contained
    {
    public:
        ForwardDef();

        virtual ~ForwardDef();

        // Operations
        // Attributes

        // References
        ::idlmm::InterfaceDef_ptr getDefinition();
        void setDefinition(::idlmm::InterfaceDef_ptr _definition);

        /*PROTECTED REGION ID(ForwardDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(ForwardDefImpl) ENABLED START*/

        virtual void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes
        // References

        ::idlmm::InterfaceDef_ptr m_definition;

    };

} // idlmm

#endif // IDLMM_FORWARDDEF_HPP
