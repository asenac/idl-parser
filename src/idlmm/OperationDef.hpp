// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/OperationDef.hpp
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

#ifndef IDLMM_OPERATIONDEF_HPP
#define IDLMM_OPERATIONDEF_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Contained.hpp>
#include <idlmm/Typed.hpp>

/*PROTECTED REGION ID(OperationDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class OperationDef: public virtual ::idlmm::Contained,
            public virtual ::idlmm::Typed
    {
    public:
        OperationDef();

        virtual ~OperationDef();

        // Operations
        // Attributes
        bool isIsOneway() const;
        void setIsOneway(bool _isOneway);

        // References
        boost::ptr_vector< ::idlmm::ParameterDef >& getParameters();

        boost::ptr_vector< ::idlmm::ExceptionDef >& getCanRaise();

        /*PROTECTED REGION ID(OperationDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(OperationDefImpl) ENABLED START*/

        void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        bool m_isOneway;

        // References

        boost::ptr_vector<
                ::idlmm::ParameterDef > m_parameters;

        boost::ptr_vector<
                ::idlmm::ExceptionDef > m_canRaise;

    };

} // idlmm

#endif // IDLMM_OPERATIONDEF_HPP
