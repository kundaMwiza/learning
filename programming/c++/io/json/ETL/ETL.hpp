#ifndef ETL
#define ETL

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <tuple>

#include "boost/tokenizer.hpp"
#include "DataHolder.hpp"

class SmartETL
{

public:
    // begin type aliases ---
    using question_map = std::map<unsigned int, std::vector<std::string>>;
    using category_map = std::map<unsigned int, std::string>;
    using resource_map = std::map<unsigned int, std::vector<std::string>>;
    using tokenizer_type = boost::tokenizer<boost::char_separator<char>, std::string::const_iterator, std::string>;
    using delimiter_type = boost::char_separator<char>;
    // end type aliases ---

    // begin constructors ---
    SmartETL(
        const char *filename,
        const char *delimiter = " :,./|\\-0123456789*!?@£$%^&()[]{}~+_'\"=",
        bool stem_words = true)
        : filename(filename),
          delimiter(delimiter)
    {
    }

    // end constructors ---

    // begin member functions ---
    DataHolder<question_map, category_map, resource_map> load_dataset();

    // end member functions ---

    // begin data members ---
    const char *filename;
    const char *delimiter;
    // end data members ---

private:
    // begin member functions ---
    unsigned int _process_question(question_map &data, unsigned int id, std::string &line_str, const delimiter_type &d);
    unsigned int _process_category(category_map &data, unsigned int id, std::string &line_str, const delimiter_type &d);
    unsigned int _process_resources(resource_map &data, unsigned int id, std::istream &input_file, const delimiter_type &d);

    // end member functions ---
};

#endif