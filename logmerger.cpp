#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>

int main() 
{
    std::ifstream ifile;
    std::string line;
    std::ofstream ofile("/tmp/merged.log"); // result file
    std::multimap<int, std::string>entries; //multimap can store sorted entries with key duplicates

    std::string path = "/tmp/logs/"; // directory with log files to be merged
    for ( const auto &entry : std::filesystem::directory_iterator( path ) ) { // iterate files
        ifile.open( entry.path() );
        while( std::getline( ifile, line ) ) { // read strings from file
            int timestamp = stoi( line.substr( 0, line.find(' ') ) ); // extract timestamp
            entries.insert( make_pair( timestamp, line ) ); 
        }
        ifile.close();
    }

    for ( auto &i : entries )
        ofile << i.second << std::endl; // write merged file

    ofile.close();
    return 0;
}