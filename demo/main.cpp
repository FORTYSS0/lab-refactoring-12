// Copyright 2021 by FORTYSS

#include <boost/program_options.hpp>
#include <header.hpp>

#include "Loger.hpp"
#include "PageContainer.hpp"
#include "UsedMemory.hpp"

namespace po = boost::program_options;

const char error_mes[] = "**********ERROR SYNTAX**********\n"
                         "Look to --help or -h";

void CreatePo(po::options_description& desc,
               po::variables_map& vm,
               const int& argc, const char** argv){
  desc.add_options()
      ("help,h", "Help screen\n")

      ("log_debug,l", "Logger status (Release(if OFF) or Debug(if ON))\n")

      ("input,i", po::value<std::string>()->default_value("data.txt"),
       "Name of input file\n")

      ("threshold,t", po::value<int>()->default_value(1),
       "Enter number\n");
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);
}

int main(const int argc, const char* argv[]) {
  try{
    po::options_description desc{"Options"};
    po::variables_map vm;
    CreatePo(desc, vm, argc, argv);
    if(vm.count("help")){
      std::cout << desc << std::endl;
    } else if(argc > 1){
      Loger::GetInstance().Setting(vm.count("log_debug"));
      UsedMemory used_memory;

      PageContainer page{};
      std::ifstream in(vm["input"].as<std::string>());

      page.RawLoad(in);
      page.DataLoad(vm["threshold"].as<int>());

      Loger::GetInstance().Write("Used memory: " +
                               std::to_string(used_memory.Used()));
      Loger::GetInstance().
          Write("Number skips in this lap: " +
                std::to_string(Histogram::GetInstance().GetNumSkip()));
      Loger::GetInstance().
          Write("AVG score: " +
                    std::to_string(Histogram::GetInstance().GetAvg()));

      page.PrintTable();

      page.DataLoad(vm["threshold"].as<int>()+3);
      Loger::GetInstance().Write("Used memory: " +
                               std::to_string(used_memory.Used()));
      Loger::GetInstance().
          Write("Number skips in this lap: " +
                std::to_string(Histogram::GetInstance().GetNumSkip()));
      Loger::GetInstance().
          Write("AVG score: " +
                std::to_string(Histogram::GetInstance().GetAvg()));
    } else {
      throw po::error(error_mes);
    }
  } catch (const po::error &ex) {
    std::cout << error_mes << "\n";
  }
}