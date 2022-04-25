// Test suite for the fileLinearSearch function
#ifndef test_fileLinearSearch_H
#define test_fileLinearSearch_H

#include "../main.h"
#include "./test_utils.h"

using namespace std;

// test file;
vector<string> lSearch_testFile = {"./test-folder/file1.txt"};

void createTestFile(vector<string> file_list=lSearch_testFile);
bool test_fileLinearSearch(string targetWord, string test_desc, bool expected_result);


bool test_fileLinearSearch(string targetWord, string test_desc, bool expected_result){
    string result;
    bool pass;
    string fileName = "./test-folder/file1.txt";

    fstream file;
    file.open(fileName, ios::in);
    if(!file){
        cout << ("failed to open file %s", fileName) << endl;
        cout << test_desc + "failed" << endl;
        return false;
    }

    string fileContent;
    if(FileLinearSearch(file, fileContent, targetWord ) == expected_result){
        pass = true;
        result = "passed";
    }else{
        pass = false;
        result = "failed";
    };

    cout << test_desc + result << endl;
    return pass;
}


// function to create a dummy files and populate it for testing
void createTestFile(vector<string> file_list){
    string dummy = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    createTestDirs(file_list); 

    fstream f;
    f.open("./test-folder/file1.txt", ios::out);
    f << dummy;
    f.close();
}
#endif