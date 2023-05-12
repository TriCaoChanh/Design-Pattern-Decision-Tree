#ifndef __PARSER_H__
#define __PARSER_H__

#include "common.h"
#include "logger.h"

class Parser
{
protected:
    string file_data;
    string path;
    fstream file;

protected:
    void read_path(string);
    void open();
    void close();

    virtual void parse() = 0;

public:
    Parser();
    virtual ~Parser() = 0;

    void read_file(string);
    string get_data();
    void print_file();
};

class CSV_Parser : public Parser
{
protected:
    void parse() override;
public:
    CSV_Parser();
    ~CSV_Parser();
};

class Parquet_Parser : public Parser
{
protected:
    void parse() override;

public:
    Parquet_Parser();
    ~Parquet_Parser();
};

#endif