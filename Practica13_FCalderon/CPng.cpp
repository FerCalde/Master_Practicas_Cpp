#include "CPng.h"



CPng::CPng()
{
	cImgType = { "Png" };
	//SetImgType();
	m_fAlpha = 1;

}

CPng::~CPng()
{
	std::cout << "Destructor del Png\n";

}

void CPng::SetImgType()
{
	cImgType = { "Png" };
}

void CPng::MakeTransparent()
{
	m_fAlpha = 0;
	std::cout << "He borrao el alpha del PNG = " << m_fAlpha<<"\n";
}