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
class LabelInfo
{
public: 
	// related path of file
	std::string related_path;
	// if without face num_object == 0, else > 0
	int num_object;
	// x y w h pitch yaw roll
	std::vector<int> bbox_pose_info;

};

class DataManagement
{

public:
	
	// empty constructor
	DataManagement(){ ; }

	// overload constructor, initialize folder path
	DataManagement(std::string _path) :path(_path){ ; }

	//store the object path and object data map<key, values>
	std::map<std::string, std::vector<std::vector<int>>> dataInfo;

	//store the face path
	std::vector<std::string> imgPaths;

	void readFaceDetectionResult();

	// open and close file
	bool OpenFile();
	void CloseFile();

	// 
	bool set_path(std::string newPath);

	std::string get_path();

private:

	std::ifstream infile;
	std::string path;
	std::vector<int> getdatas(std::string data);

};