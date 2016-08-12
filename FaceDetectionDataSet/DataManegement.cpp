#include "DataManagement.h"
#include <string>
#include <iostream>

using namespace std;

// splite label info, get bbox and pose info
std::vector<int> CDataManagement::SplitData(std::string data, std::string separator = " ")
{
	std::vector<std::string> *svec = new std::vector<std::string>;
	std::string::size_type beg = 0, end = 0;
	std::vector<int> datas;

	beg = data.find_first_not_of(separator, end);
	while (beg != std::string::npos) {
		end = data.find_first_of(separator, beg);
		if (end == std::string::npos) {
			svec->push_back(std::string(data, beg));
			break;
		}
		else {
			svec->push_back(std::string(data, beg, end - beg));
			beg = data.find_first_not_of(separator, end);
		}
	}

	std::vector<std::string>::const_iterator iter;
	int i = 0;

	for (iter = svec->begin(); iter != svec->end(); ++iter, ++i){
		datas.push_back(atoi((*iter).c_str()));
	}
	return datas;
}

// open parse file
// return file handle
bool CDataManagement::OpenParseFile()
{
	mParserFile.open(mParserPath);
	if (!mParserFile.is_open())
	{
		std::cout << "can not open facedata file: " << CDataManagement::mParserPath << endl;
		getchar();
		return false;
	}
	std::cout << "open facedata file: " << CDataManagement::mParserPath << " success!!" << endl;
	return true;
}

void CDataManagement::CloseParseFile()
{
	mParserFile.close();
}

bool CDataManagement::SetPath(std::string newPath)
{
	mParserPath = newPath;
	return true;
}

std::string CDataManagement::GetPath()
{
	return mParserPath;
}

void CDataManagement::ParseLabelFile(std::vector<CLabelInfo> &labelInfos)
{
	//map<std::string, std::vector<std::vector<int>>> data;
	//std::vector<std::string> imgpaths;

	std::string imgpath, faces, data;
	int faceNum;
	std::vector<int> datas;
	std::vector<std::vector<int>> alldatas;

	while (getline(mParserFile, imgpath))
	{
		CLabelInfo labelInfo;
		
		getline(mParserFile, faces);
		faceNum = atoi(faces.c_str());
		
		for (int i = 0; i < faceNum; i++)
		{
			getline(mParserFile, data);
			datas = SplitData(data);
			labelInfo.mBboxPoseInfo = datas;
		}

		labelInfo.mRelatedPath = imgpath;
		labelInfo.mObjectNum = faceNum;

		labelInfos.push_back(labelInfo);
	}

	cout << "Parsing is complete." << endl;
}
