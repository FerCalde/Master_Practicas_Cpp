#pragma once
#include <iostream>

class CImage
{
//private: //Clase ya es private
private:
	int m_iResolutionX;
	int m_iResolutionY;
	int m_iColorDepth;
protected:
public:

	const char* cImgType = { "Image" };


	CImage();
	CImage(const char* type);
	CImage(const char* type, int _ResX, int _ResY, int _ColorDepth);
	virtual ~CImage();
	
	int DrawRGBImage(unsigned char* ptrBuffer);
	int ScaleImage(int _i_ScaleUniform);
	int RotateImage(float _f_Degrees);

	int GetScale();

};


