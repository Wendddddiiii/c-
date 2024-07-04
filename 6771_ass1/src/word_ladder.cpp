#include "word_ladder.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
auto word_ladder::read_lexicon(const std::string& path) -> std::unordered_set<std::string> {
	std::unordered_set<std::string> lexicon;
	std::ifstream file(path);
	std::string word;
	if (file.is_open()) {
		while (std::getline(file, word)) {
			lexicon.insert(word);
		}
		file.close();
	}
	else {
		throw std::runtime_error("Unable to open file: " + path);
	}
	return lexicon;
}

auto word_ladder::generate(const std::string& from, const std::string& to, const std::unordered_set<std::string>& lexicon)
    -> std::vector<std::vector<std::string>> {
	std::unordered_set<std::string> wordList = lexicon;
	std::unordered_map<std::string, std::vector<std::string>> adjList;
	bfs(from, to, wordList, adjList);

	std::vector<std::string> currPath = {to};
	std::vector<std::vector<std::string>> shortestPaths;
	backtrack(to, from, currPath, shortestPaths, adjList);
	// Sort the shortest paths lexicographically
	std::sort(shortestPaths.begin(), shortestPaths.end());
	return shortestPaths;
}

auto word_ladder::backtrack(const std::string& source,
                            const std::string& destination,
                            std::vector<std::string>& currPath,
                            std::vector<std::vector<std::string>>& shortestPaths,
                            const std::unordered_map<std::string, std::vector<std::string>>& adjList) -> void {
	if (source == destination) {
		shortestPaths.push_back(std::vector<std::string>(currPath.rbegin(), currPath.rend()));
		return;
	}

	if (adjList.find(source) != adjList.end()) {
		for (const auto& neighbor : adjList.at(source)) {
			currPath.push_back(neighbor);
			backtrack(neighbor, destination, currPath, shortestPaths, adjList);
			currPath.pop_back();
		}
	}
}

auto word_ladder::findNeighbors(std::string& word, const std::unordered_set<std::string>& wordList)
    -> std::vector<std::string> {
	std::vector<std::string> neighbors;

	for (std::size_t i = 0; i < word.size(); i++) {
		char oldChar = word[i];
		for (char c = 'a'; c <= 'z'; c++) {
			word[i] = c;
			if (c == oldChar || wordList.count(word) == 0) {
				continue;
			}
			neighbors.push_back(word);
		}
		word[i] = oldChar;
	}
	return neighbors;
}

auto word_ladder::bfs(const std::string& beginWord,
                      const std::string& endWord,
                      std::unordered_set<std::string>& wordList,
                      std::unordered_map<std::string, std::vector<std::string>>& adjList) -> void {
	std::queue<std::string> q;
	q.push(beginWord);
	if (wordList.find(beginWord) != wordList.end()) {
		wordList.erase(beginWord);
	}
	std::unordered_map<std::string, int> isEnqueued;
	isEnqueued[beginWord] = 1;
	bool foundEndWord = false;
	while (!q.empty() && !foundEndWord) {
		std::vector<std::string> visited;
		std::size_t levelSize = q.size();
		for (std::size_t i = 0; i < levelSize; i++) {
			std::string currWord = q.front();
			q.pop();

			std::vector<std::string> neighbors = findNeighbors(currWord, wordList);
			for (const auto& word : neighbors) {
				if (word == endWord) {
					foundEndWord = true;
				}
				visited.push_back(word);
				adjList[word].push_back(currWord);

				if (isEnqueued.find(word) == isEnqueued.end()) {
					q.push(word);
					isEnqueued[word] = 1;
				}
			}
		}
		for (const auto& word : visited) {
			if (wordList.find(word) != wordList.end()) {
				wordList.erase(word);
			}
		}
	}
}
