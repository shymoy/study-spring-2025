#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template<typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string &source) {
    /* TODO: Implement this method */
    auto pred = [](char c) {
        return std::isspace(c);
    };
    auto wrap_iters = find_all(source.begin(), source.end(), pred);
    auto first1 = wrap_iters.begin();
    auto first2 = first1 + 1;
    auto last1 = wrap_iters.end() - 1;
    Corpus tokens;
    auto out = std::inserter(tokens, tokens.end());
    std::transform(first1, last1, first2, out, [&source](auto begin, auto end) {
        return Token(source, begin, end);
    });
    std::erase_if(tokens, [](Token token) {
        return token.content.empty();
    });
    return tokens;
}

std::set<Misspelling> spellcheck(const Corpus &source, const Dictionary &dictionary) {
    /* TODO: Implement this method */
    auto view = std::ranges::views::filter(source, [&dictionary](Token token) {
        return !dictionary.contains(token.content);
    });
    auto misspellings = std::ranges::views::transform(view, [&dictionary](Token token) {
    auto filter = std::ranges::views::filter(dictionary, [token](std::string word) {
        return levenshtein(token.content, word) == 1;
    });
    std::set<std::string> set(filter.begin(), filter.end());
    Misspelling misspelling(token, set);
    return misspelling;
});
    auto filter_view = std::ranges::views::filter(misspellings, [](Misspelling misspelling) {
    return !misspelling.suggestions.empty();
});
    std::set<Misspelling> res(filter_view.begin(), filter_view.end());
    return res;
};

/* Helper methods */

#include "utils.cpp"
