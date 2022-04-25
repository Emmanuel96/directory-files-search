// Run this file to execute all the test suites
#include <vector>

#include "test_utils.h"
#include "test_listDirectories.h"
#include "test_searchFiles.h"
#include "test_fileLinearSearch.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "__________________________" << endl;

    // ____________test ListDirectories____________//

    createTestDirs4list(); // create directories structure for testing
    // tests
    test_test_folder();
    test_empty_folder();
    cleanTestDirs(); // clean up


    // _______________test SearchFIles_____________//
    
    writeTestFiles();   // create directories structure for testing
    // tests
    search_test_folder();
    cleanTestDirs();   // clean up

    
    // _______________test fileLinearSearch_____________//
    
    createTestFile();  // create directories structure for testing
    // tests
    test_fileLinearSearch("Lorem", "test fileLinearSearch-word exists :", true);
    test_fileLinearSearch("When", "test fileLinearSearch-word not exists :", false);
    cleanTestDirs(); // clean up
    
    cout << "___________________________" << endl;
}