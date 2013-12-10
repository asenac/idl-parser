// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/FixedDef.hpp
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

#ifndef IDLMM_FIXEDDEF_HPP
#define IDLMM_FIXEDDEF_HPP

#include <idlmm_forward.hpp>


#include <idlmm/IDLType.hpp>

/*PROTECTED REGION ID(FixedDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class FixedDef: public virtual ::idlmm::IDLType
    {
    public:
        FixedDef();

        virtual ~FixedDef();



        // Operations


        // Attributes

        // References
        ::idlmm::Expression_ptr getDigits();
        void setDigits(::idlmm::Expression_ptr _digits);

        ::idlmm::Expression_ptr getScale();
        void setScale(::idlmm::Expression_ptr _scale);

        /*PROTECTED REGION ID(FixedDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl








        /*PROTECTED REGION ID(FixedDefImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes


        // References

        ::idlmm::Expression_ptr m_digits;

        ::idlmm::Expression_ptr m_scale;

    };

} // idlmm

#endif // IDLMM_FIXEDDEF_HPP
