#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

class Predictor {
  public:
    Predictor(std::vector<float>& historicalData, float tau) : historicalData(historicalData), tau(tau) {

    };

    ~Predictor() {};

  public: 
    std::vector<float> historicalData;
    float tau;

  public:
    bool predict() {
      return calculateExpectedReturns() >= 0;
    }

  private:
    float calculateExpectedReturns() {
      int nextPeriod = (int) historicalData.size();

      float num = 0, denom = 0;

      for (int i=0; i < nextPeriod; i++) {
        float expTerm = exp(-tau * (nextPeriod - i));
        num += historicalData[i] * expTerm;
        denom += expTerm;
      }

      return num/denom;
    }
};

std::vector<float> splitCsv(std::string input) {
  std::vector<float> result;

  std::stringstream ss(input);
  std::string str;
  while (std::getline(ss, str, ',')) result.push_back(std::stof(str));

  return result;
};

int main() {
  std::string input;
  while (std::cin >> input) {
    std::vector<float> historicalData = splitCsv(input);

    Predictor predictor(historicalData, 0.5f);
    std::cout << predictor.predict() << std::endl;
  }

  return 0;
}
