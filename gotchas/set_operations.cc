struct query {
    size_t begin;
    size_t end;
    long addend;

    bool operator==(const query& rhs) const noexcept {
        return tie(begin, end, addend) == tie(rhs.begin, rhs.end, rhs.addend);
    }

    bool operator<(const query& rhs) const noexcept {
        return tie(begin, end) < tie(rhs.begin, rhs.end);
    }
};

void test_out(bool pass) {
    if (pass) {
        cout << ".";
    }
    else {
        cout << "F";
    }
    cout << flush;
}

void test_set() {
    {
    const query value{ 2,4,6 };
    set<query> intervals{ {2,4,5}, {5,7,6}, {8,8,1} };
    const query expected{ 2,4,5 };
    test_out(*intervals.lower_bound(value) == expected);
    }
    {
    const query value{ 2,4,6 };
    set<query> intervals{ {2,3,5}, {5,7,6}, {8,8,1} };
    const query expected{ 5,7,6 };
    test_out(*intervals.lower_bound(value) == expected);
    }
    {
    const query value{ 9,11,3 };
    set<query> intervals{ {2,4,5}, {5,7,6}, {8,8,1} };
    set<query>::iterator expected{ intervals.end() };
    test_out(intervals.lower_bound(value) == expected);
    }
    {
    const query value{ 1,2,1 };
    set<query> intervals{ {2,4,5}, {5,7,6}, {8,8,1} };
    const query expected{ 2,4,5 };
    test_out(*intervals.lower_bound(value) == expected);
    }
    {
    const query value{ 2,4,6 };
    set<query> intervals{};
    set<query>::iterator expected{ intervals.end() };
    test_out(intervals.lower_bound(value) == expected);       
    }
    {
    set<query> intervals{ {2,4,6} };
    set<query>::iterator expected{ intervals.end() };
    test_out(ranges::next(intervals.begin(), intervals.end()) == expected);       
    }
}

