// playlist.hpp

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <functional>
#include <numeric>

class Song {
public:
    Song(std::string title, std::string artist, int duration)
    : title_(std::move(title)), artist_(std::move(artist)), duration_(duration) {}
    
    // Accessors
    std::string get_title() const {
        return title_;
    }
    std::string get_artist() const {
        return artist_;
    }
    int get_duration() const {
        return duration_;
    }

    // Modifiers
    void set_title(const std::string& title) {
        title_ = title;
    }
    void set_artist(const std::string& artist) {
        artist_ = artist;
    }
    void set_duration(int duration) {
        duration_ = duration;
    }

private:
    std::string title_;
    std::string artist_;
    int duration_; // in seconds
};

class Playlist {
public:
    // Default constructor
    Playlist() = default;
    
    // Destructor
    ~Playlist() = default;
    
    // Copy constructor
    Playlist(const Playlist& other) {
        songs_.reserve(other.songs_.size());
        for(const auto& song:other.songs_) {
            songs_.push_back(std::make_unique<Song>(*song));
        }
    }
    
    // Copy assignment operator
    Playlist& operator=(const Playlist& other) {
        if(this!= &other) {
            Playlist temp(other);
            std::swap(songs_, temp.songs_);
        }
        return *this;
    }

    // Move constructor
    Playlist(Playlist&& other) noexcept = default;
    
    // Move assignment operator
    Playlist& operator=(Playlist&& other) noexcept = default;

    auto operator==(const Playlist& other) -> bool {
        return songs_ == other.songs_;
    }

    // Add a song to the playlist
    void add_song(const Song& song) {
        songs_.push_back(std::make_unique<Song>(song));
    }
    
    // Remove a song from the playlist by title
    bool remove_song(const std::string& title) {
        //elements that satisfy the predicate are moved to the end of the container's range
        auto it = std::remove_if(songs_.begin(), songs_.end(), [&title](const auto& song){return song->get_title() == title; });
        if(it!=songs_.end()) {
            songs_.erase(it, songs_.end());
            return true;
        } else {
            return false;
        }
    }
    
    // Get the total duration of all songs in the playlist
    int get_total_duration() const {
        return std::accumulate(songs_.begin(), songs_.end(), 0, [](int total, const auto& song){return total + song->get_duration();});
    }
    
    // Get the number of songs in the playlist
    size_t get_song_count() const {
        return songs_.size();
    }
    
    // Remove all songs from the playlist
    void clear() {
        songs_.clear();
    }

private:
    std::vector<std::unique_ptr<Song>> songs_;
};

#endif // PLAYLIST_HPP

