
#include <string>
#include <iostream>
using namespace std;

vector<int> readFaceData::getdatas(string data)
{
	string sep = " ";
	vector<string> *svec = new vector<string>;
	string::size_type beg = 0, end = 0;
	vector<int> datas;

	beg = data.find_first_not_of(sep, end);
	while (beg != string::npos) {
		end = data.find_first_of(sep, beg);
		if (end == string::npos) {
			svec->push_back(string(data, beg));
			break;
		}
		else {
			svec->push_back(string(data, beg, end - beg));
			beg = data.find_first_not_of(sep, end);
		}
	}

	vector<string>::const_iterator iter;
	int i = 0;

	for (iter = svec->begin(); iter != svec->end(); ++iter, ++i){
		datas.push_back(atoi((*iter).c_str()));
	}
	return datas;
}

void readFaceData::openFaceData()
{
	infile.open(readFaceData::path);
	if (!infile.is_open()){
		std::cout << "can not open facedata file: " << readFaceData::path <<endl;
		getchar();
		return;
	}
	std::cout << "open facedata file: "<< readFaceData::path << " success!!" << endl;
}

void readFaceData::closeFaceData()
{
	infile.close();
}

bool readFaceData::set_path(string newPath)
{
	path = newPath;
	return true;
}

string readFaceData::get_path()
{
	return path;
}

void readFaceData::readFaceDetectionResult()
{
	//map<string, vector<vector<int>>> data;
	//vector<string> imgpaths;

	string imgpath, faces, data;
	int facenum;
	vector<int> datas;
	vector<vector<int>> alldatas;
	while (getline(infile, imgpath))
	{
		getline(infile, faces);
		facenum = 0; facenum = atoi(faces.c_str());
		if (facenum == 0){
			continue;
		}
		readFaceData::imgpaths.push_back(imgpath);
		datas.clear();
		alldatas.clear();
		for (int i = 0; i < facenum; i++){
			getline(infile, data);
			datas = getdatas(data);
			alldatas.push_back(datas);
		}
		readFaceData::data[imgpath] = alldatas;
		
	}
	cout << "having read all face datas!" << endl;
}

void example(string path){
	readFaceData read(path);
	//read.set_path("E:/MultiPIE/data/FaceDetectionRecord.txt");
	read.openFaceData();
	read.readFaceDetectionResult();
	string imgpath;
	vector<vector<int>> datas;
	vector<int> data;
	for (int i = 0; i < read.imgpaths.size(); i++){
		imgpath = read.imgpaths[i];
		datas = read.data[imgpath];
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
