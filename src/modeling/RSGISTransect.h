/*
 *  RSGISTransect.h
 *  RSGIS_LIB
 *
 *  Created by Daniel Clewley on 28/10/2009.
 *  Copyright 2009 RSGISLib. All rights reserved.
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

#ifndef RSGISTransect_H
#define RSGISTransect_H

#include <vector>
#include "modeling/RSGISModelingException.h"
#include "math/RSGISMatrices.h"
#include "utils/RSGISExportForPlotting.h"

namespace rsgis{namespace modeling {
    
    using namespace std;
    using namespace rsgis::math;
    using namespace rsgis::utils;
    
	/** Class to store transect data
	 * Data is stored as char.
	 */
	class RSGISTransect
	{
	public:
		RSGISTransect(unsigned int transectLenght, unsigned int transectWidth, unsigned int transectHeight, double transectRes);
		/// Set all values to zero
		void setZero();
		/// Set all values to newVal
		void setVal(char newVal);
		/// Get transect width (x)
		unsigned int getWidth();
		/// Get transect lenght (y)
		unsigned int getLenth();
		/// Get transect height (z)
		unsigned int getHeight();
		/// Get transect resolution
		double getRes();
		/// Get transect value at point (x, y, z)
		char getValue(unsigned int xCord, unsigned int yCord, unsigned int zCord);
		/// Get set point (x, y, z) to transectVal
		void setValue(unsigned int xCord, unsigned int yCord, unsigned int zCord, char transectVal);
		/// Count the number of points in the transect
		unsigned int countPoints();
		/// Export transect as an image
		void exportImage(string outFileName);
		/// Export the transect in ptxt format
		void exportPlot(string outFileName, unsigned int numPts);
		/// Export in SPD format
		void exportSPD(string outFileName);
		~RSGISTransect();
	protected:
		unsigned int transectLenght;
		unsigned int transectWidth;
		unsigned int transectHeight;
		double transectRes;
		char ***transectData;
	};
}}

#endif


