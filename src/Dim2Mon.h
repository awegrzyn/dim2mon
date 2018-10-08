#include <dim/dic.hxx>
#include <Monitoring/Monitoring.h>
#include <string>
#include <vector>

using namespace o2::monitoring;

class Dim2Mon : public DimClient {
  DimInfo *service;
  std::unique_ptr<Monitoring> monitoring;
public:
  Dim2Mon(const std::string& url);
  void infoHandler();
};
