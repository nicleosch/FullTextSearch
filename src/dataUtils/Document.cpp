// Created by fts on 10/31/24.

#include "Document.hpp"

Document::Document(int id, const char *data, size_t size,
                   const std::shared_ptr<arrow::Buffer> &arrowBuf) : id(id), beginPointer(data),
                                                                     size(size), arrowBuf(arrowBuf) {
}
