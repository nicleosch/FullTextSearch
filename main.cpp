#include "src/FullTextSearchEngine.hpp"
#include "src/Document.hpp"
#include "src/algorithms/VectorSpaceModelEngine/VectorSpaceModelEngine.hpp"
#include "src/algorithms/InvertedIndexEngine/InvertedIndexEngine.hpp"
#include "src/algorithms/TrigramIndexEngine/TrigramIndexEngine.hpp"
#include "src/algorithms/DummySearchEngine/DummySearchEngine.hpp"
#include <iostream>

int main() {
    // Load documents from data directory
    std::vector<Document> documents;

    // Choose search engine algorithm
    FullTextSearchEngine* engine = nullptr;
    std::string algorithmChoice;
    std::cout << "Select search algorithm (vsm/inverted/trigram): ";
    std::cin >> algorithmChoice;

    if (algorithmChoice == "vsm") {
        engine = new VectorSpaceModelEngine();
    } else if (algorithmChoice == "inverted") {
        engine = new InvertedIndexEngine();
    } else if (algorithmChoice == "trigram") {
        engine = new TrigramIndexEngine();
    }     else if (algorithmChoice == "dummy") {
        engine = new DummySearchEngine();
    } else {
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }

    engine->indexDocuments(documents);

    std::string query;
    while (true) {
        std::cout << "Enter search query (or 'exit' to quit): ";
        std::getline(std::cin, query);
        if (query == "exit") break;

        std::vector<Document> results = engine->search(query);

        for (const auto& doc : results) {
            std::cout << "Document ID: " << doc.getId() << std::endl;
        }
    }

    delete engine;
    return 0;
}
