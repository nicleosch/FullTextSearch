// Created by fts on 10/31/24.

#include "DummySearchEngine.hpp"
#include <string>

void DummySearchEngine::indexDocuments(DocumentIterator it) {
    while (it.hasNext()) { documents.push_back(it.next()); }
}

std::vector<std::shared_ptr<Document> > DummySearchEngine::search(const std::string &query) {
    std::vector<std::shared_ptr<Document> > results;
    for (const auto &doc: documents) {
        std::string_view view(doc->getBegin(), doc->getSize());

        if (view.find(query) != std::string::npos) {
            results.push_back(doc);
        }
    }

    return results;
}
