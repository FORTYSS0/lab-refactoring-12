// Copyright 2021 by FORTYSS

#ifndef TEMPLATE_STATSENDER_HPP
#define TEMPLATE_STATSENDER_HPP
#include <fstream>
#include <string_view>

#include "Log.hpp"
#include "header.hpp"

class StatSender {
 public:

  void OnLoaded(const std::vector<Item>& new_items);

  void Skip(const Item& item);

  virtual ~StatSender() = default;

 private:
  virtual void AsyncSend(const std::vector<Item>& items, std::string_view path);

  std::ofstream fstr{"network", std::ios::binary};
};
#endif  // TEMPLATE_STATSENDER_HPP
