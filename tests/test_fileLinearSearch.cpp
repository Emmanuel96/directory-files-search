// Test suite for the searchFiles function
#include <vector>

#include "test_utils.h"
#include "test_fileLinearSearch.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "__________________________" << endl;
    // create directories structure for testing
    createTestFile();

    // tests
    test_fileLinearSearch("Lorem", "test fileLinearSearch-word exists :", true);
    test_fileLinearSearch("When", "test fileLinearSearch-word not exist :", false);
    
    // clean up
    cleanTestDirs();
    cout << "___________________________" << endl;
}