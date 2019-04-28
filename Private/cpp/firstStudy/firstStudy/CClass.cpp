#include "CClass.h"



CClass::CClass() : nExample(32), pData(new int)
{
}


CClass::~CClass()
{
	delete pData;
}
