#pragma once
#include "CImage.h"

class CJpg : public CImage
{
public:
	void NoAlphaHere();
	CJpg();
	~CJpg() override;
};