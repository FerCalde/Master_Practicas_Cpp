#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>



FILE* ptrFile;
errno_t err;

const char* fileNameDefault = { "FileToSum.txt" };
const char* fileNameCadenaAparicion = { "FileToRead.txt" };
const char* fileNameSumaIntsCadena = { "FileToSum.txt" };

//char* bufferRead;
const char* cadenaToIdentify = { "Hola Hola" };



//void Func:
void OpenFile(const char* _ccFileName, const char* _ccOpenMode);
void CloseFile();

//void AparicionesCadenaEnFile();
int AparicionesCadenaEnFile();
int TotalSumaDelFile();
//void ReadFile();
const char* ReadFile();
const char* ReadFile(const char* _FileNameToOpen);
//const char* ReadFile(char*& _ptrOutBuffer_);
void WriteFile();

//void IdentificarCadena();
//