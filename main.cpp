#include <iostream>

#include "src/FullTextSearchEngine.hpp"
#include "src/algorithms/DummySearch/DummySearchEngine.hpp"
#include "src/algorithms/InvertedIndex/InvertedIndexEngine.hpp"
#include "src/algorithms/TrigramIndex/TrigramIndexEngine.hpp"
#include "src/algorithms/VectorSpaceModel/VectorSpaceModelEngine.hpp"
#include "src/dataUtils/Document.hpp"
#include "src/dataUtils/DocumentUtils.hpp"

int main() {
    // Choose search engine algorithm
    FullTextSearchEngine* engine = nullptr;
    std::string algorithmChoice;
    std::cout << "Select search algorithm (vsm/inverted/trigram/dummy): ";
    std::cin >> algorithmChoice;

    if (algorithmChoice == "vsm") {
        engine = new VectorSpaceModelEngine();
    } else if (algorithmChoice == "inverted") {
        engine = new InvertedIndexEngine();
    } else if (algorithmChoice == "trigram") {
        engine = new TrigramIndexEngine();
    } else if (algorithmChoice == "dummy") {
        engine = new DummySearchEngine();
    } else {
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }
    std::string directoryPath;
    std::cout << "Enter search directory absolute path: ";
    std::cin >> directoryPath;

    std::vector<Document> documents = loadDocuments(directoryPath);

    if (documents.empty()) {
        std::cerr << "No documents to index. Exiting..." << std::endl;
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
