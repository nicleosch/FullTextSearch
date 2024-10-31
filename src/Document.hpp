//
// Created by dhia on 10/31/24.
//

#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP
#include <string>

class Document {
   public:
    Document(int id, const std::string& content);
    int getId() const { return id; };
    std::string_view getContent() const;

   private:
    int id;
    std::string content;
    // Additional metadata can be added here
};

#endif  // DOCUMENT_HPP
