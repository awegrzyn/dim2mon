#include "Dim2Mon.h"
#include <Monitoring/MonitoringFactory.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace o2::monitoring;

Dim2Mon::Dim2Mon(const std::string& url)
{
  std::vector<std::string> serviceNames;
  boost::split(serviceNames, serviceString, boost::is_any_of(","), boost::token_compress_on);
  for (const std::string& name : serviceNames) {
    services.emplace_back(new DimUpdatedInfo(name.c_str(), -1, this));
  }
  monitoring = MonitoringFactory::Get(url);
}

void Dim2Mon::infoHandler() { 
  DimInfo *curr = getInfo();
  std::string name = std::string(curr->getName());
  std::string type;
  (name.front() == 'T') ? type = "temperature" : type = "humidity";
  monitoring->send(Metric{curr->getFloat(), std::string(curr->getName())}.addTags({{"type", type}}));
}

void Dim2Mon::addTag(const std::string& name, const std::string& value) {
  monitoring->addGlobalTag(name, value);
}
