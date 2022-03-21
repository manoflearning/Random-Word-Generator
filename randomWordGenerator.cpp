#include <iostream>
#include <vector>
using namespace std;

const int cntWords = 5886;
const int len = 54;

vector<string> words;

void input() {
    for (int i = 0; i < cntWords; i++) {
        string word; cin >> word;
        words.push_back(word);
    }
}

void output() {
    srand(time(NULL));

    vector<int> visited(cntWords);

    for (int i = 0; i < len; i++) {
        int x = rand() % cntWords;
        while (visited[x]) {
            x = rand() % cntWords;
        }
        visited[x] = true;
    
        cout << i + 1 << "번째 단어: " << words[rand() % cntWords];
        cout << '\n';
    }
}

int main() {
    freopen("5886 Korean Words.txt", "r", stdin);
    freopen("rwgOutput.txt", "w", stdout);
    
    input();

    output();

    return 0;
}