#include <string>
#include <vector>
#include <map>
#include <fstream>

//! Read a data file line by line and allows access to field entries by name.
/*! The file is expected to be in the format: 
 *
 * line 1: title1(delimiter characters)title2(delimiter characters)...(delimiter characters)titleM
 *
 * line 2: field1(delimiter characters)field2(delimiter characters)...(delimiter characters)fieldM
 *
 * ...
 *
 * line N: field1(delimiter characters)field2(delimiter characters)...(delimiter characters)fieldM
 * 
 * On any line, sequences formed from members of (delimiter
 * characters) delimit the fields. this covers two important cases
 * where (delimiter character) has only 1 character (as in a csv
 * file), or by white spaces (white space separated files). */
namespace custom_cpp_utilities {

class CsvReader {

  public:

    //! Default constructor has no behavior. 
    CsvReader();
    
    //! Construct with file name and assume whitespace delimited.
    CsvReader(const char *fname);

    //! Construct with file name with specified delimiter character.
    CsvReader(const char *fname, const char *delimiter);

    ~CsvReader();

    //! Read in the next line in the file. Return 1 if succeeded, 0 otherwise. 
    int next();

    //! Access the value of a field in the current line by name.
    std::string get(const char*);

  private:

    // file stream
    std::fstream file;

    // delimiter character set
    std::string delim;

    // fields stores the value entries of the current line
    std::vector<std::string> fields;

    // map between field names and their indices in the fields vector
    std::map<std::string, std::vector<std::string>::size_type> field_name_index;

    void Initialize(const char*, const std::string &);
};

}
