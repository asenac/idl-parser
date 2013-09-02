// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/FixedDefImpl.cpp
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

#include "FixedDef.hpp"
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

/*PROTECTED REGION ID(FixedDefImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void FixedDef::_initialize()
{
    // Supertypes
    ::idlmm::IDLType::_initialize();

    // Rerefences
    if (m_digits)
    {
        m_digits->_initialize();
        m_digits->_setEContainer(this,
                ::idlmm::IdlmmPackage::_instance()->getFixedDef__digits());
    }
    if (m_scale)
    {
        m_scale->_initialize();
        m_scale->_setEContainer(this,
                ::idlmm::IdlmmPackage::_instance()->getFixedDef__scale());
    }

    /*PROTECTED REGION ID(FixedDefImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject FixedDef::eGet(::ecore::EInt _featureID,
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
    case ::idlmm::IdlmmPackage::FIXEDDEF__DIGITS:
    {
        _any = static_cast< ::ecore::EObject* > (m_digits);
    }
        return _any;
    case ::idlmm::IdlmmPackage::FIXEDDEF__SCALE:
    {
        _any = static_cast< ::ecore::EObject* > (m_scale);
    }
        return _any;

    }
    throw "Error";
}

void FixedDef::eSet(::ecore::EInt _featureID,
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
    case ::idlmm::IdlmmPackage::FIXEDDEF__DIGITS:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Expression_ptr _t1 =
                dynamic_cast< ::idlmm::Expression_ptr > (_t0);
        ::idlmm::FixedDef::setDigits(_t1);
    }
        return;
    case ::idlmm::IdlmmPackage::FIXEDDEF__SCALE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Expression_ptr _t1 =
                dynamic_cast< ::idlmm::Expression_ptr > (_t0);
        ::idlmm::FixedDef::setScale(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean FixedDef::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::IDLTYPE__TYPECODE:
        return ::ecorecpp::mapping::set_traits< ::idlmm::ETypeCode >::is_set(
                m_typeCode);
    case ::idlmm::IdlmmPackage::FIXEDDEF__DIGITS:
        return m_digits;
    case ::idlmm::IdlmmPackage::FIXEDDEF__SCALE:
        return m_scale;

    }
    throw "Error";
}

void FixedDef::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr FixedDef::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::idlmm::IdlmmPackage_ptr > (::idlmm::IdlmmPackage::_instance())->getFixedDef();
    return _eclass;
}

