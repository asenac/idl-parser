// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ConstantDefRefImpl.cpp
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

#include "ConstantDefRef.hpp"
#include <idlmm/IdlmmPackage.hpp>
#include <idlmm/LiteralExpression.hpp>
#include <idlmm/Constant.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::idlmm;

/*PROTECTED REGION ID(ConstantDefRefImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void ConstantDefRef::_initialize()
{
    // Supertypes
    ::idlmm::LiteralExpression::_initialize();

    // Rerefences

    /*PROTECTED REGION ID(ConstantDefRefImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject ConstantDefRef::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::CONSTANTDEFREF__CONSTANT:
    {
        _any = static_cast< ::ecore::EObject* > (m_constant);
    }
        return _any;

    }
    throw "Error";
}

void ConstantDefRef::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::CONSTANTDEFREF__CONSTANT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Constant_ptr _t1 = dynamic_cast< ::idlmm::Constant_ptr > (_t0);
        ::idlmm::ConstantDefRef::setConstant(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean ConstantDefRef::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::CONSTANTDEFREF__CONSTANT:
        return m_constant;

    }
    throw "Error";
}

void ConstantDefRef::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr ConstantDefRef::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::idlmm::IdlmmPackage_ptr > (::idlmm::IdlmmPackage::_instance())->getConstantDefRef();
    return _eclass;
}

