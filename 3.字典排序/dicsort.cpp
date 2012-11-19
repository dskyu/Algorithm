#include <iostream>
#include <string>
using namespace std;

int next_permutation(string &str) {
     int len = str.size();
     int index = -1;
     for (int i = len - 2;i > 0;--i) {
         if (str[i] < str[i + 1]) {
             index = i;
             break;
         }
     }

     if (index == -1) return 0;
    
     char ch = 'z'+1;
     
     int num = -1;
     for (int i = index + 1;i < len ;++i) {
         if (str[i] <= str[index]) continue;

         if (str[i] < 'z') {
             num = i;
             ch = str[i];
         }
     }
     
     if (num != -1) {
        str[num] = str[index];
        str[index] = ch;
     }
     
     
     for (int i = index + 1;i < len ;++i) { 
         ch = str[i];
         str[i] = str[len-i+index];
         str[len-i+index] = ch;
     }        
     return 1;
}

int main()
{
    string input = "3754";
    
    cout << input;
    next_permutation(input);
    cout << endl << input;
    cin >> input;
    return 0;
}
