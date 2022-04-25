// Test suite for the ListDirectory function
#include <vector>

#include "test_utils.h"
#include "test_listDirectories.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "__________________________" << endl;
    // create directories structure for testing
    createTestDirs4list();

    // tests
    test_test_folder();
    test_empty_folder();

    // clean up
    cleanTestDirs();
    cout << "___________________________" << endl;
}