#ifndef COMP6771_WORD_LADDER_H
#define COMP6771_WORD_LADDER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

namespace word_ladder {
	// Given a file path to a newline-separated list of words...
	// Loads those words into an unordered set and returns it.
	auto read_lexicon(const std::string& path) -> std::unordered_set<std::string>;

	// Given a start word and destination word, returns all the shortest possible paths from the
	// start word to the destination, where each word in an individual path is a valid word per the
	// provided lexicon.
	// Preconditions:
	// - from.size() == to.size()
	// - lexicon.contains(from)
	// - lexicon.contains(to)

	void backtrack(const std::string& source,
	               const std::string& destination,
	               std::vector<std::string>& currPath,
	               std::vector<std::vector<std::string>>& shortestPaths,
	               const std::unordered_map<std::string, std::vector<std::string>>& adjList);

	void bfs(const std::string& beginWord,
	         const std::string& endWord,
	         std::unordered_set<std::string>& wordList,
	         std::unordered_map<std::string, std::vector<std::string>>& adjList);

	auto findNeighbors(std::string& word, const std::unordered_set<std::string>& wordList) -> std::vector<std::string>;

	auto generate(const std::string& from, const std::string& to, const std::unordered_set<std::string>& lexicon)
	    -> std::vector<std::vector<std::string>>;
} // namespace word_ladder

#endif // COMP6771_WORD_LADDER_H
