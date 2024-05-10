//     Main task - to implement the function fillCountries to put countries into a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the container.
//     4. Add a country to the container or a city to an existing country.

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

struct Coordinate
{
    double longitude;
    double latitude;
};

struct City
{
    std::string name;
    Coordinate coord;
    std::string country; 

    bool operator<(const City& other) const
    {
        return name < other.name;
    }
};

struct Country
{
    std::string name;
    std::set<City> cities;

    bool operator<(const Country& other) const
    {
        return name < other.name;
    }
};

void fillCountries(std::istream& inFile, std::map<std::string, Country>& countries)
{
    std::string line;
    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string cityName, countryName, population;
        double latitude, longitude;
        std::getline(ss, cityName, ',');
        ss >> latitude;
        ss.ignore();
        ss >> longitude;
        ss.ignore();
        std::getline(ss, countryName, ',');
        std::getline(ss, population, ',');
        ss.ignore(); 

        City city{cityName, {longitude, latitude}, countryName};

        if (countries.find(countryName) == countries.end())
        {
            countries[countryName] = {countryName, {}};
        }

        countries[countryName].cities.insert(city);
    }
}


int main()
{
    const std::string FILENAME = "../../data/problem1_cities/cities.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    if(inputFile)
    {
        std::cout<<"OK\n";
        std::map<std::string, Country> countries;
        fillCountries(inputFile, countries);

        for (const auto& country : countries)
        {
            std::cout << "Country: " << country.first << "\n";
            for (const City& city : country.second.cities)
            {
                std::cout << "City: " << city.name << ", Coordinates: (" << city.coord.longitude << ", " << city.coord.latitude << ")\n";
            }
            std::cout << "\n\n" << std::endl;
        }
    }
    return 0;
}
