#include "DataManagement.h"
#include <string>
#include <iostream>

using namespace std;

std::vector<int> DataManagement::getdatas(std::string data)
{
	std::string sep = " ";
	std::vector<std::string> *svec = new std::vector<std::string>;
	std::string::size_type beg = 0, end = 0;
	std::vector<int> datas;

	beg = data.find_first_not_of(sep, end);
	while (beg != std::string::npos) {
		end = data.find_first_of(sep, beg);
		if (end == std::string::npos) {
			svec->push_back(std::string(data, beg));
			break;
		}
		else {
			svec->push_back(std::string(data, beg, end - beg));
			beg = data.find_first_not_of(sep, end);
		}
	}

	std::vector<std::string>::const_iterator iter;
	int i = 0;

	for (iter = svec->begin(); iter != svec->end(); ++iter, ++i){
		datas.push_back(atoi((*iter).c_str()));
	}
	return datas;
}


bool DataManagement::OpenFile()
{
	infile.open(DataManagement::path);
	if (!infile.is_open())
	{
		std::cout << "can not open facedata file: " << DataManagement::path << endl;
		getchar();
		return false;
	}
	std::cout << "open facedata file: " << DataManagement::path << " success!!" << endl;
	return true;
}

void DataManagement::CloseFile()
{
	infile.close();
}

bool DataManagement::set_path(std::string newPath)
{
	path = newPath;
	return true;
}

std::string DataManagement::get_path()
{
	return path;
}

void DataManagement::readFaceDetectionResult()
{
	//map<std::string, std::vector<std::vector<int>>> data;
	//std::vector<std::string> imgpaths;

	std::string imgpath, faces, data;
	int facenum;
	std::vector<int> datas;
	std::vector<std::vector<int>> alldatas;
	while (getline(infile, imgpath))
	{
		getline(infile, faces);
		facenum = 0; facenum = atoi(faces.c_str());
		if (facenum == 0){
			continue;
		}
		imgPaths.push_back(imgpath);
		datas.clear();
		alldatas.clear();
		for (int i = 0; i < facenum; i++){
			getline(infile, data);
			datas = getdatas(data);
			alldatas.push_back(datas);
		}
		dataInfo[imgpath] = alldatas;

	}
	cout << "having read all face datas!" << endl;
}


