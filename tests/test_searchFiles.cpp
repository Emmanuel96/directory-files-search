// Test suite for the searchFiles function
#include <vector>

#include "test_utils.h"
#include "test_searchFiles.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "__________________________" << endl;
    // create directories structure for testing
    writeTestFiles();

    // tests
    search_test_folder();
    
    // clean up
    cleanTestDirs();
    cout << "___________________________" << endl;
}