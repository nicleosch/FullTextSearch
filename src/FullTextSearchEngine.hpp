//
// Created by fts on 10/31/24.
//

#ifndef FULLTEXTSEARCHENGINE_HPP
#define FULLTEXTSEARCHENGINE_HPP

#include <string>
#include <vector>

#include "dataUtils/Document.hpp"

class FullTextSearchEngine {
   public:
    virtual void indexDocuments(const std::vector<Document>& documents) = 0;

    virtual std::vector<Document> search(const std::string& query) = 0;

    virtual ~FullTextSearchEngine() = default;

   protected:
    std::vector<Document> documents;
};

#endif  // FULLTEXTSEARCHENGINE_HPP
