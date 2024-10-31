//
// Created by dhia on 10/31/24.
//

#ifndef FULLTEXTSEARCHENGINE_HPP
#define FULLTEXTSEARCHENGINE_HPP

#include <string>
#include <vector>

#include "Document.hpp"

class FullTextSearchEngine {
   public:
    virtual void indexDocuments(const std::vector<Document>& documents) = 0;
    virtual std::vector<Document> search(const std::string& query) = 0;
    virtual ~FullTextSearchEngine() {}

   protected:
    std::vector<Document> documents;  // Store documents for access in derived classes
};

#endif  // FULLTEXTSEARCHENGINE_HPP
