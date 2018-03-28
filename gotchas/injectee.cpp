namespace injectee {

	static int conf;

	int configure(int _settings) {
		conf = _settings;
	}

	int max_count() {
		return conf;
	}
}
