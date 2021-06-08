// Copyright 2021 by FORTYSS

#ifndef TEMPLATE_USEDMEMORY_HPP
#define TEMPLATE_USEDMEMORY_HPP
#include "Log.hpp"
#include "header.hpp"

class UsedMemory {
 public:

  void OnDataLoad(const std::vector<Item>& old_items,
                  const std::vector<Item>& new_items);

  void OnRawDataLoad(const std::vector<std::string>& old_items,
                     const std::vector<std::string>& new_items);

  [[nodiscard]] size_t Used() const;

 private:
  size_t used_ = 0;
};
#endif  // TEMPLATE_USEDMEMORY_HPP
