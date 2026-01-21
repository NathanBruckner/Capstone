#ifndef __GAUGE__
#define __GAUGE__

#include <iomanip>
class gaugeType {
public:
  gaugeType(double length = 56.5, std::string name = "Standard");
  ~gaugeType();

  void setLength(double length);
  void setName(std::string name);

  std::string getName();
  double getLength();

private:
  std::string gaugeName_;
  double gaugeLength_;
};
#endif
