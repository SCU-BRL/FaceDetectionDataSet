/*
	Describe and read file information.
	This is a father class.
*/
#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>

// label information per image
class CLabelInfo
{
public: 
	// related path of file
	std::string mRelatedPath;
	// if without face num_object == 0, else > 0
	int mObjectNum = 0;
	// x y w h pitch yaw roll
	std::vector<int> mBboxPoseInfo;
};

class CDataManagement
{

public:
	
	// empty constructor
	CDataManagement(){ ; }

	// overload constructor, initialize folder path
	CDataManagement(std::string _path) :mParserPath(_path){ ; }

	//store the object path and object data map<key, values>
	std::map<std::string, std::vector<std::vector<int>>> mDataInfo;

	//store the face path
	std::vector<std::string> mImgPaths;
	
	// store the object label file path
	std::string mParserPath;

	// open and close parse file
	virtual bool OpenParseFile();
	virtual void CloseParseFile();

	// scan dataset, different dataset have diferent folder format
	virtual void ScanDataSet(std::vector<std::string> &fileLists){ ; }

	// parse label file, return label info
	void ParseLabelFile(std::vector<CLabelInfo> &labelInfos);
	std::vector<int> SplitData(std::string tempData, std::string separator);

	// set parser file path
	bool SetPath(std::string newPath);

	// get parser file path
	std::string GetPath();

private:
	// label info come from parse file
	std::vector<CLabelInfo> mLabelInfos;
	std::ifstream mParserFile;

};