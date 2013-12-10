// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/ParameterDef.hpp
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

#ifndef IDLMM_PARAMETERDEF_HPP
#define IDLMM_PARAMETERDEF_HPP

#include <idlmm_forward.hpp>

#include <idlmm/Typed.hpp>

/*PROTECTED REGION ID(ParameterDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class ParameterDef: public virtual ::idlmm::Typed
    {
    public:
        ParameterDef();

        virtual ~ParameterDef();

        // Operations
        // Attributes
        std::string const& getIdentifier() const;
        void setIdentifier(std::string const& _identifier);

        ::idlmm::ParameterMode getDirection() const;
        void setDirection(::idlmm::ParameterMode _direction);

        // References
        /*PROTECTED REGION ID(ParameterDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(ParameterDefImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        std::string m_identifier;

        ::idlmm::ParameterMode m_direction;

        // References

    };

} // idlmm

#endif // IDLMM_PARAMETERDEF_HPP
