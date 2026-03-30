class Solution {
public:
    bool checkStrings(string s1, string s2) {
        /*           0 12   345          0 12     345
        Input: s1 = "a bc   dba", s2 = " c ab     dab"
        even :
        a=0; c=0;b=0

        odd:
        b=0; a=0 d =0
        


        Input: s1 = "abe", s2 = "bea"
        even:
        a=0;b=-1;e=1 -> false

        initialise map
        count the frequency of even and odd
        if i%2 == 0 -> update even freq
        s1 -> freq, ++ s2 --
        else same but for odd
        check if freq 0->true else false
        */
        vector<int> even(26,0);
        vector<int> odd(26,0);

        for(int i = 0 ;i<s1.size() ; i++){
            if(i%2 == 0){
               even[s1[i]-'a']++;
               even[s2[i]- 'a']--;
            }else{
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }
        }

        for(int i = 0 ;i<26 ; i++){
            if(even[i]!=0 or odd[i]!=0)return false;
        }
        return true;
    }
};