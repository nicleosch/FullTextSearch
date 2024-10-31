//
// Created by dhia on 10/31/24.
//

#ifndef INVERTEDINDEXENGINE_HPP
#define INVERTEDINDEXENGINE_HPP

#include "../../FullTextSearchEngine.hpp"

class InvertedIndexEngine : public FullTextSearchEngine {
   public:
    void indexDocuments(const std::vector<Document>& documents) override;
    std::vector<Document> search(const std::string& query) override;

   private:
};

#endif  // INVERTEDINDEXENGINE_HPP
