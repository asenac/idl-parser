// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/SequenceDef.hpp
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

#ifndef IDLMM_SEQUENCEDEF_HPP
#define IDLMM_SEQUENCEDEF_HPP

#include <idlmm_forward.hpp>
#include <idlmm/Typed.hpp>
#include <idlmm/IDLType.hpp>

/*PROTECTED REGION ID(SequenceDef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class SequenceDef: public virtual ::idlmm::Typed,
            public virtual ::idlmm::IDLType
    {
    public:
        SequenceDef();

        virtual ~SequenceDef();

        // Operations
        // Attributes

        // References
        ::idlmm::Expression_ptr getBound();
        void setBound(::idlmm::Expression_ptr _bound);

        /*PROTECTED REGION ID(SequenceDef) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        /*PROTECTED REGION ID(SequenceDefImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes
        // References

        ::idlmm::Expression_ptr m_bound;

    };

} // idlmm

#endif // IDLMM_SEQUENCEDEF_HPP
