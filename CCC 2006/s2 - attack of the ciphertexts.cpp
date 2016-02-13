#include <iostream>
#include <string>
using namespace std;
char alphabet[27];
int main(){
    string decoded, encoded, secret;
    getline(cin, decoded);
    getline(cin, encoded);
    getline(cin, secret);
    for(int i = 0; i < 27; i++) alphabet[i] = '.';
    for(int i = 0; i < decoded.length(); i++) alphabet[encoded[i] == ' ' ? 26 : encoded[i] - 'A'] = decoded[i];
    for(int i = 0; i < secret.length(); i++) cout << alphabet[secret[i] == ' ' ? 26 : secret[i] - 'A'];
}
