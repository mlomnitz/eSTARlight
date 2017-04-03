///////////////////////////////////////////////////////////////////////////
//
//    Copyright 2017
//
//    This file is part of estarlight.
//
//    starlight is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    starlight is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with starlight. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////
//
// File and Version Information:
// $Rev:: 263                         $: revision of last commit
// $Author:: mlomnitz                  $: author of last commit
// $Date:: 02/28/2017 #$: date of last commit
//
// Description:
//
// Container for eXEvents
//
//
///////////////////////////////////////////////////////////////////////////


#ifndef eXEVENT_H
#define eXEVENT_H


#include <vector>

#include "starlightconstants.h"
#include "starlightparticle.h"


class eXEvent 
{
   public:

      eXEvent();
      eXEvent(starlightConstants::event &ev);
      ~eXEvent();

      void addParticle(starlightParticle &part) { _particles.push_back(part); }
      void addVertex(vector3 &vertex) { _vertices.push_back(vertex); }
      void addGamma(float egamma) { _gammaEnergies.push_back(egamma); }
      void addSourceElectron(lorentzVector &el, float gammaMass){ _sources.push_back(el); _gammaMasses.push_back(gammaMass); }

      const std::vector<starlightParticle> * getParticles() const { return &_particles; }
      const std::vector<vector3> * getVertices() const { return &_vertices; }
      const std::vector<float> * getGammaEnergies() const { return &_gammaEnergies; }
      const std::vector<lorentzVector> * getSources() const { return &_sources;}
      const std::vector<float> * getPhotonMasses() const {return &_gammaMasses; }

      eXEvent & operator=(const eXEvent&);
      eXEvent & operator+(const eXEvent&);
      
      void boost(double rapidity);
   private:
      
      std::vector<starlightParticle> _particles;
      std::vector<vector3> _vertices;
      std::vector<lorentzVector> _sources;
      std::vector<float> _gammaMasses;
      std::vector<float> _gammaEnergies;
};


#endif  // UPCEVENT_H
