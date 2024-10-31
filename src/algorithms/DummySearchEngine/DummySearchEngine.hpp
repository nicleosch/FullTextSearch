//
// Created by dhia on 10/31/24.
//

#ifndef DUMMYSEARCHENGINE_HPP
#define DUMMYSEARCHENGINE_HPP

#include "../../FullTextSearchEngine.hpp"

class DummySearchEngine : public FullTextSearchEngine {
   public:
    void indexDocuments(const std::vector<Document>& documents) override;
    std::vector<Document> search(const std::string& query) override;

   private:
};

#endif  // DUMMYSEARCHENGINE_HPP
