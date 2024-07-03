#ifndef MOVING_AVERAGES_H
#define MOVING_AVERAGES_H

#include <vector>
#include <string>

std::vector<double> calculateSMA(const std::vector<double>& data, int windowLength);
std::vector<double> calculateCA(const std::vector<double>& data);
std::vector<double> calculateWMA(const std::vector<double>& data, int windowLength);
std::vector<double> calculateEMA(const std::vector<double>& data, int windowLength);
std::vector<double> calculateMM(const std::vector<double>& data, int windowLength);

#endif // MOVING_AVERAGES_H
