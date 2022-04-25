// Test suite for the searchFiles function
#ifndef test_searchFiles_H
#define test_searchFiles_H

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

#include "../main.h"
#include "./test_utils.h"

using namespace std;

// test directory structure;
vector<string> searchF_testFiles = {"./test-folder/file1.txt","./test-folder/test-subfolder/file6.env","./test-folder/test-subfolder/level2/file10.json"};

bool search_test_folder();
void writeTestFiles(vector<string> file_list=searchF_testFiles);


bool search_test_folder(){
    string test_name = "test searchFiles on test-folder: ";
    vector<string> fileList = {"./test-folder/file1.txt","./test-folder/test-subfolder/level2/file10.json"};
    
    vector<string> filesContaining;
    filesContaining = searchFiles(searchF_testFiles, "Lorem", filesContaining);

    string result;
    bool pass;
    if(checkEqual(fileList, filesContaining) && checkEqual(filesContaining, fileList)){
        pass = true;
        result = "passed";
    }else{
        pass = false;
        result = "failed";
    };

    cout << test_name + result << endl;
    return pass;
}

// function to create dummy files and populate them for testing
void writeTestFiles(vector<string> file_list){
    string dummy1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    string dummy2 = "Lorem Sed ut perspiciatis unde amet omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam.";

    createTestDirs(file_list); 

    fstream f;
    f.open("./test-folder/file1.txt", ios::out);
    f << dummy1;
    f.close();

    f.open("./test-folder/test-subfolder/level2/file10.json", ios::out);
    f << dummy2;
    f.close();
}
#endif