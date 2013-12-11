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

        virtual void visit(AliasDef * e) {}
        virtual void visit(ArrayDef * e) {}
        virtual void visit(AttributeDef * e) {}
        virtual void visit(BinaryExpression * e) {}
        virtual void visit(ConstantDef * e) {}
        virtual void visit(ConstantDefRef * e) {}
        virtual void visit(Constant * e) {}
        virtual void visit(Contained * e) {}
        virtual void visit(Container * e) {}
        virtual void visit(EnumDef * e) {}
        virtual void visit(EnumMember * e) {}
        virtual void visit(ExceptionDef * e) {}
        virtual void visit(Expression * e) {}
        virtual void visit(Field * e) {}
        virtual void visit(FixedDef * e) {}
        virtual void visit(ForwardDef * e) {}
        virtual void visit(IDLType * e) {}
        virtual void visit(Include * e) {}
        virtual void visit(InterfaceDef * e) {}
        virtual void visit(LiteralExpression * e) {}
        virtual void visit(ModelElement * e) {}
        virtual void visit(ModuleDef * e) {}
        virtual void visit(NamedElement * e) {}
        virtual void visit(OperationDef * e) {}
        virtual void visit(ParameterDef * e) {}
        virtual void visit(PrimitiveDef * e) {}
        virtual void visit(SequenceDef * e) {}
        virtual void visit(StringDef * e) {}
        virtual void visit(StructDef * e) {}
        virtual void visit(TranslationUnit * e) {}
        virtual void visit(TypedefDef * e) {}
        virtual void visit(Typed * e) {}
        virtual void visit(UnaryExpression * e) {}
        virtual void visit(UnionDef * e) {}
        virtual void visit(UnionField * e) {}
        virtual void visit(ValueExpression * e) {}
        virtual void visit(WstringDef * e) {}
    };

} // idlmm

#endif // IDLMM_VISITOR_HPP
