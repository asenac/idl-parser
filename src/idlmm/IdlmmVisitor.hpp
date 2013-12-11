// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/IdlmmVisitor.hpp
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

#ifndef IDLMM_VISITOR_HPP
#define IDLMM_VISITOR_HPP

#include <idlmm_forward.hpp>

namespace idlmm
{

    class IdlmmVisitor
    {
    public:
        virtual ~IdlmmVisitor() {}

        virtual void visit(AliasDef * e) = 0;
        virtual void visit(ArrayDef * e) = 0;
        virtual void visit(AttributeDef * e) = 0;
        virtual void visit(BinaryExpression * e) = 0;
        virtual void visit(ConstantDef * e) = 0;
        virtual void visit(ConstantDefRef * e) = 0;
        virtual void visit(Constant * e) = 0;
        virtual void visit(Contained * e) = 0;
        virtual void visit(Container * e) = 0;
        virtual void visit(EnumDef * e) = 0;
        virtual void visit(EnumMember * e) = 0;
        virtual void visit(ExceptionDef * e) = 0;
        virtual void visit(Expression * e) = 0;
        virtual void visit(Field * e) = 0;
        virtual void visit(FixedDef * e) = 0;
        virtual void visit(ForwardDef * e) = 0;
        virtual void visit(IDLType * e) = 0;
        virtual void visit(Include * e) = 0;
        virtual void visit(InterfaceDef * e) = 0;
        virtual void visit(LiteralExpression * e) = 0;
        virtual void visit(ModelElement * e) = 0;
        virtual void visit(ModuleDef * e) = 0;
        virtual void visit(NamedElement * e) = 0;
        virtual void visit(OperationDef * e) = 0;
        virtual void visit(ParameterDef * e) = 0;
        virtual void visit(PrimitiveDef * e) = 0;
        virtual void visit(SequenceDef * e) = 0;
        virtual void visit(StringDef * e) = 0;
        virtual void visit(StructDef * e) = 0;
        virtual void visit(TranslationUnit * e) = 0;
        virtual void visit(TypedefDef * e) = 0;
        virtual void visit(Typed * e) = 0;
        virtual void visit(UnaryExpression * e) = 0;
        virtual void visit(UnionDef * e) = 0;
        virtual void visit(UnionField * e) = 0;
        virtual void visit(ValueExpression * e) = 0;
        virtual void visit(WstringDef * e) = 0;
    };

} // idlmm

#endif // IDLMM_VISITOR_HPP
