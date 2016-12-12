/*
 * Copyright (c) 2010-2016 Stephane Poirier
 *
 * stephane.poirier@oifii.org
 *
 * Stephane Poirier
 * 3532 rue Ste-Famille, #3
 * Montreal, QC, H2X 2L1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// spispeartextpartialsreader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "speartextpartialsreader.h"

#include <iostream>

#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string filename("VC-8_mV_sus-sh_mf_B3(partials).txt");
	SpearTextPartialsReader mySpearTextPartialsReader(filename.c_str());

	//B3 is 246.9 Hz
	for(vector<float>::iterator it=mySpearTextPartialsReader.partialfrequencies.begin(), end=mySpearTextPartialsReader.partialfrequencies.end(); it!=end; ++it)
	{
		(*it) = (*it)/246.9;
		//std::cout << (*it) << "\n";  
	}

	for(int i=0; i<mySpearTextPartialsReader.partialfrequencies.size(); i++)
	{
		std::cout << i << ", " << mySpearTextPartialsReader.partialfrequencies[i] << ", " << mySpearTextPartialsReader.partialamplitudes[i]<< "\n";  
	}
	return 0;
}

