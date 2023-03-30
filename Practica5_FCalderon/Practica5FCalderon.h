#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//int Func:
int OpenFile(const char* _ccFileName, const char* _ccOpenMode);
int CloseFile();

//void Func:
void OpenFileVoid(const char* _ccFileName, const char* _ccOpenMode);
void CloseFileVoid();
void ReadFileVoid();

void WriteFileVoid();
//