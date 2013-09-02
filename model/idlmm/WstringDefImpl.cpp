// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/WstringDefImpl.cpp
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

#include "WstringDef.hpp"
#include <idlmm/IdlmmPackage.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/Expression.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::idlmm;

/*PROTECTED REGION ID(WstringDefImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void WstringDef::_initialize()
{
    // Supertypes
    ::idlmm::IDLType::_initialize();

    // Rerefences
    if (m_bound)
    {
        m_bound->_initialize();
        m_bound->_setEContainer(this,
                ::idlmm::IdlmmPackage::_instance()->getWstringDef__bound());
    }

    /*PROTECTED REGION ID(WstringDefImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject WstringDef::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::IDLTYPE__TYPECODE:
    {
        ::ecorecpp::mapping::any_traits< ::idlmm::ETypeCode >::toAny(_any,
                m_typeCode);
    }
        return _any;
    case ::idlmm::IdlmmPackage::WSTRINGDEF__BOUND:
    {
        _any = static_cast< ::ecore::EObject* > (m_bound);
    }
        return _any;

    }
    throw "Error";
}

void WstringDef::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::IDLTYPE__TYPECODE:
    {
        ::ecorecpp::mapping::any_traits< ::idlmm::ETypeCode >::fromAny(
                _newValue, m_typeCode);
    }
        return;
    case ::idlmm::IdlmmPackage::WSTRINGDEF__BOUND:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Expression_ptr _t1 =
                dynamic_cast< ::idlmm::Expression_ptr > (_t0);
        ::idlmm::WstringDef::setBound(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean WstringDef::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::IDLTYPE__TYPECODE:
        return ::ecorecpp::mapping::set_traits< ::idlmm::ETypeCode >::is_set(
                m_typeCode);
    case ::idlmm::IdlmmPackage::WSTRINGDEF__BOUND:
        return m_bound;

    }
    throw "Error";
}

void WstringDef::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr WstringDef::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::idlmm::IdlmmPackage_ptr > (::idlmm::IdlmmPackage::_instance())->getWstringDef();
    return _eclass;
}

