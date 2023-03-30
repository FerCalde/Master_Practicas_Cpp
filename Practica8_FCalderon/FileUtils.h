#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>



class CFile
{
	errno_t err;

public:

	FILE* ptrFile;

	const char* fileName = { "FileToRead.txt" };

	//void Func:
	void OpenFile(const char* _ccFileName, const char* _ccOpenMode);
	void CloseFile();


	void ReadFile();
	void WriteFile();
	//
};


//namespace FileSpace
//{
//	class CFile
//	{
//		errno_t err;
//
//	public:
//
//		FILE* ptrFile;
//
//		const char* fileName = { "FileToRead.txt" };
//
//		//void Func:
//		void OpenFile(const char* _ccFileName, const char* _ccOpenMode);
//		void CloseFile();
//
//
//		void ReadFile();
//		void WriteFile();
//		//
//	};
//
//}

////////namespace FileUtils
////////{
////////
////////	//void Func:
////////	void OpenFile(const char* _ccFileName, const char* _ccOpenMode);
////////	void CloseFile();
////////
////////
////////	void ReadFile();
////////	void WriteFile();
////////	//
////////
////////}