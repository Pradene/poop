#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <string>
#include <iostream>
#include <fstream>

class ILogger {
public:
    virtual ~ILogger() {}
    virtual void write(const std::string &s) = 0;
};

class FileLogger: public ILogger {
private:
    std::string     _filename;
    std::ofstream   _file;

public:
    FileLogger(const std::string &filename): _filename(filename), _file(filename.c_str(), std::ios::out | std::ios::app) {
        if (!_file.is_open()) {
            std::cerr << "Failed to open log file: " << _filename << std::endl;
        }
    }

    ~FileLogger() {
        if (_file.is_open()) {
            _file.close();
        }
    }

    void write(const std::string &s) {
        if (_file.is_open()) {
            _file << s;
        } else {
            std::cerr << "Attempted to write to a closed file.\n";
        }
    }
};

class OStreamLogger : public ILogger {
private:
    std::ostream&   _ostream;

public:
    OStreamLogger(std::ostream& ostream): _ostream(ostream) {}
    ~OStreamLogger() {}

    void write(const std::string& s) {
        _ostream << s;
    }
};

#endif // ILOGGER_HPP