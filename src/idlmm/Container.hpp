// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/Container.hpp
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

#ifndef IDLMM_CONTAINER_HPP
#define IDLMM_CONTAINER_HPP

#include <idlmm_forward.hpp>



#include <idlmm/Contained.hpp>

/*PROTECTED REGION ID(Container_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace idlmm
{

    class Container: public virtual ::idlmm::Contained
    {
    public:
        Container();

        virtual ~Container();

        

        // Operations


        // Attributes

        // References
        boost::ptr_vector< ::idlmm::Contained >& getContains();

        /*PROTECTED REGION ID(Container) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl

                

                
        
        
        

        /*PROTECTED REGION ID(ContainerImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes


        // References

        boost::ptr_vector<
                ::idlmm::Contained > m_contains;

    };

} // idlmm

#endif // IDLMM_CONTAINER_HPP
