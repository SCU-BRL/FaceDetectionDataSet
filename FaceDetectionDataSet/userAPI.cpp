#include <iostream>
#include "DataManagement.h"

using namespace std;

void example(std::string path)
{
	DataManagement read(path);
	//read.set_path("E:/MultiPIE/data/FaceDetectionRecord.txt");
	read.openFaceData();
	read.readFaceDetectionResult();
	std::string imgpath;
	std::vector<std::vector<int>> datas;
	std::vector<int> data;
	for (int i = 0; i < read.imgPaths.size(); i++){
		imgpath = read.imgPaths[i];
		datas = read.dataInfo[imgpath];
		std::cout << imgpath << endl << datas.size() << endl;
		for (int j = 0; j < datas.size(); j++){
			data = datas[j];
			for (int k = 0; k < data.size(); k++){
				std::cout << data[k] << "\t";
			}
			std::cout << endl;
		}
	}
	read.closeFaceData();
}

int main()
{
	example("E:/MultiPIE/data/FaceDetectionRecord.txt");
	getchar();
	return 1;
}