// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/BinaryExpressionImpl.cpp
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

#include "BinaryExpression.hpp"
#include <idlmm/IdlmmPackage.hpp>
#include <idlmm/Expression.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::idlmm;

/*PROTECTED REGION ID(BinaryExpressionImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void BinaryExpression::_initialize()
{
    // Supertypes
    ::idlmm::Expression::_initialize();

    // Rerefences
    if (m_left)
    {
        m_left->_initialize();
        m_left->_setEContainer(this,
                ::idlmm::IdlmmPackage::_instance()->getBinaryExpression__left());
    }
    if (m_right)
    {
        m_right->_initialize();
        m_right->_setEContainer(
                this,
                ::idlmm::IdlmmPackage::_instance()->getBinaryExpression__right());
    }

    /*PROTECTED REGION ID(BinaryExpressionImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject BinaryExpression::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__LEFT:
    {
        _any = static_cast< ::ecore::EObject* > (m_left);
    }
        return _any;
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__RIGHT:
    {
        _any = static_cast< ::ecore::EObject* > (m_right);
    }
        return _any;
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__OPERATOR:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_operator);
    }
        return _any;

    }
    throw "Error";
}

void BinaryExpression::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__LEFT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Expression_ptr _t1 =
                dynamic_cast< ::idlmm::Expression_ptr > (_t0);
        ::idlmm::BinaryExpression::setLeft(_t1);
    }
        return;
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__RIGHT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Expression_ptr _t1 =
                dynamic_cast< ::idlmm::Expression_ptr > (_t0);
        ::idlmm::BinaryExpression::setRight(_t1);
    }
        return;
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__OPERATOR:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_operator);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean BinaryExpression::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__LEFT:
        return m_left;
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__RIGHT:
        return m_right;
    case ::idlmm::IdlmmPackage::BINARYEXPRESSION__OPERATOR:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_operator);

    }
    throw "Error";
}

void BinaryExpression::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr BinaryExpression::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::idlmm::IdlmmPackage_ptr > (::idlmm::IdlmmPackage::_instance())->getBinaryExpression();
    return _eclass;
}

