// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/IdlmmPackageImpl.cpp
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

#include <idlmm/IdlmmPackage.hpp>
#include <idlmm/IdlmmFactory.hpp>
#include <ecore.hpp>
#include <ecore/EcorePackage.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/EDataType.hpp>
#include <ecore/EGenericType.hpp>
#include <ecore/ETypeParameter.hpp>
#include <ecore/EcorePackage.hpp>

using namespace ::idlmm;

IdlmmPackage::IdlmmPackage()
{

    s_instance.reset(this);

    // Factory
    ::ecore::EFactory_ptr _fa = IdlmmFactory::_instance();
    setEFactoryInstance(_fa);
    _fa->setEPackage(this);

    // Create classes and their features

    // Container
    m_ContainerEClass = new ::ecore::EClass();
    m_ContainerEClass->setClassifierID(CONTAINER);
    m_ContainerEClass->setEPackage(this);
    getEClassifiers().push_back(m_ContainerEClass);
    m_Container__contains = new ::ecore::EReference();
    m_Container__contains->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINER__CONTAINS);
    m_ContainerEClass->getEStructuralFeatures().push_back(m_Container__contains);

    // Contained
    m_ContainedEClass = new ::ecore::EClass();
    m_ContainedEClass->setClassifierID(CONTAINED);
    m_ContainedEClass->setEPackage(this);
    getEClassifiers().push_back(m_ContainedEClass);
    m_Contained__repositoryId = new ::ecore::EAttribute();
    m_Contained__repositoryId->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__REPOSITORYID);
    m_ContainedEClass->getEStructuralFeatures().push_back(
            m_Contained__repositoryId);
    m_Contained__version = new ::ecore::EAttribute();
    m_Contained__version->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__VERSION);
    m_ContainedEClass->getEStructuralFeatures().push_back(m_Contained__version);
    m_Contained__absoluteName = new ::ecore::EAttribute();
    m_Contained__absoluteName->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__ABSOLUTENAME);
    m_ContainedEClass->getEStructuralFeatures().push_back(
            m_Contained__absoluteName);
    m_Contained__definedIn = new ::ecore::EReference();
    m_Contained__definedIn->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__DEFINEDIN);
    m_ContainedEClass->getEStructuralFeatures().push_back(
            m_Contained__definedIn);

    // InterfaceDef
    m_InterfaceDefEClass = new ::ecore::EClass();
    m_InterfaceDefEClass->setClassifierID(INTERFACEDEF);
    m_InterfaceDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_InterfaceDefEClass);
    m_InterfaceDef__isAbstract = new ::ecore::EAttribute();
    m_InterfaceDef__isAbstract->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__ISABSTRACT);
    m_InterfaceDefEClass->getEStructuralFeatures().push_back(
            m_InterfaceDef__isAbstract);
    m_InterfaceDef__isCustom = new ::ecore::EAttribute();
    m_InterfaceDef__isCustom->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__ISCUSTOM);
    m_InterfaceDefEClass->getEStructuralFeatures().push_back(
            m_InterfaceDef__isCustom);
    m_InterfaceDef__isTruncatable = new ::ecore::EAttribute();
    m_InterfaceDef__isTruncatable->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__ISTRUNCATABLE);
    m_InterfaceDefEClass->getEStructuralFeatures().push_back(
            m_InterfaceDef__isTruncatable);
    m_InterfaceDef__derivesFrom = new ::ecore::EReference();
    m_InterfaceDef__derivesFrom->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__DERIVESFROM);
    m_InterfaceDefEClass->getEStructuralFeatures().push_back(
            m_InterfaceDef__derivesFrom);
    m_InterfaceDef__forward = new ::ecore::EReference();
    m_InterfaceDef__forward->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__FORWARD);
    m_InterfaceDefEClass->getEStructuralFeatures().push_back(
            m_InterfaceDef__forward);

    // ModuleDef
    m_ModuleDefEClass = new ::ecore::EClass();
    m_ModuleDefEClass->setClassifierID(MODULEDEF);
    m_ModuleDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ModuleDefEClass);
    m_ModuleDef__prefix = new ::ecore::EAttribute();
    m_ModuleDef__prefix->setFeatureID(::idlmm::IdlmmPackage::MODULEDEF__PREFIX);
    m_ModuleDefEClass->getEStructuralFeatures().push_back(m_ModuleDef__prefix);

    // IDLType
    m_IDLTypeEClass = new ::ecore::EClass();
    m_IDLTypeEClass->setClassifierID(IDLTYPE);
    m_IDLTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_IDLTypeEClass);
    m_IDLType__typeCode = new ::ecore::EAttribute();
    m_IDLType__typeCode->setFeatureID(::idlmm::IdlmmPackage::IDLTYPE__TYPECODE);
    m_IDLTypeEClass->getEStructuralFeatures().push_back(m_IDLType__typeCode);

    // OperationDef
    m_OperationDefEClass = new ::ecore::EClass();
    m_OperationDefEClass->setClassifierID(OPERATIONDEF);
    m_OperationDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_OperationDefEClass);
    m_OperationDef__isOneway = new ::ecore::EAttribute();
    m_OperationDef__isOneway->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__ISONEWAY);
    m_OperationDefEClass->getEStructuralFeatures().push_back(
            m_OperationDef__isOneway);
    m_OperationDef__contexts = new ::ecore::EAttribute();
    m_OperationDef__contexts->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__CONTEXTS);
    m_OperationDefEClass->getEStructuralFeatures().push_back(
            m_OperationDef__contexts);
    m_OperationDef__parameters = new ::ecore::EReference();
    m_OperationDef__parameters->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__PARAMETERS);
    m_OperationDefEClass->getEStructuralFeatures().push_back(
            m_OperationDef__parameters);
    m_OperationDef__canRaise = new ::ecore::EReference();
    m_OperationDef__canRaise->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__CANRAISE);
    m_OperationDefEClass->getEStructuralFeatures().push_back(
            m_OperationDef__canRaise);

    // AttributeDef
    m_AttributeDefEClass = new ::ecore::EClass();
    m_AttributeDefEClass->setClassifierID(ATTRIBUTEDEF);
    m_AttributeDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_AttributeDefEClass);
    m_AttributeDef__isReadonly = new ::ecore::EAttribute();
    m_AttributeDef__isReadonly->setFeatureID(
            ::idlmm::IdlmmPackage::ATTRIBUTEDEF__ISREADONLY);
    m_AttributeDefEClass->getEStructuralFeatures().push_back(
            m_AttributeDef__isReadonly);
    m_AttributeDef__getRaises = new ::ecore::EReference();
    m_AttributeDef__getRaises->setFeatureID(
            ::idlmm::IdlmmPackage::ATTRIBUTEDEF__GETRAISES);
    m_AttributeDefEClass->getEStructuralFeatures().push_back(
            m_AttributeDef__getRaises);
    m_AttributeDef__setRaises = new ::ecore::EReference();
    m_AttributeDef__setRaises->setFeatureID(
            ::idlmm::IdlmmPackage::ATTRIBUTEDEF__SETRAISES);
    m_AttributeDefEClass->getEStructuralFeatures().push_back(
            m_AttributeDef__setRaises);

    // ConstantDef
    m_ConstantDefEClass = new ::ecore::EClass();
    m_ConstantDefEClass->setClassifierID(CONSTANTDEF);
    m_ConstantDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ConstantDefEClass);
    m_ConstantDef__constValue = new ::ecore::EReference();
    m_ConstantDef__constValue->setFeatureID(
            ::idlmm::IdlmmPackage::CONSTANTDEF__CONSTVALUE);
    m_ConstantDefEClass->getEStructuralFeatures().push_back(
            m_ConstantDef__constValue);

    // Typed
    m_TypedEClass = new ::ecore::EClass();
    m_TypedEClass->setClassifierID(TYPED);
    m_TypedEClass->setEPackage(this);
    getEClassifiers().push_back(m_TypedEClass);
    m_Typed__containedType = new ::ecore::EReference();
    m_Typed__containedType->setFeatureID(
            ::idlmm::IdlmmPackage::TYPED__CONTAINEDTYPE);
    m_TypedEClass->getEStructuralFeatures().push_back(m_Typed__containedType);
    m_Typed__sharedType = new ::ecore::EReference();
    m_Typed__sharedType->setFeatureID(::idlmm::IdlmmPackage::TYPED__SHAREDTYPE);
    m_TypedEClass->getEStructuralFeatures().push_back(m_Typed__sharedType);

    // ParameterDef
    m_ParameterDefEClass = new ::ecore::EClass();
    m_ParameterDefEClass->setClassifierID(PARAMETERDEF);
    m_ParameterDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ParameterDefEClass);
    m_ParameterDef__identifier = new ::ecore::EAttribute();
    m_ParameterDef__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::PARAMETERDEF__IDENTIFIER);
    m_ParameterDefEClass->getEStructuralFeatures().push_back(
            m_ParameterDef__identifier);
    m_ParameterDef__direction = new ::ecore::EAttribute();
    m_ParameterDef__direction->setFeatureID(
            ::idlmm::IdlmmPackage::PARAMETERDEF__DIRECTION);
    m_ParameterDefEClass->getEStructuralFeatures().push_back(
            m_ParameterDef__direction);

    // PrimitiveDef
    m_PrimitiveDefEClass = new ::ecore::EClass();
    m_PrimitiveDefEClass->setClassifierID(PRIMITIVEDEF);
    m_PrimitiveDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_PrimitiveDefEClass);
    m_PrimitiveDef__kind = new ::ecore::EAttribute();
    m_PrimitiveDef__kind->setFeatureID(
            ::idlmm::IdlmmPackage::PRIMITIVEDEF__KIND);
    m_PrimitiveDefEClass->getEStructuralFeatures().push_back(
            m_PrimitiveDef__kind);

    // ExceptionDef
    m_ExceptionDefEClass = new ::ecore::EClass();
    m_ExceptionDefEClass->setClassifierID(EXCEPTIONDEF);
    m_ExceptionDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ExceptionDefEClass);
    m_ExceptionDef__typeCode = new ::ecore::EAttribute();
    m_ExceptionDef__typeCode->setFeatureID(
            ::idlmm::IdlmmPackage::EXCEPTIONDEF__TYPECODE);
    m_ExceptionDefEClass->getEStructuralFeatures().push_back(
            m_ExceptionDef__typeCode);
    m_ExceptionDef__members = new ::ecore::EReference();
    m_ExceptionDef__members->setFeatureID(
            ::idlmm::IdlmmPackage::EXCEPTIONDEF__MEMBERS);
    m_ExceptionDefEClass->getEStructuralFeatures().push_back(
            m_ExceptionDef__members);

    // Field
    m_FieldEClass = new ::ecore::EClass();
    m_FieldEClass->setClassifierID(FIELD);
    m_FieldEClass->setEPackage(this);
    getEClassifiers().push_back(m_FieldEClass);
    m_Field__identifier = new ::ecore::EAttribute();
    m_Field__identifier->setFeatureID(::idlmm::IdlmmPackage::FIELD__IDENTIFIER);
    m_FieldEClass->getEStructuralFeatures().push_back(m_Field__identifier);

    // FixedDef
    m_FixedDefEClass = new ::ecore::EClass();
    m_FixedDefEClass->setClassifierID(FIXEDDEF);
    m_FixedDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_FixedDefEClass);
    m_FixedDef__digits = new ::ecore::EReference();
    m_FixedDef__digits->setFeatureID(::idlmm::IdlmmPackage::FIXEDDEF__DIGITS);
    m_FixedDefEClass->getEStructuralFeatures().push_back(m_FixedDef__digits);
    m_FixedDef__scale = new ::ecore::EReference();
    m_FixedDef__scale->setFeatureID(::idlmm::IdlmmPackage::FIXEDDEF__SCALE);
    m_FixedDefEClass->getEStructuralFeatures().push_back(m_FixedDef__scale);

    // WstringDef
    m_WstringDefEClass = new ::ecore::EClass();
    m_WstringDefEClass->setClassifierID(WSTRINGDEF);
    m_WstringDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_WstringDefEClass);
    m_WstringDef__bound = new ::ecore::EReference();
    m_WstringDef__bound->setFeatureID(::idlmm::IdlmmPackage::WSTRINGDEF__BOUND);
    m_WstringDefEClass->getEStructuralFeatures().push_back(m_WstringDef__bound);

    // StringDef
    m_StringDefEClass = new ::ecore::EClass();
    m_StringDefEClass->setClassifierID(STRINGDEF);
    m_StringDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_StringDefEClass);
    m_StringDef__bound = new ::ecore::EReference();
    m_StringDef__bound->setFeatureID(::idlmm::IdlmmPackage::STRINGDEF__BOUND);
    m_StringDefEClass->getEStructuralFeatures().push_back(m_StringDef__bound);

    // AliasDef
    m_AliasDefEClass = new ::ecore::EClass();
    m_AliasDefEClass->setClassifierID(ALIASDEF);
    m_AliasDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_AliasDefEClass);

    // ArrayDef
    m_ArrayDefEClass = new ::ecore::EClass();
    m_ArrayDefEClass->setClassifierID(ARRAYDEF);
    m_ArrayDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ArrayDefEClass);
    m_ArrayDef__name = new ::ecore::EAttribute();
    m_ArrayDef__name->setFeatureID(::idlmm::IdlmmPackage::ARRAYDEF__NAME);
    m_ArrayDefEClass->getEStructuralFeatures().push_back(m_ArrayDef__name);
    m_ArrayDef__bounds = new ::ecore::EReference();
    m_ArrayDef__bounds->setFeatureID(::idlmm::IdlmmPackage::ARRAYDEF__BOUNDS);
    m_ArrayDefEClass->getEStructuralFeatures().push_back(m_ArrayDef__bounds);

    // SequenceDef
    m_SequenceDefEClass = new ::ecore::EClass();
    m_SequenceDefEClass->setClassifierID(SEQUENCEDEF);
    m_SequenceDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_SequenceDefEClass);
    m_SequenceDef__bound = new ::ecore::EReference();
    m_SequenceDef__bound->setFeatureID(
            ::idlmm::IdlmmPackage::SEQUENCEDEF__BOUND);
    m_SequenceDefEClass->getEStructuralFeatures().push_back(
            m_SequenceDef__bound);

    // UnionField
    m_UnionFieldEClass = new ::ecore::EClass();
    m_UnionFieldEClass->setClassifierID(UNIONFIELD);
    m_UnionFieldEClass->setEPackage(this);
    getEClassifiers().push_back(m_UnionFieldEClass);
    m_UnionField__identifier = new ::ecore::EAttribute();
    m_UnionField__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONFIELD__IDENTIFIER);
    m_UnionFieldEClass->getEStructuralFeatures().push_back(
            m_UnionField__identifier);
    m_UnionField__label = new ::ecore::EReference();
    m_UnionField__label->setFeatureID(::idlmm::IdlmmPackage::UNIONFIELD__LABEL);
    m_UnionFieldEClass->getEStructuralFeatures().push_back(m_UnionField__label);

    // TypedefDef
    m_TypedefDefEClass = new ::ecore::EClass();
    m_TypedefDefEClass->setClassifierID(TYPEDEFDEF);
    m_TypedefDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_TypedefDefEClass);

    // UnionDef
    m_UnionDefEClass = new ::ecore::EClass();
    m_UnionDefEClass->setClassifierID(UNIONDEF);
    m_UnionDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_UnionDefEClass);
    m_UnionDef__unionMembers = new ::ecore::EReference();
    m_UnionDef__unionMembers->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONDEF__UNIONMEMBERS);
    m_UnionDefEClass->getEStructuralFeatures().push_back(
            m_UnionDef__unionMembers);
    m_UnionDef__containedDiscrim = new ::ecore::EReference();
    m_UnionDef__containedDiscrim->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONDEF__CONTAINEDDISCRIM);
    m_UnionDefEClass->getEStructuralFeatures().push_back(
            m_UnionDef__containedDiscrim);
    m_UnionDef__sharedDiscrim = new ::ecore::EReference();
    m_UnionDef__sharedDiscrim->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONDEF__SHAREDDISCRIM);
    m_UnionDefEClass->getEStructuralFeatures().push_back(
            m_UnionDef__sharedDiscrim);

    // EnumDef
    m_EnumDefEClass = new ::ecore::EClass();
    m_EnumDefEClass->setClassifierID(ENUMDEF);
    m_EnumDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_EnumDefEClass);
    m_EnumDef__members = new ::ecore::EReference();
    m_EnumDef__members->setFeatureID(::idlmm::IdlmmPackage::ENUMDEF__MEMBERS);
    m_EnumDefEClass->getEStructuralFeatures().push_back(m_EnumDef__members);

    // StructDef
    m_StructDefEClass = new ::ecore::EClass();
    m_StructDefEClass->setClassifierID(STRUCTDEF);
    m_StructDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_StructDefEClass);
    m_StructDef__members = new ::ecore::EReference();
    m_StructDef__members->setFeatureID(
            ::idlmm::IdlmmPackage::STRUCTDEF__MEMBERS);
    m_StructDefEClass->getEStructuralFeatures().push_back(m_StructDef__members);

    // TranslationUnit
    m_TranslationUnitEClass = new ::ecore::EClass();
    m_TranslationUnitEClass->setClassifierID(TRANSLATIONUNIT);
    m_TranslationUnitEClass->setEPackage(this);
    getEClassifiers().push_back(m_TranslationUnitEClass);
    m_TranslationUnit__identifier = new ::ecore::EAttribute();
    m_TranslationUnit__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::TRANSLATIONUNIT__IDENTIFIER);
    m_TranslationUnitEClass->getEStructuralFeatures().push_back(
            m_TranslationUnit__identifier);
    m_TranslationUnit__contains = new ::ecore::EReference();
    m_TranslationUnit__contains->setFeatureID(
            ::idlmm::IdlmmPackage::TRANSLATIONUNIT__CONTAINS);
    m_TranslationUnitEClass->getEStructuralFeatures().push_back(
            m_TranslationUnit__contains);
    m_TranslationUnit__includes = new ::ecore::EReference();
    m_TranslationUnit__includes->setFeatureID(
            ::idlmm::IdlmmPackage::TRANSLATIONUNIT__INCLUDES);
    m_TranslationUnitEClass->getEStructuralFeatures().push_back(
            m_TranslationUnit__includes);

    // Include
    m_IncludeEClass = new ::ecore::EClass();
    m_IncludeEClass->setClassifierID(INCLUDE);
    m_IncludeEClass->setEPackage(this);
    getEClassifiers().push_back(m_IncludeEClass);
    m_Include__importURI = new ::ecore::EAttribute();
    m_Include__importURI->setFeatureID(
            ::idlmm::IdlmmPackage::INCLUDE__IMPORTURI);
    m_IncludeEClass->getEStructuralFeatures().push_back(m_Include__importURI);
    m_Include__translationUnit = new ::ecore::EReference();
    m_Include__translationUnit->setFeatureID(
            ::idlmm::IdlmmPackage::INCLUDE__TRANSLATIONUNIT);
    m_IncludeEClass->getEStructuralFeatures().push_back(
            m_Include__translationUnit);

    // Expression
    m_ExpressionEClass = new ::ecore::EClass();
    m_ExpressionEClass->setClassifierID(EXPRESSION);
    m_ExpressionEClass->setEPackage(this);
    getEClassifiers().push_back(m_ExpressionEClass);

    // BinaryExpression
    m_BinaryExpressionEClass = new ::ecore::EClass();
    m_BinaryExpressionEClass->setClassifierID(BINARYEXPRESSION);
    m_BinaryExpressionEClass->setEPackage(this);
    getEClassifiers().push_back(m_BinaryExpressionEClass);
    m_BinaryExpression__operator = new ::ecore::EAttribute();
    m_BinaryExpression__operator->setFeatureID(
            ::idlmm::IdlmmPackage::BINARYEXPRESSION__OPERATOR);
    m_BinaryExpressionEClass->getEStructuralFeatures().push_back(
            m_BinaryExpression__operator);
    m_BinaryExpression__left = new ::ecore::EReference();
    m_BinaryExpression__left->setFeatureID(
            ::idlmm::IdlmmPackage::BINARYEXPRESSION__LEFT);
    m_BinaryExpressionEClass->getEStructuralFeatures().push_back(
            m_BinaryExpression__left);
    m_BinaryExpression__right = new ::ecore::EReference();
    m_BinaryExpression__right->setFeatureID(
            ::idlmm::IdlmmPackage::BINARYEXPRESSION__RIGHT);
    m_BinaryExpressionEClass->getEStructuralFeatures().push_back(
            m_BinaryExpression__right);

    // UnaryExpression
    m_UnaryExpressionEClass = new ::ecore::EClass();
    m_UnaryExpressionEClass->setClassifierID(UNARYEXPRESSION);
    m_UnaryExpressionEClass->setEPackage(this);
    getEClassifiers().push_back(m_UnaryExpressionEClass);
    m_UnaryExpression__operator = new ::ecore::EAttribute();
    m_UnaryExpression__operator->setFeatureID(
            ::idlmm::IdlmmPackage::UNARYEXPRESSION__OPERATOR);
    m_UnaryExpressionEClass->getEStructuralFeatures().push_back(
            m_UnaryExpression__operator);
    m_UnaryExpression__expression = new ::ecore::EReference();
    m_UnaryExpression__expression->setFeatureID(
            ::idlmm::IdlmmPackage::UNARYEXPRESSION__EXPRESSION);
    m_UnaryExpressionEClass->getEStructuralFeatures().push_back(
            m_UnaryExpression__expression);

    // LiteralExpression
    m_LiteralExpressionEClass = new ::ecore::EClass();
    m_LiteralExpressionEClass->setClassifierID(LITERALEXPRESSION);
    m_LiteralExpressionEClass->setEPackage(this);
    getEClassifiers().push_back(m_LiteralExpressionEClass);

    // ConstantDefRef
    m_ConstantDefRefEClass = new ::ecore::EClass();
    m_ConstantDefRefEClass->setClassifierID(CONSTANTDEFREF);
    m_ConstantDefRefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ConstantDefRefEClass);
    m_ConstantDefRef__constant = new ::ecore::EReference();
    m_ConstantDefRef__constant->setFeatureID(
            ::idlmm::IdlmmPackage::CONSTANTDEFREF__CONSTANT);
    m_ConstantDefRefEClass->getEStructuralFeatures().push_back(
            m_ConstantDefRef__constant);

    // ValueExpression
    m_ValueExpressionEClass = new ::ecore::EClass();
    m_ValueExpressionEClass->setClassifierID(VALUEEXPRESSION);
    m_ValueExpressionEClass->setEPackage(this);
    getEClassifiers().push_back(m_ValueExpressionEClass);
    m_ValueExpression__value = new ::ecore::EAttribute();
    m_ValueExpression__value->setFeatureID(
            ::idlmm::IdlmmPackage::VALUEEXPRESSION__VALUE);
    m_ValueExpressionEClass->getEStructuralFeatures().push_back(
            m_ValueExpression__value);

    // ForwardDef
    m_ForwardDefEClass = new ::ecore::EClass();
    m_ForwardDefEClass->setClassifierID(FORWARDDEF);
    m_ForwardDefEClass->setEPackage(this);
    getEClassifiers().push_back(m_ForwardDefEClass);
    m_ForwardDef__definition = new ::ecore::EReference();
    m_ForwardDef__definition->setFeatureID(
            ::idlmm::IdlmmPackage::FORWARDDEF__DEFINITION);
    m_ForwardDefEClass->getEStructuralFeatures().push_back(
            m_ForwardDef__definition);

    // EnumMember
    m_EnumMemberEClass = new ::ecore::EClass();
    m_EnumMemberEClass->setClassifierID(ENUMMEMBER);
    m_EnumMemberEClass->setEPackage(this);
    getEClassifiers().push_back(m_EnumMemberEClass);
    m_EnumMember__enum = new ::ecore::EReference();
    m_EnumMember__enum->setFeatureID(::idlmm::IdlmmPackage::ENUMMEMBER__ENUM);
    m_EnumMemberEClass->getEStructuralFeatures().push_back(m_EnumMember__enum);

    // Constant
    m_ConstantEClass = new ::ecore::EClass();
    m_ConstantEClass->setClassifierID(CONSTANT);
    m_ConstantEClass->setEPackage(this);
    getEClassifiers().push_back(m_ConstantEClass);

    // NamedElement
    m_NamedElementEClass = new ::ecore::EClass();
    m_NamedElementEClass->setClassifierID(NAMEDELEMENT);
    m_NamedElementEClass->setEPackage(this);
    getEClassifiers().push_back(m_NamedElementEClass);
    m_NamedElement__identifier = new ::ecore::EAttribute();
    m_NamedElement__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::NAMEDELEMENT__IDENTIFIER);
    m_NamedElementEClass->getEStructuralFeatures().push_back(
            m_NamedElement__identifier);

    // Create enums

    m_ParameterModeEEnum = new ::ecore::EEnum();
    m_ParameterModeEEnum->setClassifierID(PARAMETERMODE);
    m_ParameterModeEEnum->setEPackage(this);
    getEClassifiers().push_back(m_ParameterModeEEnum);

    m_PrimitiveKindEEnum = new ::ecore::EEnum();
    m_PrimitiveKindEEnum->setClassifierID(PRIMITIVEKIND);
    m_PrimitiveKindEEnum->setEPackage(this);
    getEClassifiers().push_back(m_PrimitiveKindEEnum);

    // Create data types

    m_EAnyEDataType = new ::ecore::EDataType();
    m_EAnyEDataType->setClassifierID(EANY);
    m_EAnyEDataType->setEPackage(this);
    getEClassifiers().push_back(m_EAnyEDataType);

    m_ETypeCodeEDataType = new ::ecore::EDataType();
    m_ETypeCodeEDataType->setClassifierID(ETYPECODE);
    m_ETypeCodeEDataType->setEPackage(this);
    getEClassifiers().push_back(m_ETypeCodeEDataType);

    // Initialize package
    setName("idlmm");
    setNsPrefix("idlmm");
    setNsURI("http://idlmm/1.0");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_ContainerEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_ContainedEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_InterfaceDefEClass->getESuperTypes().push_back(m_ContainerEClass);
    m_InterfaceDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_ModuleDefEClass->getESuperTypes().push_back(m_ContainerEClass);
    m_OperationDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_OperationDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_AttributeDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_AttributeDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_ConstantDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_ConstantDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_ConstantDefEClass->getESuperTypes().push_back(m_ConstantEClass);
    m_ParameterDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_PrimitiveDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_ExceptionDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_FieldEClass->getESuperTypes().push_back(m_TypedEClass);
    m_FixedDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_WstringDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_StringDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_AliasDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_AliasDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_ArrayDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_ArrayDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_SequenceDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_SequenceDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_UnionFieldEClass->getESuperTypes().push_back(m_TypedEClass);
    m_TypedefDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_TypedefDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_UnionDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_EnumDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_StructDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_BinaryExpressionEClass->getESuperTypes().push_back(m_ExpressionEClass);
    m_UnaryExpressionEClass->getESuperTypes().push_back(m_ExpressionEClass);
    m_LiteralExpressionEClass->getESuperTypes().push_back(m_ExpressionEClass);
    m_ConstantDefRefEClass->getESuperTypes().push_back(
            m_LiteralExpressionEClass);
    m_ValueExpressionEClass->getESuperTypes().push_back(
            m_LiteralExpressionEClass);
    m_ForwardDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_EnumMemberEClass->getESuperTypes().push_back(m_ConstantEClass);
    m_ConstantEClass->getESuperTypes().push_back(m_ContainedEClass);

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    // Container
    m_ContainerEClass->setName("Container");
    m_ContainerEClass->setAbstract(true);
    m_ContainerEClass->setInterface(false);
    m_Container__contains->setEType(m_ContainedEClass);
    m_Container__contains->setName("contains");
    m_Container__contains->setDefaultValueLiteral("");
    m_Container__contains->setLowerBound(0);
    m_Container__contains->setUpperBound(-1);
    m_Container__contains->setTransient(false);
    m_Container__contains->setVolatile(false);
    m_Container__contains->setChangeable(true);
    m_Container__contains->setContainment(true);
    m_Container__contains->setResolveProxies(true);
    m_Container__contains->setUnique(true);
    m_Container__contains->setDerived(false);
    m_Container__contains->setOrdered(true);
    m_Container__contains->setEOpposite(
            ::ecore::instanceOf< ::ecore::EReference >(
                    m_ContainedEClass->getEStructuralFeatures()[3]));
    // Contained
    m_ContainedEClass->setName("Contained");
    m_ContainedEClass->setAbstract(true);
    m_ContainedEClass->setInterface(false);
    m_Contained__repositoryId->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Contained__repositoryId->setName("repositoryId");
    m_Contained__repositoryId->setDefaultValueLiteral("");
    m_Contained__repositoryId->setLowerBound(0);
    m_Contained__repositoryId->setUpperBound(1);
    m_Contained__repositoryId->setTransient(false);
    m_Contained__repositoryId->setVolatile(false);
    m_Contained__repositoryId->setChangeable(true);
    m_Contained__repositoryId->setUnsettable(false);
    m_Contained__repositoryId->setID(false);
    m_Contained__repositoryId->setUnique(true);
    m_Contained__repositoryId->setDerived(false);
    m_Contained__repositoryId->setOrdered(true);
    m_Contained__version->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Contained__version->setName("version");
    m_Contained__version->setDefaultValueLiteral("");
    m_Contained__version->setLowerBound(0);
    m_Contained__version->setUpperBound(1);
    m_Contained__version->setTransient(false);
    m_Contained__version->setVolatile(false);
    m_Contained__version->setChangeable(true);
    m_Contained__version->setUnsettable(false);
    m_Contained__version->setID(false);
    m_Contained__version->setUnique(true);
    m_Contained__version->setDerived(false);
    m_Contained__version->setOrdered(true);
    m_Contained__absoluteName->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Contained__absoluteName->setName("absoluteName");
    m_Contained__absoluteName->setDefaultValueLiteral("");
    m_Contained__absoluteName->setLowerBound(0);
    m_Contained__absoluteName->setUpperBound(1);
    m_Contained__absoluteName->setTransient(false);
    m_Contained__absoluteName->setVolatile(false);
    m_Contained__absoluteName->setChangeable(true);
    m_Contained__absoluteName->setUnsettable(false);
    m_Contained__absoluteName->setID(false);
    m_Contained__absoluteName->setUnique(true);
    m_Contained__absoluteName->setDerived(false);
    m_Contained__absoluteName->setOrdered(true);
    m_Contained__definedIn->setEType(m_ContainerEClass);
    m_Contained__definedIn->setName("definedIn");
    m_Contained__definedIn->setDefaultValueLiteral("");
    m_Contained__definedIn->setLowerBound(0);
    m_Contained__definedIn->setUpperBound(1);
    m_Contained__definedIn->setTransient(false);
    m_Contained__definedIn->setVolatile(false);
    m_Contained__definedIn->setChangeable(true);
    m_Contained__definedIn->setContainment(false);
    m_Contained__definedIn->setResolveProxies(true);
    m_Contained__definedIn->setUnique(true);
    m_Contained__definedIn->setDerived(false);
    m_Contained__definedIn->setOrdered(true);
    m_Contained__definedIn->setEOpposite(
            ::ecore::instanceOf< ::ecore::EReference >(
                    m_ContainerEClass->getEStructuralFeatures()[0]));
    // InterfaceDef
    m_InterfaceDefEClass->setName("InterfaceDef");
    m_InterfaceDefEClass->setAbstract(false);
    m_InterfaceDefEClass->setInterface(false);
    m_InterfaceDef__isAbstract->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_InterfaceDef__isAbstract->setName("isAbstract");
    m_InterfaceDef__isAbstract->setDefaultValueLiteral("");
    m_InterfaceDef__isAbstract->setLowerBound(0);
    m_InterfaceDef__isAbstract->setUpperBound(1);
    m_InterfaceDef__isAbstract->setTransient(false);
    m_InterfaceDef__isAbstract->setVolatile(false);
    m_InterfaceDef__isAbstract->setChangeable(true);
    m_InterfaceDef__isAbstract->setUnsettable(false);
    m_InterfaceDef__isAbstract->setID(false);
    m_InterfaceDef__isAbstract->setUnique(true);
    m_InterfaceDef__isAbstract->setDerived(false);
    m_InterfaceDef__isAbstract->setOrdered(true);
    m_InterfaceDef__isCustom->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_InterfaceDef__isCustom->setName("isCustom");
    m_InterfaceDef__isCustom->setDefaultValueLiteral("");
    m_InterfaceDef__isCustom->setLowerBound(0);
    m_InterfaceDef__isCustom->setUpperBound(1);
    m_InterfaceDef__isCustom->setTransient(false);
    m_InterfaceDef__isCustom->setVolatile(false);
    m_InterfaceDef__isCustom->setChangeable(true);
    m_InterfaceDef__isCustom->setUnsettable(false);
    m_InterfaceDef__isCustom->setID(false);
    m_InterfaceDef__isCustom->setUnique(true);
    m_InterfaceDef__isCustom->setDerived(false);
    m_InterfaceDef__isCustom->setOrdered(true);
    m_InterfaceDef__isTruncatable->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_InterfaceDef__isTruncatable->setName("isTruncatable");
    m_InterfaceDef__isTruncatable->setDefaultValueLiteral("");
    m_InterfaceDef__isTruncatable->setLowerBound(0);
    m_InterfaceDef__isTruncatable->setUpperBound(1);
    m_InterfaceDef__isTruncatable->setTransient(false);
    m_InterfaceDef__isTruncatable->setVolatile(false);
    m_InterfaceDef__isTruncatable->setChangeable(true);
    m_InterfaceDef__isTruncatable->setUnsettable(false);
    m_InterfaceDef__isTruncatable->setID(false);
    m_InterfaceDef__isTruncatable->setUnique(true);
    m_InterfaceDef__isTruncatable->setDerived(false);
    m_InterfaceDef__isTruncatable->setOrdered(true);
    m_InterfaceDef__derivesFrom->setEType(m_InterfaceDefEClass);
    m_InterfaceDef__derivesFrom->setName("derivesFrom");
    m_InterfaceDef__derivesFrom->setDefaultValueLiteral("");
    m_InterfaceDef__derivesFrom->setLowerBound(0);
    m_InterfaceDef__derivesFrom->setUpperBound(-1);
    m_InterfaceDef__derivesFrom->setTransient(false);
    m_InterfaceDef__derivesFrom->setVolatile(false);
    m_InterfaceDef__derivesFrom->setChangeable(true);
    m_InterfaceDef__derivesFrom->setContainment(false);
    m_InterfaceDef__derivesFrom->setResolveProxies(true);
    m_InterfaceDef__derivesFrom->setUnique(true);
    m_InterfaceDef__derivesFrom->setDerived(false);
    m_InterfaceDef__derivesFrom->setOrdered(true);
    m_InterfaceDef__forward->setEType(m_ForwardDefEClass);
    m_InterfaceDef__forward->setName("forward");
    m_InterfaceDef__forward->setDefaultValueLiteral("");
    m_InterfaceDef__forward->setLowerBound(0);
    m_InterfaceDef__forward->setUpperBound(1);
    m_InterfaceDef__forward->setTransient(false);
    m_InterfaceDef__forward->setVolatile(false);
    m_InterfaceDef__forward->setChangeable(true);
    m_InterfaceDef__forward->setContainment(false);
    m_InterfaceDef__forward->setResolveProxies(true);
    m_InterfaceDef__forward->setUnique(true);
    m_InterfaceDef__forward->setDerived(false);
    m_InterfaceDef__forward->setOrdered(true);
    // ModuleDef
    m_ModuleDefEClass->setName("ModuleDef");
    m_ModuleDefEClass->setAbstract(false);
    m_ModuleDefEClass->setInterface(false);
    m_ModuleDef__prefix->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_ModuleDef__prefix->setName("prefix");
    m_ModuleDef__prefix->setDefaultValueLiteral("");
    m_ModuleDef__prefix->setLowerBound(0);
    m_ModuleDef__prefix->setUpperBound(1);
    m_ModuleDef__prefix->setTransient(false);
    m_ModuleDef__prefix->setVolatile(false);
    m_ModuleDef__prefix->setChangeable(true);
    m_ModuleDef__prefix->setUnsettable(false);
    m_ModuleDef__prefix->setID(false);
    m_ModuleDef__prefix->setUnique(true);
    m_ModuleDef__prefix->setDerived(false);
    m_ModuleDef__prefix->setOrdered(true);
    // IDLType
    m_IDLTypeEClass->setName("IDLType");
    m_IDLTypeEClass->setAbstract(true);
    m_IDLTypeEClass->setInterface(false);
    m_IDLType__typeCode->setEType(m_ETypeCodeEDataType);
    m_IDLType__typeCode->setName("typeCode");
    m_IDLType__typeCode->setDefaultValueLiteral("");
    m_IDLType__typeCode->setLowerBound(0);
    m_IDLType__typeCode->setUpperBound(1);
    m_IDLType__typeCode->setTransient(false);
    m_IDLType__typeCode->setVolatile(false);
    m_IDLType__typeCode->setChangeable(true);
    m_IDLType__typeCode->setUnsettable(false);
    m_IDLType__typeCode->setID(false);
    m_IDLType__typeCode->setUnique(true);
    m_IDLType__typeCode->setDerived(false);
    m_IDLType__typeCode->setOrdered(true);
    // OperationDef
    m_OperationDefEClass->setName("OperationDef");
    m_OperationDefEClass->setAbstract(false);
    m_OperationDefEClass->setInterface(false);
    m_OperationDef__isOneway->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_OperationDef__isOneway->setName("isOneway");
    m_OperationDef__isOneway->setDefaultValueLiteral("");
    m_OperationDef__isOneway->setLowerBound(0);
    m_OperationDef__isOneway->setUpperBound(1);
    m_OperationDef__isOneway->setTransient(false);
    m_OperationDef__isOneway->setVolatile(false);
    m_OperationDef__isOneway->setChangeable(true);
    m_OperationDef__isOneway->setUnsettable(false);
    m_OperationDef__isOneway->setID(false);
    m_OperationDef__isOneway->setUnique(true);
    m_OperationDef__isOneway->setDerived(false);
    m_OperationDef__isOneway->setOrdered(true);
    m_OperationDef__contexts->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_OperationDef__contexts->setName("contexts");
    m_OperationDef__contexts->setDefaultValueLiteral("");
    m_OperationDef__contexts->setLowerBound(0);
    m_OperationDef__contexts->setUpperBound(-1);
    m_OperationDef__contexts->setTransient(false);
    m_OperationDef__contexts->setVolatile(false);
    m_OperationDef__contexts->setChangeable(true);
    m_OperationDef__contexts->setUnsettable(false);
    m_OperationDef__contexts->setID(false);
    m_OperationDef__contexts->setUnique(true);
    m_OperationDef__contexts->setDerived(false);
    m_OperationDef__contexts->setOrdered(true);
    m_OperationDef__parameters->setEType(m_ParameterDefEClass);
    m_OperationDef__parameters->setName("parameters");
    m_OperationDef__parameters->setDefaultValueLiteral("");
    m_OperationDef__parameters->setLowerBound(0);
    m_OperationDef__parameters->setUpperBound(-1);
    m_OperationDef__parameters->setTransient(false);
    m_OperationDef__parameters->setVolatile(false);
    m_OperationDef__parameters->setChangeable(true);
    m_OperationDef__parameters->setContainment(true);
    m_OperationDef__parameters->setResolveProxies(true);
    m_OperationDef__parameters->setUnique(true);
    m_OperationDef__parameters->setDerived(false);
    m_OperationDef__parameters->setOrdered(true);
    m_OperationDef__canRaise->setEType(m_ExceptionDefEClass);
    m_OperationDef__canRaise->setName("canRaise");
    m_OperationDef__canRaise->setDefaultValueLiteral("");
    m_OperationDef__canRaise->setLowerBound(0);
    m_OperationDef__canRaise->setUpperBound(-1);
    m_OperationDef__canRaise->setTransient(false);
    m_OperationDef__canRaise->setVolatile(false);
    m_OperationDef__canRaise->setChangeable(true);
    m_OperationDef__canRaise->setContainment(false);
    m_OperationDef__canRaise->setResolveProxies(true);
    m_OperationDef__canRaise->setUnique(true);
    m_OperationDef__canRaise->setDerived(false);
    m_OperationDef__canRaise->setOrdered(true);
    // AttributeDef
    m_AttributeDefEClass->setName("AttributeDef");
    m_AttributeDefEClass->setAbstract(false);
    m_AttributeDefEClass->setInterface(false);
    m_AttributeDef__isReadonly->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_AttributeDef__isReadonly->setName("isReadonly");
    m_AttributeDef__isReadonly->setDefaultValueLiteral("");
    m_AttributeDef__isReadonly->setLowerBound(0);
    m_AttributeDef__isReadonly->setUpperBound(1);
    m_AttributeDef__isReadonly->setTransient(false);
    m_AttributeDef__isReadonly->setVolatile(false);
    m_AttributeDef__isReadonly->setChangeable(true);
    m_AttributeDef__isReadonly->setUnsettable(false);
    m_AttributeDef__isReadonly->setID(false);
    m_AttributeDef__isReadonly->setUnique(true);
    m_AttributeDef__isReadonly->setDerived(false);
    m_AttributeDef__isReadonly->setOrdered(true);
    m_AttributeDef__getRaises->setEType(m_ExceptionDefEClass);
    m_AttributeDef__getRaises->setName("getRaises");
    m_AttributeDef__getRaises->setDefaultValueLiteral("");
    m_AttributeDef__getRaises->setLowerBound(0);
    m_AttributeDef__getRaises->setUpperBound(-1);
    m_AttributeDef__getRaises->setTransient(false);
    m_AttributeDef__getRaises->setVolatile(false);
    m_AttributeDef__getRaises->setChangeable(true);
    m_AttributeDef__getRaises->setContainment(false);
    m_AttributeDef__getRaises->setResolveProxies(true);
    m_AttributeDef__getRaises->setUnique(true);
    m_AttributeDef__getRaises->setDerived(false);
    m_AttributeDef__getRaises->setOrdered(true);
    m_AttributeDef__setRaises->setEType(m_ExceptionDefEClass);
    m_AttributeDef__setRaises->setName("setRaises");
    m_AttributeDef__setRaises->setDefaultValueLiteral("");
    m_AttributeDef__setRaises->setLowerBound(0);
    m_AttributeDef__setRaises->setUpperBound(-1);
    m_AttributeDef__setRaises->setTransient(false);
    m_AttributeDef__setRaises->setVolatile(false);
    m_AttributeDef__setRaises->setChangeable(true);
    m_AttributeDef__setRaises->setContainment(false);
    m_AttributeDef__setRaises->setResolveProxies(true);
    m_AttributeDef__setRaises->setUnique(true);
    m_AttributeDef__setRaises->setDerived(false);
    m_AttributeDef__setRaises->setOrdered(true);
    // ConstantDef
    m_ConstantDefEClass->setName("ConstantDef");
    m_ConstantDefEClass->setAbstract(false);
    m_ConstantDefEClass->setInterface(false);
    m_ConstantDef__constValue->setEType(m_ExpressionEClass);
    m_ConstantDef__constValue->setName("constValue");
    m_ConstantDef__constValue->setDefaultValueLiteral("");
    m_ConstantDef__constValue->setLowerBound(1);
    m_ConstantDef__constValue->setUpperBound(1);
    m_ConstantDef__constValue->setTransient(false);
    m_ConstantDef__constValue->setVolatile(false);
    m_ConstantDef__constValue->setChangeable(true);
    m_ConstantDef__constValue->setContainment(true);
    m_ConstantDef__constValue->setResolveProxies(true);
    m_ConstantDef__constValue->setUnique(true);
    m_ConstantDef__constValue->setDerived(false);
    m_ConstantDef__constValue->setOrdered(true);
    // Typed
    m_TypedEClass->setName("Typed");
    m_TypedEClass->setAbstract(true);
    m_TypedEClass->setInterface(false);
    m_Typed__containedType->setEType(m_IDLTypeEClass);
    m_Typed__containedType->setName("containedType");
    m_Typed__containedType->setDefaultValueLiteral("");
    m_Typed__containedType->setLowerBound(0);
    m_Typed__containedType->setUpperBound(1);
    m_Typed__containedType->setTransient(false);
    m_Typed__containedType->setVolatile(false);
    m_Typed__containedType->setChangeable(true);
    m_Typed__containedType->setContainment(true);
    m_Typed__containedType->setResolveProxies(true);
    m_Typed__containedType->setUnique(true);
    m_Typed__containedType->setDerived(false);
    m_Typed__containedType->setOrdered(true);
    m_Typed__sharedType->setEType(m_TypedefDefEClass);
    m_Typed__sharedType->setName("sharedType");
    m_Typed__sharedType->setDefaultValueLiteral("");
    m_Typed__sharedType->setLowerBound(0);
    m_Typed__sharedType->setUpperBound(1);
    m_Typed__sharedType->setTransient(false);
    m_Typed__sharedType->setVolatile(false);
    m_Typed__sharedType->setChangeable(true);
    m_Typed__sharedType->setContainment(false);
    m_Typed__sharedType->setResolveProxies(true);
    m_Typed__sharedType->setUnique(true);
    m_Typed__sharedType->setDerived(false);
    m_Typed__sharedType->setOrdered(true);
    // ParameterDef
    m_ParameterDefEClass->setName("ParameterDef");
    m_ParameterDefEClass->setAbstract(false);
    m_ParameterDefEClass->setInterface(false);
    m_ParameterDef__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_ParameterDef__identifier->setName("identifier");
    m_ParameterDef__identifier->setDefaultValueLiteral("");
    m_ParameterDef__identifier->setLowerBound(0);
    m_ParameterDef__identifier->setUpperBound(1);
    m_ParameterDef__identifier->setTransient(false);
    m_ParameterDef__identifier->setVolatile(false);
    m_ParameterDef__identifier->setChangeable(true);
    m_ParameterDef__identifier->setUnsettable(false);
    m_ParameterDef__identifier->setID(false);
    m_ParameterDef__identifier->setUnique(true);
    m_ParameterDef__identifier->setDerived(false);
    m_ParameterDef__identifier->setOrdered(true);
    m_ParameterDef__direction->setEType(m_ParameterModeEEnum);
    m_ParameterDef__direction->setName("direction");
    m_ParameterDef__direction->setDefaultValueLiteral("");
    m_ParameterDef__direction->setLowerBound(0);
    m_ParameterDef__direction->setUpperBound(1);
    m_ParameterDef__direction->setTransient(false);
    m_ParameterDef__direction->setVolatile(false);
    m_ParameterDef__direction->setChangeable(true);
    m_ParameterDef__direction->setUnsettable(false);
    m_ParameterDef__direction->setID(false);
    m_ParameterDef__direction->setUnique(true);
    m_ParameterDef__direction->setDerived(false);
    m_ParameterDef__direction->setOrdered(true);
    // PrimitiveDef
    m_PrimitiveDefEClass->setName("PrimitiveDef");
    m_PrimitiveDefEClass->setAbstract(false);
    m_PrimitiveDefEClass->setInterface(false);
    m_PrimitiveDef__kind->setEType(m_PrimitiveKindEEnum);
    m_PrimitiveDef__kind->setName("kind");
    m_PrimitiveDef__kind->setDefaultValueLiteral("");
    m_PrimitiveDef__kind->setLowerBound(0);
    m_PrimitiveDef__kind->setUpperBound(1);
    m_PrimitiveDef__kind->setTransient(false);
    m_PrimitiveDef__kind->setVolatile(false);
    m_PrimitiveDef__kind->setChangeable(true);
    m_PrimitiveDef__kind->setUnsettable(false);
    m_PrimitiveDef__kind->setID(false);
    m_PrimitiveDef__kind->setUnique(true);
    m_PrimitiveDef__kind->setDerived(false);
    m_PrimitiveDef__kind->setOrdered(true);
    // ExceptionDef
    m_ExceptionDefEClass->setName("ExceptionDef");
    m_ExceptionDefEClass->setAbstract(false);
    m_ExceptionDefEClass->setInterface(false);
    m_ExceptionDef__typeCode->setEType(m_ETypeCodeEDataType);
    m_ExceptionDef__typeCode->setName("typeCode");
    m_ExceptionDef__typeCode->setDefaultValueLiteral("");
    m_ExceptionDef__typeCode->setLowerBound(0);
    m_ExceptionDef__typeCode->setUpperBound(1);
    m_ExceptionDef__typeCode->setTransient(false);
    m_ExceptionDef__typeCode->setVolatile(false);
    m_ExceptionDef__typeCode->setChangeable(true);
    m_ExceptionDef__typeCode->setUnsettable(false);
    m_ExceptionDef__typeCode->setID(false);
    m_ExceptionDef__typeCode->setUnique(true);
    m_ExceptionDef__typeCode->setDerived(false);
    m_ExceptionDef__typeCode->setOrdered(true);
    m_ExceptionDef__members->setEType(m_FieldEClass);
    m_ExceptionDef__members->setName("members");
    m_ExceptionDef__members->setDefaultValueLiteral("");
    m_ExceptionDef__members->setLowerBound(0);
    m_ExceptionDef__members->setUpperBound(-1);
    m_ExceptionDef__members->setTransient(false);
    m_ExceptionDef__members->setVolatile(false);
    m_ExceptionDef__members->setChangeable(true);
    m_ExceptionDef__members->setContainment(true);
    m_ExceptionDef__members->setResolveProxies(true);
    m_ExceptionDef__members->setUnique(true);
    m_ExceptionDef__members->setDerived(false);
    m_ExceptionDef__members->setOrdered(true);
    // Field
    m_FieldEClass->setName("Field");
    m_FieldEClass->setAbstract(false);
    m_FieldEClass->setInterface(false);
    m_Field__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Field__identifier->setName("identifier");
    m_Field__identifier->setDefaultValueLiteral("");
    m_Field__identifier->setLowerBound(0);
    m_Field__identifier->setUpperBound(1);
    m_Field__identifier->setTransient(false);
    m_Field__identifier->setVolatile(false);
    m_Field__identifier->setChangeable(true);
    m_Field__identifier->setUnsettable(false);
    m_Field__identifier->setID(false);
    m_Field__identifier->setUnique(true);
    m_Field__identifier->setDerived(false);
    m_Field__identifier->setOrdered(true);
    // FixedDef
    m_FixedDefEClass->setName("FixedDef");
    m_FixedDefEClass->setAbstract(false);
    m_FixedDefEClass->setInterface(false);
    m_FixedDef__digits->setEType(m_ExpressionEClass);
    m_FixedDef__digits->setName("digits");
    m_FixedDef__digits->setDefaultValueLiteral("");
    m_FixedDef__digits->setLowerBound(1);
    m_FixedDef__digits->setUpperBound(1);
    m_FixedDef__digits->setTransient(false);
    m_FixedDef__digits->setVolatile(false);
    m_FixedDef__digits->setChangeable(true);
    m_FixedDef__digits->setContainment(true);
    m_FixedDef__digits->setResolveProxies(true);
    m_FixedDef__digits->setUnique(true);
    m_FixedDef__digits->setDerived(false);
    m_FixedDef__digits->setOrdered(true);
    m_FixedDef__scale->setEType(m_ExpressionEClass);
    m_FixedDef__scale->setName("scale");
    m_FixedDef__scale->setDefaultValueLiteral("");
    m_FixedDef__scale->setLowerBound(1);
    m_FixedDef__scale->setUpperBound(1);
    m_FixedDef__scale->setTransient(false);
    m_FixedDef__scale->setVolatile(false);
    m_FixedDef__scale->setChangeable(true);
    m_FixedDef__scale->setContainment(true);
    m_FixedDef__scale->setResolveProxies(true);
    m_FixedDef__scale->setUnique(true);
    m_FixedDef__scale->setDerived(false);
    m_FixedDef__scale->setOrdered(true);
    // WstringDef
    m_WstringDefEClass->setName("WstringDef");
    m_WstringDefEClass->setAbstract(false);
    m_WstringDefEClass->setInterface(false);
    m_WstringDef__bound->setEType(m_ExpressionEClass);
    m_WstringDef__bound->setName("bound");
    m_WstringDef__bound->setDefaultValueLiteral("");
    m_WstringDef__bound->setLowerBound(0);
    m_WstringDef__bound->setUpperBound(1);
    m_WstringDef__bound->setTransient(false);
    m_WstringDef__bound->setVolatile(false);
    m_WstringDef__bound->setChangeable(true);
    m_WstringDef__bound->setContainment(true);
    m_WstringDef__bound->setResolveProxies(true);
    m_WstringDef__bound->setUnique(true);
    m_WstringDef__bound->setDerived(false);
    m_WstringDef__bound->setOrdered(true);
    // StringDef
    m_StringDefEClass->setName("StringDef");
    m_StringDefEClass->setAbstract(false);
    m_StringDefEClass->setInterface(false);
    m_StringDef__bound->setEType(m_ExpressionEClass);
    m_StringDef__bound->setName("bound");
    m_StringDef__bound->setDefaultValueLiteral("");
    m_StringDef__bound->setLowerBound(0);
    m_StringDef__bound->setUpperBound(1);
    m_StringDef__bound->setTransient(false);
    m_StringDef__bound->setVolatile(false);
    m_StringDef__bound->setChangeable(true);
    m_StringDef__bound->setContainment(true);
    m_StringDef__bound->setResolveProxies(true);
    m_StringDef__bound->setUnique(true);
    m_StringDef__bound->setDerived(false);
    m_StringDef__bound->setOrdered(true);
    // AliasDef
    m_AliasDefEClass->setName("AliasDef");
    m_AliasDefEClass->setAbstract(false);
    m_AliasDefEClass->setInterface(false);
    // ArrayDef
    m_ArrayDefEClass->setName("ArrayDef");
    m_ArrayDefEClass->setAbstract(false);
    m_ArrayDefEClass->setInterface(false);
    m_ArrayDef__name->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_ArrayDef__name->setName("name");
    m_ArrayDef__name->setDefaultValueLiteral("");
    m_ArrayDef__name->setLowerBound(0);
    m_ArrayDef__name->setUpperBound(1);
    m_ArrayDef__name->setTransient(false);
    m_ArrayDef__name->setVolatile(false);
    m_ArrayDef__name->setChangeable(true);
    m_ArrayDef__name->setUnsettable(false);
    m_ArrayDef__name->setID(false);
    m_ArrayDef__name->setUnique(true);
    m_ArrayDef__name->setDerived(false);
    m_ArrayDef__name->setOrdered(true);
    m_ArrayDef__bounds->setEType(m_ExpressionEClass);
    m_ArrayDef__bounds->setName("bounds");
    m_ArrayDef__bounds->setDefaultValueLiteral("");
    m_ArrayDef__bounds->setLowerBound(1);
    m_ArrayDef__bounds->setUpperBound(-1);
    m_ArrayDef__bounds->setTransient(false);
    m_ArrayDef__bounds->setVolatile(false);
    m_ArrayDef__bounds->setChangeable(true);
    m_ArrayDef__bounds->setContainment(true);
    m_ArrayDef__bounds->setResolveProxies(true);
    m_ArrayDef__bounds->setUnique(true);
    m_ArrayDef__bounds->setDerived(false);
    m_ArrayDef__bounds->setOrdered(true);
    // SequenceDef
    m_SequenceDefEClass->setName("SequenceDef");
    m_SequenceDefEClass->setAbstract(false);
    m_SequenceDefEClass->setInterface(false);
    m_SequenceDef__bound->setEType(m_ExpressionEClass);
    m_SequenceDef__bound->setName("bound");
    m_SequenceDef__bound->setDefaultValueLiteral("");
    m_SequenceDef__bound->setLowerBound(0);
    m_SequenceDef__bound->setUpperBound(1);
    m_SequenceDef__bound->setTransient(false);
    m_SequenceDef__bound->setVolatile(false);
    m_SequenceDef__bound->setChangeable(true);
    m_SequenceDef__bound->setContainment(true);
    m_SequenceDef__bound->setResolveProxies(true);
    m_SequenceDef__bound->setUnique(true);
    m_SequenceDef__bound->setDerived(false);
    m_SequenceDef__bound->setOrdered(true);
    // UnionField
    m_UnionFieldEClass->setName("UnionField");
    m_UnionFieldEClass->setAbstract(false);
    m_UnionFieldEClass->setInterface(false);
    m_UnionField__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_UnionField__identifier->setName("identifier");
    m_UnionField__identifier->setDefaultValueLiteral("");
    m_UnionField__identifier->setLowerBound(0);
    m_UnionField__identifier->setUpperBound(1);
    m_UnionField__identifier->setTransient(false);
    m_UnionField__identifier->setVolatile(false);
    m_UnionField__identifier->setChangeable(true);
    m_UnionField__identifier->setUnsettable(false);
    m_UnionField__identifier->setID(false);
    m_UnionField__identifier->setUnique(true);
    m_UnionField__identifier->setDerived(false);
    m_UnionField__identifier->setOrdered(true);
    m_UnionField__label->setEType(m_ExpressionEClass);
    m_UnionField__label->setName("label");
    m_UnionField__label->setDefaultValueLiteral("");
    m_UnionField__label->setLowerBound(0);
    m_UnionField__label->setUpperBound(-1);
    m_UnionField__label->setTransient(false);
    m_UnionField__label->setVolatile(false);
    m_UnionField__label->setChangeable(true);
    m_UnionField__label->setContainment(true);
    m_UnionField__label->setResolveProxies(true);
    m_UnionField__label->setUnique(true);
    m_UnionField__label->setDerived(false);
    m_UnionField__label->setOrdered(true);
    // TypedefDef
    m_TypedefDefEClass->setName("TypedefDef");
    m_TypedefDefEClass->setAbstract(true);
    m_TypedefDefEClass->setInterface(false);
    // UnionDef
    m_UnionDefEClass->setName("UnionDef");
    m_UnionDefEClass->setAbstract(false);
    m_UnionDefEClass->setInterface(false);
    m_UnionDef__unionMembers->setEType(m_UnionFieldEClass);
    m_UnionDef__unionMembers->setName("unionMembers");
    m_UnionDef__unionMembers->setDefaultValueLiteral("");
    m_UnionDef__unionMembers->setLowerBound(0);
    m_UnionDef__unionMembers->setUpperBound(-1);
    m_UnionDef__unionMembers->setTransient(false);
    m_UnionDef__unionMembers->setVolatile(false);
    m_UnionDef__unionMembers->setChangeable(true);
    m_UnionDef__unionMembers->setContainment(true);
    m_UnionDef__unionMembers->setResolveProxies(true);
    m_UnionDef__unionMembers->setUnique(true);
    m_UnionDef__unionMembers->setDerived(false);
    m_UnionDef__unionMembers->setOrdered(true);
    m_UnionDef__containedDiscrim->setEType(m_IDLTypeEClass);
    m_UnionDef__containedDiscrim->setName("containedDiscrim");
    m_UnionDef__containedDiscrim->setDefaultValueLiteral("");
    m_UnionDef__containedDiscrim->setLowerBound(0);
    m_UnionDef__containedDiscrim->setUpperBound(1);
    m_UnionDef__containedDiscrim->setTransient(false);
    m_UnionDef__containedDiscrim->setVolatile(false);
    m_UnionDef__containedDiscrim->setChangeable(true);
    m_UnionDef__containedDiscrim->setContainment(true);
    m_UnionDef__containedDiscrim->setResolveProxies(true);
    m_UnionDef__containedDiscrim->setUnique(true);
    m_UnionDef__containedDiscrim->setDerived(false);
    m_UnionDef__containedDiscrim->setOrdered(true);
    m_UnionDef__sharedDiscrim->setEType(m_TypedefDefEClass);
    m_UnionDef__sharedDiscrim->setName("sharedDiscrim");
    m_UnionDef__sharedDiscrim->setDefaultValueLiteral("");
    m_UnionDef__sharedDiscrim->setLowerBound(0);
    m_UnionDef__sharedDiscrim->setUpperBound(1);
    m_UnionDef__sharedDiscrim->setTransient(false);
    m_UnionDef__sharedDiscrim->setVolatile(false);
    m_UnionDef__sharedDiscrim->setChangeable(true);
    m_UnionDef__sharedDiscrim->setContainment(false);
    m_UnionDef__sharedDiscrim->setResolveProxies(true);
    m_UnionDef__sharedDiscrim->setUnique(true);
    m_UnionDef__sharedDiscrim->setDerived(false);
    m_UnionDef__sharedDiscrim->setOrdered(true);
    // EnumDef
    m_EnumDefEClass->setName("EnumDef");
    m_EnumDefEClass->setAbstract(false);
    m_EnumDefEClass->setInterface(false);
    m_EnumDef__members->setEType(m_EnumMemberEClass);
    m_EnumDef__members->setName("members");
    m_EnumDef__members->setDefaultValueLiteral("");
    m_EnumDef__members->setLowerBound(1);
    m_EnumDef__members->setUpperBound(-1);
    m_EnumDef__members->setTransient(false);
    m_EnumDef__members->setVolatile(false);
    m_EnumDef__members->setChangeable(true);
    m_EnumDef__members->setContainment(true);
    m_EnumDef__members->setResolveProxies(true);
    m_EnumDef__members->setUnique(true);
    m_EnumDef__members->setDerived(false);
    m_EnumDef__members->setOrdered(true);
    m_EnumDef__members->setEOpposite(
            ::ecore::instanceOf< ::ecore::EReference >(
                    m_EnumMemberEClass->getEStructuralFeatures()[0]));
    // StructDef
    m_StructDefEClass->setName("StructDef");
    m_StructDefEClass->setAbstract(false);
    m_StructDefEClass->setInterface(false);
    m_StructDef__members->setEType(m_FieldEClass);
    m_StructDef__members->setName("members");
    m_StructDef__members->setDefaultValueLiteral("");
    m_StructDef__members->setLowerBound(0);
    m_StructDef__members->setUpperBound(-1);
    m_StructDef__members->setTransient(false);
    m_StructDef__members->setVolatile(false);
    m_StructDef__members->setChangeable(true);
    m_StructDef__members->setContainment(true);
    m_StructDef__members->setResolveProxies(true);
    m_StructDef__members->setUnique(true);
    m_StructDef__members->setDerived(false);
    m_StructDef__members->setOrdered(true);
    // TranslationUnit
    m_TranslationUnitEClass->setName("TranslationUnit");
    m_TranslationUnitEClass->setAbstract(false);
    m_TranslationUnitEClass->setInterface(false);
    m_TranslationUnit__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_TranslationUnit__identifier->setName("identifier");
    m_TranslationUnit__identifier->setDefaultValueLiteral("");
    m_TranslationUnit__identifier->setLowerBound(0);
    m_TranslationUnit__identifier->setUpperBound(1);
    m_TranslationUnit__identifier->setTransient(false);
    m_TranslationUnit__identifier->setVolatile(false);
    m_TranslationUnit__identifier->setChangeable(true);
    m_TranslationUnit__identifier->setUnsettable(false);
    m_TranslationUnit__identifier->setID(false);
    m_TranslationUnit__identifier->setUnique(true);
    m_TranslationUnit__identifier->setDerived(false);
    m_TranslationUnit__identifier->setOrdered(true);
    m_TranslationUnit__contains->setEType(m_ContainedEClass);
    m_TranslationUnit__contains->setName("contains");
    m_TranslationUnit__contains->setDefaultValueLiteral("");
    m_TranslationUnit__contains->setLowerBound(0);
    m_TranslationUnit__contains->setUpperBound(-1);
    m_TranslationUnit__contains->setTransient(false);
    m_TranslationUnit__contains->setVolatile(false);
    m_TranslationUnit__contains->setChangeable(true);
    m_TranslationUnit__contains->setContainment(true);
    m_TranslationUnit__contains->setResolveProxies(true);
    m_TranslationUnit__contains->setUnique(true);
    m_TranslationUnit__contains->setDerived(false);
    m_TranslationUnit__contains->setOrdered(true);
    m_TranslationUnit__includes->setEType(m_IncludeEClass);
    m_TranslationUnit__includes->setName("includes");
    m_TranslationUnit__includes->setDefaultValueLiteral("");
    m_TranslationUnit__includes->setLowerBound(0);
    m_TranslationUnit__includes->setUpperBound(-1);
    m_TranslationUnit__includes->setTransient(false);
    m_TranslationUnit__includes->setVolatile(false);
    m_TranslationUnit__includes->setChangeable(true);
    m_TranslationUnit__includes->setContainment(true);
    m_TranslationUnit__includes->setResolveProxies(true);
    m_TranslationUnit__includes->setUnique(true);
    m_TranslationUnit__includes->setDerived(false);
    m_TranslationUnit__includes->setOrdered(true);
    // Include
    m_IncludeEClass->setName("Include");
    m_IncludeEClass->setAbstract(false);
    m_IncludeEClass->setInterface(false);
    m_Include__importURI->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Include__importURI->setName("importURI");
    m_Include__importURI->setDefaultValueLiteral("");
    m_Include__importURI->setLowerBound(0);
    m_Include__importURI->setUpperBound(1);
    m_Include__importURI->setTransient(false);
    m_Include__importURI->setVolatile(false);
    m_Include__importURI->setChangeable(true);
    m_Include__importURI->setUnsettable(false);
    m_Include__importURI->setID(false);
    m_Include__importURI->setUnique(true);
    m_Include__importURI->setDerived(false);
    m_Include__importURI->setOrdered(true);
    m_Include__translationUnit->setEType(m_TranslationUnitEClass);
    m_Include__translationUnit->setName("translationUnit");
    m_Include__translationUnit->setDefaultValueLiteral("");
    m_Include__translationUnit->setLowerBound(0);
    m_Include__translationUnit->setUpperBound(1);
    m_Include__translationUnit->setTransient(false);
    m_Include__translationUnit->setVolatile(false);
    m_Include__translationUnit->setChangeable(true);
    m_Include__translationUnit->setContainment(false);
    m_Include__translationUnit->setResolveProxies(true);
    m_Include__translationUnit->setUnique(true);
    m_Include__translationUnit->setDerived(false);
    m_Include__translationUnit->setOrdered(true);
    // Expression
    m_ExpressionEClass->setName("Expression");
    m_ExpressionEClass->setAbstract(true);
    m_ExpressionEClass->setInterface(false);
    // BinaryExpression
    m_BinaryExpressionEClass->setName("BinaryExpression");
    m_BinaryExpressionEClass->setAbstract(false);
    m_BinaryExpressionEClass->setInterface(false);
    m_BinaryExpression__operator->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_BinaryExpression__operator->setName("operator");
    m_BinaryExpression__operator->setDefaultValueLiteral("");
    m_BinaryExpression__operator->setLowerBound(1);
    m_BinaryExpression__operator->setUpperBound(1);
    m_BinaryExpression__operator->setTransient(false);
    m_BinaryExpression__operator->setVolatile(false);
    m_BinaryExpression__operator->setChangeable(true);
    m_BinaryExpression__operator->setUnsettable(false);
    m_BinaryExpression__operator->setID(false);
    m_BinaryExpression__operator->setUnique(true);
    m_BinaryExpression__operator->setDerived(false);
    m_BinaryExpression__operator->setOrdered(true);
    m_BinaryExpression__left->setEType(m_ExpressionEClass);
    m_BinaryExpression__left->setName("left");
    m_BinaryExpression__left->setDefaultValueLiteral("");
    m_BinaryExpression__left->setLowerBound(1);
    m_BinaryExpression__left->setUpperBound(1);
    m_BinaryExpression__left->setTransient(false);
    m_BinaryExpression__left->setVolatile(false);
    m_BinaryExpression__left->setChangeable(true);
    m_BinaryExpression__left->setContainment(true);
    m_BinaryExpression__left->setResolveProxies(true);
    m_BinaryExpression__left->setUnique(true);
    m_BinaryExpression__left->setDerived(false);
    m_BinaryExpression__left->setOrdered(true);
    m_BinaryExpression__right->setEType(m_ExpressionEClass);
    m_BinaryExpression__right->setName("right");
    m_BinaryExpression__right->setDefaultValueLiteral("");
    m_BinaryExpression__right->setLowerBound(1);
    m_BinaryExpression__right->setUpperBound(1);
    m_BinaryExpression__right->setTransient(false);
    m_BinaryExpression__right->setVolatile(false);
    m_BinaryExpression__right->setChangeable(true);
    m_BinaryExpression__right->setContainment(true);
    m_BinaryExpression__right->setResolveProxies(true);
    m_BinaryExpression__right->setUnique(true);
    m_BinaryExpression__right->setDerived(false);
    m_BinaryExpression__right->setOrdered(true);
    // UnaryExpression
    m_UnaryExpressionEClass->setName("UnaryExpression");
    m_UnaryExpressionEClass->setAbstract(false);
    m_UnaryExpressionEClass->setInterface(false);
    m_UnaryExpression__operator->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_UnaryExpression__operator->setName("operator");
    m_UnaryExpression__operator->setDefaultValueLiteral("");
    m_UnaryExpression__operator->setLowerBound(1);
    m_UnaryExpression__operator->setUpperBound(1);
    m_UnaryExpression__operator->setTransient(false);
    m_UnaryExpression__operator->setVolatile(false);
    m_UnaryExpression__operator->setChangeable(true);
    m_UnaryExpression__operator->setUnsettable(false);
    m_UnaryExpression__operator->setID(false);
    m_UnaryExpression__operator->setUnique(true);
    m_UnaryExpression__operator->setDerived(false);
    m_UnaryExpression__operator->setOrdered(true);
    m_UnaryExpression__expression->setEType(m_ExpressionEClass);
    m_UnaryExpression__expression->setName("expression");
    m_UnaryExpression__expression->setDefaultValueLiteral("");
    m_UnaryExpression__expression->setLowerBound(1);
    m_UnaryExpression__expression->setUpperBound(1);
    m_UnaryExpression__expression->setTransient(false);
    m_UnaryExpression__expression->setVolatile(false);
    m_UnaryExpression__expression->setChangeable(true);
    m_UnaryExpression__expression->setContainment(true);
    m_UnaryExpression__expression->setResolveProxies(true);
    m_UnaryExpression__expression->setUnique(true);
    m_UnaryExpression__expression->setDerived(false);
    m_UnaryExpression__expression->setOrdered(true);
    // LiteralExpression
    m_LiteralExpressionEClass->setName("LiteralExpression");
    m_LiteralExpressionEClass->setAbstract(true);
    m_LiteralExpressionEClass->setInterface(false);
    // ConstantDefRef
    m_ConstantDefRefEClass->setName("ConstantDefRef");
    m_ConstantDefRefEClass->setAbstract(false);
    m_ConstantDefRefEClass->setInterface(false);
    m_ConstantDefRef__constant->setEType(m_ConstantEClass);
    m_ConstantDefRef__constant->setName("constant");
    m_ConstantDefRef__constant->setDefaultValueLiteral("");
    m_ConstantDefRef__constant->setLowerBound(1);
    m_ConstantDefRef__constant->setUpperBound(1);
    m_ConstantDefRef__constant->setTransient(false);
    m_ConstantDefRef__constant->setVolatile(false);
    m_ConstantDefRef__constant->setChangeable(true);
    m_ConstantDefRef__constant->setContainment(false);
    m_ConstantDefRef__constant->setResolveProxies(true);
    m_ConstantDefRef__constant->setUnique(true);
    m_ConstantDefRef__constant->setDerived(false);
    m_ConstantDefRef__constant->setOrdered(true);
    // ValueExpression
    m_ValueExpressionEClass->setName("ValueExpression");
    m_ValueExpressionEClass->setAbstract(false);
    m_ValueExpressionEClass->setInterface(false);
    m_ValueExpression__value->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_ValueExpression__value->setName("value");
    m_ValueExpression__value->setDefaultValueLiteral("");
    m_ValueExpression__value->setLowerBound(1);
    m_ValueExpression__value->setUpperBound(1);
    m_ValueExpression__value->setTransient(false);
    m_ValueExpression__value->setVolatile(false);
    m_ValueExpression__value->setChangeable(true);
    m_ValueExpression__value->setUnsettable(false);
    m_ValueExpression__value->setID(false);
    m_ValueExpression__value->setUnique(true);
    m_ValueExpression__value->setDerived(false);
    m_ValueExpression__value->setOrdered(true);
    // ForwardDef
    m_ForwardDefEClass->setName("ForwardDef");
    m_ForwardDefEClass->setAbstract(false);
    m_ForwardDefEClass->setInterface(false);
    m_ForwardDef__definition->setEType(m_InterfaceDefEClass);
    m_ForwardDef__definition->setName("definition");
    m_ForwardDef__definition->setDefaultValueLiteral("");
    m_ForwardDef__definition->setLowerBound(0);
    m_ForwardDef__definition->setUpperBound(1);
    m_ForwardDef__definition->setTransient(false);
    m_ForwardDef__definition->setVolatile(false);
    m_ForwardDef__definition->setChangeable(true);
    m_ForwardDef__definition->setContainment(false);
    m_ForwardDef__definition->setResolveProxies(true);
    m_ForwardDef__definition->setUnique(true);
    m_ForwardDef__definition->setDerived(false);
    m_ForwardDef__definition->setOrdered(true);
    // EnumMember
    m_EnumMemberEClass->setName("EnumMember");
    m_EnumMemberEClass->setAbstract(false);
    m_EnumMemberEClass->setInterface(false);
    m_EnumMember__enum->setEType(m_EnumDefEClass);
    m_EnumMember__enum->setName("enum");
    m_EnumMember__enum->setDefaultValueLiteral("");
    m_EnumMember__enum->setLowerBound(1);
    m_EnumMember__enum->setUpperBound(1);
    m_EnumMember__enum->setTransient(false);
    m_EnumMember__enum->setVolatile(false);
    m_EnumMember__enum->setChangeable(true);
    m_EnumMember__enum->setContainment(false);
    m_EnumMember__enum->setResolveProxies(true);
    m_EnumMember__enum->setUnique(true);
    m_EnumMember__enum->setDerived(false);
    m_EnumMember__enum->setOrdered(true);
    m_EnumMember__enum->setEOpposite(
            ::ecore::instanceOf< ::ecore::EReference >(
                    m_EnumDefEClass->getEStructuralFeatures()[0]));
    // Constant
    m_ConstantEClass->setName("Constant");
    m_ConstantEClass->setAbstract(true);
    m_ConstantEClass->setInterface(false);
    // NamedElement
    m_NamedElementEClass->setName("NamedElement");
    m_NamedElementEClass->setAbstract(true);
    m_NamedElementEClass->setInterface(false);
    m_NamedElement__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NamedElement__identifier->setName("identifier");
    m_NamedElement__identifier->setDefaultValueLiteral("");
    m_NamedElement__identifier->setLowerBound(0);
    m_NamedElement__identifier->setUpperBound(1);
    m_NamedElement__identifier->setTransient(false);
    m_NamedElement__identifier->setVolatile(false);
    m_NamedElement__identifier->setChangeable(true);
    m_NamedElement__identifier->setUnsettable(false);
    m_NamedElement__identifier->setID(false);
    m_NamedElement__identifier->setUnique(true);
    m_NamedElement__identifier->setDerived(false);
    m_NamedElement__identifier->setOrdered(true);

    // TODO: Initialize data types

    // EAny
    m_EAnyEDataType->setName("EAny");
    m_EAnyEDataType->setSerializable(true);

    // ETypeCode
    m_ETypeCodeEDataType->setName("ETypeCode");
    m_ETypeCodeEDataType->setSerializable(true);

    // ParameterMode
    m_ParameterModeEEnum->setName("ParameterMode");
    m_ParameterModeEEnum->setSerializable(true);

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PARAM_IN
        _el->setName("PARAM_IN");
        _el->setValue(0);
        _el->setLiteral("PARAM_IN");
        _el->setEEnum(m_ParameterModeEEnum);
        m_ParameterModeEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PARAM_OUT
        _el->setName("PARAM_OUT");
        _el->setValue(1);
        _el->setLiteral("PARAM_OUT");
        _el->setEEnum(m_ParameterModeEEnum);
        m_ParameterModeEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PARAM_INOUT
        _el->setName("PARAM_INOUT");
        _el->setValue(2);
        _el->setLiteral("PARAM_INOUT");
        _el->setEEnum(m_ParameterModeEEnum);
        m_ParameterModeEEnum->getELiterals().push_back(_el);
    }

    // PrimitiveKind
    m_PrimitiveKindEEnum->setName("PrimitiveKind");
    m_PrimitiveKindEEnum->setSerializable(true);

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_NULL
        _el->setName("PK_NULL");
        _el->setValue(0);
        _el->setLiteral("PK_NULL");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_VOID
        _el->setName("PK_VOID");
        _el->setValue(1);
        _el->setLiteral("PK_VOID");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_SHORT
        _el->setName("PK_SHORT");
        _el->setValue(2);
        _el->setLiteral("PK_SHORT");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_LONG
        _el->setName("PK_LONG");
        _el->setValue(3);
        _el->setLiteral("PK_LONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_USHORT
        _el->setName("PK_USHORT");
        _el->setValue(4);
        _el->setLiteral("PK_USHORT");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_ULONG
        _el->setName("PK_ULONG");
        _el->setValue(5);
        _el->setLiteral("PK_ULONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_FLOAT
        _el->setName("PK_FLOAT");
        _el->setValue(6);
        _el->setLiteral("PK_FLOAT");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_DOUBLE
        _el->setName("PK_DOUBLE");
        _el->setValue(7);
        _el->setLiteral("PK_DOUBLE");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_BOOLEAN
        _el->setName("PK_BOOLEAN");
        _el->setValue(8);
        _el->setLiteral("PK_BOOLEAN");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_CHAR
        _el->setName("PK_CHAR");
        _el->setValue(9);
        _el->setLiteral("PK_CHAR");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_OCTET
        _el->setName("PK_OCTET");
        _el->setValue(10);
        _el->setLiteral("PK_OCTET");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_ANY
        _el->setName("PK_ANY");
        _el->setValue(11);
        _el->setLiteral("PK_ANY");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_LONGDOUBLE
        _el->setName("PK_LONGDOUBLE");
        _el->setValue(12);
        _el->setLiteral("PK_LONGDOUBLE");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_WSTRING
        _el->setName("PK_WSTRING");
        _el->setValue(13);
        _el->setLiteral("PK_WSTRING");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_TYPECODE
        _el->setName("PK_TYPECODE");
        _el->setValue(14);
        _el->setLiteral("PK_TYPECODE");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_WCHAR
        _el->setName("PK_WCHAR");
        _el->setValue(15);
        _el->setLiteral("PK_WCHAR");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_PRINCIPAL
        _el->setName("PK_PRINCIPAL");
        _el->setValue(16);
        _el->setLiteral("PK_PRINCIPAL");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_STRING
        _el->setName("PK_STRING");
        _el->setValue(17);
        _el->setLiteral("PK_STRING");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_ULONGLONG
        _el->setName("PK_ULONGLONG");
        _el->setValue(18);
        _el->setLiteral("PK_ULONGLONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_OBJREF
        _el->setName("PK_OBJREF");
        _el->setValue(19);
        _el->setLiteral("PK_OBJREF");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = new ::ecore::EEnumLiteral();
        // PK_LONGLONG
        _el->setName("PK_LONGLONG");
        _el->setValue(20);
        _el->setLiteral("PK_LONGLONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    _initialize();
}

::ecore::EClass_ptr IdlmmPackage::getContainer()
{
    return m_ContainerEClass;
}
::ecore::EClass_ptr IdlmmPackage::getContained()
{
    return m_ContainedEClass;
}
::ecore::EClass_ptr IdlmmPackage::getInterfaceDef()
{
    return m_InterfaceDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getModuleDef()
{
    return m_ModuleDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getIDLType()
{
    return m_IDLTypeEClass;
}
::ecore::EClass_ptr IdlmmPackage::getOperationDef()
{
    return m_OperationDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getAttributeDef()
{
    return m_AttributeDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getConstantDef()
{
    return m_ConstantDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getTyped()
{
    return m_TypedEClass;
}
::ecore::EClass_ptr IdlmmPackage::getParameterDef()
{
    return m_ParameterDefEClass;
}
::ecore::EEnum_ptr IdlmmPackage::getParameterMode()
{
    return m_ParameterModeEEnum;
}
::ecore::EClass_ptr IdlmmPackage::getPrimitiveDef()
{
    return m_PrimitiveDefEClass;
}
::ecore::EEnum_ptr IdlmmPackage::getPrimitiveKind()
{
    return m_PrimitiveKindEEnum;
}
::ecore::EClass_ptr IdlmmPackage::getExceptionDef()
{
    return m_ExceptionDefEClass;
}
::ecore::EDataType_ptr IdlmmPackage::getEAny()
{
    return m_EAnyEDataType;
}
::ecore::EDataType_ptr IdlmmPackage::getETypeCode()
{
    return m_ETypeCodeEDataType;
}
::ecore::EClass_ptr IdlmmPackage::getField()
{
    return m_FieldEClass;
}
::ecore::EClass_ptr IdlmmPackage::getFixedDef()
{
    return m_FixedDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getWstringDef()
{
    return m_WstringDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getStringDef()
{
    return m_StringDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getAliasDef()
{
    return m_AliasDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getArrayDef()
{
    return m_ArrayDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getSequenceDef()
{
    return m_SequenceDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getUnionField()
{
    return m_UnionFieldEClass;
}
::ecore::EClass_ptr IdlmmPackage::getTypedefDef()
{
    return m_TypedefDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getUnionDef()
{
    return m_UnionDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getEnumDef()
{
    return m_EnumDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getStructDef()
{
    return m_StructDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getTranslationUnit()
{
    return m_TranslationUnitEClass;
}
::ecore::EClass_ptr IdlmmPackage::getInclude()
{
    return m_IncludeEClass;
}
::ecore::EClass_ptr IdlmmPackage::getExpression()
{
    return m_ExpressionEClass;
}
::ecore::EClass_ptr IdlmmPackage::getBinaryExpression()
{
    return m_BinaryExpressionEClass;
}
::ecore::EClass_ptr IdlmmPackage::getUnaryExpression()
{
    return m_UnaryExpressionEClass;
}
::ecore::EClass_ptr IdlmmPackage::getLiteralExpression()
{
    return m_LiteralExpressionEClass;
}
::ecore::EClass_ptr IdlmmPackage::getConstantDefRef()
{
    return m_ConstantDefRefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getValueExpression()
{
    return m_ValueExpressionEClass;
}
::ecore::EClass_ptr IdlmmPackage::getForwardDef()
{
    return m_ForwardDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getEnumMember()
{
    return m_EnumMemberEClass;
}
::ecore::EClass_ptr IdlmmPackage::getConstant()
{
    return m_ConstantEClass;
}
::ecore::EClass_ptr IdlmmPackage::getNamedElement()
{
    return m_NamedElementEClass;
}

::ecore::EAttribute_ptr IdlmmPackage::getNamedElement__identifier()
{
    return m_NamedElement__identifier;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__repositoryId()
{
    return m_Contained__repositoryId;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__version()
{
    return m_Contained__version;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__absoluteName()
{
    return m_Contained__absoluteName;
}
::ecore::EReference_ptr IdlmmPackage::getContained__definedIn()
{
    return m_Contained__definedIn;
}
::ecore::EReference_ptr IdlmmPackage::getContainer__contains()
{
    return m_Container__contains;
}
::ecore::EAttribute_ptr IdlmmPackage::getIDLType__typeCode()
{
    return m_IDLType__typeCode;
}
::ecore::EAttribute_ptr IdlmmPackage::getInterfaceDef__isAbstract()
{
    return m_InterfaceDef__isAbstract;
}
::ecore::EAttribute_ptr IdlmmPackage::getInterfaceDef__isCustom()
{
    return m_InterfaceDef__isCustom;
}
::ecore::EAttribute_ptr IdlmmPackage::getInterfaceDef__isTruncatable()
{
    return m_InterfaceDef__isTruncatable;
}
::ecore::EReference_ptr IdlmmPackage::getInterfaceDef__derivesFrom()
{
    return m_InterfaceDef__derivesFrom;
}
::ecore::EReference_ptr IdlmmPackage::getInterfaceDef__forward()
{
    return m_InterfaceDef__forward;
}
::ecore::EAttribute_ptr IdlmmPackage::getModuleDef__prefix()
{
    return m_ModuleDef__prefix;
}
::ecore::EReference_ptr IdlmmPackage::getTyped__containedType()
{
    return m_Typed__containedType;
}
::ecore::EReference_ptr IdlmmPackage::getTyped__sharedType()
{
    return m_Typed__sharedType;
}
::ecore::EReference_ptr IdlmmPackage::getOperationDef__parameters()
{
    return m_OperationDef__parameters;
}
::ecore::EAttribute_ptr IdlmmPackage::getOperationDef__isOneway()
{
    return m_OperationDef__isOneway;
}
::ecore::EAttribute_ptr IdlmmPackage::getOperationDef__contexts()
{
    return m_OperationDef__contexts;
}
::ecore::EReference_ptr IdlmmPackage::getOperationDef__canRaise()
{
    return m_OperationDef__canRaise;
}
::ecore::EReference_ptr IdlmmPackage::getAttributeDef__getRaises()
{
    return m_AttributeDef__getRaises;
}
::ecore::EReference_ptr IdlmmPackage::getAttributeDef__setRaises()
{
    return m_AttributeDef__setRaises;
}
::ecore::EAttribute_ptr IdlmmPackage::getAttributeDef__isReadonly()
{
    return m_AttributeDef__isReadonly;
}
::ecore::EReference_ptr IdlmmPackage::getConstantDef__constValue()
{
    return m_ConstantDef__constValue;
}
::ecore::EAttribute_ptr IdlmmPackage::getParameterDef__identifier()
{
    return m_ParameterDef__identifier;
}
::ecore::EAttribute_ptr IdlmmPackage::getParameterDef__direction()
{
    return m_ParameterDef__direction;
}
::ecore::EAttribute_ptr IdlmmPackage::getPrimitiveDef__kind()
{
    return m_PrimitiveDef__kind;
}
::ecore::EAttribute_ptr IdlmmPackage::getExceptionDef__typeCode()
{
    return m_ExceptionDef__typeCode;
}
::ecore::EReference_ptr IdlmmPackage::getExceptionDef__members()
{
    return m_ExceptionDef__members;
}
::ecore::EAttribute_ptr IdlmmPackage::getField__identifier()
{
    return m_Field__identifier;
}
::ecore::EReference_ptr IdlmmPackage::getFixedDef__digits()
{
    return m_FixedDef__digits;
}
::ecore::EReference_ptr IdlmmPackage::getFixedDef__scale()
{
    return m_FixedDef__scale;
}
::ecore::EReference_ptr IdlmmPackage::getWstringDef__bound()
{
    return m_WstringDef__bound;
}
::ecore::EReference_ptr IdlmmPackage::getStringDef__bound()
{
    return m_StringDef__bound;
}
::ecore::EAttribute_ptr IdlmmPackage::getArrayDef__name()
{
    return m_ArrayDef__name;
}
::ecore::EReference_ptr IdlmmPackage::getArrayDef__bounds()
{
    return m_ArrayDef__bounds;
}
::ecore::EReference_ptr IdlmmPackage::getSequenceDef__bound()
{
    return m_SequenceDef__bound;
}
::ecore::EAttribute_ptr IdlmmPackage::getUnionField__identifier()
{
    return m_UnionField__identifier;
}
::ecore::EReference_ptr IdlmmPackage::getUnionField__label()
{
    return m_UnionField__label;
}
::ecore::EReference_ptr IdlmmPackage::getUnionDef__unionMembers()
{
    return m_UnionDef__unionMembers;
}
::ecore::EReference_ptr IdlmmPackage::getUnionDef__containedDiscrim()
{
    return m_UnionDef__containedDiscrim;
}
::ecore::EReference_ptr IdlmmPackage::getUnionDef__sharedDiscrim()
{
    return m_UnionDef__sharedDiscrim;
}
::ecore::EReference_ptr IdlmmPackage::getEnumDef__members()
{
    return m_EnumDef__members;
}
::ecore::EReference_ptr IdlmmPackage::getStructDef__members()
{
    return m_StructDef__members;
}
::ecore::EReference_ptr IdlmmPackage::getTranslationUnit__contains()
{
    return m_TranslationUnit__contains;
}
::ecore::EAttribute_ptr IdlmmPackage::getTranslationUnit__identifier()
{
    return m_TranslationUnit__identifier;
}
::ecore::EReference_ptr IdlmmPackage::getTranslationUnit__includes()
{
    return m_TranslationUnit__includes;
}
::ecore::EAttribute_ptr IdlmmPackage::getInclude__importURI()
{
    return m_Include__importURI;
}
::ecore::EReference_ptr IdlmmPackage::getInclude__translationUnit()
{
    return m_Include__translationUnit;
}
::ecore::EReference_ptr IdlmmPackage::getBinaryExpression__left()
{
    return m_BinaryExpression__left;
}
::ecore::EReference_ptr IdlmmPackage::getBinaryExpression__right()
{
    return m_BinaryExpression__right;
}
::ecore::EAttribute_ptr IdlmmPackage::getBinaryExpression__operator()
{
    return m_BinaryExpression__operator;
}
::ecore::EReference_ptr IdlmmPackage::getUnaryExpression__expression()
{
    return m_UnaryExpression__expression;
}
::ecore::EAttribute_ptr IdlmmPackage::getUnaryExpression__operator()
{
    return m_UnaryExpression__operator;
}
::ecore::EReference_ptr IdlmmPackage::getConstantDefRef__constant()
{
    return m_ConstantDefRef__constant;
}
::ecore::EAttribute_ptr IdlmmPackage::getValueExpression__value()
{
    return m_ValueExpression__value;
}
::ecore::EReference_ptr IdlmmPackage::getForwardDef__definition()
{
    return m_ForwardDef__definition;
}
::ecore::EReference_ptr IdlmmPackage::getEnumMember__enum()
{
    return m_EnumMember__enum;
}

