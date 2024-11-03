// DummySearchEngine.cpp
// Created by fts on 10/31/24.

#include "DummySearchEngine.hpp"

void DummySearchEngine::indexDocuments(const std::vector<Document>& documents) {
    this->documents = documents;
}

std::vector<Document> DummySearchEngine::search(const std::string& query) {
    std::vector<Document> results;

    // Perform a linear search over all documents
    for (const auto& doc : documents) {
        if (doc.getContent().find(query) != std::string::npos) {
            results.push_back(doc);
        }
    }

    return results;
}
