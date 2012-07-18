/*
 *  RSGISFilterBank.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 16/12/2008.
 *  Copyright 2008 RSGISLib.
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

#ifndef RSGISFilterBank_H
#define RSGISFilterBank_H

#include <iostream>
#include <string>
#include <vector>

#include "gdal_priv.h"

#include "filtering/RSGISImageFilterException.h"
#include "filtering/RSGISImageFilter.h"
#include "filtering/RSGISCalcImageFilters.h"
#include "filtering/RSGISGenerateFilter.h"
#include "filtering/RSGISImageKernelFilter.h"

#include "common/RSGISImageException.h"

namespace rsgis{namespace filter{
	
	class RSGISFilterBank
		{
		public: 
			RSGISFilterBank();
			void addFilter(RSGISImageFilter *filter);
			RSGISImageFilter* getFilter(int i);
			int getNumFilters();
			void executeFilters(GDALDataset **datasets, int numDS, string outImageBase) throw(rsgis::RSGISImageException);
			void exectuteFilter(int i, GDALDataset **datasets, int numDS, string outImageBase) throw(rsgis::RSGISImageException);
			void exportFilterBankImages(string imagebase);
			void createLeungMalikFilterBank() throw(rsgis::RSGISImageException);
			~RSGISFilterBank();
		protected:
            std::vector<RSGISImageFilter*> *filters;
		};
	
	
}}

#endif


