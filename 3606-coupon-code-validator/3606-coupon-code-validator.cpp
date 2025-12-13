class Solution {
private:
    bool business(string& str)
    {
        if(str == "electronics" || str == "grocery" || str == "pharmacy" || str == "restaurant")
        {
            return true;
        }

        return false;
    }

    bool codes(const string &str)
    {
        regex pattern("^[a-zA-Z0-9_]+$");
        return regex_match(str, pattern);
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) 
    {
        vector<string> result;
        unordered_map<string, vector<string>> sortedCoupons;
        for(int i=0; i<code.size(); i++){
            if(business(businessLine[i]) && codes(code[i]) && isActive[i]){
                sortedCoupons[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> businessOrder = {"electronics", "grocery", "pharmacy", "restaurant"};


        for(const string& category: businessOrder)
            {
                sort(sortedCoupons[category].begin(), sortedCoupons[category].end());
                result.insert(result.end(), sortedCoupons[category].begin(), sortedCoupons[category].end());
            }

        return result;

        
    }
};