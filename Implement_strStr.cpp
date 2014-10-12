#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle) return haystack;

        const char *p1;
        const char *p2;
        const char *p1_advance = haystack;
        for(p2 = &needle[1]; *p2; ++p2){
        	p1_advance++;
        }

        for(p1 = haystack; *p1_advance; p1_advance++){
        	char *p1_old = (char*) p1;
        	p2 = needle;
        	while(*p1 && *p2 && *p1 == *p2){
        		p1++;
        		p2++;
        	}
        	if(!*p2) return p1_old;

        	p1 = p1_old + 1;
        }


		return nullptr;
    }

	char* strStr_stl(char* haystack, char* needle) 
	{
	    string hs = string(haystack);
	    string ns = string(needle);

	    if(haystack == NULL || needle == NULL || strlen(needle)>strlen(haystack))
	        return NULL;

	    size_t location = hs.find(needle);

	    if(location == string::npos)
	        return NULL;
	    else
	        return &haystack[location];
	}
};


int main(int argc, char* argv[]){
	Solution sol;
	char *needle  = "world";
	char *haystack = "helloworld";

	char *res = sol.strStr(haystack, needle);
	cout << res << endl;	

	return 0;
}