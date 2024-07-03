#include "MovingAverages.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void printUsage() {
    std::cout << "Usage: DataPipelineProject <input_file> <output_file> <feature_range> <window_length> <methods>\n";
}

std::vector<double> readData(const std::string& TestData) {
    std::vector<double> data;
    std::ifstream file(TestData);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        double value;
        while (ss >> value) {
            data.push_back(value);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
    }
    return data;
}

void writeData(const std::string& TestData, const std::vector<double>& data) {
    std::ofstream file(TestData);
    for (const auto& value : data) {
        file << value << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 6) {
        printUsage();
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string featureRange = argv[3];
    int windowLength = std::stoi(argv[4]);
    std::string methods = argv[5];

    std::vector<double> data = readData(inputFile);

    std::vector<double> result;
    if (methods.find("SMA") != std::string::npos) {
        result = calculateSMA(data, windowLength);
        writeData("SMA_" + outputFile, result);
    }
    if (methods.find("CA") != std::string::npos) {
        result = calculateCA(data);
        writeData("CA_" + outputFile, result);
    }
    if (methods.find("WMA") != std::string::npos) {
        result = calculateWMA(data, windowLength);
        writeData("WMA_" + outputFile, result);
    }
    if (methods.find("EMA") != std::string::npos) {
        result = calculateEMA(data, windowLength);
        writeData("EMA_" + outputFile, result);
    }
    if (methods.find("MM") != std::string::npos) {
        result = calculateMM(data, windowLength);
        writeData("MM_" + outputFile, result);
    }

    return 0;
}
