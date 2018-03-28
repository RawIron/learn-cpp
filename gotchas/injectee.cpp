#include "injectee.h"

namespace injectee {

	static std::map<std::string,std::string> conf;

	void configure(std::map<std::string,std::string> _settings) {
		conf = _settings;
	}

	std::string max_count() {
		return conf["max_count"];
	}
}
