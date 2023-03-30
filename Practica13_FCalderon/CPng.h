#pragma once
#include "CImage.h"
class CPng : public CImage
{
	float m_fAlpha;


	
public :
	void MakeTransparent();
	void SetImgType();
	CPng();
	~CPng() override;
};
