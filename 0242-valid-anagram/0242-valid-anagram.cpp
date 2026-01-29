class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> count(26, 0 );
     if (s.size() != t.size() ){
            return false;
            }


        for(auto i : s)
        {
           count[ i-'a']++;
        }
        for(auto  j : t  )
        {
           count[j - 'a']--;
        }

        for( auto k :count)
        {
           if ( k != 0)
           {
            return false ;
           }

        }
        return true;

    }
};