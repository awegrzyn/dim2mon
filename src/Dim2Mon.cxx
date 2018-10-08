#include "Dim2Mon.h"
#include <Monitoring/MonitoringFactory.h>
#include <boost/program_options.hpp>
#include <chrono>
#include <iostream>
#include <thread>

using namespace o2::monitoring;


Dim2Mon::Dim2Mon(const std::string& url)
{
  service = new DimUpdatedInfo("/DCS/TEMPERATURE", -1, this);
  monitoring = MonitoringFactory::Get(url);
}

void Dim2Mon::infoHandler() { 
  DimInfo *curr = getInfo();
  monitoring->send({curr->getInt(), std::string(curr->getName())});
  delete curr;
}

int main(int argc, char* argv[]) {
   boost::program_options::options_description desc("Allowed options");
  desc.add_options()
    ("url", boost::program_options::value<std::string>()->required(), "Monitoring URL")
  ;

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);
  auto bridge = std::make_unique<Dim2Mon>(vm["url"].as<std::string>());
  while(1) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
  return 0;
}
