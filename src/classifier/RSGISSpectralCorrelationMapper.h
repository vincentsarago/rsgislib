 /*
 *  RSGISSpectralCorrelationMapper.h
 *  RSGIS_LIB
 *
 *  Created by Daniel Clewley on 14/02/2010.
 *  Copyright 2010 RSGISLib. All rights reserved.
 *  This file is part of RSGISLib.
 * 
 *  RSGISLib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RSGISLib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RSGISLib.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RSGISSpectralCorrelationMapper_H
#define RSGISSpectralCorrelationMapper_H

#include <math.h>
#include <gsl/gsl_matrix.h>

#include "img/RSGISCalcImage.h"
#include "img/RSGISCalcImageValue.h"
#include "img/RSGISImageBandException.h"
#include "img/RSGISImageCalcException.h"

namespace rsgis { namespace classifier {
	
    using namespace rsgis::img;
    
	/**
	 This implements the Spectral Correlation mapper approach to calculate the correlation between image specta and a reffernce spectra.
	 As only correlation is importand not negative or positive values, the result is normallised to be between 0 and 1
	 
	 De Carvalho and Meneses. Spectral correlation mapper (SCM): <br>
	 An improvement on the spectral angle mapper (SAM). Airborne Visible/Infrared Imaging Spectrometer (AVIRIS) <br
	 2000 Workshop Proceedings, Pasadena (2000)<br
	 */
	
	
	class RSGISSpectralCorrelationMapperRule : public RSGISCalcImageValue
	{
	public:
		RSGISSpectralCorrelationMapperRule(int numOutBands, gsl_matrix *refSpectra);
		void calcImageValue(float *bandValues, int numBands, float *output) throw(RSGISImageCalcException);
		void calcImageValue(float *bandValues, int numBands) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
		void calcImageValue(float *bandValues, int numBands, Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
		void calcImageValue(float *bandValues, int numBands, float *output, Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
		void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};															
		~RSGISSpectralCorrelationMapperRule();
	private:
		int numOutBands;
		double *imageSpecArray;
		gsl_matrix *refSpectra;
	};
		
	/// Classify rule image produced by SAM
	class RSGISSpectralCorrelationMapperClassifier : public RSGISCalcImageValue
	{
	public:
		RSGISSpectralCorrelationMapperClassifier(int numOutBands, double threashold);
		void calcImageValue(float *bandValues, int numBands, float *output) throw(RSGISImageCalcException);
		void calcImageValue(float *bandValues, int numBands) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
		void calcImageValue(float *bandValues, int numBands, Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
		void calcImageValue(float *bandValues, int numBands, float *output, Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
		void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(RSGISImageCalcException){throw RSGISImageCalcException("Not implemented");};															
		~RSGISSpectralCorrelationMapperClassifier();
	private:
		int numOutBands;
		double threashold;
	};
	
}}

#endif
