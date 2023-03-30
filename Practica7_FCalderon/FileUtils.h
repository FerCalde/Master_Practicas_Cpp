#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
//#include "Practica7FCalderon.h"
	

namespace FileUtils
{

	

	//void Func:
	void OpenFile(const char* _ccFileName, const char* _ccOpenMode);
	void CloseFile();

	//void ReadFile(); Obsoleta de la P5
	void WriteFile();
	void WriteFile(const char* _FileNameToOpen);
	//

	const char* ReadFile(); //P6
	const char* ReadFile(const char* _FileNameToOpen); //P6

	int AparicionesCadenaEnFile(); //P6
	int TotalSumaDelFile(); //P6


}