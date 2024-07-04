#include "word_ladder.h"

#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
// Please note: it's not good practice to test your code via a main function that does
//  printing. Instead, you should be using your test folder. This file should only really
//  be used for more "primitive" debugging as we know that working solely with test
//  frameworks might be overwhelming for some.

auto main() -> int {
	try {
		auto const english_lexicon = word_ladder::read_lexicon("src/english.txt");
		auto const ladders = word_ladder::generate("work", "play", english_lexicon);

		// debug here
		std::cout << "Found" << ladders.size() << " ladders.\n";
		for (const auto& ladder : ladders) {
			for (const auto& word : ladder) {
				std::cout << word << " ";
			}
			std::cout << "\n";
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	return 0;
}
