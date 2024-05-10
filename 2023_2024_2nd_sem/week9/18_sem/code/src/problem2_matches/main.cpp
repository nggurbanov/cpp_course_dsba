#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class FootballTeam {
public:
  FootballTeam(const std::string &name, const std::string &city,
               const std::string &stadium, double level)
      : name(name), city(city), stadium(stadium), level(level), points(0),
        wins(0), draws(0), losses(0) {}

  std::string name;
  std::string city;
  std::string stadium;
  double level;
  int points;
  int wins;
  int draws;
  int losses;
};

class Match {
public:
  Match(FootballTeam &localTeam, FootballTeam &visitorTeam,
        const std::string &stadium)
      : localTeam(localTeam), visitorTeam(visitorTeam), stadium(stadium),
        localGoals(0), visitorGoals(0) {}

  void play() {
    int k = static_cast<int>(std::rand() %
        (static_cast<int>(std::ceil(std::abs(localTeam.level - visitorTeam.level)) * 10)) +
    1);


    for (int i = 0; i < k; ++i) {
      int x = triangularDistribution(-localTeam.level, visitorTeam.level);
      if (x < 0) {
        ++localGoals;
      } else {
        ++visitorGoals;
      }
    }

    if (localGoals > visitorGoals) {
      localTeam.points += 3;
      localTeam.wins++;
      visitorTeam.losses++;
    } else if (localGoals < visitorGoals) {
      visitorTeam.points += 3;
      visitorTeam.wins++;
      localTeam.losses++;
    } else {
      localTeam.points++;
      visitorTeam.points++;
      localTeam.draws++;
      visitorTeam.draws++;
    }
  }

  FootballTeam &localTeam;
  FootballTeam &visitorTeam;
  std::string stadium;
  int localGoals;
  int visitorGoals;

private:
  int triangularDistribution(int min, int max) {
    double range = (max - min) / 2.0;
    double result =
        min + range +
        (std::rand() / static_cast<double>(RAND_MAX) - 0.5) * range *
            (1.0 -
             std::abs((std::rand() / static_cast<double>(RAND_MAX) - 0.5) *
                      2.0));
    return static_cast<int>(std::round(result));
  }
};

class Tournament {
public:
  Tournament(std::istream &in) : round(0) { loadTeams(in, teams); }

  void simulateRound() {
    int N = teams.size();
    for (int k = 1; k <= N / 2; ++k) {
      FootballTeam &team_k = teams[k - 1];
      FootballTeam &team_N_k = teams[N - k];
      Match match(team_k, team_N_k, team_k.stadium);
      match.play();
    }

    // Re-order the teams in the vector.
    std::rotate(teams.begin() + 1, teams.begin() + N - 1, teams.end());
    ++round;
  }

  void printResults() {
    std::sort(teams.begin(), teams.end(),
              [](const FootballTeam &a, const FootballTeam &b) {
                return a.points > b.points;
              });

    for (size_t i = 0; i < teams.size(); ++i) {
      std::cout << "Position " << i + 1 << ": " << teams[i].name << " ("
                << teams[i].points << " points)" << std::endl;
    }
  }

private:
  void loadTeams(std::istream &in, std::vector<FootballTeam> &teams) {
    std::string buffer;
    std::getline(in, buffer);
    while (std::getline(in, buffer)) {
      std::string name;
      std::string city;
      std::string stadium;
      double level;
      parseLineTeam(buffer, name, city, stadium, level);
      teams.push_back(FootballTeam(name, city, stadium, level));
    }
  }

  void parseLineTeam(const std::string &line, std::string &name,
                     std::string &city, std::string &stadium, double &level) {
    size_t posName = line.find(',');
    name = line.substr(0, posName);

    size_t posCity = line.find(',', posName + 1);
    city = line.substr(posName + 1, posCity - posName - 1);

    size_t posStadium = line.find(',', posCity + 1);
    stadium = line.substr(posCity + 1, posStadium - posCity - 1);

    size_t posLevel = line.size() - 1;
    std::string levelString =
        line.substr(posStadium + 1, posLevel - posStadium);
    std::stringstream ss(levelString);
    ss >> level;
  }

  std::vector<FootballTeam> teams;
  int round;
};

std::ostream &operator<<(std::ostream &out, const Match &match) {
  out << "(localTeam=" << match.localTeam.name
      << ", visitorTeam=" << match.visitorTeam.name
      << ", stadium=" << match.stadium << ", result=" << match.localGoals << "-"
      << match.visitorGoals << ")";
  return out;
}

int main() {
  const std::string FILENAME = "../../data/problem2_matches/football.csv";
  std::ifstream inputFile;
  inputFile.open(FILENAME);

  std::srand(static_cast<unsigned int>(std::time(0)));

  Tournament tournament(inputFile);

  for (int i = 0; i < 10; ++i) {
    tournament.simulateRound();
  }

  tournament.printResults();

  return 0;
}
