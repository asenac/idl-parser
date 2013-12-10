// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/IdlmmFactoryImpl.cpp
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

#include <idlmm/IdlmmFactory.hpp>
#include <idlmm/ModelElement.hpp>
#include <idlmm/Container.hpp>
#include <idlmm/Contained.hpp>
#include <idlmm/InterfaceDef.hpp>
#include <idlmm/ModuleDef.hpp>
#include <idlmm/IDLType.hpp>
#include <idlmm/OperationDef.hpp>
#include <idlmm/AttributeDef.hpp>
#include <idlmm/ConstantDef.hpp>
#include <idlmm/Typed.hpp>
#include <idlmm/ParameterDef.hpp>
#include <idlmm/PrimitiveDef.hpp>
#include <idlmm/ExceptionDef.hpp>
#include <idlmm/Field.hpp>
#include <idlmm/FixedDef.hpp>
#include <idlmm/WstringDef.hpp>
#include <idlmm/StringDef.hpp>
#include <idlmm/AliasDef.hpp>
#include <idlmm/ArrayDef.hpp>
#include <idlmm/SequenceDef.hpp>
#include <idlmm/UnionField.hpp>
#include <idlmm/TypedefDef.hpp>
#include <idlmm/UnionDef.hpp>
#include <idlmm/EnumDef.hpp>
#include <idlmm/StructDef.hpp>
#include <idlmm/TranslationUnit.hpp>
#include <idlmm/Include.hpp>
#include <idlmm/Expression.hpp>
#include <idlmm/BinaryExpression.hpp>
#include <idlmm/UnaryExpression.hpp>
#include <idlmm/LiteralExpression.hpp>
#include <idlmm/ConstantDefRef.hpp>
#include <idlmm/ValueExpression.hpp>
#include <idlmm/ForwardDef.hpp>
#include <idlmm/EnumMember.hpp>
#include <idlmm/Constant.hpp>
#include <idlmm/NamedElement.hpp>

using namespace ::idlmm;

IdlmmFactory::IdlmmFactory()
{
}

ModelElement_ptr IdlmmFactory::createModelElement()
{
    return new ModelElement();
}
Container_ptr IdlmmFactory::createContainer()
{
    return new Container();
}
Contained_ptr IdlmmFactory::createContained()
{
    return new Contained();
}
InterfaceDef_ptr IdlmmFactory::createInterfaceDef()
{
    return new InterfaceDef();
}
ModuleDef_ptr IdlmmFactory::createModuleDef()
{
    return new ModuleDef();
}
IDLType_ptr IdlmmFactory::createIDLType()
{
    return new IDLType();
}
OperationDef_ptr IdlmmFactory::createOperationDef()
{
    return new OperationDef();
}
AttributeDef_ptr IdlmmFactory::createAttributeDef()
{
    return new AttributeDef();
}
ConstantDef_ptr IdlmmFactory::createConstantDef()
{
    return new ConstantDef();
}
Typed_ptr IdlmmFactory::createTyped()
{
    return new Typed();
}
ParameterDef_ptr IdlmmFactory::createParameterDef()
{
    return new ParameterDef();
}
PrimitiveDef_ptr IdlmmFactory::createPrimitiveDef()
{
    return new PrimitiveDef();
}
ExceptionDef_ptr IdlmmFactory::createExceptionDef()
{
    return new ExceptionDef();
}
Field_ptr IdlmmFactory::createField()
{
    return new Field();
}
FixedDef_ptr IdlmmFactory::createFixedDef()
{
    return new FixedDef();
}
WstringDef_ptr IdlmmFactory::createWstringDef()
{
    return new WstringDef();
}
StringDef_ptr IdlmmFactory::createStringDef()
{
    return new StringDef();
}
AliasDef_ptr IdlmmFactory::createAliasDef()
{
    return new AliasDef();
}
ArrayDef_ptr IdlmmFactory::createArrayDef()
{
    return new ArrayDef();
}
SequenceDef_ptr IdlmmFactory::createSequenceDef()
{
    return new SequenceDef();
}
UnionField_ptr IdlmmFactory::createUnionField()
{
    return new UnionField();
}
TypedefDef_ptr IdlmmFactory::createTypedefDef()
{
    return new TypedefDef();
}
UnionDef_ptr IdlmmFactory::createUnionDef()
{
    return new UnionDef();
}
EnumDef_ptr IdlmmFactory::createEnumDef()
{
    return new EnumDef();
}
StructDef_ptr IdlmmFactory::createStructDef()
{
    return new StructDef();
}
TranslationUnit_ptr IdlmmFactory::createTranslationUnit()
{
    return new TranslationUnit();
}
Include_ptr IdlmmFactory::createInclude()
{
    return new Include();
}
Expression_ptr IdlmmFactory::createExpression()
{
    return new Expression();
}
BinaryExpression_ptr IdlmmFactory::createBinaryExpression()
{
    return new BinaryExpression();
}
UnaryExpression_ptr IdlmmFactory::createUnaryExpression()
{
    return new UnaryExpression();
}
LiteralExpression_ptr IdlmmFactory::createLiteralExpression()
{
    return new LiteralExpression();
}
ConstantDefRef_ptr IdlmmFactory::createConstantDefRef()
{
    return new ConstantDefRef();
}
ValueExpression_ptr IdlmmFactory::createValueExpression()
{
    return new ValueExpression();
}
ForwardDef_ptr IdlmmFactory::createForwardDef()
{
    return new ForwardDef();
}
EnumMember_ptr IdlmmFactory::createEnumMember()
{
    return new EnumMember();
}
Constant_ptr IdlmmFactory::createConstant()
{
    return new Constant();
}
NamedElement_ptr IdlmmFactory::createNamedElement()
{
    return new NamedElement();
}

