/*
	Multi-Pie Face DataSet. There are four session data which include differnet yaw pose, illumination and expression.

*/
#pragma once
#include "DataManagement.h"

class CMultiPie : CDataManagement
{
public:
	// empty constructor
	CMultiPie(){ ; }

	void ScanDataSet(std::vector<std::string> &fileLists);

private:

};