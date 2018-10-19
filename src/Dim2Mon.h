#include <dim/dic.hxx>
#include <Monitoring/Monitoring.h>
#include <string>
#include <vector>

using namespace o2::monitoring;

class Dim2Mon : public DimClient {
  std::vector<DimInfo*> services;
  const std::string serviceString = "HCR01M,HCR03M,HCR05M,HCR07M,HCR09M,HCR11M,HCR13M,HCR15M,HCR17M,HCE01M,HHA01M,HHA02M,HHA03M,HHA04M,HHA05M,TCR01T,TCR01M,TCR01B,TCR03T,TCR03M,TCR03B,TCR05T,TCR05M,TCR05B,TCR07T,TCR07M,TCR07B,TCR09T,TCR09M,TCR09B,TCR11T,TCR11M,TCR11B,TCR13T,TCR13M,TCR13B,TCR15T,TCR15M,TCR15B,TCR17T,TCR17M,TCR17B,TCE01T,TCE01M,TCE01B,THA01T,THA01M,THA01B,THA02T,THA02M,THA02B,THA03T,THA03M,THA03B,THA04T,THA04M,THA04B,THA05T,THA05M,THA05B";
  std::unique_ptr<Monitoring> monitoring;
public:
  Dim2Mon(const std::string& url);
  void infoHandler();
  void addTag(const std::string& name, const std::string& value);
};
