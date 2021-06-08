// Copyright 2021 by FORTYSS

#ifndef INCLUDE_USEDMEMORY_HPP_
#define INCLUDE_USEDMEMORY_HPP_
#include "Log.hpp"
#include "header.hpp"
#include <string>
#include <vector>

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
#endif  // INCLUDE_USEDMEMORY_HPP_
