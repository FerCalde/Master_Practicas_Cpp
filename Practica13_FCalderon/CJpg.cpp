#include "CJpg.h"

CJpg::CJpg()
{
	cImgType = { "JPG" };
}
CJpg::~CJpg()
{
	std::cout << "Destructor del JPG\n";
}
void CJpg::NoAlphaHere()
{
	std::cout << "No tengo alpha! soy Un JPEEEEEEEG\n";
}