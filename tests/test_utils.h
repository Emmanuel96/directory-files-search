// Some utility fuctions used for testing
#ifndef test_utils_H
#define test_utils_H

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

// functions prototypes
bool checkEqual(vector<string> vec1, vector<string> vec2);
bool check(vector<string> vec1, vector<string> vec2, int i);
void createTestDirs(vector<string>file_list, int index=0);
void cleanTestDirs();

bool checkEqual(vector<string> vec1, vector<string> vec2){
    if(vec1.size() != vec2.size()){
        return false;
    }

    return check(vec1, vec2, 0);
}


bool check(vector<string> vec1, vector<string> vec2, int i){
    if(i >= vec1.size()) return true;
    if( find(vec2.begin(), vec2.end(), vec1[i]) != vec2.end()){
        return check(vec1, vec2, i+=1);
    }
    return false;
}


void createTestDirs(vector<string>file_list, int index){
    int i= file_list.size();
    fstream f;
    if(index == i) return;
    filesystem::path path = file_list[index];
    if(path.parent_path() != ""){
        filesystem::create_directory(path.parent_path());
    }
    f.open(path, ios::out);
    f.close();
    createTestDirs(file_list, index+=1);
}


void cleanTestDirs(){
    error_code errorCode;
    if (!filesystem::remove_all("test-folder", errorCode)) {
        cout << errorCode.message() << endl;
    }
}

#endif