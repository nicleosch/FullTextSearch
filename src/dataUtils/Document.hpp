// Document.hpp
// Created by fts on 10/31/24.

#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

class Document {
   public:
    Document(int id, const std::string& content);

    [[nodiscard]] int getId() const { return id; }

    [[nodiscard]] std::string getContent() const { return content; }

   private:
    int id;
    std::string content;
};

#endif  // DOCUMENT_HPP
