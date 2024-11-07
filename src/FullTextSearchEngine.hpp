//
// Created by fts on 10/31/24.
//

#ifndef FULLTEXTSEARCHENGINE_HPP
#define FULLTEXTSEARCHENGINE_HPP

#include <string>
#include <vector>

#include "dataUtils/Document.hpp"
#include "dataUtils/DocumentIterator.hpp"

class FullTextSearchEngine {
public:
    virtual void indexDocuments(DocumentIterator it) = 0;

    virtual std::vector<std::shared_ptr<Document> > search(const std::string &query) = 0;

    virtual ~FullTextSearchEngine() = default;

protected:
};

#endif  // FULLTEXTSEARCHENGINE_HPP
