// DocumentUtils.cpp
// Created by fts on 11/3/24.

#include "DocumentUtils.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

std::vector<Document> loadDocuments(const std::string& directoryPath) {
    std::vector<Document> documents;
    int idCounter = 1;

    // Resolve to absolute path
    std::filesystem::path absPath = std::filesystem::absolute(directoryPath);

    // Check if the directory exists
    if (!std::filesystem::exists(absPath) || !std::filesystem::is_directory(absPath)) {
        std::cerr << "Invalid directory path: " << absPath << std::endl;
        return documents;
    }

    for (const auto& entry : std::filesystem::directory_iterator(absPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            if (file.is_open()) {
                std::string content((std::istreambuf_iterator<char>(file)),
                                    std::istreambuf_iterator<char>());
                documents.emplace_back(idCounter++, content);
                file.close();
            } else {
                std::cerr << "Failed to open file: " << entry.path() << std::endl;
            }
        }
    }

    if (documents.empty()) {
        std::cerr << "No documents found in the directory: " << absPath << std::endl;
    }

    return documents;
}
