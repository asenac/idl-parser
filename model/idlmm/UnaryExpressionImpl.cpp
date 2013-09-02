// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/UnaryExpressionImpl.cpp
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

#include "UnaryExpression.hpp"
#include <idlmm/IdlmmPackage.hpp>
#include <idlmm/Expression.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::idlmm;

/*PROTECTED REGION ID(UnaryExpressionImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void UnaryExpression::_initialize()
{
    // Supertypes
    ::idlmm::Expression::_initialize();

    // Rerefences
    if (m_expression)
    {
        m_expression->_initialize();
        m_expression->_setEContainer(
                this,
                ::idlmm::IdlmmPackage::_instance()->getUnaryExpression__expression());
    }

    /*PROTECTED REGION ID(UnaryExpressionImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject UnaryExpression::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::UNARYEXPRESSION__EXPRESSION:
    {
        _any = static_cast< ::ecore::EObject* > (m_expression);
    }
        return _any;
    case ::idlmm::IdlmmPackage::UNARYEXPRESSION__OPERATOR:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_operator);
    }
        return _any;

    }
    throw "Error";
}

void UnaryExpression::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::UNARYEXPRESSION__EXPRESSION:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::idlmm::Expression_ptr _t1 =
                dynamic_cast< ::idlmm::Expression_ptr > (_t0);
        ::idlmm::UnaryExpression::setExpression(_t1);
    }
        return;
    case ::idlmm::IdlmmPackage::UNARYEXPRESSION__OPERATOR:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_operator);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean UnaryExpression::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::idlmm::IdlmmPackage::UNARYEXPRESSION__EXPRESSION:
        return m_expression;
    case ::idlmm::IdlmmPackage::UNARYEXPRESSION__OPERATOR:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_operator);

    }
    throw "Error";
}

void UnaryExpression::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr UnaryExpression::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::idlmm::IdlmmPackage_ptr > (::idlmm::IdlmmPackage::_instance())->getUnaryExpression();
    return _eclass;
}

