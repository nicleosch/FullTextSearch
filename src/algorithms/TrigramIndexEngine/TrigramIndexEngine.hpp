//
// Created by dhia on 10/31/24.
//

#ifndef TRIGRAMINDEXENGINE_HPP
#define TRIGRAMINDEXENGINE_HPP

#include "../../FullTextSearchEngine.hpp"

class TrigramIndexEngine : public FullTextSearchEngine {
   public:
    void indexDocuments(const std::vector<Document>& documents) override;
    std::vector<Document> search(const std::string& query) override;

   private:
};

#endif  // TRIGRAMINDEXENGINE_HPP
