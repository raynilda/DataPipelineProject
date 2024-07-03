#include "MovingAverages.h"
#include <numeric>
#include <deque>
#include <algorithm>
#include <cmath>

std::vector<double> calculateSMA(const std::vector<double>& data, int windowLength) {
    std::vector<double> result;
    double sum = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
        if (i >= windowLength) {
            sum -= data[i - windowLength];
        }
        if (i >= windowLength - 1) {
            result.push_back(sum / windowLength);
        }
    }
    return result;
}

std::vector<double> calculateCA(const std::vector<double>& data) {
    std::vector<double> result;
    double sum = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
        result.push_back(sum / (i + 1));
    }
    return result;
}

std::vector<double> calculateWMA(const std::vector<double>& data, int windowLength) {
    std::vector<double> result;
    double sum = 0.0;
    int weightSum = windowLength * (windowLength + 1) / 2;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i] * (i + 1);
        if (i >= windowLength) {
            sum -= data[i - windowLength] * (i - windowLength + 1);
        }
        if (i >= windowLength - 1) {
            result.push_back(sum / weightSum);
        }
    }
    return result;
}

std::vector<double> calculateEMA(const std::vector<double>& data, int windowLength) {
    std::vector<double> result;
    double k = 2.0 / (windowLength + 1);
    double ema = data[0];
    result.push_back(ema);
    for (size_t i = 1; i < data.size(); ++i) {
        ema = data[i] * k + ema * (1 - k);
        result.push_back(ema);
    }
    return result;
}

std::vector<double> calculateMM(const std::vector<double>& data, int windowLength) {
    std::vector<double> result;
    std::deque<double> window;
    for (size_t i = 0; i < data.size(); ++i) {
        window.push_back(data[i]);
        if (window.size() > windowLength) {
            window.pop_front();
        }
        if (window.size() == windowLength) {
            std::vector<double> sortedWindow(window.begin(), window.end());
            std::sort(sortedWindow.begin(), sortedWindow.end());
            result.push_back(sortedWindow[windowLength / 2]);
        }
    }
    return result;
}
