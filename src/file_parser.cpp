#include "file_parser.h"

Parser::Parser() {}
Parser::~Parser() {}

void Parser::read_file(string path)
{
    this->read_path(path);
    this->open();
    this->parse();
    this->close();
}

void Parser::read_path(string path)
{
    this->path = path;
}

void Parser::open()
{
    this->file.open(path, ios::in);
}

void Parser::close()
{
    this->file.close();
}

string Parser::get_data()
{
    return this->file_data;
}

void Parser::print_file()
{
    Logger *console = Logger::get_logger();

    console->log(this->file_data);
}

CSV_Parser::CSV_Parser() {}
CSV_Parser::~CSV_Parser() {}

void CSV_Parser::parse()
{
    string line;
    while (file >> line)
    {
        this->file_data += line + '\n';
    }
}

Parquet_Parser::Parquet_Parser() {}
Parquet_Parser::~Parquet_Parser() {}

void Parquet_Parser::parse()
{
    Logger *console = Logger::get_logger();

    console->log("This method has not been implemented yet");
}