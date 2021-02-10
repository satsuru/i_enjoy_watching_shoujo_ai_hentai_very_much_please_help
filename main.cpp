#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>
#include <set>

using namespace std;

string line;
int n;
map<string, vector<set<string>::iterator>> words;
set<string> sentences;

void read_input() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string word, sentence;
    getline(cin, line);
    stringstream linestream(line);

    while (getline(linestream, sentence, '.')) {
        if (sentence[0] == ' ')
            sentence.erase(0, 1);
        sentences.emplace(sentence);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        words.emplace(word, vector<set<string>::iterator>());
    }

}

void solve() {

    string word;
    set<string>::iterator it;


    for (it = sentences.begin(); it != sentences.end(); ++it) {
        stringstream sstream(*it);
        while (getline(sstream, word, ' ')) {
            auto word_it = words.find(word);
            if (word_it != words.end()) {
                word_it->second.push_back(it);
            }
        }
    }

    for (auto r_it : words) {

        string upper_word;
        for (auto c : r_it.first)
            upper_word.push_back(toupper(c));

        cout << r_it.second.size() << endl;
        for (auto & i : r_it.second) {
            string out_s = *i;
            size_t start_pos = out_s.find(r_it.first);
            out_s.replace(start_pos, (r_it.first).length(), upper_word);
            cout << out_s << "." << endl;
        }
    }

}

int main() {

    read_input();
    solve();

    return 0;
}
