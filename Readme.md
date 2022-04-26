## Input
    word (to search for)
    directory path
## Output
    list of files which are descendents of the directory path inputted which contain the word in question.
    The files in the result set are printed to stdout each on a separate line.

## Build:
    g++ main.cpp -o main -std=c++17

## Run: 
    ./main <word> <directory_path>

    
## Testing
### Run all tests
    cd tests
    g++ ./test_all.cpp -o run_test -std=c++17

### Run individual function test suites
    cd tests 
    g++ ./test_listDirectories.cpp -o test -std=c++17
    g++ ./test_searchFiles.cpp -o test -std=c++17
    g++ ./test_fileLinearSearch.cpp -o test -std=c++17