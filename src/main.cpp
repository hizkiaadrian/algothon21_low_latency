#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

class Predictor
{
public:
  Predictor(vector<float> &historicalData, short window) : historicalData(historicalData), window(window){};

  ~Predictor(){};

public:
  vector<float> historicalData;
  short window;

public:
  bool predict()
  {
    return calculateExpectedReturns() >= 0;
  }

private:
  float calculateExpectedReturns()
  {
    int nextPeriod = (int)historicalData.size();

    float sum = 0, lambda = ((float)window - 1) / ((float)window + 1);
    float theta;

    for (int i=0; i < nextPeriod; i++) {
      theta = (1 - lambda) * pow(lambda, i);
      sum += historicalData[nextPeriod - i - 1] * theta;
    }

    return sum;
  }
};

int main()
{
  std::vector<float> vec;
  Predictor predictor(vec, 15);

  string input;
  while (std::cin >> input)
  {
    predictor.historicalData = splitCommas(input);

    cout << predictor.predict() << endl;
  }

  return 0;
}

/*Function to split comma-delimited string of floats into a vector of floats*/
vector<float> splitCommas(string input)
{
  vector<float> result;

  stringstream ss(input);
  string str;
  while (getline(ss, str, ','))
    result.push_back(stof(str));

  return result;
};
