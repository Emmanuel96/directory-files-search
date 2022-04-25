#include <iostream>
#include <dirent.h>
#include <cstring>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include "main.h"

using namespace std;


int main(int argc, char *argv[]){
    // Error handling for wrong amount of args
    if(argc != 3){
        // Direction on how to use
        printf("Usage: main.exe <word> <dirctory_path>\n");
        return -1;
    }
    // fetch the arguments from command input
    string targetWord = argv[1];
    string dirPath = argv[2];

    //Container to store list of all the files in the folder and it's subfolders (all descendant files)
    vector<string> fileList; 
    /*pass the container and the and the entered directory path to the listDirectories function 
      which populates it with the list of all files and returns it. */
    fileList = listDirectories(dirPath,fileList);

    //Container to store the list of files that contain the target word.
    vector<string> filesContaining; 
    /*pass the container to the searchFiles function alongside the fileList and the targetWord, which searches through
      the fileList and populates with the names of those in which the target word is found.*/ 
    filesContaining = searchFiles(fileList, targetWord, filesContaining);

    printResult(filesContaining, targetWord);
}