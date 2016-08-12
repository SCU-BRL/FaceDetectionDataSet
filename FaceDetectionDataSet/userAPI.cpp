#include <iostream>
#include <string>
#include "DataManagement.h"

using namespace std;

void example(std::vector<CLabelInfo> &labelInfos, std::string path)
{
	CDataManagement dataManage(path);
	dataManage.OpenParseFile();
	dataManage.ParseLabelFile(labelInfos);
	dataManage.CloseParseFile();
}

int main()
{
	std::vector<CLabelInfo> labelInfos;
	example(labelInfos,"D:/FaceDatabase/Multi-Pie/Multi-pie_FaceLabel/Multi-PieProfileBbox.txt");
	for (int i = 0; i < labelInfos.size(); i++)
	{
		std::string imgpath = labelInfos[i].mRelatedPath;
		int faceNum = labelInfos[i].mObjectNum;
		std::vector<int> datas = labelInfos[i].mBboxPoseInfo;

		std::cout << imgpath << endl << datas.size() << endl;
		for (int k = 0; k < faceNum; k++)
		{
			for (int j = 0; j < datas.size(); j++)
			{
				std::cout << datas[j] << "\t";
			}
			std::cout << endl;
		}
	}
	getchar();
	return 1;
}