#include "word_ladder.h"

#include <catch2/catch.hpp>
#include <fstream>

TEST_CASE("word_ladder::read_lexicon works as expected") {
	std::ofstream testFile("test_lexicon.txt");
	REQUIRE(testFile.is_open());
	testFile << "cat\nbat\nrat\n";
	testFile.close();
	// Read the lexicon
	auto const lexicon = word_ladder::read_lexicon("test_lexicon.txt");
	// Check if the lexicon contains the expected words
	REQUIRE(lexicon.find("cat") != lexicon.end());
	REQUIRE(lexicon.find("bat") != lexicon.end());
	REQUIRE(lexicon.find("rat") != lexicon.end());
	REQUIRE(lexicon.size() == 3);
	std::remove("test_lexicon.txt");
}
TEST_CASE("at -> it") {
	auto const lexicon = std::unordered_set<std::string>{"at", "it"};

	const auto expected = std::vector<std::vector<std::string>>{{"at", "it"}};

	auto const ladders = word_ladder::generate("at", "it", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("short words: me -> my") {
	auto const lexicon = word_ladder::read_lexicon("./english.txt");

	const auto expected = std::vector<std::vector<std::string>>{{"me", "my"}};

	auto const ladders = word_ladder::generate("me", "my", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("medium words: cat -> dog") {
	auto const lexicon = word_ladder::read_lexicon("./english.txt");

	const auto expected =
	    std::vector<std::vector<std::string>>{{"cat", "cot", "cog", "dog"}, {"cat", "cot", "dot", "dog"}};

	auto const ladders = word_ladder::generate("cat", "dog", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("multiple transformation paths: hit -> cog") {
	auto const lexicon = word_ladder::read_lexicon("./english.txt");

	const auto expected =
	    std::vector<std::vector<std::string>>{{"hit", "hot", "cot", "cog"}, {"hit", "hot", "hog", "cog"}};

	auto const ladders = word_ladder::generate("hit", "cog", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("words with no direct ladder: lead -> gold") {
	auto const lexicon = word_ladder::read_lexicon("./english.txt");
	const auto expected = std::vector<std::vector<std::string>>{{"lead", "load", "goad", "gold"}};

	auto const ladders = word_ladder::generate("lead", "gold", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("multiple paths: work -> play") {
	auto const lexicon = word_ladder::read_lexicon("./english.txt");

	const auto expected =
	    std::vector<std::vector<std::string>>{{"work", "fork", "form", "foam", "flam", "flay", "play"},
	                                          {"work", "pork", "perk", "peak", "pean", "plan", "play"},
	                                          {"work", "pork", "perk", "peak", "peat", "plat", "play"},
	                                          {"work", "pork", "perk", "pert", "peat", "plat", "play"},
	                                          {"work", "pork", "porn", "pirn", "pian", "plan", "play"},
	                                          {"work", "pork", "port", "pert", "peat", "plat", "play"},
	                                          {"work", "word", "wood", "pood", "plod", "ploy", "play"},
	                                          {"work", "worm", "form", "foam", "flam", "flay", "play"},
	                                          {"work", "worn", "porn", "pirn", "pian", "plan", "play"},
	                                          {"work", "wort", "bort", "boat", "blat", "plat", "play"},
	                                          {"work", "wort", "port", "pert", "peat", "plat", "play"},
	                                          {"work", "wort", "wert", "pert", "peat", "plat", "play"}};

	auto const ladders = word_ladder::generate("work", "play", lexicon);

	CHECK(ladders == expected);
}
