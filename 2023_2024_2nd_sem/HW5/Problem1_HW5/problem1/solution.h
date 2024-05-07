#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
    Citation(const std::string& title, int year)
        : _title(title), _year(year)
    {
    }

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    virtual void printCitationEDIT(std::string string) const = 0;

    virtual std::string getInlineCitation() const = 0;

protected:
    std::string _title;
    int _year;
};

// example 1 - Web Page
// you will need to modify it
class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }

    void printCitationEDIT(std::string string) const override
    {
        string += "Title: " + _title + "\n";
        string += "Year: " + std::to_string(_year) + "\n";
        string += "URL: " + _url + "\n";
    }

    std::string getInlineCitation() const override
    {
        std::string year = std::to_string(_year);
        return "[Web page, " + year + "]";
    }


protected:
    std::string _url;
};

class PublishedWork : public Citation
{
public:
    PublishedWork(const std::string& title, int year,
                  const std::string& firstname, const std::string& lastname)
        : Citation(title, year),
          _firstname(firstname), _lastname(lastname){};

protected:
    std::string _firstname;
    std::string _lastname;
};

class Article : public PublishedWork
{
public:
    Article(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& journal)
        : PublishedWork(title, year, firstname, lastname), _journal(journal) {}
    std::string _journal;
    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname + " " + _lastname << std::endl;
        ostr << "Journal: " << _journal << std::endl;
    }

    void printCitationEDIT(std::string string) const override
    {
        string += "Title: " + _title + "\n";
        string += "Year: " + std::to_string(_year) + "\n";
        string += "Author: " + _firstname + " " + _lastname + "\n";
        string += "Journal: " + _journal + "\n";
    }


    std::string getInlineCitation() const override
    {
        std::string year = std::to_string(_year);
        return "[" + _lastname + ", " + year + "]";
    }
};


// example 2 - Book
// included only as an example, not used in the tasks
// class Book : public PublishedWork
// {
// public:
//     Book(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& publisher)
//         : PublishedWork(title, year, firstname, lastname),
//           _publisher(publisher)
//     {
//     }

//     void printCitation(std::ostream& ostr) const override
//     {
//         PublishedWork::printCitation(ostr);
//         ostr << "Publisher:" << _publisher << std::endl;
//     }

// protected:
//     std::string _publisher;
// };


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;
    switch (type)
    {
        case CitationType::WebPage: {
            std::string title = data.at("title");
            std::string year = data.at("year");
            std::string url = data.at("url");
            citationToAdd = new WebPage(title, std::stoi(year), url);
            break;
        }
        case CitationType::Article: {
            std::string title = data.at("title");
            std::string year = data.at("year");
            std::string first = data.at("firstname");
            std::string second = data.at("lastname");
            std::string journal = data.at("journal");
            citationToAdd = new Article(title, std::stoi(year), first, second, journal);
            break;
        }
        default:
            throw std::invalid_argument("Invalid citation type");
    }
    std::string key = data.at("key");
    citations[key] = citationToAdd;
    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    for (const auto& e: citations)
    {
        std::string key = e.first;
        size_t pos = text.find(key);
        while (pos != std::string::npos)
        {
            text.replace(pos, key.length(), e.second->getInlineCitation());
            pos = text.find(key, pos + e.second->getInlineCitation().length());
        }
    }
}


// task 5
bool citationExistsInVector(const std::vector<Citation*>& vec, const std::map<std::string, Citation*>& citations, const std::string& key)
{
    for (const auto& citation: vec)
    {
        for (const auto& map_entry: citations)
        {
            if (map_entry.second == citation && map_entry.first == key)
            {
                return true;
            }
        }
    }
    return false;
}


void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::map<int, std::string> bibliography;
    int count = 1;
    std::vector<std::string> keys;

    // Extract keys from text
    size_t start_pos = text.find("{");
    while (start_pos != std::string::npos)
    {
        size_t end_pos = text.find("}", start_pos);
        if (end_pos != std::string::npos)
        {
            std::string key = text.substr(start_pos + 1, end_pos - start_pos - 1);
            keys.push_back(key);
        }
        start_pos = text.find("{", end_pos);
    }

    // Create bibliography in order of appearance
    for (const auto& key: keys)
    {
        const Citation* citation = citations.at(key);
        std::stringstream ss;
        citation->printCitation(ss);
        bibliography[count] = ss.str();
        count++;
    }

    // Print bibliography
    for (const auto& entry: bibliography)
    {
        std::cout << entry.second << std::endl;
    }
}


// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions
void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
}

#endif
