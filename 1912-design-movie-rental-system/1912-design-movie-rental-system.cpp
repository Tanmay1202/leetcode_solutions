class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> available;
    set<tuple<int, int, int>> rented;
    unordered_map<long long, int> priceMap;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i < entries.size(); i++) {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];

            available[movie].insert({price, shop});
            long long key = (static_cast<long long>(shop) << 20) | movie;
            priceMap[key] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;

        if (available.count(movie) == 0)
            return {};

        for (auto it = available[movie].begin();
             it != available[movie].end() && result.size() < 5; ++it) {
            result.push_back(it->second);
        }

        return result;
    }

    void rent(int shop, int movie) {
        long long key = (static_cast<long long>(shop) << 20) | movie;
        int price = priceMap[key];

        available[movie].erase({price, shop});

        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        long long key = (static_cast<long long>(shop) << 20) | movie;
        int price = priceMap[key];
        rented.erase({price, shop, movie});

        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; ++it) {
            int price = get<0>(*it);
            int shop = get<1>(*it);
            int movie = get<2>(*it);
            res.push_back({shop, movie});

            count++;
        }

        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */