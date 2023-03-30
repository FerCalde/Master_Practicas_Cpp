
#include "CImage.h"

CImage::CImage()
{
	cImgType = { "Image" };
	m_iResolutionX = 0;
	m_iResolutionY = 0;
	m_iColorDepth = 0;
}


CImage::CImage(const char* type)
	: cImgType(type)
{
	
	m_iResolutionX = 0;
	m_iResolutionY = 0;
	m_iColorDepth = 0;
}


CImage::CImage(const char* type, int _ResX, int _ResY, int _ColorDepth)
	: cImgType(type),
	m_iResolutionX(_ResX),
	m_iResolutionY(_ResY),
	m_iColorDepth(_ColorDepth)
{

}
CImage::~CImage()
{
	std::cout << "Destructor de ImgBase\n";

}

int CImage::DrawRGBImage(unsigned char* ptrBuffer)
{
	std::cout << "Que bonita la fotico"<<ptrBuffer<<"\n";
	return 0;
}
int CImage::ScaleImage(int _f_ScaleUniform)
{
	m_iResolutionX *= _f_ScaleUniform;
	m_iResolutionY *= _f_ScaleUniform;
	std::cout << "Nueva escala " << m_iResolutionX << ", " << m_iResolutionY << " Esto no tiene más zoom?? (Ampliando la foto)\n";
	return 0;
}
int CImage::GetScale()
{
	std::cout << "Current escala de Resolucion " << m_iResolutionX << ", " << m_iResolutionY << "\n";
	return 0;
}
int CImage::RotateImage(float _f_Degrees)
{
	std::cout << "Rotando la Imagen "<<_f_Degrees<<"!\n";
	return 0;
}