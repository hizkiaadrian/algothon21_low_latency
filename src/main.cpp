#include <iostream>
#include <vector>

class Predictor {
  public:
    Predictor() {};

  public: 
    std::vector<float> historicalData;

  public:
    bool predict(float newestData) {
      historicalData.push_back(newestData);

      return historicalData.size() % 2 == 0;
    }
};

int main() {
  float input;

  Predictor predictor;
  while (std::cin >> input) {
    std::cout << predictor.predict(input) << std::endl;
  }

  return 0;
}
