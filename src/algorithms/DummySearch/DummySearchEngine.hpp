//
// Created by fts on 10/31/24.
//

#ifndef DUMMYSEARCHENGINE_HPP
#define DUMMYSEARCHENGINE_HPP

#include "../../FullTextSearchEngine.hpp"

class DummySearchEngine : public FullTextSearchEngine {
public:
    void indexDocuments(DocumentIterator it) override;

    std::vector<std::shared_ptr<Document> > search(const std::string &query) override;

private:
    std::vector<std::shared_ptr<Document> > documents;
};

#endif  // DUMMYSEARCHENGINE_HPP
