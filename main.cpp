#include <iostream>
#include <dirent.h> //for opendir
#include <cstring>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

string checkPathString( string strPath);
vector<string> listDirectories(string dirPath, vector<string> fileList);
vector<string> searchFiles( vector<string> fileList, string targetWord, vector<string> filesContaining, int index=0);
bool FileLinearSearch(fstream& file, string fileContent, string targetWord);
void printVector(vector<string> vec, int index=0);

string validFileTypes[] = {".txt", ".json", ".html", ".docx", ".go", ".cpp"};

int main(int argc, char *argv[]){
    if(argc != 3){
        // Error handling for wrong amout of args
        // Direction on how to use
        printf("Usage: main.exe <word> <dirctory_path>\n");
        return -1;
    }
    // fetch the arguments from input
    string targetWord = argv[1];
    string dirPath = argv[2];

    vector<string> fileList; //Container to store list of all the files in the folder and it's subfolders (all descendant files)
    fileList = listDirectories(dirPath,fileList);

    vector<string> filesContaining;  //Container to store the list of files that contain the target word.
    filesContaining = searchFiles(fileList, targetWord, filesContaining);
    if(!(filesContaining.size() == 0)){
        cout << "____________________" << endl;
        cout << ("Target word '"+targetWord+"' found in: ") << endl;
        printVector(filesContaining);
        cout << "____________________" << endl;
    }else{
        cout << "____________________" << endl;
        cout << "Word not found." << endl;
        cout << "____________________" << endl;
    }
}

string checkPathString( string strPath){
    if(strPath[strPath.length()-1] == '/'){
        strPath = strPath.substr(0, strPath.length()-1);
    }
    return strPath;
}


vector<string> listDirectories(string dirPath, vector<string> fileList){
    struct dirent *dir;
    DIR *dp = opendir(dirPath.c_str());
    if(dp){
        while((dir=readdir(dp)) != NULL){
            string strPath = "";
            if(strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name, "..") == 0) continue;
            if(dir->d_type == DT_DIR){
                dirPath = checkPathString(dirPath);
                strPath = dirPath + "/" +dir->d_name;
                fileList = listDirectories(strPath, fileList);
            }else{
                dirPath = checkPathString(dirPath);
                strPath = dirPath + "/" +dir->d_name;
                fileList.push_back(strPath);
            }
        }
        closedir(dp);
    }
    return fileList;
}

// Iterate through file list and search through files using the Linear text search function bellow
vector<string> searchFiles(vector<string> fileList, string targetWord, vector<string> filesContaining, int index){
    if(index == fileList.size()){
        return filesContaining;
    } 
    filesystem::path fileName = fileList[index];
    // cout << fileName.string() << endl;
    
    if(find(begin(validFileTypes), end(validFileTypes), fileName.extension())){ //check if the file type is in the valid file type list
        fstream file;
        file.open(fileName, ios::in);
        if(!file){
            cout << ("failed to open file %s\n", fileName) << endl;
            filesContaining = searchFiles(fileList, targetWord, filesContaining, index+=1);
        }
        string fileContent;
        // search
        bool wordFound = FileLinearSearch(file, fileContent, targetWord);
        if(wordFound){
            // cout << fileName.string() << endl;
            filesContaining.push_back(fileName.string());
        }
    }
    filesContaining = searchFiles(fileList, targetWord, filesContaining, index+=1);
    return filesContaining;
}

// Linear search a file for a target word
bool FileLinearSearch(fstream& file, string fileContent, string targetWord){
    if(file.eof()){
        return false;
    }
    file >> fileContent;
    if(fileContent.compare(targetWord) == 0){
        return true;
    }else{
        return FileLinearSearch(file, fileContent, targetWord);
    }
}

// function to print out the result set each on a seperate line
void printVector(vector<string> vec, int index){
    if(index == vec.size()) return;
    cout << vec[index] << endl;
    printVector(vec, index+=1);
}
