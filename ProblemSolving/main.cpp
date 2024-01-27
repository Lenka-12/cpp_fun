#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <deque>
bool isValid(std::string s) {
        std::deque<char> chars;
        for (char& c : s){
            if (c == '(' || c== '{' || c == '['){
                // opening character
                chars.push_front(c);
            }
            else if (c == ')'){
                if (chars.front() == (c-1)){
                    // delete matching character
                    chars.pop_front();
                }
                else {
                    // not valid
                    return false;
                }
            }
            else {
                // } or ]
                if (chars.front() == (c-2)){
                    // delete matching character
                    chars.pop_front();
                }
                else {
                    // not valid
                    return false;
                }
            }
        }

        return (chars.empty());
    }
bool is_balanced(const std::string& str){
    std::map<char,int> hash = {
        {'(',0},{'[',0},{'{',0}
    };
      std::map<char,int>::iterator it;

    for (const char& ch : str){
        // check if its 
        it = std::find_if (hash.begin(),hash.end(),
        [&ch](std::pair<char,int> p) {return (p.first == ch);}
        );

        if (it != hash.end()){
            // increment opening brackets
            hash[ch]++;
        }

        else if (ch == ')') {
            if (hash[ch-1] == 0){
                return false;
            }

            else {
                hash[ch-1]--;
            }
        }

        else if (ch == '}' || ch == ']'){
            if (hash[ch-2] == 0){
                return false;
            }

            else {
                hash[ch-2]--;
            }

        }

        else {
            // ignore any other character
        }


    }
    it = std::find_if(hash.begin(),hash.end(),
        [](std::pair<char,int> p) {return (p.second == 0);}
    );

    return (it != hash.end());

    
}

int main(){

    std::string str{"((a+b)*(c-d)())"};
    std::cout << std::boolalpha;

    std::cout << is_balanced(str) << std::endl;

    return 0;
}