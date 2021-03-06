// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/UnaryExpression.hpp
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

#ifndef IDLMM_UNARYEXPRESSION_HPP
#define IDLMM_UNARYEXPRESSION_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Expression.hpp>

/*PROTECTED REGION ID(UnaryExpression_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class UnaryExpression: public virtual ::idlmm::Expression
    {
    public:
        UnaryExpression();

        virtual ~UnaryExpression();

        // Operations
        // Attributes
        std::string const& getOperator() const;
        void setOperator(std::string const& _operator);

        // References
        ::idlmm::Expression_ptr getExpression();
        void setExpression(::idlmm::Expression_ptr _expression);

        /*PROTECTED REGION ID(UnaryExpression) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(UnaryExpressionImpl) ENABLED START*/

        virtual void accept(IdlmmVisitor& visitor);

        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_operator;

        // References

        ::idlmm::Expression_ptr m_expression;

    };

} // idlmm

#endif // IDLMM_UNARYEXPRESSION_HPP
