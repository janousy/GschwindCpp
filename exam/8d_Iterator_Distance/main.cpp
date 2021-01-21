#include <iostream>
#include "vector"
#include "set"
using namespace std;

namespace iterd {
    template<typename I>
    int distance(I it1, I it2, std::random_access_iterator_tag) {
        return std::abs(it1 - it2);
    }

    template<typename I>
    int distance(I it1, I it2, std::input_iterator_tag) {
        int cnt = 0;
        while (it1 != it2) {
            cnt++;
            it1++;
        }
        return cnt;
    }

    template <typename I>
    int dist_dispatch(I it1, I it2) {
        typedef typename std::iterator_traits<I>::iterator_category cat;
        int dist = iterd::distance(it1, it2, cat());
        return dist;
    }
}


template<typename Iter>
typename enable_if<!std::is_base_of<std::random_access_iterator_tag, typename std::iterator_traits<Iter>::iterator_category>::value,  int>::type
dist(Iter fst, Iter lst)  {
    int dis = 0;
    std::cout << "called for general iterator\n";
    while(fst != lst) {
        dis = dis+1;
        fst++;
    }
    return dis;
}

template<class RAIter>
typename enable_if<std::is_base_of<std::random_access_iterator_tag, typename std::iterator_traits<RAIter>::iterator_category>::value,  int>::type
dist(RAIter fst, RAIter lst) {
    std::cout << "called for random-access iterator\n";
    return lst - fst;
}

int main() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    auto begin = v1.begin();
    auto end = v1.end();
    cout << iterd::dist_dispatch(begin, end) << endl;
    cout << dist(begin, end) << endl;


    set<int> s {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto start = s.begin();
    auto stop = s.end();
    cout << iterd::dist_dispatch(start, stop) << endl;
    cout << dist(start, stop) << endl;

    return 0;
}
