#include <iostream>
#include <stack>
#include <unordered_map>

#define umap std::unordered_map

void build_table(umap<std::string, std::pair<std::string, std::string>> &table);

void predictive(const std::string &input, umap<std::string, std::pair<std::string, std::string>> &table);


void build_table(umap<std::string, std::pair<std::string, std::string>> &table) {
    table.insert({"A", {std::string(), std::string()}});
    table["A"].first = "aAa||e";
    table["A"].second = "e";
}

void predictive(const std::string &input, umap<std::string, std::pair<std::string, std::string>> &table) {
    std::string X = "A";
    std::string a;
    std::string w = input + "$";
    int ip = 0;
    std::stack<std::string> s;
    s.push("$");
    s.push(X);
    while (X != "$") {
        if (X == std::string(w[ip], 1)) {
            s.pop();
            ip++;
        } else {
            if (w[ip] != 'a' && w[ip] != 'e')
                throw std::invalid_argument("Error - Character does not match any terminal value.");

            else if (w[ip] == 'a') {
                if (table[X].first.find("||") != std::string::npos)
                    throw std::invalid_argument("Error - Table does not meet LL(1) properties.");
                else {
                    s.pop();
                    for (int i = table[X].first.length() - 1; i >= 0; i--) {
                        std::string temp = std::string(table[X].first[i], 1);
                        s.push(temp);
                    }
                }
            } else {
                if (table[X].second.find("||") != std::string::npos)
                    throw std::invalid_argument("Error - Table does not meet LL(1) properties.");
                else {
                    s.pop();
                    for (int i = table[X].second.length() - 1; i >= 0; i--) {
                        std::string temp = std::string(table[X].first[i], 1);
                        s.push(temp);
                    }
                }
            }
        }

        X = s.top();
    }

}

int main() {
    umap<std::string, std::pair<std::string, std::string>> table;
    build_table(table);
    predictive("e", table);
    return 0;
}