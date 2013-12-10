// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/InterfaceDef.hpp
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

#ifndef IDLMM_INTERFACEDEF_HPP
#define IDLMM_INTERFACEDEF_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Container.hpp>
#include <idlmm/TypedefDef.hpp>

/*PROTECTED REGION ID(InterfaceDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class InterfaceDef: public virtual ::idlmm::Container,
            public virtual ::idlmm::TypedefDef
    {
    public:
        InterfaceDef();

        virtual ~InterfaceDef();

        // Operations
        // Attributes
        bool isIsAbstract() const;
        void setIsAbstract(bool _isAbstract);

        bool isIsCustom() const;
        void setIsCustom(bool _isCustom);

        bool isIsTruncatable() const;
        void setIsTruncatable(bool _isTruncatable);

        // References
        boost::ptr_vector< ::idlmm::InterfaceDef >& getDerivesFrom();

        ::idlmm::ForwardDef_ptr getForward();
        void setForward(::idlmm::ForwardDef_ptr _forward);

        /*PROTECTED REGION ID(InterfaceDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(InterfaceDefImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        bool m_isAbstract;

        bool m_isCustom;

        bool m_isTruncatable;

        // References

        boost::ptr_vector<
                ::idlmm::InterfaceDef > m_derivesFrom;

        ::idlmm::ForwardDef_ptr m_forward;

    };

} // idlmm

#endif // IDLMM_INTERFACEDEF_HPP
