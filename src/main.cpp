#include <iostream>
#include <vector>
#include <math.h>

class Predictor {
  public:
    Predictor(float tau) : tau(tau) {};

    ~Predictor() {};

  public: 
    std::vector<float> historicalData;
    float tau;

  public:
    bool predict(float newestData) {
      historicalData.push_back(newestData);

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

int main() {
  float input;

  Predictor predictor(0.5f);
  while (std::cin >> input) {
    std::cout << predictor.predict(input) << std::endl;
  }

  return 0;
}
