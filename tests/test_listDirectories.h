// Test suite for the ListDirectory function
#ifndef test_ListDirectory_H
#define test_ListDirectory_H

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

#include "../main.h"
#include "./test_utils.h"

using namespace std;

// test directory structure;
vector<string> listD_testFiles = {"./test-folder/file1.txt", "./test-folder/file2.json", "./test-folder/file3.exe", "./test-folder/file4.html",\
    "./test-folder/test-subfolder/file5.txt", "./test-folder/test-subfolder/file6.env", "./test-folder/test-subfolder/file7.md", "./test-folder/empty-folder",\
    "./test-folder/test-subfolder/level2/file10.sh", "./test-folder/test-subfolder/level2/file11.txt", "./test-folder/test-subfolder/level2/file12.css"};


// functions prototypes
bool test_test_folder();
bool test_empty_folder();
void createTestDirs4list(vector<string> file_list=listD_testFiles);


bool test_test_folder(){
    string test_name = "test listDirectories on test-folder: ";
    string dirPath = "./test-folder";
    vector<string> fileList;
    fileList = listDirectories(dirPath, fileList);

    string result;
    bool pass;
    if(checkEqual(fileList, listD_testFiles) && checkEqual(listD_testFiles, fileList)){
        pass = true;
        result = "passed";
    }else{
        pass = false;
        result = "failed";
    };

    cout << test_name + result << endl;
    return pass;
}


bool test_empty_folder(){
    string test_name = "test listDirectories on empty-folder: ";
    listD_testFiles = {};
    string dirPath = "./test-folder/empty-folder";

    vector<string> fileList;
    fileList = listDirectories(dirPath, fileList);

    string result;
    bool pass;
    if(checkEqual(fileList, listD_testFiles) && checkEqual(listD_testFiles, fileList)){
        pass = true;
        result = "passed";
    }else{
        pass = false;
        result = "failed";
    };

    cout << test_name + result << endl;
    return pass;
}

void createTestDirs4list(vector<string> file_list){
    createTestDirs(file_list);
}

#endif