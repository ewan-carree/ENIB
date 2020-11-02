//////////////////////////////////
//	Prog.cpp
//	2020-04-26 22:24:11.050602
//	ewan
//////////////////////////////////

#include "fullgeneric.hpp"

void test_min_max()
{
	std::cout << "~~~~~~" << __func__ << "~~~~~~" << std::endl;
	int a=1,b=2;
	double c=1.1,d=2.2;
	std::string e="hello", f="hallo";

	std::cout << "~~" << std::min(a,b) << "~~" << std::endl;
	std::cout << "~~" << std::min(c,d) << "~~" << std::endl;
	std::cout << "~~" << std::min(e,f) << "~~" << std::endl;
	std::cout << "~~" << std::min(e,f,[&](const auto &a, const auto &b)
									  {
  										return size(a)<size(b);
									  }) << "~~" << std::endl;
	const auto invCmp=[&](const auto &a, const auto &b) 
	{
	  return a>b;
	};
	std::cout << "~~" << std::min(e,f,invCmp) << "~~" << std::endl;
	std::cout << "~~" << std::max(e,f,invCmp) << "~~" << std::endl;
}

void test_average()
{
	std::cout << "~~~~~~" << __func__ << "~~~~~~" << std::endl;
	int a=1,b=2;
	double c=1.1,d=2.2;
	std::string e="hello", f="hallo";

	std::cout << exam::avg(a,b) << std::endl;
	std::cout << exam::avg(c,d) << std::endl;
	std::cout << exam::avg(e,f) << std::endl;
	std::cout << exam::avg(a,c) << std::endl;
	std::cout << exam::avg(a,f) << std::endl;

}

void
test_range_for()
{
  std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
  std::array<std::string, 7> strArray{"here", "are", "many", "strings",
                                      "in", "a", "std::array<T,N>"};
  std::vector<std::string> strVector{"here", "are", "many", "strings",
                                     "in", "a", "std::vector<T>"};
  for(const auto &elem: strArray)
  {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  for(const auto &elem: strVector)
  {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  std::cout << "--------\n";
  for(const auto &elem: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
  {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  for(const auto &elem: {"we", "can", "enumerate", "anything"})
  {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  std::cout << "--------\n";
  for(auto &elem: strVector[0])
  {
    elem=char(std::toupper(elem));
  }
  std::cout << strVector[0] << '\n';
}

void
test_iter()
{
  std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
  std::vector<std::string> strVector{"here", "are", "many", "strings",
                                     "in", "a", "std::vector<T>"};
  // WARNING: a range-for loop should have been used in real C++ code!
  for(auto it=cbegin(strVector); it!=cend(strVector); ++it)
  {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  const auto show=[&](const auto &seq)
  {
    for(const auto &elem: seq)
    {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  };
  strVector.emplace(cbegin(strVector)+3, "NEW");
  show(strVector);
  strVector.erase(cbegin(strVector)+2);
  show(strVector);
  if(const auto pos=std::find(begin(strVector), end(strVector), "a");
     pos!=end(strVector))
  {
    *pos="THIS";
  }
  show(strVector);
  std::cout << "--------\n";
  const auto min1=std::min_element(cbegin(strVector), cend(strVector));
  const auto max1=std::max_element(cbegin(strVector), cend(strVector));
  std::cout << "*min1: " << *min1 << "  *max1: " << *max1 << '\n';
  const auto noCaseCmp=[&](const auto &a, const auto &b)
  {
    return std::lexicographical_compare(cbegin(a),cend(a),
                                        cbegin(b),cend(b),
      [&](const auto &ca, const auto &cb)
      {
        return std::tolower(ca)<std::tolower(cb);
      });
  };
  const auto min2=std::min_element(cbegin(strVector), cend(strVector),
                                   noCaseCmp);
  const auto max2=std::max_element(cbegin(strVector), cend(strVector),
                                   noCaseCmp);
  std::cout << "*min2: " << *min2 << "  *max2: " << *max2 << '\n';
  std::cout << "--------\n";
  std::vector<double> values{1.0, 2.0, 3.0, 4.0, 0.5, 0.6, 0.7, 0.8};
  const auto fullAvg=exam::seqAvg(cbegin(values), cend(values));
  const auto partialAvg=exam::seqAvg(cbegin(values)+2, cend(values)-2);
  std::cout << "fullAvg: " << fullAvg << '\n';
  std::cout << "partialAvg: " << partialAvg << '\n';
  const auto strAvg=exam::seqAvg(cbegin(strVector), cend(strVector),
    [&](const auto &a, const auto &b)
    {
      std::string result;
      for(int i=0; i<int(size(a)); i+=b)
      {
        result+=a[i];
      }
      return result;
    });
  std::cout << "strAvg: " << strAvg << '\n';
  using Point2D = std::array<double, 2>;
  const std::vector<Point2D> points{{1.2, 3.4}, {5.6, 7.8}, {9.0, 1.2}};
  const auto pointAvg=exam::seqAvg(cbegin(points),cend(points),
    [&](auto &a, const auto &b)
    {
      a[0]+=b[0];
      a[1]+=b[1];
    },
    [&](const auto &a, const auto &b)
    {
      return Point2D{a[0]/b, a[1]/b};
    });
  std::cout << "pointAvg: "; show(pointAvg);
}

int main(int argc, char const *argv[])
{
	//test_min_max();
	//test_average();
	//test_range_for();
	test_iter();
	return 0;
}
